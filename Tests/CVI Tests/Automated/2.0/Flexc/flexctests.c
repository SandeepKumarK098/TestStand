#include "stdtst.h"
//#include "flexctests.h"
#include "tsapicvi.h"
#include "tsutil.h"
#include <ansi_c.h>
#include <utility.h>
#include "toolbox.h"

#define EXPORT _stdcall __export 

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

//////////////////////////////////////////////////////////////////

	// VerifyArrayValues expects array to contain base, base+1, base+2,...	
	// SetArrayValues sets array to contain base, base+1, base+2,...						

int EXPORT VerifyArrayValuesDouble (CAObjHandle context, int numElements, double base, double *array)	
	{											
	int	index;									
												
	for (index = 0; index < numElements; index++)				
		if (CompareWithPrecision(array[index], base + index) != 0)		
			{
			char errorMsg[1024];
			
			sprintf(errorMsg,"Error in element %d. Expected %f, found %f", index, base + index, array[index]);
			TS_SetStepError(context, TS_Err_ValueIsInvalidOrOutOfRange, errorMsg);
			return TS_Err_ValueIsInvalidOrOutOfRange;
			}
			
	return 0;													
	}
	
void EXPORT SetArrayValuesDouble (int numElements, double base, double *array)	
	{																
	int	index;														
																	
	for (index = 0; index < numElements; index++)					
		array[index] = base + index;										
	}																
		
/////////////////////////////////////////

int EXPORT VerifyArrayValuesFloat (CAObjHandle context, int numElements, double base, float *array)	
	{											
	int	index;									
												
	for (index = 0; index < numElements; index++)				
		if (CompareWithPrecision(array[index], base + index) != 0)		
			{
			char errorMsg[1024];
			
			sprintf(errorMsg,"Error in element %d. Expected %f, found %f", index, base + index, array[index]);
			TS_SetStepError(context, TS_Err_ValueIsInvalidOrOutOfRange, errorMsg);
			return TS_Err_ValueIsInvalidOrOutOfRange;
			}
																
	return 0;													
	}
	
void EXPORT SetArrayValuesFloat (int numElements, double base, float *array)	
	{																
	int	index;														
																	
	for (index = 0; index < numElements; index++)					
		array[index] = base + index;										
	}																

/////////////////////////////////////////

int EXPORT VerifyArrayValuesInt (CAObjHandle context, int numElements, double base, int *array)	
	{											
	int	index;									
												
	for (index = 0; index < numElements; index++)				
		if (CompareWithPrecision(array[index], base + index) != 0)		
			{
			char errorMsg[1024];
			
			sprintf(errorMsg,"Error in element %d. Expected %d, found %d", index, base + index, array[index]);
			TS_SetStepError(context, TS_Err_ValueIsInvalidOrOutOfRange, errorMsg);
			return TS_Err_ValueIsInvalidOrOutOfRange;
			}
																
	return 0;													
	}
	
void EXPORT SetArrayValuesInt (int numElements, double base, int *array)	
	{																
	int	index;														
																	
	for (index = 0; index < numElements; index++)					
		array[index] = base + index;										
	}																



/////////////////////////////////////////

int EXPORT VerifyArrayValuesUInt (CAObjHandle context, int numElements, double base, unsigned int *array)	
	{											
	int	index;									
												
	for (index = 0; index < numElements; index++)				
		{
		double expected = base + index;
		
		if (expected < 0)
			expected = 0xFFFFFFFF + expected + 1;
		if (CompareWithPrecision(array[index], expected) != 0)		
			{
			char errorMsg[1024];
			
			sprintf(errorMsg,"Error in element %d. Expected %u, found %u", index, expected, array[index]);
			TS_SetStepError(context, TS_Err_ValueIsInvalidOrOutOfRange, errorMsg);
			return TS_Err_ValueIsInvalidOrOutOfRange;
			}
		}
																
	return 0;													
	}
	
