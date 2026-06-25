// PrototypeCompatibility.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"
#include "PrototypeCompatibility.h"

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

// This is an example of an exported variable
PROTOTYPECOMPATIBILITY_API int nPrototypeCompatibility=0;

// This is an example of an exported function.
PROTOTYPECOMPATIBILITY_API int fnPrototypeCompatibility(void)
{
	return 42;
}

// This is the constructor of a class that has been exported.
// see PrototypeCompatibility.h for the class definition
CPrototypeCompatibility::CPrototypeCompatibility()
{ 
	return; 
}

typedef char * StringType;
typedef char BufferType[356];
typedef wchar_t UBufferType[356];

namespace String
{
	void PROTOTYPECOMPATIBILITY_API Char_Ptr(char *ptr) { };
	void PROTOTYPECOMPATIBILITY_API Char_PtrConst(const char *ptr) {};
	void PROTOTYPECOMPATIBILITY_API Char_Array(char array[10]) { };
	void PROTOTYPECOMPATIBILITY_API Char_ArrayConst(const char array[10]) {};


	void PROTOTYPECOMPATIBILITY_API WChar_Ptr(wchar_t *ptr) {};
	void PROTOTYPECOMPATIBILITY_API WChar_PtrConst(const wchar_t *ptr) {};
	void PROTOTYPECOMPATIBILITY_API WChar_Array(wchar_t array[10]) {};
	void PROTOTYPECOMPATIBILITY_API WChar_ArrayConst(const wchar_t array[10]) {};

	void PROTOTYPECOMPATIBILITY_API UString_Ptr(wchar_t * *ptr){ };
	void PROTOTYPECOMPATIBILITY_API UStringConst_Ptr(const wchar_t * *ptr){ };
	void PROTOTYPECOMPATIBILITY_API UString_Array(wchar_t * array[10]){ };
	void PROTOTYPECOMPATIBILITY_API UStringConst_Array(const wchar_t * array[10]){ };
	void PROTOTYPECOMPATIBILITY_API UStringBuffer_Ptr(UBufferType *ptr){ };
	void PROTOTYPECOMPATIBILITY_API UStringBuffer_Array(UBufferType array[10]){ };

	void PROTOTYPECOMPATIBILITY_API String_Array2(char a[10][200]){ };

	void PROTOTYPECOMPATIBILITY_API String_Ptr(char * *ptr){ };
	void PROTOTYPECOMPATIBILITY_API StringConst_Ptr(const char * *ptr){ };
	void PROTOTYPECOMPATIBILITY_API String_Array(char * array[10]){ };
	void PROTOTYPECOMPATIBILITY_API StringConst_Array(const char * array[10]){ };
	void PROTOTYPECOMPATIBILITY_API StringBuffer_Ptr(BufferType *ptr){ };
	void PROTOTYPECOMPATIBILITY_API StringBuffer_Array(BufferType array[10]){ };

};

struct Struct1
{
	char c;
};

struct Struct2
{
	int i;
};

namespace Overloads
{
	void PROTOTYPECOMPATIBILITY_API Function(void) {};
	void PROTOTYPECOMPATIBILITY_API Function(int i) {};
}

namespace Pointers
{
	void PROTOTYPECOMPATIBILITY_API BoolPtr(bool *ptr) {};
	void PROTOTYPECOMPATIBILITY_API BoolArray_1D(bool (&arr)[2]) {};
	void PROTOTYPECOMPATIBILITY_API BoolArray_2D(bool arra[2][3]){};
	void PROTOTYPECOMPATIBILITY_API BoolPtr_Ptr(bool **ptr) {};

	void PROTOTYPECOMPATIBILITY_API IDispatchPtr(IDispatch *ptr) { };
	void PROTOTYPECOMPATIBILITY_API IUnknownPtr(IUnknown *ptr) { };
	void PROTOTYPECOMPATIBILITY_API IDispatchPtrConst(const IDispatch *ptr) { };
	void PROTOTYPECOMPATIBILITY_API IUnknownPtrConst(const IUnknown *ptr) { };
	void PROTOTYPECOMPATIBILITY_API Struct1_Ptr(Struct1 *ptr) {};
	void PROTOTYPECOMPATIBILITY_API Struct1_PtrConst(const Struct1 *ptr) {};
	void PROTOTYPECOMPATIBILITY_API Struct2_Ptr(Struct2 *ptr) {};
	void PROTOTYPECOMPATIBILITY_API Float_Ptr(float *ptr) {};
	void PROTOTYPECOMPATIBILITY_API Double_Ptr(double *ptr) {};
	void PROTOTYPECOMPATIBILITY_API Int_Ptr(int *ptr) {};
	void PROTOTYPECOMPATIBILITY_API Long_Ptr(long *ptr) {};
	void PROTOTYPECOMPATIBILITY_API Short_Ptr(short *ptr) {};
	void PROTOTYPECOMPATIBILITY_API Char_Ptr(char *ptr) {};
	void PROTOTYPECOMPATIBILITY_API UInt_Ptr(unsigned int *ptr) {};
	void PROTOTYPECOMPATIBILITY_API ULong_Ptr(unsigned long *ptr) {};
	void PROTOTYPECOMPATIBILITY_API UShort_Ptr(unsigned short *ptr) {};
	void PROTOTYPECOMPATIBILITY_API UChar_Ptr(unsigned char *ptr) {};
	void PROTOTYPECOMPATIBILITY_API Float_PtrConst(const float *ptr) {};
	void PROTOTYPECOMPATIBILITY_API Double_PtrConst(const double *ptr) {};
	void PROTOTYPECOMPATIBILITY_API Int_PtrConst(const int *ptr) {};
	void PROTOTYPECOMPATIBILITY_API Long_PtrConst(const long *ptr) {};
	void PROTOTYPECOMPATIBILITY_API Short_PtrConst(const short *ptr) {};
	void PROTOTYPECOMPATIBILITY_API Char_PtrConst(const char *ptr) {};

	void PROTOTYPECOMPATIBILITY_API Int_Array1D(int (&array)[2]);

	void PROTOTYPECOMPATIBILITY_API CharArray_2D(char array[2][3]) {};
	void PROTOTYPECOMPATIBILITY_API CharPtrConst_Ptr(const char **ptr) {};
	void PROTOTYPECOMPATIBILITY_API CharPtr_Ptr(char **ptr) {};
	void PROTOTYPECOMPATIBILITY_API CharPtr_PtrConst(char * const * ptr) {};
	void PROTOTYPECOMPATIBILITY_API CharPtrConst_PtrConst(const char * const * ptr) {};

	void PROTOTYPECOMPATIBILITY_API Struct1Ptr_Ptr(Struct1 **ptr) {};
	void PROTOTYPECOMPATIBILITY_API Struct1PtrConst_Ptr(const Struct1 **ptr) {};
	void PROTOTYPECOMPATIBILITY_API Struct1Ptr_ConstPtr(Struct1 * const *ptr) {};
	void PROTOTYPECOMPATIBILITY_API Struct1PtrConst_ConstPtr(const Struct1 * const *ptr) {};
	
	void PROTOTYPECOMPATIBILITY_API IDispatchPtr_Ptr(IDispatch **ptr) { };
	void PROTOTYPECOMPATIBILITY_API IUnknokwnPtr_Ptr(IUnknown **ptr) { };

};



