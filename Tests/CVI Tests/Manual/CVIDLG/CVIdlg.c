#include <userint.h>
#include <cvirte.h>    /* Needed if linking in external compiler; harmless otherwise */
#include "CVIdlg.h"

#define EVENT_DLG_DONE_OK 	1

int __stdcall DllMain (HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
	switch (fdwReason)
		{
		case DLL_PROCESS_ATTACH:
			if (InitCVIRTE (hinstDLL, 0, 0) == 0)    /* Needed if linking in external compiler; harmless otherwise */
				return 0;	  /* out of memory */
			break;
		case DLL_PROCESS_DETACH:
			CloseCVIRTE ();    /* Needed if linking in external compiler; harmless otherwise */
			break;
		}
	
	return 1;
}

int __stdcall DllEntryPoint (HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
	/* Included for compatibility with Borland */

	return DllMain (hinstDLL, fdwReason, lpvReserved);
}

void DisplayDialog(void)
{	
	int						panel = 0, result;

		// Load UUT Dialog 
	panel = LoadPanelEx (0, "CVIdlg.uir", PANEL, __CVIUserHInst);

	InstallPopup(panel);	    // Display panel and wait for input 
    result = RunUserInterface();

    if (result == EVENT_DLG_DONE_OK)	// if operator pressed OK
    	{
    	}
        
Error:  
	if (panel > 0)
		DiscardPanel(panel);
}    
		

int CVICALLBACK OkCallback (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
		{
		case EVENT_COMMIT:
			QuitUserInterface(EVENT_DLG_DONE_OK);
			break;
		}
	return 0;
}

