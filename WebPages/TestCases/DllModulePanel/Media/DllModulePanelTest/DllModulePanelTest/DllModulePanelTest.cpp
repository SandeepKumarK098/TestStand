// DllModulePanelTest.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"
#include "DllModulePanelTest.h"


#ifdef _MANAGED
#pragma managed(push, off)
#endif

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
    return TRUE;
}

#ifdef _MANAGED
#pragma managed(pop)
#endif

// This is an example of an exported variable
DLLMODULEPANELTEST_API int nDllModulePanelTest=0;

// This is an example of an exported function.
DLLMODULEPANELTEST_API int fnDllModulePanelTest(void)
{
	return 42;
}

// This is the constructor of a class that has been exported.
// see DllModulePanelTest.h for the class definition
CDllModulePanelTest::CDllModulePanelTest()
{
	return;
}


class __declspec(dllexport) Numeric
{
public:
	static void ByValue(char x1, unsigned char x2, short x3, unsigned short x4, long x5, unsigned long x6, float x7, double x8)
	{
	}

	static void ByValue2(char x1, unsigned char x2, short x3, unsigned short x4, long x5, unsigned long x6, float x7, double x8)
	{
	}
	static void ByPtr(char *x1, unsigned char *x2, short *x3, unsigned short *x4, long *x5, unsigned long *x6, float *x7, double *x8)
	{
	}
	static void ByRef(char &x1, unsigned char &x2, short &x3, unsigned short &x4, long &x5, unsigned long &x6, float &x7, double &x8)
	{
	}
	static void ByPtrWithBool(char *x1, unsigned char *x2, short *x3, unsigned short *x4, long *x5, unsigned long *x6, float *x7, double *x8, bool *x9)
	{
	}
};