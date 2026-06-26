#include "LVServer.h"

const IID LabVIEW_IID_App =
    {
        0x9A872072, 0xA06, 0x11D1, 0x90, 0xB7, 0x0, 0xA0, 0x24, 0xCE, 0x27, 0x44
    };

const IID LabVIEW_IID_Generic =
    {
        0x18C9E, 0xA06, 0x11D1, 0x90, 0xB7, 0x0, 0xA0, 0x24, 0xCE, 0x27, 0x44
    };

const IID LabVIEW_IID_VirtualInstr =
    {
        0x9A872074, 0xA06, 0x11D1, 0x90, 0xB7, 0x0, 0xA0, 0x24, 0xCE, 0x27, 0x44
    };

HRESULT CVIFUNC LabVIEW_GetProperty (CAObjHandle objectHandle,
                                     ERRORINFO *errorInfo,
                                     unsigned int propertyID,
                                     unsigned int propertyType, void *value)
{
    HRESULT __result;

    __result = CA_PropertyGetEx (objectHandle, errorInfo, 0, propertyID,
                                 propertyType, value);

    return __result;
}

HRESULT CVIFUNC LabVIEW_SetProperty (CAObjHandle objectHandle,
                                     ERRORINFO *errorInfo,
                                     unsigned int propertyID,
                                     unsigned int propertyType, ...)
{
    HRESULT __result;
    va_list args;

    va_start (args, propertyType);

    __result = CA_PropertySetVEx (objectHandle, errorInfo, 0, propertyID,
                                  propertyType, args);

    va_end (args);

    return __result;
}

HRESULT CVIFUNC LabVIEW_NewApp (const char *server, int supportMultithreading,
                                LCID locale, int reserved,
                                CAObjHandle *objectHandle)
{
    HRESULT __result;
    GUID clsid = {0x9A872070, 0xA06, 0x11D1, 0x90, 0xB7, 0x0, 0xA0, 0x24, 0xCE,
                  0x27, 0x44};

    __result = CA_CreateObjectByClassIdEx (&clsid, server, &LabVIEW_IID_App,
                                           supportMultithreading, locale,
                                           reserved, objectHandle);

    return __result;
}

HRESULT CVIFUNC LabVIEW_OpenApp (const char *fileName, const char *server,
                                 int supportMultithreading, LCID locale,
                                 int reserved, CAObjHandle *objectHandle)
{
    HRESULT __result;
    GUID clsid = {0x9A872070, 0xA06, 0x11D1, 0x90, 0xB7, 0x0, 0xA0, 0x24, 0xCE,
                  0x27, 0x44};

    __result = CA_LoadObjectFromFileByClassIdEx (fileName, &clsid, server,
                                                 &LabVIEW_IID_App,
                                                 supportMultithreading, locale,
                                                 reserved, objectHandle);

    return __result;
}

HRESULT CVIFUNC LabVIEW_ActiveApp (const char *server, int supportMultithreading,
                                   LCID locale, int reserved,
                                   CAObjHandle *objectHandle)
{
    HRESULT __result;
    GUID clsid = {0x9A872070, 0xA06, 0x11D1, 0x90, 0xB7, 0x0, 0xA0, 0x24, 0xCE,
                  0x27, 0x44};

    __result = CA_GetActiveObjectByClassIdEx (&clsid, server, &LabVIEW_IID_App,
                                              supportMultithreading, locale,
                                              reserved, objectHandle);

    return __result;
}

HRESULT CVIFUNC LabVIEW_AppGetVIReference (CAObjHandle objectHandle,
                                           ERRORINFO *errorInfo,
                                           const char *viPath,
                                           const char *password,
                                           VBOOL resvForCall,
                                           LabVIEWObj_VirtualInstr *returnValue)
{
    HRESULT __result;
    unsigned int __paramTypes[] = {CAVT_CSTRING, CAVT_CSTRING, CAVT_BOOL};

    __result = CA_MethodInvokeEx (objectHandle, errorInfo, &LabVIEW_IID_App,
                                  0x7D4, CAVT_OBJHANDLE, returnValue, 3,
                                  __paramTypes, viPath, password, resvForCall);

    return __result;
}

