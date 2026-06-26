// VS2005.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"
#include "stdafx.h"
#import "teapi.dll"     // VC++ generates an implicit header file: teapi.tlh.
using namespace TS;


#ifdef _MANAGED
#pragma managed(push, off)
#endif

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
    return TRUE;
}

#ifdef _MANAGED
#pragma managed(pop)
#endif


__declspec(dllexport) void ExistingMethod(TS::SequenceContext * seqContext, bool & errorOccurred, int & errorCode)
{
	try 
	{
		// INSERT YOUR SPECIFIC TEST CODE HERE

		// The following code shows how to access properties and variables via the TestStand API
		// _bstr_t lastUserName = seqContext->AsPropertyObject()->GetValString("StationGlobals.TS.LastUserName", 0);

	}
	catch (_com_error &com_error)   // The TestStand API only throws this kind of exception 
	{
		errorOccurred = true;
		errorCode = (short)HRESULT_CODE(com_error.Error());
	}
}
