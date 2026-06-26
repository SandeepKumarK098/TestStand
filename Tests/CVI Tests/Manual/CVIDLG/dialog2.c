#include <userint.h>
#include "dialog2.h"
#include "stdtst.h"
#include "tsutil.h"

void __declspec(dllexport) __stdcall Dialog(tTestData *testData, tTestError *testError)
{
    TSModalData modalID;
    CAObjHandle engine;
    int error = 0;
     ErrMsg errMsg;
     ERRORINFO errorInfo;

	int panel;
	
	panel = LoadPanelEx(0, "dialog2.uir", PANEL, __CVIUserHInst);
	
    // INSERT YOUR SPECIFIC TEST CODE HERE
    // char *lastUserName = NULL;
    
    // The following code shows how to accesses a property or variable via the TestStand ActiveX API
    // tsErrChk (TS_PropertyGetValString(testData->seqContextCVI, &errorInfo, 
    //                                   "StationGlobals.TS.LastUserName", 
    //                                   0, &lastUserName));
    
	TS_SeqContextGetProperty (testData->seqContextCVI, &errorInfo,
							  TS_SeqContextEngine, CAVT_OBJHANDLE,
							  &engine);

	TS_StartModalDialog (engine, &errorInfo, &modalID);
	
	InstallPopup(panel);
	RunUserInterface();
	
	// NOTE: End modal dialog before discarding panel to prevent flashing.
	TS_EndModalDialog (&errorInfo, &modalID);

	DiscardPanel(panel);
	
Error:  
    // FREE RESOURCES
    // if (lastUserName != NULL)
    //     CA_FreeMemory(lastUserName);
   	CA_DiscardObjHandle (engine);
   	
    // If an error occurred, set the error flag to cause a run-time error in TestStand.
    if (error < 0)
        {
        testError->errorFlag = TRUE;
    
        // OPTIONALLY SET THE ERROR CODE AND STRING
        // testError->errorCode = error;
        // testData->replaceStringFuncPtr(&testError->errorMessage, errMsg);
        }
    
    return;    
}

int CVICALLBACK OKButtonCallback (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event) {
		case EVENT_COMMIT:
		
			QuitUserInterface(0);
			break;
	}
	return 0;
}
