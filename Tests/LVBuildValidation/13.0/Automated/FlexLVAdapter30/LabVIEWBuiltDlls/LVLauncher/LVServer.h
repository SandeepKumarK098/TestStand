#ifndef _LABVIEW_H
#define _LABVIEW_H

#if defined(INCLUDE_AFTER_WINDOWS_H) && !defined(_INC_WINDOWS)
#error  This header must be included before utility.h and formatio.h
#error  because it includes cviauto.h which includes Windows SDK headers.
#endif /* INCLUDE_AFTER_WINDOWS_H */

#include <cviauto.h>

#ifdef __cplusplus
    extern "C" {
#endif
/* NICDBLD_BEGIN> ActiveX Automation Properties */

/* NICDBLD_BEGIN> Object Name: _Application */
#define LabVIEW_AppAppName                       0x00000000
#define LabVIEW_AppUserName                      0x00000001
#define LabVIEW_AppVersion                       0x00000002
#define LabVIEW_AppAppKind                       0x00000003
#define LabVIEW_AppAppTargetOS                   0x00000004
#define LabVIEW_AppAppTargetCPU                  0x00000005
#define LabVIEW_AppOSName                        0x00000006
#define LabVIEW_AppOSVersion                     0x00000007
#define LabVIEW_AppExportedVIs                   0x00000008
#define LabVIEW_AppPrintSetupFileWrapText        0x00000009
#define LabVIEW_AppPrintSetupPNGCompressLevel    0x0000000A
#define LabVIEW_AppPrintSetupJPEGQuality         0x0000000B
#define LabVIEW_AppPrintSetupCustomConnector     0x0000000C
#define LabVIEW_AppPrintSetupCustomDescription   0x0000000D
#define LabVIEW_AppPrintSetupCustomPanel         0x0000000E
#define LabVIEW_AppPrintSetupCustomPanelBorder   0x0000000F
#define LabVIEW_AppPrintSetupCustomControls      0x00000010
#define LabVIEW_AppPrintSetupCustomControlDesc   0x00000011
#define LabVIEW_AppPrintSetupCustomControlTypes  0x00000012
#define LabVIEW_AppPrintSetupCustomDiagram       0x00000013
#define LabVIEW_AppPrintSetupCustomDiagramHidden 0x00000014
#define LabVIEW_AppPrintSetupCustomDiagramRepeat 0x00000015
#define LabVIEW_AppPrintSetupCustomSubVIs        0x00000016
#define LabVIEW_AppPrintSetupCustomHierarchy     0x00000017
#define LabVIEW_AppPrintSetupCustomHistory       0x00000018
#define LabVIEW_AppApplicationDirectory          0x00000019
#define LabVIEW_AppAllVIsInMemory                0x0000001C
#define LabVIEW_AppAutomaticClose                0x00000023
#define LabVIEW_App_ParentWindowForDialogs       0x00000036
#define LabVIEW_AppShowFPTipStrips               0x0000003F
/* NICDBLD_END> Object Name: _Application */

/* NICDBLD_BEGIN> Object Name: Generic */
#define LabVIEW_GenericClassID   0x06327800
#define LabVIEW_GenericOwner     0x06327801
#define LabVIEW_GenericOwningVI  0x06327802
#define LabVIEW_GenericClassName 0x06327803
/* NICDBLD_END> Object Name: Generic */

/* NICDBLD_BEGIN> Object Name: VirtualInstrument */
#define LabVIEW_VirtualInstrName                        0x000001F4
#define LabVIEW_VirtualInstrPath                        0x000001F5
#define LabVIEW_VirtualInstrDescription                 0x000001F6
#define LabVIEW_VirtualInstrHistoryText                 0x000001F7
#define LabVIEW_VirtualInstrFPTitleBarVisible           0x000001F9
#define LabVIEW_VirtualInstrFPWinClosable               0x000001FA
#define LabVIEW_VirtualInstrFPResizable                 0x000001FB
#define LabVIEW_VirtualInstrFPAllowRTPopup              0x000001FC
#define LabVIEW_VirtualInstrFPHiliteReturnButton        0x000001FD
#define LabVIEW_VirtualInstrFPSizeToScreen              0x000001FE
#define LabVIEW_VirtualInstrFPAutoCenter                0x000001FF
#define LabVIEW_VirtualInstrFPShowScrollBars            0x00000200
#define LabVIEW_VirtualInstrFPShowMenuBar               0x00000201
#define LabVIEW_VirtualInstrTBVisible                   0x00000202
#define LabVIEW_VirtualInstrTBShowRunButton             0x00000203
#define LabVIEW_VirtualInstrTBShowFreeRunButton         0x00000204
#define LabVIEW_VirtualInstrTBShowAbortButton           0x00000205
#define LabVIEW_VirtualInstrAllowDebugging              0x00000206
#define LabVIEW_VirtualInstrFPIsDialog                  0x00000208
#define LabVIEW_VirtualInstrShowFPOnLoad                0x00000209
#define LabVIEW_VirtualInstrShowFPOnCall                0x0000020A
#define LabVIEW_VirtualInstrCloseFPAfterCall            0x0000020B
#define LabVIEW_VirtualInstrRunOnOpen                   0x0000020C
#define LabVIEW_VirtualInstrIsReentrant                 0x0000020D
#define LabVIEW_VirtualInstrExecPriority                0x0000020E
#define LabVIEW_VirtualInstrHistUseDefaults             0x0000020F
#define LabVIEW_VirtualInstrHistAddCommentsAtSave       0x00000210
#define LabVIEW_VirtualInstrHistPromptAtClose           0x00000211
#define LabVIEW_VirtualInstrHistPromptForCommentsAtSave 0x00000212
#define LabVIEW_VirtualInstrHistRecordAppComments       0x00000213
#define LabVIEW_VirtualInstrHelpDocumentTag             0x00000214
#define LabVIEW_VirtualInstrHelpDocumentPath            0x00000215
#define LabVIEW_VirtualInstrFPWinOpen                   0x00000216
#define LabVIEW_VirtualInstrFPWinIsFrontMost            0x00000217
#define LabVIEW_VirtualInstrFPWinBounds                 0x00000218
#define LabVIEW_VirtualInstrVIModificationBitSet        0x00000219
#define LabVIEW_VirtualInstrFPModificationBitSet        0x0000021A
#define LabVIEW_VirtualInstrBDModificationBitSet        0x0000021B
#define LabVIEW_VirtualInstrCodeSize                    0x0000021C
#define LabVIEW_VirtualInstrDataSize                    0x0000021D
#define LabVIEW_VirtualInstrFPSize                      0x0000021E
#define LabVIEW_VirtualInstrBDSize                      0x0000021F
#define LabVIEW_VirtualInstrCallers                     0x00000220
#define LabVIEW_VirtualInstrCallees                     0x00000221
#define LabVIEW_VirtualInstrLogFilePath                 0x00000225
#define LabVIEW_VirtualInstrLogAtFinish                 0x00000226
#define LabVIEW_VirtualInstrPrintLogFileAtFinish        0x00000227
#define LabVIEW_VirtualInstrFPWinOrigin                 0x00000228
#define LabVIEW_VirtualInstrFPWinTitle                  0x00000229
#define LabVIEW_VirtualInstrSuspendOnCall               0x0000022B
#define LabVIEW_VirtualInstrFPWinPanelBounds            0x0000022C
#define LabVIEW_VirtualInstrExecState                   0x0000022D
#define LabVIEW_VirtualInstrEditMode                    0x0000022E
#define LabVIEW_VirtualInstrPreferredExecSystem         0x0000022F
#define LabVIEW_VirtualInstrFPWinCustomTitle            0x00000231
#define LabVIEW_VirtualInstrVIType                      0x00000232
#define LabVIEW_VirtualInstrRevisionNumber              0x00000234
#define LabVIEW_VirtualInstr_ConPaneTD                  0x00000239
#define LabVIEW_VirtualInstrFPKeepWinProps              0x0000023F
#define LabVIEW_VirtualInstrRunTimeMenuPath             0x00000244
/* NICDBLD_END> Object Name: VirtualInstrument */
/* NICDBLD_END> ActiveX Automation Properties */

/* NICDBLD_BEGIN> Type Library Specific Types */
enum LabVIEWEnum_AppKindEnum
{
    LabVIEWConst_eInvalidAppKind = 0,
    LabVIEWConst_eDevSysKind = 1,
    LabVIEWConst_eRunTimeSysKind = 2,
    LabVIEWConst_eStudEdKind = 3,
    LabVIEWConst_eEmbeddedKind = 4,
    _LabVIEW_AppKindEnumForceSizeToFourBytes = 0xFFFFFFFF
};
enum LabVIEWEnum_AppTargOSEnum
{
    LabVIEWConst_eInvalidTargOS = 0,
    LabVIEWConst_eMacOS = 1,
    LabVIEWConst_eWin31OS = 2,
    LabVIEWConst_eWin95NTOS = 3,
    LabVIEWConst_eSolaris1OS = 4,
    LabVIEWConst_eSolaris2OS = 5,
    LabVIEWConst_eHPUXOS = 6,
    LabVIEWConst_ePowerMaxOS = 7,
    LabVIEWConst_eLinuxOS = 8,
    LabVIEWConst_eIrixOS = 9,
    LabVIEWConst_eRhapsodyOS = 10,
    LabVIEWConst_eBeOS = 11,
    LabVIEWConst_eAIXOS = 12,
    LabVIEWConst_eOSF1OS = 13,
    LabVIEWConst_eVxWorksOS = 14,
    LabVIEWConst_ePharlapOS = 15,
    LabVIEWConst_eCarbonOS = 16,
    _LabVIEW_AppTargOSEnumForceSizeToFourBytes = 0xFFFFFFFF
};
enum LabVIEWEnum_AppTargCPUEnum
{
    LabVIEWConst_eInvalidTargCPU = 0,
    LabVIEWConst_eMotorola68kCPU = 1,
    LabVIEWConst_ePowerPCCPU = 2,
    LabVIEWConst_eIntelx86CPU = 3,
    LabVIEWConst_eSPARCCPU = 4,
    LabVIEWConst_ePARISCCPU = 5,
    LabVIEWConst_eMIPSCPU = 6,
    LabVIEWConst_eAlphaCPU = 7,
    _LabVIEW_AppTargCPUEnumForceSizeToFourBytes = 0xFFFFFFFF
};
enum LabVIEWEnum_VIPriorityEnum
{
    LabVIEWConst_ePriInvalid = 0,
    LabVIEWConst_ePriBackground = 1,
    LabVIEWConst_ePriNormal = 2,
    LabVIEWConst_ePriAboveNormal = 3,
    LabVIEWConst_ePriHigh = 4,
    LabVIEWConst_ePriCritical = 5,
    LabVIEWConst_ePriSubroutine = 6,
    _LabVIEW_VIPriorityEnumForceSizeToFourBytes = 0xFFFFFFFF
};
enum LabVIEWEnum_ExecStateEnum
{
    LabVIEWConst_eBad = 0,
    LabVIEWConst_eIdle = 1,
    LabVIEWConst_eRunTopLevel = 2,
    LabVIEWConst_eRunning = 3,
    _LabVIEW_ExecStateEnumForceSizeToFourBytes = 0xFFFFFFFF
};
enum LabVIEWEnum_VIExecSysEnum
{
    LabVIEWConst_eESysInvalid = 0,
    LabVIEWConst_eESysUserInterface = 1,
    LabVIEWConst_eESysNormal = 2,
    LabVIEWConst_eESysInstrIO = 3,
    LabVIEWConst_eESysDAQ = 4,
    LabVIEWConst_eESysOther1 = 5,
    LabVIEWConst_eESysOther2 = 6,
    LabVIEWConst_eESysSameAsCaller = 7,
    _LabVIEW_VIExecSysEnumForceSizeToFourBytes = 0xFFFFFFFF
};
enum LabVIEWEnum_VITypeEnum
{
    LabVIEWConst_eInvalidVIType = 0,
    LabVIEWConst_eStandardVIType = 1,
    LabVIEWConst_eControlVIType = 2,
    LabVIEWConst_eGlobalVIType = 3,
    LabVIEWConst_ePolymorphicVIType = 4,
    LabVIEWConst_eConfigurationVIType = 5,
    _LabVIEW_VITypeEnumForceSizeToFourBytes = 0xFFFFFFFF
};
enum LabVIEWEnum_PrintFormatEnum
{
    LabVIEWConst_eCustom = 0,
    LabVIEWConst_eStandard = 1,
    LabVIEWConst_eUsingPanel = 2,
    LabVIEWConst_eUsingSubVI = 3,
    LabVIEWConst_eComplete = 4,
    _LabVIEW_PrintFormatEnumForceSizeToFourBytes = 0xFFFFFFFF
};
enum LabVIEWEnum_HTMLImageFormatEnum
{
    LabVIEWConst_ePNG = 0,
    LabVIEWConst_eJPEG = 1,
    LabVIEWConst_eGIF = 2,
    _LabVIEW_HTMLImageFormatEnumForceSizeToFourBytes = 0xFFFFFFFF
};
enum LabVIEWEnum_VILockStateEnum
{
    LabVIEWConst_eInvalidLockState = 0,
    LabVIEWConst_eUnlockedState = 1,
    LabVIEWConst_eLockedNoPwdState = 2,
    LabVIEWConst_ePwdProtectedState = 3,
    _LabVIEW_VILockStateEnumForceSizeToFourBytes = 0xFFFFFFFF
};
typedef CAObjHandle LabVIEWObj_VirtualInstr;
typedef CAObjHandle LabVIEWObj_Generic;
/* NICDBLD_END> Type Library Specific Types */

extern const IID LabVIEW_IID_App;
extern const IID LabVIEW_IID_Generic;
extern const IID LabVIEW_IID_VirtualInstr;

HRESULT CVIFUNC LabVIEW_GetProperty (CAObjHandle objectHandle,
                                     ERRORINFO *errorInfo,
                                     unsigned int propertyID,
                                     unsigned int propertyType, void *value);

HRESULT CVIFUNC LabVIEW_SetProperty (CAObjHandle objectHandle,
                                     ERRORINFO *errorInfo,
                                     unsigned int propertyID,
                                     unsigned int propertyType, ...);

HRESULT CVIFUNC LabVIEW_NewApp (const char *server, int supportMultithreading,
                                LCID locale, int reserved,
                                CAObjHandle *objectHandle);

HRESULT CVIFUNC LabVIEW_OpenApp (const char *fileName, const char *server,
                                 int supportMultithreading, LCID locale,
                                 int reserved, CAObjHandle *objectHandle);

HRESULT CVIFUNC LabVIEW_ActiveApp (const char *server, int supportMultithreading,
                                   LCID locale, int reserved,
                                   CAObjHandle *objectHandle);

HRESULT CVIFUNC LabVIEW_AppGetVIReference (CAObjHandle objectHandle,
                                           ERRORINFO *errorInfo,
                                           const char *viPath,
                                           const char *password,
                                           VBOOL resvForCall,
                                           LabVIEWObj_VirtualInstr *returnValue);

HRESULT CVIFUNC LabVIEW_AppMassCompile (CAObjHandle objectHandle,
                                        ERRORINFO *errorInfo,
                                        const char *directory,
                                        const char *logFile, VBOOL appendLog,
                                        long viCacheSize, VBOOL reloadLVSBs);

HRESULT CVIFUNC LabVIEW_AppQuit (CAObjHandle objectHandle, ERRORINFO *errorInfo);

HRESULT CVIFUNC LabVIEW_AppBringToFront (CAObjHandle objectHandle,
                                         ERRORINFO *errorInfo);

HRESULT CVIFUNC LabVIEW_AppDisconnectFromSlave (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo);

HRESULT CVIFUNC LabVIEW_App_CompareTypes (CAObjHandle objectHandle,
                                          ERRORINFO *errorInfo,
                                          VARIANT typeDesc1, VARIANT typeDesc2,
                                          short options, long *returnValue);

HRESULT CVIFUNC LabVIEW_VirtualInstrExportVIStrings (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     const char *stringFile,
                                                     VBOOL interactive,
                                                     const char *logFile,
                                                     VBOOL captions,
                                                     VBOOL diagram);

HRESULT CVIFUNC LabVIEW_VirtualInstrImportVIStrings (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     const char *stringFile,
                                                     VBOOL interactive,
                                                     const char *logFile);

HRESULT CVIFUNC LabVIEW_VirtualInstrSaveInstrument (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    const char *viPath,
                                                    VBOOL saveACopy,
                                                    VBOOL withoutDiagram);

HRESULT CVIFUNC LabVIEW_VirtualInstrAbort (CAObjHandle objectHandle,
                                           ERRORINFO *errorInfo);

HRESULT CVIFUNC LabVIEW_VirtualInstrPrintVIToPrinter (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      enum LabVIEWEnum_PrintFormatEnum format,
                                                      VBOOL scalePanel,
                                                      VBOOL scaleDiagram,
                                                      VBOOL pageHeaders,
                                                      VBOOL pageBreaks,
                                                      VBOOL sectionHeaders);

HRESULT CVIFUNC LabVIEW_VirtualInstrPrintVIToHTML (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   const char *htmlFilePath,
                                                   VBOOL append,
                                                   enum LabVIEWEnum_PrintFormatEnum format,
                                                   enum LabVIEWEnum_HTMLImageFormatEnum imageFormat,
                                                   long imageDepth,
                                                   const char *imageDirectory);

HRESULT CVIFUNC LabVIEW_VirtualInstrPrintVIToRTF (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  const char *rtfFilePath,
                                                  VBOOL append,
                                                  enum LabVIEWEnum_PrintFormatEnum format,
                                                  long imageFormat,
                                                  long imageDepth,
                                                  const char *imageDirectory,
                                                  VBOOL helpFormat);

HRESULT CVIFUNC LabVIEW_VirtualInstrPrintVIToText (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   const char *textFilePath,
                                                   VBOOL append,
                                                   enum LabVIEWEnum_PrintFormatEnum format);

HRESULT CVIFUNC LabVIEW_VirtualInstrMakeCurValueDefault (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo);

HRESULT CVIFUNC LabVIEW_VirtualInstrReinitAllToDefault (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo);

HRESULT CVIFUNC LabVIEW_VirtualInstrGetControlValue (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     const char *controlName,
                                                     VARIANT *returnValue);

HRESULT CVIFUNC LabVIEW_VirtualInstrSetControlValue (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     const char *controlName,
                                                     VARIANT value);

HRESULT CVIFUNC LabVIEW_VirtualInstrCall (CAObjHandle objectHandle,
                                          ERRORINFO *errorInfo,
                                          VARIANT *paramNames,
                                          VARIANT *paramVals);

HRESULT CVIFUNC LabVIEW_VirtualInstrGetPanelImage (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VBOOL visibleOnly,
                                                   long imgDepth, VARIANT *img,
                                                   VARIANT *colors,
                                                   VARIANT *bounds);

HRESULT CVIFUNC LabVIEW_VirtualInstrRun (CAObjHandle objectHandle,
                                         ERRORINFO *errorInfo, VBOOL async);

HRESULT CVIFUNC LabVIEW_VirtualInstrRevert (CAObjHandle objectHandle,
                                            ERRORINFO *errorInfo);

HRESULT CVIFUNC LabVIEW_VirtualInstrPrintPanel (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                VBOOL entirePanel);

HRESULT CVIFUNC LabVIEW_VirtualInstrGetLockState (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  VBOOL *pwdInCache,
                                                  enum LabVIEWEnum_VILockStateEnum *returnValue);

HRESULT CVIFUNC LabVIEW_VirtualInstrSetLockState (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  enum LabVIEWEnum_VILockStateEnum lockState,
                                                  VBOOL interactive,
                                                  const char *password,
                                                  VBOOL putInCache);

HRESULT CVIFUNC LabVIEW_VirtualInstrSaveForPrevious (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     const char *viPath,
                                                     char **warnings);

HRESULT CVIFUNC LabVIEW_VirtualInstrCall2 (CAObjHandle objectHandle,
                                           ERRORINFO *errorInfo,
                                           VARIANT *paramNames,
                                           VARIANT *paramVals, VBOOL openFP,
                                           VBOOL closeFPAfterCall,
                                           VBOOL suspendOnCall,
                                           VBOOL bringAppToFront);

HRESULT CVIFUNC LabVIEW_VirtualInstrSetVIIcon (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               const char *imageFile);

HRESULT CVIFUNC LabVIEW_VirtualInstrSaveRunTimeMenu (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     const char *filePath);

HRESULT CVIFUNC LabVIEW_VirtualInstrPrintPanelToPostScript (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            const char *postScriptFile,
                                                            VBOOL append,
                                                            VBOOL entirePanel);
#ifdef __cplusplus
    }
#endif
#endif /* _LABVIEW_H */
