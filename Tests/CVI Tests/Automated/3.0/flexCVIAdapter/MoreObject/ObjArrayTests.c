#include "stdtst.h"
#include "tsutil.h"

long __declspec(dllexport) Test1DObjArrays(struct IDispatch *arg1[100],  CAObjHandle arg2[100],  struct IUnknown *arg3[100])
{
    ErrMsg errMsg = {'\0'};
    ERRORINFO errorInfo;
    int error = 0;
    int i;
    int passed = 1;
    
    for (i = 0; i < 10; i++) {
    	int expected1 = i;
    	int expected2 = 10 * i;
    	int expected3 = 100 * i;
    	double actual1;
    	double actual2;
    	double actual3;
    	CAObjHandle arg1Handle;
    	CAObjHandle arg3Handle;
    	
    	CA_CreateObjHandleFromInterface (arg1[i], &TS_IID_Property, 1,
                                 			LOCALE_NEUTRAL, 0, 1, &arg1Handle);
	   	CA_CreateObjHandleFromInterface (arg3[i], &TS_IID_Property, 1,
                                 			LOCALE_NEUTRAL, 0, 1, &arg3Handle);

    	tsErrChk (TS_PropertyGetValNumber(arg2[i], &errorInfo, "", 0, &actual2));
      	tsErrChk (TS_PropertyGetValNumber(arg1Handle, &errorInfo, "", 0, &actual1));
      	tsErrChk (TS_PropertyGetValNumber(arg3Handle, &errorInfo, "", 0, &actual3));
  
  		CA_DiscardObjHandle(arg1Handle);
    	CA_DiscardObjHandle(arg3Handle);
		
    	if (actual1 != expected1) {
    		passed = 0;
    		break;
    	}
    	if (actual2 != expected2) {
    		passed = 0;
    		break;
    	}
    	if (actual3 != expected3) {
    		passed = 0;
    		break;
    	}
    }
    

    // REPLACE THE FOLLOWING WITH YOUR SPECIFIC TEST CODE 
    // Boolean success = TRUE;
    // char *lastUserName = NULL;    

    // if (success)
    //     *result = PASS;
    // else
    //     *result = FAIL;   

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
        //*errorOccurred = TRUE;
    
        // OPTIONALLY SET THE ERROR CODE AND STRING
        // *errorCode = error;
        // strcpy(errorMsg, errMsg);
        }
    
    return passed;    
}

long __declspec(dllexport) Test2DObjArrays(struct IDispatch *arg1[10][10],  CAObjHandle arg2[10][10],  struct IUnknown *arg3[10][10])
{
    int error = 0;
    ErrMsg errMsg = {'\0'};
    ERRORINFO errorInfo;
    int i, j;
    int passed = 1;
    
	for (j = 0; j < 10; j++) {
		for (i = 0; i < 10; i++) {
			int expected1 = 10*j + 1*i;
			int expected2 = 100*j + 10*i;
			int expected3 = 1000*j + 100*i;
			double actual1;
			double actual2;
			double actual3;
			CAObjHandle arg1Handle;
			CAObjHandle arg3Handle;
    	
			CA_CreateObjHandleFromInterface (arg1[j][i], &TS_IID_Property, 1,
											 LOCALE_NEUTRAL, 0, 1, &arg1Handle);
			CA_CreateObjHandleFromInterface (arg3[j][i], &TS_IID_Property, 1,
											 LOCALE_NEUTRAL, 0, 1, &arg3Handle);

			tsErrChk (TS_PropertyGetValNumber(arg2[j][i], &errorInfo, "", 0, &actual2));
			tsErrChk (TS_PropertyGetValNumber(arg1Handle, &errorInfo, "", 0, &actual1));
			tsErrChk (TS_PropertyGetValNumber(arg3Handle, &errorInfo, "", 0, &actual3));
  
			CA_DiscardObjHandle(arg1Handle);
			CA_DiscardObjHandle(arg3Handle);
		
			if (actual1 != expected1) {
				passed = 0;
				break;
			}
			if (actual2 != expected2) {
				passed = 0;
				break;
			}
			if (actual3 != expected3) {
				passed = 0;
				break;
			}
		}
	}

Error:  
    // FREE RESOURCES
    // if (lastUserName != NULL)
    //     CA_FreeMemory(lastUserName);

    // If an error occurred, set the error flag to cause a run-time error in TestStand.
    if (error < 0)
        {
 //       *errorOccurred = TRUE;
    
        // OPTIONALLY SET THE ERROR CODE AND STRING
        // *errorCode = error;
        // strcpy(errorMsg, errMsg);
        }
    
    return passed;    
}
