#include "tsutil.h" 
#include <ansi_c.h>
#include <utility.h>
#include "toolbox.h"		 
#include "inifile.h"
#include "toolbox.h"

#define EXPORT _stdcall __export 
#define GLOBAL_VAR_NAME "GlobalsPersistenceTestNumber"
	
//////////////////////////////////////////////////////////////////

/*===========================================================================*/
/* CompareWithPrecision								                         */
/* This function compares two double numbers.  It uses the following         */
/* equations where a and b are the numbers to be compared and d is the       */
/* digits of precision to be used											 */
/*                              								 			 */
/*			|a-b|	    -(d-1) 		   			    	    -(d-1) 			 */
/*			-----  <  10		if |a| == 0 use  |b|  <  10					 */
/*			 |a|	   														 */
/* The function returns 0 if a=b, -1 if a<b, and 1 if a>b					 */
/*===========================================================================*/

static int CompareWithPrecision (double a, double b)
	{	
	int comparePrecision = 14;
	double toleranceVal;
	errno = 0;

	toleranceVal = pow ((double)10, (double)((comparePrecision-1)*-1));

	if (a == 0)
		{
		if (fabs (b) < toleranceVal)
			if (errno == 0)
				return 0;
			else
				{
				AssertMsg(FALSE, "non-zero errno in CompareWithPrecision");
				return 0;
				}
		}
	else
		{
		if ((fabs(a-b)/fabs(a)) < toleranceVal)
			if (errno == 0)
				return 0;
			else
				{
				AssertMsg(FALSE, "non-zero errno in CompareWithPrecision");
				return 0;
				}
		}
	
	if (a < b)
		return -1;
	else
		return 1;
	}
	
/////////////////////////////////////////////////////////////

int GetIniFilePath(CAObjHandle engine, char path[MAX_PATHNAME_LEN])
	{
	int			error = 0;
	ERRORINFO	errorInfo;
	char *		teDirectory = 0;
	long 		testStandMajorVersion;
	long 		testStandMinorVersion;
	
	tsErrChkMsgPopup(TS_EngineGetMajorVersion(engine, &errorInfo, &testStandMajorVersion));
	tsErrChkMsgPopup(TS_EngineGetMinorVersion(engine, &errorInfo, &testStandMinorVersion));
	
	if (testStandMajorVersion < 4 || (testStandMajorVersion == 4 && testStandMinorVersion == 0))
	{
		tsErrChkMsgPopup( TS_EngineGetProperty (engine, &errorInfo, TS_EngineTestStandDirectory,CAVT_CSTRING, &teDirectory));
	}
	else
	{
		// Starting with 4.1: Changed the path from TestStand app dir to Public dir so we can write it on Vista.
		tsErrChkMsgPopup( TS_EngineGetTestStandPath(engine, &errorInfo, TS_TestStandPath_Public, &teDirectory));
	}
		
	
	if (MakePathname (teDirectory, "globaltest.ini", path) < 0)
		errChk( TS_Err_OperationFailed);
	
Error:
	CA_FreeMemory(teDirectory);
	return error;
	}

//////////////////////////////////////////////////////////////////

int ReadIniFile(CAObjHandle engine, IniText iniText, int *fileExisted)
	{
	int		error = 0;
	char 	path[MAX_PATHNAME_LEN];

	errChk( GetIniFilePath(engine, path));

	errChk( *fileExisted = FileExists(path, 0));
	if (!*fileExisted)
		errChk( Ini_WriteToFile (iniText, path));
		
	errChk( Ini_ReadFromFile (iniText, path));

Error:
	return error;
	}
	
//////////////////////////////////////////////////////////////////

int WriteIniFile(CAObjHandle engine, IniText iniText)
	{
	int		error = 0;
	char 	path[MAX_PATHNAME_LEN];
	
	errChk( GetIniFilePath(engine, path));
	errChk( Ini_WriteToFile (iniText, path));
		
Error:
	return error;
	}

//////////////////////////////////////////////////////////////////	
	
int EXPORT TestGlobalPersistence(CAObjHandle context)
	{
	int			error = 0;
	ERRORINFO	errorInfo;
	IniText		iniText = 0;
	int			fileExisted;
	CAObjHandle	globals = 0;
	CAObjHandle	engine = 0;
	VBOOL		variableExists;
	double		globalVal;
	double		iniVal;
	char		errorMsg[512] = "";
	char 		path[MAX_PATHNAME_LEN];
	
	tsErrChkMsgPopup( TS_SeqContextGetProperty (context, &errorInfo, TS_SeqContextEngine, CAVT_OBJHANDLE, &engine));
	tsErrChkMsgPopup( TS_EngineGetProperty (engine, &errorInfo, TS_EngineGlobals, CAVT_OBJHANDLE, &globals));

	nullChk( iniText = Ini_New (0));
	
	errChk( ReadIniFile(engine, iniText, &fileExisted));

	tsErrChkMsgPopup( TS_PropertyExists (globals, &errorInfo, GLOBAL_VAR_NAME, 0, &variableExists));
	
	if (!fileExisted || (variableExists == VFALSE))
		{
		tsErrChkMsgPopup( TS_PropertySetValNumber (globals, &errorInfo, GLOBAL_VAR_NAME, TS_PropOption_InsertIfMissing, 0.0));
		errChk( Ini_PutDouble (iniText, GLOBAL_VAR_NAME, GLOBAL_VAR_NAME, 0.0));
		}
			
	tsErrChkMsgPopup( TS_PropertyGetValNumber (globals, &errorInfo, GLOBAL_VAR_NAME, 0, &globalVal));
	errChk( Ini_GetDouble (iniText, GLOBAL_VAR_NAME, GLOBAL_VAR_NAME, &iniVal));
	if (CompareWithPrecision(globalVal, iniVal) != 0)
		{
		errChk( GetIniFilePath(engine, path));

		sprintf(errorMsg, "Global Persistence Test Failed: Global Value = %f, IniFile Value = %f.\nIniFile is in '%s'", globalVal, iniVal, path);
		errChk(TS_Err_OperationFailed);
		}
	
	globalVal += 1.0;
	tsErrChkMsgPopup( TS_PropertySetValNumber (globals, &errorInfo, GLOBAL_VAR_NAME, 0, globalVal));
	errChk( Ini_PutDouble (iniText, GLOBAL_VAR_NAME, GLOBAL_VAR_NAME, globalVal));
	
	errChk( WriteIniFile (engine, iniText));

Error:
	if (error < 0)
		TS_SetStepError (context, error, errorMsg);
		
	if (iniText)
	    Ini_Dispose(iniText);
	    
	CA_DiscardObjHandle(engine);
	CA_DiscardObjHandle(globals);
	return error;
	}
	

