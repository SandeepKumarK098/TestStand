#include "Windows.h"
#include "WinDef.h"
#include "WinBase.h"
#include "Utils.h"
#include "LVServer.h"
#include <toolbox.h>
#include <cviauto.h>
#include <ansi_c.h>
#include <utility.h>

static CAObjHandle  lvServer = 0;
char gOpenLvVersion[256] = "";


//////////////////////////////////////////////////

int RunLabVIEWVI(const char *viPath)
{
    int         error = 0;
    ERRORINFO   errorInfo;
    CAObjHandle vi = 0;
    char        buf[1024];

    errChk( LabVIEW_AppGetVIReference (lvServer, &errorInfo, viPath,
                               "", VFALSE, &vi));

    DoSystemProcessing();
    
    errChk( LabVIEW_VirtualInstrRun (vi, &errorInfo, VFALSE));
    
    DoSystemProcessing();
    
Error:
    if (vi != 0)
        CA_DiscardObjHandle(vi);

    return error;
}

/////////////////////////////////////////////////

long __declspec(dllexport) CloseLV(const char *viToRun)
{
    int         error = 0;
    ERRORINFO   errorInfo;

    if (lvServer != 0)
    {
		if (viToRun != 0)
			RunLabVIEWVI(viToRun);
		
        error = LabVIEW_AppQuit (lvServer, &errorInfo);

        DoSystemProcessing();
    
        CA_DiscardObjHandle(lvServer);
        lvServer = 0;

        DoSystemProcessing();
    }
    
    return error;
}

////////////////////////////////////////////////////////////

long __declspec(dllexport) LaunchLVVersion(const char *lvVersion, int getLocalAXRef)
{
   	int         error = 0;
    ERRORINFO   errorInfo;
    char		lvPathReg[256], lvPath[MAX_PATHNAME_LEN], lvExePath[MAX_PATHNAME_LEN];
    char		modulePath[MAX_PATHNAME_LEN], launchViPath[MAX_PATHNAME_LEN], lvCommand[MAX_PATHNAME_LEN + MAX_PATHNAME_LEN + 1];
    unsigned int lvPathSize = MAX_PATHNAME_LEN;    
    DWORD		exitCode;
    char		buf[1024];

	if (lvServer)
	{
		if (strcmp(lvVersion, gOpenLvVersion) != 0)
			CloseLV(NULL);
	}
		
    if (!lvServer)
    {
	    // First run the version of LabVIEW that you want.
	    sprintf(lvPathReg, "SOFTWARE\\National Instruments\\LabVIEW\\%s", lvVersion);
	    errChk( RegReadString(REGKEY_HKLM, lvPathReg, "Path", lvPath, MAX_PATHNAME_LEN, &lvPathSize));
	    MakePathname(lvPath, "labview.exe", lvExePath);

	    errChk( GetModuleDir (__CVIUserHInst, modulePath));
		sprintf(launchViPath, "\"%s\\LVRun %s.vi\"", modulePath, lvVersion);
	    errChk( ExecuteCommand(lvExePath, launchViPath, NULL, &exitCode));
	    errChk((long) exitCode);

		DoSystemProcessing(); 

		if (getLocalAXRef != 0)
		{
	   	    // Now when you invoke the ActiveX server you get the expected version.
			errChk( LabVIEW_NewApp (NULL, 1, LOCALE_NEUTRAL, 0, &lvServer));	// Attaches to launched app.
		}
		strcpy(gOpenLvVersion, lvVersion);

	    DoSystemProcessing();
	}

Error:
    return error;
}