HRESULT CVIFUNC LabVIEW_AppMassCompile (CAObjHandle objectHandle,
                                        ERRORINFO *errorInfo,
                                        const char *directory,
                                        const char *logFile, VBOOL appendLog,
                                        long viCacheSize, VBOOL reloadLVSBs)
{
    HRESULT __result;
    unsigned int __paramTypes[] = {CAVT_CSTRING, CAVT_CSTRING, CAVT_BOOL,
                                   CAVT_LONG, CAVT_BOOL};

    __result = CA_MethodInvokeEx (objectHandle, errorInfo, &LabVIEW_IID_App,
                                  0x7D5, CAVT_EMPTY, NULL, 5, __paramTypes,
                                  directory, logFile, appendLog, viCacheSize,
                                  reloadLVSBs);

    return __result;
}

HRESULT CVIFUNC LabVIEW_AppQuit (CAObjHandle objectHandle, ERRORINFO *errorInfo)
{
    HRESULT __result;

    __result = CA_MethodInvokeEx (objectHandle, errorInfo, &LabVIEW_IID_App,
                                  0x7DD, CAVT_EMPTY, NULL, 0, NULL);

    return __result;
}

HRESULT CVIFUNC LabVIEW_AppBringToFront (CAObjHandle objectHandle,
                                         ERRORINFO *errorInfo)
{
    HRESULT __result;

    __result = CA_MethodInvokeEx (objectHandle, errorInfo, &LabVIEW_IID_App,
                                  0x7DE, CAVT_EMPTY, NULL, 0, NULL);

    return __result;
}

HRESULT CVIFUNC LabVIEW_AppDisconnectFromSlave (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo)
{
    HRESULT __result;

    __result = CA_MethodInvokeEx (objectHandle, errorInfo, &LabVIEW_IID_App,
                                  0x7E3, CAVT_EMPTY, NULL, 0, NULL);

    return __result;
}

HRESULT CVIFUNC LabVIEW_App_CompareTypes (CAObjHandle objectHandle,
                                          ERRORINFO *errorInfo,
                                          VARIANT typeDesc1, VARIANT typeDesc2,
                                          short options, long *returnValue)
{
    HRESULT __result;
    unsigned int __paramTypes[] = {CAVT_VARIANT, CAVT_VARIANT, CAVT_SHORT};

    __result = CA_MethodInvokeEx (objectHandle, errorInfo, &LabVIEW_IID_App,
                                  0x7EC, CAVT_LONG, returnValue, 3,
                                  __paramTypes, typeDesc1, typeDesc2, options);

    return __result;
}

HRESULT CVIFUNC LabVIEW_VirtualInstrExportVIStrings (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     const char *stringFile,
                                                     VBOOL interactive,
                                                     const char *logFile,
                                                     VBOOL captions,
                                                     VBOOL diagram)
{
    HRESULT __result;
    unsigned int __paramTypes[] = {CAVT_CSTRING, CAVT_BOOL, CAVT_CSTRING,
                                   CAVT_BOOL, CAVT_BOOL};

    __result = CA_MethodInvokeEx (objectHandle, errorInfo,
                                  &LabVIEW_IID_VirtualInstr, 0x3E8, CAVT_EMPTY,
                                  NULL, 5, __paramTypes, stringFile,
                                  interactive, logFile, captions, diagram);

    return __result;
}

HRESULT CVIFUNC LabVIEW_VirtualInstrImportVIStrings (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     const char *stringFile,
                                                     VBOOL interactive,
                                                     const char *logFile)
{
    HRESULT __result;
    unsigned int __paramTypes[] = {CAVT_CSTRING, CAVT_BOOL, CAVT_CSTRING};

    __result = CA_MethodInvokeEx (objectHandle, errorInfo,
                                  &LabVIEW_IID_VirtualInstr, 0x3E9, CAVT_EMPTY,
                                  NULL, 3, __paramTypes, stringFile,
                                  interactive, logFile);

    return __result;
}

HRESULT CVIFUNC LabVIEW_VirtualInstrSaveInstrument (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    const char *viPath,
                                                    VBOOL saveACopy,
                                                    VBOOL withoutDiagram)
{
    HRESULT __result;
    unsigned int __paramTypes[] = {CAVT_CSTRING, CAVT_BOOL, CAVT_BOOL};

    __result = CA_MethodInvokeEx (objectHandle, errorInfo,
                                  &LabVIEW_IID_VirtualInstr, 0x3EA, CAVT_EMPTY,
                                  NULL, 3, __paramTypes, viPath, saveACopy,
                                  withoutDiagram);

    return __result;
}

