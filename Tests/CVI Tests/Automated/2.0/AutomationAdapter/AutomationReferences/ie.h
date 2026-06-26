#ifndef _IE_H
#define _IE_H

#if defined(INCLUDE_AFTER_WINDOWS_H) && !defined(_INC_WINDOWS)
#error  This header must be included before utility.h and formatio.h
#error  because it includes cviauto.h which includes Windows SDK headers.
#endif /* INCLUDE_AFTER_WINDOWS_H */

#include <cviauto.h>

#ifdef __cplusplus
    extern "C" {
#endif
/* NICDBLD_BEGIN> ActiveX Automation Properties */

/* NICDBLD_BEGIN> Object Name: IWebBrowser2 */
#define SHDocVw_IWebBrowser2ReadyState           0xFFFFFDF3
#define SHDocVw_IWebBrowser2HWND                 0xFFFFFDFD
#define SHDocVw_IWebBrowser2Name                 0x00000000
#define SHDocVw_IWebBrowser2Application          0x000000C8
#define SHDocVw_IWebBrowser2Parent               0x000000C9
#define SHDocVw_IWebBrowser2Container            0x000000CA
#define SHDocVw_IWebBrowser2Document             0x000000CB
#define SHDocVw_IWebBrowser2TopLevelContainer    0x000000CC
#define SHDocVw_IWebBrowser2Type                 0x000000CD
#define SHDocVw_IWebBrowser2Left                 0x000000CE
#define SHDocVw_IWebBrowser2Top                  0x000000CF
#define SHDocVw_IWebBrowser2Width                0x000000D0
#define SHDocVw_IWebBrowser2Height               0x000000D1
#define SHDocVw_IWebBrowser2LocationName         0x000000D2
#define SHDocVw_IWebBrowser2LocationURL          0x000000D3
#define SHDocVw_IWebBrowser2Busy                 0x000000D4
#define SHDocVw_IWebBrowser2FullName             0x00000190
#define SHDocVw_IWebBrowser2Path                 0x00000191
#define SHDocVw_IWebBrowser2Visible              0x00000192
#define SHDocVw_IWebBrowser2StatusBar            0x00000193
#define SHDocVw_IWebBrowser2StatusText           0x00000194
#define SHDocVw_IWebBrowser2ToolBar              0x00000195
#define SHDocVw_IWebBrowser2MenuBar              0x00000196
#define SHDocVw_IWebBrowser2FullScreen           0x00000197
#define SHDocVw_IWebBrowser2Offline              0x00000226
#define SHDocVw_IWebBrowser2Silent               0x00000227
#define SHDocVw_IWebBrowser2RegisterAsBrowser    0x00000228
#define SHDocVw_IWebBrowser2RegisterAsDropTarget 0x00000229
#define SHDocVw_IWebBrowser2TheaterMode          0x0000022A
#define SHDocVw_IWebBrowser2AddressBar           0x0000022B
#define SHDocVw_IWebBrowser2Resizable            0x0000022C
/* NICDBLD_END> Object Name: IWebBrowser2 */
/* NICDBLD_END> ActiveX Automation Properties */

/* NICDBLD_BEGIN> Type Library Specific Types */
enum SHDocVwEnum_CommandStateChangeConstants
{
	SHDocVwConst_CSC_UPDATECOMMANDS = -1,
	SHDocVwConst_CSC_NAVIGATEFORWARD = 1,
	SHDocVwConst_CSC_NAVIGATEBACK = 2,
	_SHDocVw_CommandStateChangeConstantsForceSizeToFourBytes = -1
};
enum SHDocVwEnum_OLECMDID
{
	SHDocVwConst_OLECMDID_OPEN = 1,
	SHDocVwConst_OLECMDID_NEW = 2,
	SHDocVwConst_OLECMDID_SAVE = 3,
	SHDocVwConst_OLECMDID_SAVEAS = 4,
	SHDocVwConst_OLECMDID_SAVECOPYAS = 5,
	SHDocVwConst_OLECMDID_PRINT = 6,
	SHDocVwConst_OLECMDID_PRINTPREVIEW = 7,
	SHDocVwConst_OLECMDID_PAGESETUP = 8,
	SHDocVwConst_OLECMDID_SPELL = 9,
	SHDocVwConst_OLECMDID_PROPERTIES = 10,
	SHDocVwConst_OLECMDID_CUT = 11,
	SHDocVwConst_OLECMDID_COPY = 12,
	SHDocVwConst_OLECMDID_PASTE = 13,
	SHDocVwConst_OLECMDID_PASTESPECIAL = 14,
	SHDocVwConst_OLECMDID_UNDO = 15,
	SHDocVwConst_OLECMDID_REDO = 16,
	SHDocVwConst_OLECMDID_SELECTALL = 17,
	SHDocVwConst_OLECMDID_CLEARSELECTION = 18,
	SHDocVwConst_OLECMDID_ZOOM = 19,
	SHDocVwConst_OLECMDID_GETZOOMRANGE = 20,
	SHDocVwConst_OLECMDID_UPDATECOMMANDS = 21,
	SHDocVwConst_OLECMDID_REFRESH = 22,
	SHDocVwConst_OLECMDID_STOP = 23,
	SHDocVwConst_OLECMDID_HIDETOOLBARS = 24,
	SHDocVwConst_OLECMDID_SETPROGRESSMAX = 25,
	SHDocVwConst_OLECMDID_SETPROGRESSPOS = 26,
	SHDocVwConst_OLECMDID_SETPROGRESSTEXT = 27,
	SHDocVwConst_OLECMDID_SETTITLE = 28,
	SHDocVwConst_OLECMDID_SETDOWNLOADSTATE = 29,
	SHDocVwConst_OLECMDID_STOPDOWNLOAD = 30,
	SHDocVwConst_OLECMDID_ONTOOLBARACTIVATED = 31,
	SHDocVwConst_OLECMDID_FIND = 32,
	SHDocVwConst_OLECMDID_DELETE = 33,
	SHDocVwConst_OLECMDID_HTTPEQUIV = 34,
	SHDocVwConst_OLECMDID_HTTPEQUIV_DONE = 35,
	SHDocVwConst_OLECMDID_ENABLE_INTERACTION = 36,
	SHDocVwConst_OLECMDID_ONUNLOAD = 37,
	SHDocVwConst_OLECMDID_PROPERTYBAG2 = 38,
	SHDocVwConst_OLECMDID_PREREFRESH = 39,
	_SHDocVw_OLECMDIDForceSizeToFourBytes = -1
};
enum SHDocVwEnum_OLECMDF
{
	SHDocVwConst_OLECMDF_SUPPORTED = 1,
	SHDocVwConst_OLECMDF_ENABLED = 2,
	SHDocVwConst_OLECMDF_LATCHED = 4,
	SHDocVwConst_OLECMDF_NINCHED = 8,
	_SHDocVw_OLECMDFForceSizeToFourBytes = -1
};
enum SHDocVwEnum_OLECMDEXECOPT
{
	SHDocVwConst_OLECMDEXECOPT_DODEFAULT = 0,
	SHDocVwConst_OLECMDEXECOPT_PROMPTUSER = 1,
	SHDocVwConst_OLECMDEXECOPT_DONTPROMPTUSER = 2,
	SHDocVwConst_OLECMDEXECOPT_SHOWHELP = 3,
	_SHDocVw_OLECMDEXECOPTForceSizeToFourBytes = -1
};
enum SHDocVwEnum_tagREADYSTATE
{
	SHDocVwConst_READYSTATE_UNINITIALIZED = 0,
	SHDocVwConst_READYSTATE_LOADING = 1,
	SHDocVwConst_READYSTATE_LOADED = 2,
	SHDocVwConst_READYSTATE_INTERACTIVE = 3,
	SHDocVwConst_READYSTATE_COMPLETE = 4,
	_SHDocVw_tagREADYSTATEForceSizeToFourBytes = -1
};
enum SHDocVwEnum_ShellWindowTypeConstants
{
	SHDocVwConst_SWC_EXPLORER = 0,
	SHDocVwConst_SWC_BROWSER = 1,
	SHDocVwConst_SWC_3RDPARTY = 2,
	SHDocVwConst_SWC_CALLBACK = 4,
	_SHDocVw_ShellWindowTypeConstantsForceSizeToFourBytes = -1
};
enum SHDocVwEnum_ShellWindowFindWindowOptions
{
	SHDocVwConst_SWFO_NEEDDISPATCH = 1,
	SHDocVwConst_SWFO_INCLUDEPENDING = 2,
	SHDocVwConst_SWFO_COOKIEPASSED = 4,
	_SHDocVw_ShellWindowFindWindowOptionsForceSizeToFourBytes = -1
};
enum SHDocVwEnum_ShellFolderViewOptions
{
	SHDocVwConst_SFVVO_SHOWALLOBJECTS = 1,
	SHDocVwConst_SFVVO_SHOWEXTENSIONS = 2,
	SHDocVwConst_SFVVO_SHOWCOMPCOLOR = 8,
	SHDocVwConst_SFVVO_SHOWSYSFILES = 32,
	SHDocVwConst_SFVVO_WIN95CLASSIC = 64,
	SHDocVwConst_SFVVO_DOUBLECLICKINWEBVIEW = 128,
	SHDocVwConst_SFVVO_DESKTOPHTML = 512,
	_SHDocVw_ShellFolderViewOptionsForceSizeToFourBytes = -1
};
enum SHDocVwEnum_ShellSpecialFolderConstants
{
	SHDocVwConst_ssfDESKTOP = 0,
	SHDocVwConst_ssfPROGRAMS = 2,
	SHDocVwConst_ssfCONTROLS = 3,
	SHDocVwConst_ssfPRINTERS = 4,
	SHDocVwConst_ssfPERSONAL = 5,
	SHDocVwConst_ssfFAVORITES = 6,
	SHDocVwConst_ssfSTARTUP = 7,
	SHDocVwConst_ssfRECENT = 8,
	SHDocVwConst_ssfSENDTO = 9,
	SHDocVwConst_ssfBITBUCKET = 10,
	SHDocVwConst_ssfSTARTMENU = 11,
	SHDocVwConst_ssfDESKTOPDIRECTORY = 16,
	SHDocVwConst_ssfDRIVES = 17,
	SHDocVwConst_ssfNETWORK = 18,
	SHDocVwConst_ssfNETHOOD = 19,
	SHDocVwConst_ssfFONTS = 20,
	SHDocVwConst_ssfTEMPLATES = 21,
	_SHDocVw_ShellSpecialFolderConstantsForceSizeToFourBytes = -1
};
/* NICDBLD_END> Type Library Specific Types */

HRESULT CVIFUNC SHDocVw_GetProperty (CAObjHandle objectHandle,
                                     ERRORINFO *errorInfo,
                                     unsigned int propertyID,
                                     unsigned int propertyType, void *value);

HRESULT CVIFUNC SHDocVw_SetProperty (CAObjHandle objectHandle,
                                     ERRORINFO *errorInfo,
                                     unsigned int propertyID,
                                     unsigned int propertyType, ...);

HRESULT CVIFUNC SHDocVw_NewIWebBrowser2 (char *server, CAObjHandle *objectHandle);

HRESULT CVIFUNC SHDocVw_OpenIWebBrowser2 (char *fileName, char *server,
                                          CAObjHandle *objectHandle);

HRESULT CVIFUNC SHDocVw_ActiveIWebBrowser2 (char *server,
                                            CAObjHandle *objectHandle);

HRESULT CVIFUNC SHDocVw_IWebBrowser2GoBack (CAObjHandle objectHandle,
                                            ERRORINFO *errorInfo);

HRESULT CVIFUNC SHDocVw_IWebBrowser2GoForward (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo);

HRESULT CVIFUNC SHDocVw_IWebBrowser2GoHome (CAObjHandle objectHandle,
                                            ERRORINFO *errorInfo);

HRESULT CVIFUNC SHDocVw_IWebBrowser2GoSearch (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo);

HRESULT CVIFUNC SHDocVw_IWebBrowser2Navigate (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo, char *URL,
                                              VARIANT flags,
                                              VARIANT targetFrameName,
                                              VARIANT postData, VARIANT headers);

HRESULT CVIFUNC SHDocVw_IWebBrowser2Refresh (CAObjHandle objectHandle,
                                             ERRORINFO *errorInfo);

HRESULT CVIFUNC SHDocVw_IWebBrowser2Refresh2 (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              VARIANT level);

HRESULT CVIFUNC SHDocVw_IWebBrowser2Stop (CAObjHandle objectHandle,
                                          ERRORINFO *errorInfo);

HRESULT CVIFUNC SHDocVw_IWebBrowser2Quit (CAObjHandle objectHandle,
                                          ERRORINFO *errorInfo);

HRESULT CVIFUNC SHDocVw_IWebBrowser2ClientToWindow (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    long *pcx, long *pcy);

HRESULT CVIFUNC SHDocVw_IWebBrowser2PutProperty (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 char *property, VARIANT vtValue);

HRESULT CVIFUNC SHDocVw_IWebBrowser2GetProperty (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 char *property,
                                                 VARIANT *returnValue);

HRESULT CVIFUNC SHDocVw_IWebBrowser2Navigate2 (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo, VARIANT URL,
                                               VARIANT flags,
                                               VARIANT targetFrameName,
                                               VARIANT postData, VARIANT headers);

HRESULT CVIFUNC SHDocVw_IWebBrowser2QueryStatusWB (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   enum SHDocVwEnum_OLECMDID cmdID,
                                                   enum SHDocVwEnum_OLECMDF *returnValue);

HRESULT CVIFUNC SHDocVw_IWebBrowser2ExecWB (CAObjHandle objectHandle,
                                            ERRORINFO *errorInfo,
                                            enum SHDocVwEnum_OLECMDID cmdID,
                                            enum SHDocVwEnum_OLECMDEXECOPT cmdexecopt,
                                            VARIANT pvaIn, VARIANT *pvaOut);

HRESULT CVIFUNC SHDocVw_IWebBrowser2ShowBrowserBar (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    VARIANT pvaClsid,
                                                    VARIANT pvarShow,
                                                    VARIANT pvarSize);
#ifdef __cplusplus
    }
#endif
#endif /* _IE_H */
