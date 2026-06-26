#include <userint.h>
#include "dialog1.h"
#include "tsapicvi.h"
#include <ansi_c.h>
#include "utility.h"
#include "stdtst.h"

typedef CAObjHandle 			EngineHandle;     
typedef CAObjHandle 	SeqContextHandle;

static ERRORINFO gErrorInfo;

void _export DisplayToolMenuDialog(SeqContextHandle seqContext)
{
	VBOOL modified;
	HRESULT error = 0;
	EngineHandle engine = 0;

	TS_SeqContextGetProperty(seqContext,
							 &gErrorInfo,
							 TS_SeqContextEngine,
							 CAVT_OBJHANDLE,
							 &engine);
							 
	TS_EngineDisplayToolMenuDialog (engine, &gErrorInfo, "LKJ", 0, 0,
									   &modified);
	
	CA_DiscardObjHandle(engine);
}

void _export DisplayEngineOptionsDialog(CAObjHandle engine)
{
	VBOOL modified;
	HRESULT error = 0;
							 
	TS_EngineDisplayOptionsDialog (engine, &gErrorInfo, "OPTIONS", 0,
															0, &modified);
}

void _export DisplayLoginDialog(CAObjHandle engine, char *userName, char *userPassword)
{
	VBOOL userHitOK;
	CAObjHandle user = 0;
	VBOOL modified;
	HRESULT error = 0;
							 
	TS_EngineDisplayLoginDialog (engine, &gErrorInfo, "LOGIN DIALOG",
								 userName, userPassword, VTRUE,
								 &user, &userHitOK);

	if (user != 0) 
		CA_DiscardObjHandle(user);    
}

void _export DisplayOpenFileDialog(CAObjHandle engine)
{

	VBOOL hitOK;
	char *absolutePath;
	char *selectedPath;
	
	TS_EngineDisplayOpenFileDialog (engine, &gErrorInfo, "Open File",
									   "DO IT!", "", 0, &selectedPath,
									   &absolutePath, 0, "", 4100, "",
									   CA_DEFAULT_VAL, &hitOK);

 
}

void _export Pause(int seconds)
{
	Delay(seconds);
}

void _export ProgressTest(CAObjHandle thread)
{
	VBOOL modified;
	HRESULT error = 0;
	int i;
	

	for (i = 0; i < 4; i++) {
		double percentCompleted = 25*(i+1);
		char buffer[100];
		
		Pause(1);

		TS_ThreadPostUIMessage (thread, &gErrorInfo,
							   TS_UIMsg_ProgressPercent, percentCompleted,
							   "", VFALSE);
							   
		sprintf(buffer, "%g %% completed...", percentCompleted);
		
		TS_ThreadPostUIMessage (thread, &gErrorInfo,
								   TS_UIMsg_ProgressText, 0,
								   buffer, VFALSE);

	}
	
	TS_ThreadPostUIMessage (thread, &gErrorInfo,
								   TS_UIMsg_ProgressText, 0,
								   "Done", VFALSE);
							   

}



void _export NewBoolProperty(CAObjHandle object, char *propertyName)
{
	HRESULT error = 0;

	error = TS_PropertyNewSubProperty (object, &gErrorInfo, propertyName,
						  TS_PropValType_Boolean, VFALSE, NULL,
						  0);

}

void _export DisplayCVIMessagePopup(char *message)
{
	MessagePopup ("CVI Message", message);
}

void _export DisplayModalCVIMessagePopup(CAObjHandle engine, char *message)
{
	long dummyHWND;
	HRESULT error = 0;
	extern void _cdecl __SetKludgeState(int, int);
	error = TS_EngineNotifyStartOfModalDialog (engine, &gErrorInfo,
												&dummyHWND);
	
	// this doesn't work with message popups!
	__SetKludgeState(5, dummyHWND);
	
	MessagePopup("CVI (modal) message", message);
	
	TS_EngineNotifyEndOfModalDialog (engine, &gErrorInfo, dummyHWND);
}

void _export DisplayModalCVIFilePopup(CAObjHandle engine)
{
	extern void _cdecl __SetKludgeState(int, int);
	char path[MAX_PATHNAME_LEN];
	int handle;
	long dummyHWND;
	HRESULT error = 0;
	
	error = TS_EngineNotifyStartOfModalDialog (engine, &gErrorInfo,
												&dummyHWND);
	
	// this doesn't work with file select popup!
	__SetKludgeState(5, dummyHWND);
	
	
	// Have to do this to bring it to the front
//	handle = GetCVIWindowHandle ();
//	SetForegroundWindow((HWND)handle);

	
	FileSelectPopup ("", "*.*", "", "CVI File Dialog", VAL_OK_BUTTON, 0,
				 0, 1, 0, path);

	TS_EngineNotifyEndOfModalDialog (engine, &gErrorInfo, dummyHWND);
}

void _export DisplayCVIFilePopup(void)
{
	char path[MAX_PATHNAME_LEN];
	int handle;
	
	// Have to do this to bring it to the front
	handle = GetCVIWindowHandle ();
	SetForegroundWindow((HWND)handle);

	
	FileSelectPopup ("", "*.*", "", "CVI File Dialog", VAL_OK_BUTTON, 0,
				 0, 1, 0, path);

}

void _export DisplayCVIPopup(CAObjHandle engine, char *message)
{
	char dllDir[MAX_PATHNAME_LEN];
	char uirPath[MAX_PATHNAME_LEN];
	int panel;
	int textCtrl;
	long dummyHWND;
	HRESULT error = 0;
	extern void _cdecl __SetKludgeState(int, int);
	

	GetModuleDir (__CVIUserHInst, dllDir);							  
	MakePathname (dllDir, "dialog1.uir", uirPath);
	
	panel = LoadPanelEx (0, uirPath, PANEL, __CVIUserHInst);
	SetCtrlVal (panel, PANEL_TEXTMSG, message);
	
	error = TS_EngineNotifyStartOfModalDialog (engine, &gErrorInfo,
												 &dummyHWND);
	
	__SetKludgeState(5, dummyHWND);
	InstallPopup(panel);
	
	RunUserInterface();
	
	RemovePopup(0);
	
	TS_EngineNotifyEndOfModalDialog (engine, &gErrorInfo, dummyHWND);
}


int _export CVICALLBACK OnOK (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event) {
		case EVENT_COMMIT:
			QuitUserInterface(0);
			break;
	}
	return 0;
}


void __declspec(dllexport) DisplayCVIPopup_cvistep(tTestData *data, tTestError *error)
{
	CAObjHandle engine = 0;
	

	TS_SeqContextGetProperty(data->seqContextCVI,
							 &gErrorInfo,
							 TS_SeqContextEngine,
							 CAVT_OBJHANDLE,
							 &engine);
							 
	DisplayCVIPopup(engine, "cvistep Message");
	
	CA_DiscardObjHandle(engine);  	
}
