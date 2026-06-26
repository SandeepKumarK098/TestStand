static int mInt = 0x12345;


__declspec(dllexport) void 	Int__GetPtr(void **pointer) { *pointer = (void *)&mInt; }
__declspec(dllexport) void *Int__ReturnPtr() { return (void *)&mInt; }
__declspec(dllexport) int 	Int__VerifyPtr(void *pointer) { return pointer == (void *)&mInt; }
__declspec(dllexport) void  Int__Array(int a[10]) {}
__declspec(dllexport) void  Int__PointerPointer(void **pointer) {} 
