#include "stdtst.h"
#include "tsutil.h"

void __declspec(dllexport) action(CAObjHandle seqContextCVI, char reportText[1024], short *errorOccurred, long *errorCode, char errorMsg[1024])
{
    int error = 0;
    // ErrMsg errMsg = {'\0'};
    // ERRORINFO errorInfo;
    // char *lastUserName = NULL;    

    // INSERT YOUR SPECIFIC TEST CODE HERE

    // The following code shows how to access a property or variable via the TestStand ActiveX API
    // tsErrChk (TS_PropertyGetValString(seqContextCVI, &errorInfo, 
    //                                   "StationGlobals.TS.LastUserName", 
    //                                   0, &lastUserName));

Error:  
    // FREE RESOURCES
    // if (lastUserName != NULL)
    //     CA_FreeMemory(lastUserName);

    // If an error occurred, set the error flag to cause a run-time error in TestStand.
    if (error < 0)
        {
        // *errorOccurred = TRUE;
    
        // OPTIONALLY SET THE ERROR CODE AND STRING
        // *errorCode = error;
        // strcpy(errorMsg, errMsg);
        }
}

void __declspec(dllexport) __stdcall pf(int *result,
        char reportText[1024], short *errorOccurred, long *errorCode, char errorMsg[1024])
{
    int error = 0;
    // ErrMsg errMsg = {'\0'};
    // ERRORINFO errorInfo;

    // REPLACE THE FOLLOWING WITH YOUR SPECIFIC TEST CODE 
    // Boolean success = TRUE;
    // char *lastUserName = NULL;    

    // if (success)
    //     *result = PASS;
    // else
    //     *result = FAIL;   

    // The following code shows how to access a property or variable via the TestStand ActiveX API
    // To use this code you must add a parameter "CAObjHandle seqContextCVI" to this function and pass
    // a sequence context to it.
    // tsErrChk (TS_PropertyGetValString(seqContextCVI, &errorInfo, 
    //                                   "StationGlobals.TS.LastUserName", 
    //                                   0, &lastUserName));

Error:  
    // FREE RESOURCES
    // if (lastUserName != NULL)
    //     CA_FreeMemory(lastUserName);

    // If an error occurred, set the error flag to cause a run-time error in TestStand.
    if (error < 0)
        {
        // *errorOccurred = TRUE;
    
        // OPTIONALLY SET THE ERROR CODE AND STRING
        // *errorCode = error;
        // strcpy(errorMsg, errMsg);
        }
}

//////////////////////////////////////////
void __declspec(dllexport) nl(double *measurement, char reportText[1024], short *errorOccurred, long *errorCode, char errorMsg[1024])
{
    int error = 0;
    // ErrMsg errMsg = {'\0'};
    // ERRORINFO errorInfo;
    
    // REPLACE THE FOLLOWING WITH YOUR SPECIFIC TEST CODE
    // double testMeasurement = 5.0;
    // double lowLimit;
    
    // *measurement = testMeasurement;
    
    // The following code shows how to access a property or variable via the TestStand ActiveX API
    // To use this code you must add a parameter "CAObjHandle seqContextCVI" to this function and pass
    // a sequence context to it.
    // tsErrChk(TS_PropertyGetValNumber(seqContextCVI, &errorInfo, 
    //                                  "Step.Limits.Low", 0, &lowLimit));

Error:  
    // FREE RESOURCES HERE

    // If an error occurred, set the error flag to cause a run-time error in TestStand.
    if (error < 0)
        {
        // *errorOccurred = TRUE;
    
        // OPTIONALLY SET THE ERROR CODE AND STRING
        // *errorCode = error;
        // strcpy(errorMsg, errMsg);
        }
}

