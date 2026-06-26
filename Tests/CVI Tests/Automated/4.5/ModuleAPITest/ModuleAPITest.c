#include <cviauto.h>
#include "tsapicvi.h"
#include <utility.h>

int __declspec(dllexport) CVITestFun(int intIn, double doubleIn, const char *stringIn, CAObjHandle objectIn,
	int *intOut, double *doubleOut, char stringOut[], CAObjHandle *objectOut)
{
	*intOut = intIn;
	*doubleOut = doubleIn;
	strcpy(stringOut, stringIn);
	CA_DuplicateObjHandle(objectIn, NULL, objectOut);
	
	return intIn;
}

static int gLockHandle;

void __declspec(dllexport) CreateLock()
{
	CmtNewLock (NULL, 0, &gLockHandle);
}

void __declspec(dllexport) DestroyLock()
{
	CmtDiscardLock (gLockHandle);
}

void __declspec(dllexport) CVIConcurrencyTest(int threadId, CAObjHandle outputArray)
{
	int i;
	for (i = 0; i < 50; i++)
	{
		ERRORINFO errorInfo;
		int numElements;
		CmtGetLock(gLockHandle);
		
		TS_PropertyGetNumElements(outputArray, &errorInfo, &numElements);
		TS_PropertySetNumElements(outputArray, &errorInfo, numElements + 1, 0);
		TS_PropertySetValNumberByOffset (outputArray, &errorInfo, numElements, 0,
                                 threadId);
		
		CmtReleaseLock(gLockHandle);
		
		Sleep(10);
	}
	
}