void EXPORT SetArrayValuesUInt (int numElements, double base, unsigned int *array)	
	{																
	int	index;														
																	
	for (index = 0; index < numElements; index++)					
		array[index] = base + index;										
	}																
	
/////////////////////////////////////////

int EXPORT VerifyArrayValuesShort (CAObjHandle context, int numElements, double base, short *array)	
	{											
	int	index;									
												
	for (index = 0; index < numElements; index++)				
		if (CompareWithPrecision(array[index], base + index) != 0)		
			{
			char errorMsg[1024];
			
			sprintf(errorMsg,"Error in element %d. Expected %d, found %d", index, base + index, array[index]);
			TS_SetStepError(context, TS_Err_ValueIsInvalidOrOutOfRange, errorMsg);
			return TS_Err_ValueIsInvalidOrOutOfRange;
			}
																
	return 0;													
	}
	
void EXPORT SetArrayValuesShort (int numElements, double base, short *array)	
	{																
	int	index;														
																	
	for (index = 0; index < numElements; index++)					
		array[index] = base + index;										
	}																

/////////////////////////////////////////

int EXPORT VerifyArrayValuesUShort (CAObjHandle context, int numElements, double base, unsigned short *array)	
	{											
	int	index;									
												
	for (index = 0; index < numElements; index++)				
		{
		double expected = base + index;
		
		if (expected < 0)
			expected = 0xFFFF + expected + 1;
		if (CompareWithPrecision(array[index], expected) != 0)		
			{
			char errorMsg[1024];
			
			sprintf(errorMsg,"Error in element %d. Expected %u, found %u", index, expected, array[index]);
			TS_SetStepError(context, TS_Err_ValueIsInvalidOrOutOfRange, errorMsg);
			return TS_Err_ValueIsInvalidOrOutOfRange;
			}
		}
																
	return 0;													
	}
	
void EXPORT SetArrayValuesUShort (int numElements, double base, unsigned short *array)	
	{																
	int	index;														
																	
	for (index = 0; index < numElements; index++)					
		array[index] = base + index;										
	}																

/////////////////////////////////////////

int EXPORT VerifyArrayValuesChar (CAObjHandle context, int numElements, double base, char *array)	
	{											
	int	index;									
												
	for (index = 0; index < numElements; index++)				
		if (CompareWithPrecision(array[index], base + index) != 0)		
			{
			char errorMsg[1024];
			
			sprintf(errorMsg,"Error in element %d. Expected %d, found %d", index, base + index, array[index]);
			TS_SetStepError(context, TS_Err_ValueIsInvalidOrOutOfRange, errorMsg);
			return TS_Err_ValueIsInvalidOrOutOfRange;
			}
																
	return 0;													
	}
	
void EXPORT SetArrayValuesChar (int numElements, double base, char *array)	
	{																
	int	index;														
																	
	for (index = 0; index < numElements; index++)					
		array[index] = base + index;										
	}																

/////////////////////////////////////////

int EXPORT VerifyArrayValuesUChar(CAObjHandle context, int numElements, double base, unsigned char *array)	
	{											
	int	index;									
												
	for (index = 0; index < numElements; index++)				
		{
		double expected = base + index;
		
		if (expected < 0)
			expected = 0xFF + expected + 1;
		if (CompareWithPrecision(array[index], expected) != 0)		
			{
			char errorMsg[1024];
			
			sprintf(errorMsg,"Error in element %d. Expected %u, found %u", index, expected, array[index]);
			TS_SetStepError(context, TS_Err_ValueIsInvalidOrOutOfRange, errorMsg);
			return TS_Err_ValueIsInvalidOrOutOfRange;
			}
		}
																
	return 0;													
	}
	
void EXPORT SetArrayValuesUChar (int numElements, double base, unsigned char *array)	
	{																
	int	index;														
																	
	for (index = 0; index < numElements; index++)					
		array[index] = base + index;										
	}																

