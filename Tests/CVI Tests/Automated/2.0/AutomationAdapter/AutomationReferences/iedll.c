#include "tsapicvi.h"
#include <cvirte.h>    /* Needed if linking in external compiler; harmless otherwise */
#include "iedll.h"

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

void __stdcall Navigate(CAObjHandle objHandle, char *urlStr)
{
	VARIANT variant;
	ERRORINFO errorInfo;
	int ready = SHDocVwConst_READYSTATE_UNINITIALIZED;
	int i = 0;
	
	CA_VariantSetCString (&variant, urlStr);
	SHDocVw_IWebBrowser2Navigate2 (objHandle, &errorInfo, variant,
								   CA_DEFAULT_VAL, CA_DEFAULT_VAL,
								   CA_DEFAULT_VAL, CA_DEFAULT_VAL);
	CA_VariantClear (&variant);
	
	while ((ready != SHDocVwConst_READYSTATE_COMPLETE) && (i < 1000))
	{
		SHDocVw_GetProperty (objHandle, &errorInfo,
							 SHDocVw_IWebBrowser2ReadyState, CAVT_LONG, (void *)&ready);
		i++;
	}
	
}

void  __stdcall Navigate2(CAObjHandle seqContext, char *urlStr)
{
	CAObjHandle objHandle;
	ERRORINFO errorInfo;
	HRESULT hr;
	
	hr = TS_PropertyGetValIDispatch (seqContext, &errorInfo, "Parameters.ref",
									 0, &objHandle);
	if (hr < 0)
		CA_DisplayErrorInfo (seqContext, NULL, hr, &errorInfo);
	else
		Navigate(objHandle, urlStr);

	CA_DiscardObjHandle(objHandle);

	SHDocVw_NewIWebBrowser2 (NULL, &objHandle);
	SHDocVw_SetProperty (objHandle, &errorInfo,
						 SHDocVw_IWebBrowser2Visible, CAVT_BOOL, VTRUE);
	
	TS_PropertySetValIDispatch(seqContext, &errorInfo,
	                           "Locals.tempRef", 0, objHandle);
	CA_DiscardObjHandle(objHandle);

}
