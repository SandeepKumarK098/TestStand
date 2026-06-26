#include "stdtst.h"
#include "tsutil.h"

void __declspec(dllexport) __stdcall PassFail(int *result,
        char reportText[1024], short *errorOccurred, long *errorCode, char errorMsg[1024])
{
    int error = 0;
	// The tsErrChk macro expects the following two variables to exist. This macro is like the CVI toolbox.h macro errChk except that it also retrieves the error message from an ActiveX function and places it in errMsg.
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

void __declspec(dllexport) __stdcall Action(CAObjHandle seqContextCVI,
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