HRESULT CVIFUNC LabVIEW_VirtualInstrAbort (CAObjHandle objectHandle,
                                           ERRORINFO *errorInfo)
{
    HRESULT __result;

    __result = CA_MethodInvokeEx (objectHandle, errorInfo,
                                  &LabVIEW_IID_VirtualInstr, 0x3EC, CAVT_EMPTY,
                                  NULL, 0, NULL);

    return __result;
}

HRESULT CVIFUNC LabVIEW_VirtualInstrPrintVIToPrinter (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      enum LabVIEWEnum_PrintFormatEnum format,
                                                      VBOOL scalePanel,
                                                      VBOOL scaleDiagram,
                                                      VBOOL pageHeaders,
                                                      VBOOL pageBreaks,
                                                      VBOOL sectionHeaders)
{
    HRESULT __result;
    unsigned int __paramTypes[] = {CAVT_LONG, CAVT_BOOL, CAVT_BOOL, CAVT_BOOL,
                                   CAVT_BOOL, CAVT_BOOL};

    __result = CA_MethodInvokeEx (objectHandle, errorInfo,
                                  &LabVIEW_IID_VirtualInstr, 0x3ED, CAVT_EMPTY,
                                  NULL, 6, __paramTypes, format, scalePanel,
                                  scaleDiagram, pageHeaders, pageBreaks,
                                  sectionHeaders);

    return __result;
}

HRESULT CVIFUNC LabVIEW_VirtualInstrPrintVIToHTML (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   const char *htmlFilePath,
                                                   VBOOL append,
                                                   enum LabVIEWEnum_PrintFormatEnum format,
                                                   enum LabVIEWEnum_HTMLImageFormatEnum imageFormat,
                                                   long imageDepth,
                                                   const char *imageDirectory)
{
    HRESULT __result;
    unsigned int __paramTypes[] = {CAVT_CSTRING, CAVT_BOOL, CAVT_LONG,
                                   CAVT_LONG, CAVT_LONG, CAVT_CSTRING};

    __result = CA_MethodInvokeEx (objectHandle, errorInfo,
                                  &LabVIEW_IID_VirtualInstr, 0x3EE, CAVT_EMPTY,
                                  NULL, 6, __paramTypes, htmlFilePath, append,
                                  format, imageFormat, imageDepth,
                                  imageDirectory);

    return __result;
}

HRESULT CVIFUNC LabVIEW_VirtualInstrPrintVIToRTF (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  const char *rtfFilePath,
                                                  VBOOL append,
                                                  enum LabVIEWEnum_PrintFormatEnum format,
                                                  long imageFormat,
                                                  long imageDepth,
                                                  const char *imageDirectory,
                                                  VBOOL helpFormat)
{
    HRESULT __result;
    unsigned int __paramTypes[] = {CAVT_CSTRING, CAVT_BOOL, CAVT_LONG,
                                   CAVT_LONG, CAVT_LONG, CAVT_CSTRING,
                                   CAVT_BOOL};

    __result = CA_MethodInvokeEx (objectHandle, errorInfo,
                                  &LabVIEW_IID_VirtualInstr, 0x3EF, CAVT_EMPTY,
                                  NULL, 7, __paramTypes, rtfFilePath, append,
                                  format, imageFormat, imageDepth,
                                  imageDirectory, helpFormat);

    return __result;
}

HRESULT CVIFUNC LabVIEW_VirtualInstrPrintVIToText (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   const char *textFilePath,
                                                   VBOOL append,
                                                   enum LabVIEWEnum_PrintFormatEnum format)
{
    HRESULT __result;
    unsigned int __paramTypes[] = {CAVT_CSTRING, CAVT_BOOL, CAVT_LONG};

    __result = CA_MethodInvokeEx (objectHandle, errorInfo,
                                  &LabVIEW_IID_VirtualInstr, 0x3F0, CAVT_EMPTY,
                                  NULL, 3, __paramTypes, textFilePath, append,
                                  format);

    return __result;
}

HRESULT CVIFUNC LabVIEW_VirtualInstrMakeCurValueDefault (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo)
{
    HRESULT __result;

    __result = CA_MethodInvokeEx (objectHandle, errorInfo,
                                  &LabVIEW_IID_VirtualInstr, 0x3F3, CAVT_EMPTY,
                                  NULL, 0, NULL);

    return __result;
}

