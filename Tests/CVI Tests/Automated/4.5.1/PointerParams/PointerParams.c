#include <cviauto.h>

#define DECLARE_CLASS(_name, _type)\
__declspec(dllexport) 		void _name ## Value(_type p) {}\
__declspec(dllexport)		void _name ## Pointer1(_type *p) {}\
__declspec(dllexport)		void _name ## Pointer2(_type **p) {}\
__declspec(dllexport)		void _name ## Pointer3(_type ***p) {}\
__declspec(dllexport)		void _name ## Array1(_type a[10]) {}\
__declspec(dllexport)		void _name ## Array2(_type a[10][10]) {}\
__declspec(dllexport)		void _name ## ArrayPtr1(_type *a[10]) {}\
__declspec(dllexport)		void _name ## ArrayPtr2(_type *a[10][10]) {}\
__declspec(dllexport)		_type _name ## ReturnValue() { _type x; return x; }\
__declspec(dllexport)		_type * _name ## ReturnPointer( ) { return 0; } 

struct InternalStruct
{
	int i;
};

DECLARE_CLASS(Int_, int)
DECLARE_CLASS(Char_, char)
DECLARE_CLASS(String_, char *)
DECLARE_CLASS(Dispatch_, IDispatch *)
DECLARE_CLASS(CVIObject_, CAObjHandle)
DECLARE_CLASS(Struct_, struct InternalStruct)
DECLARE_CLASS(Pointer_, void *)

//----------------------------------------------------------
static int mInt = 0x12345;

__declspec(dllexport) void 	Int_GetByPtr(int *ptr) {*ptr =  mInt; }
__declspec(dllexport) int 	Int_Verify(int value) { return value == mInt; }

__declspec(dllexport) void	Int_GetPtr(int **pointer) { *pointer = &mInt; }
__declspec(dllexport) int *	Int_ReturnPtr() { return &mInt; }
__declspec(dllexport) int 	Int_VerifyPtr(int *pointer) { return pointer == &mInt; }

__declspec(dllexport) void 	Int__GetPtr(void **pointer) { *pointer = (void *)&mInt; }
__declspec(dllexport) void *Int__ReturnPtr() { return (void *)&mInt; }
__declspec(dllexport) int 	Int__VerifyPtr(void *pointer) { return pointer == (void *)&mInt; }

//----------------------------------------------------------
static struct InternalStruct mStruct = {34};

__declspec(dllexport) void 	Struct_GetByPtr(struct InternalStruct *ptr) {*ptr =  mStruct; }
__declspec(dllexport) int 	Struct_Verify(struct InternalStruct value) { return value.i == mStruct.i; }

__declspec(dllexport) void	Struct_GetPtr(struct InternalStruct **pointer) { *pointer = &mStruct; }
__declspec(dllexport) struct InternalStruct *	Struct_ReturnPtr() { return &mStruct; }
__declspec(dllexport) int 	Struct_VerifyPtr(struct InternalStruct *pointer) { return pointer == &mStruct; }

__declspec(dllexport) void 	Struct__GetPtr(void **pointer) { *pointer = (void *)&mStruct; }
__declspec(dllexport) void *Struct__ReturnPtr() { return (void *)&mStruct; }
__declspec(dllexport) int 	Struct__VerifyPtr(void *pointer) { return pointer == (void *)&mStruct; }

//----------------------------------------------------------
static char mChar = 0x12;

__declspec(dllexport) void 	Char_GetByPtr(char *ptr) {*ptr =  mChar; }
__declspec(dllexport) int 	Char_Verify(char value) { return value == mChar; }

__declspec(dllexport) void	Char_GetPtr(char **pointer) { *pointer = &mChar; }
__declspec(dllexport) char *	Char_ReturnPtr() { return &mChar; }
__declspec(dllexport) int 	Char_VerifyPtr(char *pointer) { return pointer == &mChar; }

__declspec(dllexport) void 	Char__GetPtr(void **pointer) { *pointer = (void *)&mChar; }
__declspec(dllexport) void *Char__ReturnPtr() { return (void *)&mChar; }
__declspec(dllexport) int 	Char__VerifyPtr(void *pointer) { return pointer == (void *)&mChar; }

//----------------------------------------------------------
static char *mString = "SDF";

__declspec(dllexport) void 	String_GetByPtr(char* *ptr) {*ptr =  mString; }
__declspec(dllexport) int 	String_Verify(void* value) { return value == mString; }

__declspec(dllexport) void	String_GetPtr(char* **pointer) { *pointer = &mString; }
__declspec(dllexport) char* *	String_ReturnPtr() { return &mString; }
__declspec(dllexport) int 	String_VerifyPtr(char* *pointer) { return pointer == &mString; }

__declspec(dllexport) void 	String__GetPtr(void **pointer) { *pointer = (void *)&mString; }
__declspec(dllexport) void *String__ReturnPtr() { return (void *)&mString; }
__declspec(dllexport) int 	String__VerifyPtr(void *pointer) { return pointer == (void *)&mString; }
