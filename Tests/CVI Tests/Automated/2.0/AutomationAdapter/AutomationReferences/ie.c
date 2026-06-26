#include "ie.h"

HRESULT CVIFUNC SHDocVw_GetProperty (CAObjHandle objectHandle,
                                     ERRORINFO *errorInfo,
                                     unsigned int propertyID,
                                     unsigned int propertyType, void *value)
{
	HRESULT __result;

	__result = CA_PropertyGet (objectHandle, errorInfo, propertyID,
	                           propertyType, value);

	return __result;
}

HRESULT CVIFUNC SHDocVw_SetProperty (CAObjHandle objectHandle,
                                     ERRORINFO *errorInfo,
                                     unsigned int propertyID,
                                     unsigned int propertyType, ...)
{
	HRESULT __result;
	va_list args;

	va_start (args, propertyType);

	__result = CA_PropertySetV (objectHandle, errorInfo, propertyID,
	                            propertyType, args);

	va_end (args);

	return __result;
}

HRESULT CVIFUNC SHDocVw_NewIWebBrowser2 (char *server, CAObjHandle *objectHandle)
{
	HRESULT __result;
	GUID clsid = {0x2DF01, 0x0, 0x0, 0xC0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x46};

	__result = CA_CreateObjectByClassId (&clsid, server, objectHandle);

	return __result;
}

HRESULT CVIFUNC SHDocVw_OpenIWebBrowser2 (char *fileName, char *server,
                                          CAObjHandle *objectHandle)
{
	HRESULT __result;
	GUID clsid = {0x2DF01, 0x0, 0x0, 0xC0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x46};

	__result = CA_LoadObjectFromFileByClassId (fileName, &clsid, server,
	                                           objectHandle);

	return __result;
}

HRESULT CVIFUNC SHDocVw_ActiveIWebBrowser2 (char *server,
                                            CAObjHandle *objectHandle)
{
	HRESULT __result;
	GUID clsid = {0x2DF01, 0x0, 0x0, 0xC0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x46};

	__result = CA_GetActiveObjectByClassId (&clsid, server, objectHandle);

	return __result;
}

HRESULT CVIFUNC SHDocVw_IWebBrowser2GoBack (CAObjHandle objectHandle,
                                            ERRORINFO *errorInfo)
{
	HRESULT __result;

	__result = CA_MethodInvoke (objectHandle, errorInfo, 0x64, CAVT_EMPTY,
	                            NULL, 0, NULL);

	return __result;
}

HRESULT CVIFUNC SHDocVw_IWebBrowser2GoForward (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo)
{
	HRESULT __result;

	__result = CA_MethodInvoke (objectHandle, errorInfo, 0x65, CAVT_EMPTY,
	                            NULL, 0, NULL);

	return __result;
}

HRESULT CVIFUNC SHDocVw_IWebBrowser2GoHome (CAObjHandle objectHandle,
                                            ERRORINFO *errorInfo)
{
	HRESULT __result;

	__result = CA_MethodInvoke (objectHandle, errorInfo, 0x66, CAVT_EMPTY,
	                            NULL, 0, NULL);

	return __result;
}

HRESULT CVIFUNC SHDocVw_IWebBrowser2GoSearch (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo)
{
	HRESULT __result;

	__result = CA_MethodInvoke (objectHandle, errorInfo, 0x67, CAVT_EMPTY,
	                            NULL, 0, NULL);

	return __result;
}

HRESULT CVIFUNC SHDocVw_IWebBrowser2Navigate (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo, char *URL,
                                              VARIANT flags,
                                              VARIANT targetFrameName,
                                              VARIANT postData, VARIANT headers)
{
	HRESULT __result;
	unsigned int __paramTypes[] = {CAVT_CSTRING, CAVT_VARIANT | CAVT_BYREFI,
	                               CAVT_VARIANT | CAVT_BYREFI,
	                               CAVT_VARIANT | CAVT_BYREFI,
	                               CAVT_VARIANT | CAVT_BYREFI};

	__result = CA_MethodInvoke (objectHandle, errorInfo, 0x68, CAVT_EMPTY,
	                            NULL, 5, __paramTypes, URL, &flags,
	                            &targetFrameName, &postData, &headers);

	return __result;
}

HRESULT CVIFUNC SHDocVw_IWebBrowser2Refresh (CAObjHandle objectHandle,
                                             ERRORINFO *errorInfo)
{
	HRESULT __result;

	__result = CA_MethodInvoke (objectHandle, errorInfo, 0xFFFFFDDA,
	                            CAVT_EMPTY, NULL, 0, NULL);

	return __result;
}

HRESULT CVIFUNC SHDocVw_IWebBrowser2Refresh2 (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              VARIANT level)
{
	HRESULT __result;
	unsigned int __paramTypes[] = {CAVT_VARIANT | CAVT_BYREFI};

	__result = CA_MethodInvoke (objectHandle, errorInfo, 0x69, CAVT_EMPTY,
	                            NULL, 1, __paramTypes, &level);

	return __result;
}