//////////////////////////////////////////////////////////////////
typedef enum	
{
	FirstValue = 0,
	SecondValue,
	ThirdValue
} ShortEnum;

typedef enum  
{

	first = 0,
	second,
	third,
	bignum = 0xffffffff
} MyEnum1;

#define I_RETURN_WHAT_YOU_PASS_ME(typeName, type)	\
													\
type EXPORT  IReturnWhatYouPassMe ## typeName (type value)	\
	{														\
	return value;											\
	}														\

I_RETURN_WHAT_YOU_PASS_ME(Double, double)	
I_RETURN_WHAT_YOU_PASS_ME(Float, float)	
I_RETURN_WHAT_YOU_PASS_ME(Int, int)	
I_RETURN_WHAT_YOU_PASS_ME(UInt, unsigned int)	
I_RETURN_WHAT_YOU_PASS_ME(Short, short)	
I_RETURN_WHAT_YOU_PASS_ME(UShort, unsigned short)	
I_RETURN_WHAT_YOU_PASS_ME(Char, char)	
I_RETURN_WHAT_YOU_PASS_ME(UChar, unsigned char)	
I_RETURN_WHAT_YOU_PASS_ME(Enum, MyEnum1)
I_RETURN_WHAT_YOU_PASS_ME(ShortEnum, ShortEnum)


//////////////////////////////////////////////////////////////////

#define I_INCREMENT_WHAT_YOU_PASS_ME(typeName, type)	\
													\
void EXPORT  IIncrementWhatYouPassMe ## typeName (type *value)	\
	{														\
	*value += 1;											\
	}														\

I_INCREMENT_WHAT_YOU_PASS_ME(Double, double)	
I_INCREMENT_WHAT_YOU_PASS_ME(Float, float)	
I_INCREMENT_WHAT_YOU_PASS_ME(Int, int)	
I_INCREMENT_WHAT_YOU_PASS_ME(UInt, unsigned int)	
I_INCREMENT_WHAT_YOU_PASS_ME(Short, short)	
I_INCREMENT_WHAT_YOU_PASS_ME(UShort, unsigned short)	
I_INCREMENT_WHAT_YOU_PASS_ME(Char, char)	
I_INCREMENT_WHAT_YOU_PASS_ME(UChar, unsigned char)
I_INCREMENT_WHAT_YOU_PASS_ME(Enum, MyEnum1)

//////////////////////////////////////////////////////////////////
	
void EXPORT VoidFunction(void)
	{
	}
	
//////////////////////////////////////////////////////////////////
	
void EXPORT CauseGeneralProtectionFault(void)
	{
	int	x = *(int *)0;
	}
	
//////////////////////////////////////////////////////////////////

void EXPORT Matrix(double inMatrix[10][10], double outMatrix[10][10])
	{


	}
	
//////////////////////////////////////////////////////////////////
/////////////////////////////////////////
// Used for the PostStep of the PassOnRTE step type
int EXPORT GetAndClearErrorOccurred(CAObjHandle context)
{
	ERRORINFO	errorInfo;
	HRESULT 	error = 0;
	
	VBOOL errorOccurred;
	
	errChk( TS_PropertyGetValBoolean (context, &errorInfo,
							  "Step.Result.Error.Occurred", 0,
							  &errorOccurred));
							  
	errChk( TS_PropertySetValBoolean (context, &errorInfo,
							  "Step.Result.Error.Occurred", 0,
							  VFALSE));

Error:	
	if (error < 0)
		CA_DisplayErrorInfo (context, "Failed to get error occurred.", error, &errorInfo);
		
	return errorOccurred == VFALSE ? 0 : 1;
}

//////////////////
//For testing specifymodule of flexc adapter
void EXPORT NotAFunction1(char **ptrPtrChar)
{
}

typedef struct {
int x;
int y;
} StructType;

void EXPORT PassAStruct(StructType structParam)
{
}

void EXPORT PassAStructPtr(StructType *structParam)
{
}

