#include "tsutil.h"
#include "stdtst.h"
#include <utility.h>
#include <cvirte.h>		/* Needed if linking in external compiler; harmless otherwise */
#include <userint.h>
#include "Waveform.h"

    // Global variables
static int panel;
double  waveform[1024];

    // Forward Declarations
void GraphWaveform(void);


    // This function can be used to set the status of a step.
    // By default, the status is set in the status expression at runtime.
void TX_TEST DLLEXPORT GetWaveform(tTestData *data,tTestError *testError)    
{
    int         error = 0;
    ErrMsg      errMsg = {'\0'};
    ERRORINFO   errorInfo;
    VARIANT     variantData;
    CAObjHandle engine = 0;
	TSModalData modalData = InitialModalData;
    
    tsErrChk( TS_SeqContextGetProperty (data->seqContextCVI, &errorInfo, TS_SeqContextEngine, CAVT_OBJHANDLE, &engine));
                                  
    errChk(panel = LoadPanelEx (0, "Waveform.uir", PANEL, __CVIUserHInst));

        // Display Waveform on Graph control
    GraphWaveform();    
    
	tsErrChk( TS_StartModalDialog (engine, &errorInfo, &modalData));
	InstallPopup(panel);
	errChk(RunUserInterface());
	
    // Copy C array to VARIANT
    CA_VariantSet1DArray (&variantData, CAVT_DOUBLE, 1024, waveform);
    
    // The following code shows how to accesses a property or variable via the TestStand ActiveX API
    tsErrChk (TS_PropertySetValVariant (data->seqContextCVI, &errorInfo, "Step.Waveform", 0, variantData));

	
Error:  
    if (engine)
        CA_DiscardObjHandle(engine);
        
	// NOTE: End modal dialog before discarding panel to prevent flashing.
	TS_EndModalDialog(&errorInfo, &modalData);

	if (panel > 0)
		DiscardPanel (panel);

    // If an error occurred, set the error flag to cause a run-time error in TestStand.
    if (error < 0)
        TS_SetStepError (data->seqContextCVI, error, errMsg);
    return;    
}

    // Display Waveform on Graph control
void GraphWaveform(void)
{
    static double      amplitude;
    static double      numCycles;
    static int         i;

    GetCtrlVal (panel, PANEL_AMPLITUDE, &amplitude);
    GetCtrlVal (panel, PANEL_NUMCYCLES, &numCycles);

    for (i=0; i<1024; i++)
        waveform[i] = amplitude * sin((2*3.14) * i *numCycles/ 1024);
    
    DeleteGraphPlot (panel, PANEL_WAVEFORM, -1, VAL_IMMEDIATE_DRAW);
    
    PlotY (panel, PANEL_WAVEFORM, waveform, 1024, VAL_DOUBLE,
            VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1, VAL_RED);
}


    // User changed number of cycles in waveform
int CVICALLBACK NumberCycles (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
   
	switch (event)
        {
		case EVENT_COMMIT:
                // Display Waveform on Graph control		
		    GraphWaveform();
			break;
        }
	return 0;
}


    // User changed amplitude of waveform
int CVICALLBACK SetAmplitude (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
        {
		case EVENT_COMMIT:
                // Display Waveform on Graph control				
		    GraphWaveform();
			break;
        }
	return 0;
}

int CVICALLBACK Done (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
        {
		case EVENT_COMMIT:
			QuitUserInterface (0);
			break;
        }
	return 0;
}

