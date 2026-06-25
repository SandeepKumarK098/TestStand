// CppDll.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "CppDll.h"

#include <stdio.h>
#include <string.h>

CPPDLL_API int SprintfWrapper( char * buffer, unsigned int bufferSize, const char * format, ...)
{
	va_list vl;
	va_start(vl, format);

	return _vsprintf_p(buffer, bufferSize, format, vl);
}

static int foo;

CPPDLL_API void * ReturnPointer()
{
	return &foo;
}

CPPDLL_API bool CheckPointer(void * ptr)
{
	return ptr == &foo;
}

CPPDLL_API unsigned char SumUnt8s(const unsigned char * array, unsigned int size)
{
	unsigned char sum = 0;

	for (unsigned int ii=0; ii < size; ++ii)
	{
		sum += array[ii];
	}

	return sum;
}


CPPDLL_API int SumInt32s(const int * array, unsigned int size)
{
	int sum = 0;

	for (unsigned int ii=0; ii < size; ++ii)
	{
		sum += array[ii];
	}

	return sum;
}

CPPDLL_API double SumDoubles(const double * array, unsigned int size)
{
	double sum = 0;

	for (unsigned int ii=0; ii < size; ++ii)
	{
		sum += array[ii];
	}

	return sum;
}

CPPDLL_API void OutputNumberSizes(char * sbyte, short * word, int * dword, long long * qword, float * real, double * dreal)
{
	*sbyte = sizeof(*sbyte);
	*word = sizeof(*word);
	*dword = sizeof(*dword);
	*qword = sizeof(*qword);
	*real = sizeof(*real);
	*dreal = sizeof(*dreal);
}

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
	Point expectedPoint)
{
	bool expected = (myStruct.byte == expectedByte);
	expected &= (myStruct.float64 == expectedDouble);
	expected &= (myStruct.integer32 == expectedInt32);
	expected &= (myStruct.integer64 == expectedInt64);
	expected &= (strcmp(expectedInString, myStruct.inString) == 0);
	expected &= (strcmp(expectedEmbeddedString, myStruct.embeddedString) == 0);
	expected &= (myStruct.point.x == expectedX);
	expected &= (myStruct.point.y == expectedY);
	expected &= (myStruct.pPoint->x == expectedPoint.x);
	expected &= (myStruct.pPoint->y == expectedPoint.y);

	return expected;
}

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
	Point expectedPoint)
{
	bool expected = (myStruct.byte == expectedByte);
	expected &= (myStruct.float64 == expectedDouble);
	expected &= (myStruct.integer32 == expectedInt32);
	expected &= (myStruct.integer64 == expectedInt64);
	expected &= (strcmp(expectedInString, myStruct.inString) == 0);
	expected &= (strcmp(expectedEmbeddedString, myStruct.embeddedString) == 0);
	expected &= (myStruct.point.x == expectedX);
	expected &= (myStruct.point.y == expectedY);
	expected &= (myStruct.pPoint->x == expectedPoint.x);
	expected &= (myStruct.pPoint->y == expectedPoint.y);

	return expected;
}

CPPDLL_API bool PassStructByPointer(
	const MyStruct * myStruct,
	unsigned char expectedByte,
	double expectedDouble,
	const char * expectedInString,
	const char * expectedEmbeddedString,
	int expectedInt32,
	__int64 expectedInt64,
	float expectedX,
	float expectedY,
	Point expectedPoint)
{
	bool expected = (myStruct->byte == expectedByte);
	expected &= (myStruct->float64 == expectedDouble);
	expected &= (myStruct->integer32 == expectedInt32);
	expected &= (myStruct->integer64 == expectedInt64);
	expected &= (strcmp(expectedInString, myStruct->inString) == 0);
	expected &= (strcmp(expectedEmbeddedString, myStruct->embeddedString) == 0);
	expected &= (myStruct->point.x == expectedX);
	expected &= (myStruct->point.y == expectedY);
	expected &= (myStruct->pPoint->x == expectedPoint.x);
	expected &= (myStruct->pPoint->y == expectedPoint.y);

	return expected;
}

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
	Point newPoint)
{
	myStruct->byte = newByte;
	myStruct->float64 = newDouble;
	myStruct->integer32 = newInt32;
	myStruct->integer64 = newInt64;
	myStruct->point.x = newX;
	myStruct->point.y = newY;
	*(myStruct->pPoint) = newPoint;

	strncpy(myStruct->embeddedString, newEmbeddedString, 16);

	const size_t bufSize = strlen(myStruct->inString);
	strncpy(myStruct->inString, newEmbeddedString, bufSize);
}

CPPDLL_API int __cdecl cdecl_CppFunction(int val) { return val; }
CPPDLL_API int __stdcall stdcall_CppFunction(int val) { return val; }
CPPDLL_API int nocall_CppFunction(int val) { return val; }
CPPDLL_API void * CppPointerFunction(int * ptr) { return ptr; }
CPPDLL_API void * CppReferenceFunction(int & ptr) { return &ptr; }

CPPDLL_API int __cdecl cdecl_CppDecoratedFunction(int val) { return val; }
CPPDLL_API int __stdcall stdcall_CppDecoratedFunction(int val) { return val; }
CPPDLL_API int nocall_CppDecoratedFunction(int val) { return val; }
CPPDLL_API void * CppDecoratedPointerFunction(int * ptr) { return ptr; }
CPPDLL_API void * CppDecoratedReferenceFunction(int & ptr) { return &ptr; }