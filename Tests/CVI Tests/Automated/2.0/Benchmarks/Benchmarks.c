#include "stdtst.h" 

void __declspec(dllexport) __stdcall DLLFlexAdapterTest()
{
}

void TX_TEST DLLEXPORT CVIStandardPrototypeTest(tTestData * data, tTestError * error)
{
}

int __declspec(dllexport) __stdcall DLLFlexAdapterTestParams(int *numeric, int * errorOccurred, char * errMsg)
{
return 0;
}