HRESULT CVIFUNC SHDocVw_IWebBrowser2Stop (CAObjHandle objectHandle,
                                          ERRORINFO *errorInfo)
{
	HRESULT __result;

	__result = CA_MethodInvoke (objectHandle, errorInfo, 0x6A, CAVT_EMPTY,
	                            NULL, 0, NULL);

	return __result;
}

HRESULT CVIFUNC SHDocVw_IWebBrowser2Quit (CAObjHandle objectHandle,
                                          ERRORINFO *errorInfo)
{
	HRESULT __result;

	__result = CA_MethodInvoke (objectHandle, errorInfo, 0x12C, CAVT_EMPTY,
	                            NULL, 0, NULL);

	return __result;
}

HRESULT CVIFUNC SHDocVw_IWebBrowser2ClientToWindow (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    long *pcx, long *pcy)
{
	HRESULT __result;
	unsigned int __paramTypes[] = {CAVT_LONG | CAVT_BYREFIO,
	                               CAVT_LONG | CAVT_BYREFIO};

	__result = CA_MethodInvoke (objectHandle, errorInfo, 0x12D, CAVT_EMPTY,
	                            NULL, 2, __paramTypes, pcx, pcy);

	return __result;
}

HRESULT CVIFUNC SHDocVw_IWebBrowser2PutProperty (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 char *property, VARIANT vtValue)
{
	HRESULT __result;
	unsigned int __paramTypes[] = {CAVT_CSTRING, CAVT_VARIANT};

	__result = CA_MethodInvoke (objectHandle, errorInfo, 0x12E, CAVT_EMPTY,
	                            NULL, 2, __paramTypes, property, vtValue);

	return __result;
}

HRESULT CVIFUNC SHDocVw_IWebBrowser2GetProperty (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 char *property,
                                                 VARIANT *returnValue)
{
	HRESULT __result;
	unsigned int __paramTypes[] = {CAVT_CSTRING};

	__result = CA_MethodInvoke (objectHandle, errorInfo, 0x12F, CAVT_VARIANT,
	                            returnValue, 1, __paramTypes, property);

	return __result;
}

HRESULT CVIFUNC SHDocVw_IWebBrowser2Navigate2 (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo, VARIANT URL,
                                               VARIANT flags,
                                               VARIANT targetFrameName,
                                               VARIANT postData, VARIANT headers)
{
	HRESULT __result;
	unsigned int __paramTypes[] = {CAVT_VARIANT | CAVT_BYREFI,
	                               CAVT_VARIANT | CAVT_BYREFI,
	                               CAVT_VARIANT | CAVT_BYREFI,
	                               CAVT_VARIANT | CAVT_BYREFI,
	                               CAVT_VARIANT | CAVT_BYREFI};

	__result = CA_MethodInvoke (objectHandle, errorInfo, 0x1F4, CAVT_EMPTY,
	                            NULL, 5, __paramTypes, &URL, &flags,
	                            &targetFrameName, &postData, &headers);

	return __result;
}

HRESULT CVIFUNC SHDocVw_IWebBrowser2QueryStatusWB (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   enum SHDocVwEnum_OLECMDID cmdID,
                                                   enum SHDocVwEnum_OLECMDF *returnValue)
{
	HRESULT __result;
	unsigned int __paramTypes[] = {CAVT_LONG};

	__result = CA_MethodInvoke (objectHandle, errorInfo, 0x1F5, CAVT_LONG,
	                            returnValue, 1, __paramTypes, cmdID);

	return __result;
}

HRESULT CVIFUNC SHDocVw_IWebBrowser2ExecWB (CAObjHandle objectHandle,
                                            ERRORINFO *errorInfo,
                                            enum SHDocVwEnum_OLECMDID cmdID,
                                            enum SHDocVwEnum_OLECMDEXECOPT cmdexecopt,
                                            VARIANT pvaIn, VARIANT *pvaOut)
{
	HRESULT __result;
	unsigned int __paramTypes[] = {CAVT_LONG, CAVT_LONG,
	                               CAVT_VARIANT | CAVT_BYREFI,
	                               CAVT_VARIANT | CAVT_BYREFIO};

	__result = CA_MethodInvoke (objectHandle, errorInfo, 0x1F6, CAVT_EMPTY,
	                            NULL, 4, __paramTypes, cmdID, cmdexecopt,
	                            &pvaIn, pvaOut);

	return __result;
}

HRESULT CVIFUNC SHDocVw_IWebBrowser2ShowBrowserBar (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    VARIANT pvaClsid,
                                                    VARIANT pvarShow,
                                                    VARIANT pvarSize)
{
	HRESULT __result;
	unsigned int __paramTypes[] = {CAVT_VARIANT | CAVT_BYREFI,
	                               CAVT_VARIANT | CAVT_BYREFI,
	                               CAVT_VARIANT | CAVT_BYREFI};

	__result = CA_MethodInvoke (objectHandle, errorInfo, 0x1F7, CAVT_EMPTY,
	                            NULL, 3, __paramTypes, &pvaClsid, &pvarShow,
	                            &pvarSize);

	return __result;
}
