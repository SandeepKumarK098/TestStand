#include <cvirte.h>    /* Needed if linking in external compiler; harmless otherwise */

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



double __declspec(dllexport) GetNan(void)
{
	static unsigned char  nanArray[] = {0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF};
	
	return *(double *)nanArray;

}