HRESULT CVIFUNC LabVIEW_VirtualInstrReinitAllToDefault (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo)
{
    HRESULT __result;

    __result = CA_MethodInvokeEx (objectHandle, errorInfo,
                                  &LabVIEW_IID_VirtualInstr, 0x3F4, CAVT_EMPTY,
                                  NULL, 0, NULL);

    return __result;
}

HRESULT CVIFUNC LabVIEW_VirtualInstrGetControlValue (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     const char *controlName,
                                                     VARIANT *returnValue)
{
    HRESULT __result;
    unsigned int __paramTypes[] = {CAVT_CSTRING};

    __result = CA_MethodInvokeEx (objectHandle, errorInfo,
                                  &LabVIEW_IID_VirtualInstr, 0x3F5,
                                  CAVT_VARIANT, returnValue, 1, __paramTypes,
                                  controlName);

    return __result;
}

HRESULT CVIFUNC LabVIEW_VirtualInstrSetControlValue (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     const char *controlName,
                                                     VARIANT value)
{
    HRESULT __result;
    unsigned int __paramTypes[] = {CAVT_CSTRING, CAVT_VARIANT};

    __result = CA_MethodInvokeEx (objectHandle, errorInfo,
                                  &LabVIEW_IID_VirtualInstr, 0x3F6, CAVT_EMPTY,
                                  NULL, 2, __paramTypes, controlName, value);

    return __result;
}

HRESULT CVIFUNC LabVIEW_VirtualInstrCall (CAObjHandle objectHandle,
                                          ERRORINFO *errorInfo,
                                          VARIANT *paramNames,
                                          VARIANT *paramVals)
{
    HRESULT __result;
    unsigned int __paramTypes[] = {CAVT_VARIANT | CAVT_BYREFIO,
                                   CAVT_VARIANT | CAVT_BYREFIO};

    __result = CA_MethodInvokeEx (objectHandle, errorInfo,
                                  &LabVIEW_IID_VirtualInstr, 0x3F7, CAVT_EMPTY,
                                  NULL, 2, __paramTypes, paramNames, paramVals);

    return __result;
}

HRESULT CVIFUNC LabVIEW_VirtualInstrGetPanelImage (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VBOOL visibleOnly,
                                                   long imgDepth, VARIANT *img,
                                                   VARIANT *colors,
                                                   VARIANT *bounds)
{
    HRESULT __result;
    unsigned int __paramTypes[] = {CAVT_BOOL, CAVT_LONG,
                                   CAVT_VARIANT | CAVT_BYREFO,
                                   CAVT_VARIANT | CAVT_BYREFO,
                                   CAVT_VARIANT | CAVT_BYREFO};

    __result = CA_MethodInvokeEx (objectHandle, errorInfo,
                                  &LabVIEW_IID_VirtualInstr, 0x3F8, CAVT_EMPTY,
                                  NULL, 5, __paramTypes, visibleOnly, imgDepth,
                                  img, colors, bounds);

    return __result;
}

HRESULT CVIFUNC LabVIEW_VirtualInstrRun (CAObjHandle objectHandle,
                                         ERRORINFO *errorInfo, VBOOL async)
{
    HRESULT __result;
    unsigned int __paramTypes[] = {CAVT_BOOL};

    __result = CA_MethodInvokeEx (objectHandle, errorInfo,
                                  &LabVIEW_IID_VirtualInstr, 0x3F9, CAVT_EMPTY,
                                  NULL, 1, __paramTypes, async);

    return __result;
}

HRESULT CVIFUNC LabVIEW_VirtualInstrRevert (CAObjHandle objectHandle,
                                            ERRORINFO *errorInfo)
{
    HRESULT __result;

    __result = CA_MethodInvokeEx (objectHandle, errorInfo,
                                  &LabVIEW_IID_VirtualInstr, 0x3FA, CAVT_EMPTY,
                                  NULL, 0, NULL);

    return __result;
}

HRESULT CVIFUNC LabVIEW_VirtualInstrPrintPanel (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                VBOOL entirePanel)
{
    HRESULT __result;
    unsigned int __paramTypes[] = {CAVT_BOOL};

    __result = CA_MethodInvokeEx (objectHandle, errorInfo,
                                  &LabVIEW_IID_VirtualInstr, 0x3FB, CAVT_EMPTY,
                                  NULL, 1, __paramTypes, entirePanel);

    return __result;
}

