// ThreadDll.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"
#include <stdio.h>
#include "ThreadDll.h"
BOOL APIENTRY DllMain( HANDLE hModule, 
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

// This is an example of an exported function.
THREADDLL_API unsigned long GetThreadId(void)
{
	return GetCurrentThreadId();
}

inline DWORD_PTR GetCurrentProcessAffinityMask() {
	DWORD_PTR processAffinityMask = 0;
	DWORD_PTR systemAffinityMask = 0;

	::GetProcessAffinityMask(GetCurrentProcess(), &processAffinityMask, &systemAffinityMask);

	return processAffinityMask;
}

THREADDLL_API  DWORD_PTR GetCurThreadAffinityMask()
{
	// Unfortunately, there is no GetThreadAffinityMask(), but SetThreadAffinityMask() returns the old thread affinty,
	// so we have to use SetThreadAffinityMask to get a thread's affinity.
	// Note that no lock is needed since this always returns the mask for the current thread.

	DWORD_PTR processAffinity = GetCurrentProcessAffinityMask();
	HANDLE hThread = GetCurrentThread();

	DWORD_PTR threadAffinity = SetThreadAffinityMask(hThread, processAffinity);

	if (threadAffinity != processAffinity)
		SetThreadAffinityMask(hThread, threadAffinity);

	return threadAffinity;
}

THREADDLL_API void DisplayMessageBox(unsigned long idNumber)
{
	char title[100];
	DWORD threadId = GetCurrentThreadId ();
	sprintf_s (title, "Message box %d - Thread Id(%d)                         ", idNumber, threadId);
	MessageBoxA (NULL,"Click on the button to continue", title, MB_OK);
	return;
}