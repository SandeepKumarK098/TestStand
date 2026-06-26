/**************************************************************************/
/* LabWindows/CVI User Interface Resource (UIR) Include File              */
/* Copyright (c) National Instruments 1999. All Rights Reserved.          */
/*                                                                        */
/* WARNING: Do not add to, delete from, or otherwise modify the contents  */
/*          of this include file.                                         */
/**************************************************************************/

#include <userint.h>

#ifdef __cplusplus
    extern "C" {
#endif

     /* Panels and Controls: */

#define  PANEL                           1       /* callback function: ClosePanel */
#define  PANEL_NUMCYCLES                 2       /* callback function: NumberCycles */
#define  PANEL_AMPLITUDE                 3       /* callback function: SetAmplitude */
#define  PANEL_WAVEFORM                  4
#define  PANEL_DONE                      5       /* callback function: Done */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */ 

int  CVICALLBACK ClosePanel(int panel, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Done(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK NumberCycles(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK SetAmplitude(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