HRESULT CVIFUNC LabVIEW_VirtualInstrGetLockState (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  VBOOL *pwdInCache,
                                                  enum LabVIEWEnum_VILockStateEnum *returnValue)
{
    HRESULT __result;
    unsigned int __paramTypes[] = {CAVT_BOOL | CAVT_BYREFO};

    __result = CA_MethodInvokeEx (objectHandle, errorInfo,
                                  &LabVIEW_IID_VirtualInstr, 0x3FD, CAVT_LONG,
                                  returnValue, 1, __paramTypes, pwdInCache);

    return __result;
}

HRESULT CVIFUNC LabVIEW_VirtualInstrSetLockState (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  enum LabVIEWEnum_VILockStateEnum lockState,
                                                  VBOOL interactive,
                                                  const char *password,
                                                  VBOOL putInCache)
{
    HRESULT __result;
    unsigned int __paramTypes[] = {CAVT_LONG, CAVT_BOOL, CAVT_CSTRING,
                                   CAVT_BOOL};

    __result = CA_MethodInvokeEx (objectHandle, errorInfo,
                                  &LabVIEW_IID_VirtualInstr, 0x3FE, CAVT_EMPTY,
                                  NULL, 4, __paramTypes, lockState,
                                  interactive, password, putInCache);

    return __result;
}

HRESULT CVIFUNC LabVIEW_VirtualInstrSaveForPrevious (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     const char *viPath,
                                                     char **warnings)
{
    HRESULT __result;
    unsigned int __paramTypes[] = {CAVT_CSTRING, CAVT_CSTRING | CAVT_BYREFO};

    __result = CA_MethodInvokeEx (objectHandle, errorInfo,
                                  &LabVIEW_IID_VirtualInstr, 0x400, CAVT_EMPTY,
                                  NULL, 2, __paramTypes, viPath, warnings);

    return __result;
}

HRESULT CVIFUNC LabVIEW_VirtualInstrCall2 (CAObjHandle objectHandle,
                                           ERRORINFO *errorInfo,
                                           VARIANT *paramNames,
                                           VARIANT *paramVals, VBOOL openFP,
                                           VBOOL closeFPAfterCall,
                                           VBOOL suspendOnCall,
                                           VBOOL bringAppToFront)
{
    HRESULT __result;
    unsigned int __paramTypes[] = {CAVT_VARIANT | CAVT_BYREFIO,
                                   CAVT_VARIANT | CAVT_BYREFIO, CAVT_BOOL,
                                   CAVT_BOOL, CAVT_BOOL, CAVT_BOOL};

    __result = CA_MethodInvokeEx (objectHandle, errorInfo,
                                  &LabVIEW_IID_VirtualInstr, 0x406, CAVT_EMPTY,
                                  NULL, 6, __paramTypes, paramNames, paramVals,
                                  openFP, closeFPAfterCall, suspendOnCall,
                                  bringAppToFront);

    return __result;
}

HRESULT CVIFUNC LabVIEW_VirtualInstrSetVIIcon (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               const char *imageFile)
{
    HRESULT __result;
    unsigned int __paramTypes[] = {CAVT_CSTRING};

    __result = CA_MethodInvokeEx (objectHandle, errorInfo,
                                  &LabVIEW_IID_VirtualInstr, 0x407, CAVT_EMPTY,
                                  NULL, 1, __paramTypes, imageFile);

    return __result;
}

HRESULT CVIFUNC LabVIEW_VirtualInstrSaveRunTimeMenu (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     const char *filePath)
{
    HRESULT __result;
    unsigned int __paramTypes[] = {CAVT_CSTRING};

    __result = CA_MethodInvokeEx (objectHandle, errorInfo,
                                  &LabVIEW_IID_VirtualInstr, 0x413, CAVT_EMPTY,
                                  NULL, 1, __paramTypes, filePath);

    return __result;
}

HRESULT CVIFUNC LabVIEW_VirtualInstrPrintPanelToPostScript (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            const char *postScriptFile,
                                                            VBOOL append,
                                                            VBOOL entirePanel)
{
    HRESULT __result;
    unsigned int __paramTypes[] = {CAVT_CSTRING, CAVT_BOOL, CAVT_BOOL};

    __result = CA_MethodInvokeEx (objectHandle, errorInfo,
                                  &LabVIEW_IID_VirtualInstr, 0x415, CAVT_EMPTY,
                                  NULL, 3, __paramTypes, postScriptFile,
                                  append, entirePanel);

    return __result;
}
