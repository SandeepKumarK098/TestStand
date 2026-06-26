#include "SessionMgr.h"

#include "stdtst.h"
#include "tsutil.h"

void __declspec(dllexport) __stdcall GetSession(CAObjHandle *session,
        short *errorOccurred, long *errorCode, char errorMsg[1024])
{
    int error = 0;
    ErrMsg errMsg = {'\0'};
    ERRORINFO errorInfo;

    tsErrChk( SM_GetSession ("Custom::X", session, &errorInfo));

Error:  

    // If an error occurred, set the error flag to cause a run-time error in TestStand.
    if (error < 0)
        {
        *errorOccurred = TRUE;
        *errorCode = error;
        strcpy(errorMsg, errMsg);
        }
    
    return;    
}

void __declspec(dllexport) __stdcall DoNothing(CAObjHandle context,CAObjHandle *thread,
        short *errorOccurred, long *errorCode, char errorMsg[1024])
{
    int error = 0;
    ErrMsg errMsg = {'\0'};
    ERRORINFO errorInfo;
    
    *thread = 0;
    //tsErrChk( TS_SeqContextGetProperty (context, &errorInfo, TS_SeqContextThread, CAVT_OBJHANDLE, thread));

Error:  

    // If an error occurred, set the error flag to cause a run-time error in TestStand.
    if (error < 0)
        {
        *errorOccurred = TRUE;
        *errorCode = error;
        strcpy(errorMsg, errMsg);
        }
    
    return;    
}


int __declspec(dllexport) __stdcall GetNum(CAObjHandle session,
        short *errorOccurred, long *errorCode, char errorMsg[1024])
{
    int error = 0;
    ErrMsg errMsg = {'\0'};
    ERRORINFO errorInfo;        
    long        num = 0;

   tsErrChk (SM_IInstrSessionGetLong (session, &errorInfo, "?", &num));

#if 0
   error = -17001;
   errorInfo.wCode = -17001;
   errorInfo.sCode = -17001;
   strcpy(errorInfo.source,"source");
   strcpy(errorInfo.description,"error description");
   errorInfo.helpContext = 0;
   errorInfo.errorParamPos = 0;
#endif   

Error:  

    // If an error occurred, set the error flag to cause a run-time error in TestStand.
    if (error < 0)
        {
        *errorOccurred = TRUE;
    
        *errorCode = error;
        strcpy(errorMsg, errMsg);
        }
    
    return num;    
}
