// Please see readme.txt that is included with this example.

#include "stdtst.h"
#include "tsutil.h"
#include <cvirte.h>		/* Needed if linking in external compiler; harmless otherwise */
#include <userint.h>
#include <utility.h>
#include "editLimitsDialog.h"

    // Forward declarations                        
static int InitializePanelWithStepSettings(CAObjHandle context, int panel);
static int SetStepSettingsFromPanel(CAObjHandle context, int panel);



    // Display Edit Numeric Limits Dialog
    // Edit dialogs must be modal to the TestStand application
void TX_TEST DLLEXPORT EditLimits(tTestData *data,tTestError *testError)    
{
    int             error = 0;
    ErrMsg          errMsg = {'\0'};
    ERRORINFO       errorInfo;
    CAObjHandle     engine = 0;
    int             panel = -1;
	TSModalData		modalData = InitialModalData;
	CAObjHandle     evaluationObject = 0;

    tsErrChk( TS_SeqContextGetProperty (data->seqContextCVI, &errorInfo, TS_SeqContextEngine, CAVT_OBJHANDLE, &engine));
                                  
    errChk(panel = LoadPanelEx (0, "EditLimitsDialog.uir", PANEL, __CVIUserHInst));

        // Initialize panel with limits
    errChk( InitializePanelWithStepSettings(data->seqContextCVI, panel));
		
		// Modal dialog
	tsErrChk( TS_StartModalDialog (engine, &errorInfo, &modalData));
	InstallPopup(panel);
	errChk(RunUserInterface());
	
	if(error == EVENT_DLG_DONE_OK) 
	    {
            // Indicates to sequence editor that sequence file has changed
        tsErrChk (TS_PropertyEvaluate (data->seqContextCVI, &errorInfo, "RunState.InitialSelection.SelectedFile.ChangeCount++", &evaluationObject));

		errChk(SetStepSettingsFromPanel(data->seqContextCVI, panel));   // Set limits and comparison values to step properties
	    }
    
Error:  
    if (engine)
        CA_DiscardObjHandle(engine);
        
    if (evaluationObject)
        CA_DiscardObjHandle(evaluationObject);
        
	// NOTE: End modal dialog before discarding panel to prevent flashing.
	TS_EndModalDialog(&errorInfo, &modalData);
    
	if (panel > 0)
		DiscardPanel (panel);

		// Set error information in step.
	if (error<0)
        TS_SetStepError (data->seqContextCVI, error, errMsg);

	return;
}

    // Set limit values to step properties
static int SetStepSettingsFromPanel(CAObjHandle seqContext, int panel)
{
	int         error = 0;
	ERRORINFO   errorInfo;
    ErrMsg      errMsg = {'\0'};

    errChk( TS_SetPropertyToCtrlVal (panel, PANEL_HIGHLIMIT, seqContext, "Step.Limits.High"));
    errChk( TS_SetPropertyToCtrlVal (panel, PANEL_LOWLIMIT,  seqContext, "Step.Limits.Low"));
	
Error:
	return error;
}

    // Initialize panel with step settings
static int InitializePanelWithStepSettings(CAObjHandle context, int panel)
{
	int         error = 0;
	ERRORINFO   errorInfo;
	ErrMsg      errMsg = {'\0'};
    
    errChk( TS_SetCtrlToPropertyVal (context, "Step.Limits.Low",  panel, PANEL_LOWLIMIT));
    errChk( TS_SetCtrlToPropertyVal (context, "Step.Limits.High", panel, PANEL_HIGHLIMIT));
    
Error:
	return error;
}


int CVICALLBACK Ok (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
        {
		case EVENT_COMMIT:
			QuitUserInterface (EVENT_DLG_DONE_OK);
			break;
        }
	return 0;
}

int CVICALLBACK ClosePanel (int panel, int event, void *callbackData,
		int eventData1, int eventData2)
{
	switch (event)
        {
		case EVENT_CLOSE:
			QuitUserInterface (EVENT_DLG_DONE_CANCEL);
			break;
        }
	return 0;
}


int CVICALLBACK Cancel (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
        {
		case EVENT_COMMIT:
			QuitUserInterface (EVENT_DLG_DONE_CANCEL);
			break;
        }
	return 0;
}


int __stdcall DllMain (HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
	switch (fdwReason)
        {
		case DLL_PROCESS_ATTACH:
			if (InitCVIRTE (hinstDLL, 0, 0) == 0)		/* Needed if linking in external compiler; harmless otherwise */
				return 0;	/* out of memory */
			break;
		case DLL_PROCESS_DETACH:
			if (!CVIRTEHasBeenDetached())		/* Do not call CVI functions if cvirte.dll has already been detached. */
                {
				CloseCVIRTE ();		/* Needed if linking in external compiler; harmless otherwise */
                }
			break;
        }

	return 1;
}

int __stdcall DllEntryPoint (HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
	/* Included for compatibility with Borland */

	 return DllMain (hinstDLL, fdwReason, lpvReserved);
}