void __declspec(dllexport) ml(double measurements[], char reportText[1024], short *errorOccurred, long *errorCode, char errorMsg[1024])
{
    int error = 0;
    // ErrMsg errMsg = {'\0'};
    // ERRORINFO errorInfo;
    
    //// REPLACE THE FOLLOWING WITH YOUR SPECIFIC TEST CODE
    // double lowLimit0;
    // const int NUM_MEASUREMENTS = 3; // Replace with the number of measurements you define in the MultipleNumericLimitTest step.
    // int i;
    // for (i = 0; i < NUM_MEASUREMENTS; i++) 
    //     measurements[i] = 5.0;  // Replace with the actual measurement values
    
    // The following code shows how to access a property or variable via the TestStand ActiveX API
    // To use this code you must add a parameter "struct IDispatch *seqContextDisp" to this function
    // and pass a sequence context to it.
    // tsErrChk(TS_PropertyGetValNumber(seqContextCVI, &errorInfo,
    //                                  "Step.Result.Measurement[0].Limits.Low", 0, &lowLimit0));

	// Note: This template requires that you do not select the Specify a Data Source for Each Measurement step option.  
	//       If you select this option, the MultipleNumericLimitTest step does not necessarily use the contents of Step.NumericArray. 
	//       You typically do not call a code module when you set this step option.

  Error:  
    //// FREE RESOURCES HERE

    // If an error occurred, set the error flag to cause a run-time error in TestStand.
    if (error < 0)
    {
        // *errorOccurred = TRUE;
    
        // OPTIONALLY SET THE ERROR CODE AND STRING
        // *errorCode = error;
        // strcpy(errorMsg, errMsg);
    }
}

void __declspec(dllexport) sv(char stringMeasurement[1024], char reportText[1024], short *errorOccurred, long *errorCode, char errorMsg[1024])
{
    int error = 0;
    // ErrMsg errMsg = {'\0'};
    // ERRORINFO errorInfo;
    
    // REPLACE THE FOLLOWING WITH YOUR SPECIFIC TEST CODE
    // char *stringValue = "String value from test.";
    // char *lastUserName = NULL;    

    // MBStringCopyMax(stringMeasurement, stringValue, 1024);

    // The following code shows how to access a property or variable via the TestStand ActiveX API
    // To use this code you must add a parameter "CAObjHandle seqContextCVI" to this function and pass
    // a sequence context to it.
    // tsErrChk (TS_PropertyGetValString(seqContextCVI, &errorInfo, 
    //                                   "StationGlobals.TS.LastUserName", 
    //                                   0, &lastUserName));

Error:  
    // FREE RESOURCES
    // if (lastUserName != NULL)
    //     CA_FreeMemory(lastUserName);

    // If an error occurred, set the error flag to cause a run-time error in TestStand.
    if (error < 0)
        {
        // *errorOccurred = TRUE;
    
        // OPTIONALLY SET THE ERROR CODE AND STRING
        // *errorCode = error;
        // strcpy(errorMsg, errMsg);
        }
}

void __declspec(dllexport) pf1(long *result, char reportText[1024], short *errorOccurred, long *errorCode, char errorMsg[1024])
{
	//Insert function body here.
}

void __declspec(dllexport) __stdcall action1(CAObjHandle seqContextCVI,
        char reportText[1024], short *errorOccurred, long *errorCode, char errorMsg[1024])
{
    int error = 0;
	// The tsErrChk macro expects the following two variables to exist. This macro is like the CVI toolbox.h macro errChk except that it also retrieves the error message from an ActiveX function and places it in errMsg.
    // ErrMsg errMsg = {'\0'};
    // ERRORINFO errorInfo;
    // char *lastUserName = NULL;    

    // INSERT YOUR SPECIFIC TEST CODE HERE

    // The following code shows how to access a property or variable via the TestStand ActiveX API
    // tsErrChk (TS_PropertyGetValString(seqContextCVI, &errorInfo, 
    //                                   "StationGlobals.TS.LastUserName", 
    //                                   0, &lastUserName));

Error:  
    // FREE RESOURCES
    // if (lastUserName != NULL)
    //     CA_FreeMemory(lastUserName);

    // If an error occurred, set the error flag to cause a run-time error in TestStand.
    if (error < 0)
        {
        // *errorOccurred = TRUE;
    
        // OPTIONALLY SET THE ERROR CODE AND STRING
        // *errorCode = error;
        // strcpy(errorMsg, errMsg);
        }
}
