// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the CPPDLL_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// CPPDLL_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef CPPDLL_EXPORTS
#define CPPDLL_API __declspec(dllexport)
#else
#define CPPDLL_API __declspec(dllimport)
#endif

extern "C" CPPDLL_API int SprintfWrapper( char * buffer, unsigned int bufferSize, const char * format, ...);

CPPDLL_API unsigned int PointerSize(void)
{
	return sizeof(void*);
}

CPPDLL_API void ReturnVoid() {}
CPPDLL_API bool ReturnBool(bool val1, bool val2) { return val1 && !val2; } 
CPPDLL_API int ReturnInt32(int val1, int val2) { return val1 + val2; }
CPPDLL_API long long ReturnInt64(long long val1, long long val2) { return val1 + val2; }
CPPDLL_API float ReturnFloat(float val1, float val2) { return val1 + val2; }
CPPDLL_API double ReturnDouble(double val1, double val2) { return val1 + val2; }
CPPDLL_API void * ReturnPointer();
CPPDLL_API bool CheckPointer(void * ptr);

CPPDLL_API unsigned char SumUnt8s(const unsigned char * array, unsigned int size);
CPPDLL_API int SumInt32s(const int * array, unsigned int size);
CPPDLL_API double SumDoubles(const double * array, unsigned int size);


CPPDLL_API void OutputNumberSizes(char * sbyte, short * word, int * dword, long long * qword, float * real, double * dreal);


CPPDLL_API void ThrowException() { throw 1234; }

struct Point
{
	float x;
	float y;
};

struct MyStruct
{
	unsigned char byte;
	double float64;
	char * inString;
	char embeddedString[16];
	int integer32;
	__int64 integer64;
	Point point;
	Point * pPoint;
};

CPPDLL_API bool PassStructByValue(
	MyStruct myStruct,
	unsigned char expectedByte,
	double expectedDouble,
	const char * expectedInString,
	const char * expectedEmbeddedString,
	int expectedInt32,
	__int64 expectedInt64,
	float expectedX,
	float expectedY,
	Point expectedPoint);

CPPDLL_API bool PassStructByReference(
	const MyStruct & myStruct,
	unsigned char expectedByte,
	double expectedDouble,
	const char * expectedInString,
	const char * expectedEmbeddedString,
	int expectedInt32,
	__int64 expectedInt64,
	float expectedX,
	float expectedY,
	Point expectedPoint);

CPPDLL_API bool PassStructByPointer(
	MyStruct * myStruct,
	unsigned char expectedByte,
	double expectedDouble,
	const char * expectedInString,
	const char * expectedEmbeddedString,
	int expectedInt32,
	__int64 expectedInt64,
	float expectedX,
	float expectedY,
	Point expectedPoint);

CPPDLL_API void FillStructByPointer(
	MyStruct * myStruct,
	unsigned char newByte,
	double newDouble,
	const char * newInString,
	const char * newEmbeddedString,
	int newInt32,
	__int64 newInt64,
	float newX,
	float newY,
	Point newPoint);

extern "C"
{
	CPPDLL_API int __cdecl cdecl_CppFunction(int);
	CPPDLL_API int __stdcall stdcall_CppFunction(int);
	CPPDLL_API int nocall_CppFunction(int);
	CPPDLL_API void * CppPointerFunction(int * ptr);
	CPPDLL_API void * CppReferenceFunction(int & ptr);
}

CPPDLL_API int __cdecl cdecl_CppDecoratedFunction(int);
CPPDLL_API int __stdcall stdcall_CppDecoratedFunction(int);
CPPDLL_API int nocall_CppDecoratedFunction(int);
CPPDLL_API void * CppDecoratedPointerFunction(int * ptr);
CPPDLL_API void * CppDecoratedReferenceFunction(int & ptr);