//==============================================================================
//
// Title:		CviDll.c
// Purpose:		A short description of the implementation.
//
// Created on:	6/24/2013 at 4:40:04 PM by Jed Beach.
// Copyright:	ni. All Rights Reserved.
//
//==============================================================================

//==============================================================================
// Include files

#include <ansi_c.h>
#include "CviDll.h"
#include <stdio.h>
#include <stdarg.h>

//==============================================================================
// Constants

//==============================================================================
// Types

//==============================================================================
// Static global variables

//==============================================================================
// Static functions

//==============================================================================
// Global variables

//==============================================================================
// Global functions

int SprintfWrapper( char * buffer, const char * format, ...)
{
	va_list vl;
	va_start(vl, format);

	return vsprintf(buffer, format, vl);
}

unsigned int PointerSize(void)
{
	return (unsigned int)sizeof(void*);
}


static int foo;

void * ReturnPointer()
{
	return &foo;
}

int CheckPointer(void * ptr)
{
	return ptr == &foo;
}

unsigned char SumUnt8s(const unsigned char * array, unsigned int size)
{
	unsigned char sum = 0;

	for (unsigned int ii=0; ii < size; ++ii)
	{
		sum += array[ii];
	}

	return sum;
}


int SumInt32s(const int * array, unsigned int size)
{
	int sum = 0;

	for (unsigned int ii=0; ii < size; ++ii)
	{
		sum += array[ii];
	}

	return sum;
}

double SumDoubles(const double * array, unsigned int size)
{
	double sum = 0;

	for (unsigned int ii=0; ii < size; ++ii)
	{
		sum += array[ii];
	}

	return sum;
}

void ThrowException()
{
	char * nullPtr = 0;
	*nullPtr = 'a';
}

void OutputNumberSizes(char * sbyte, short * word, int * dword, long long * qword, float * real, double * dreal)
{
	*sbyte = (char)sizeof(*sbyte);
	*word = (short)sizeof(*word);
	*dword = (int)sizeof(*dword);
	*qword = (long long)sizeof(*qword);
	*real = (float)sizeof(*real);
	*dreal = (double)sizeof(*dreal);
}

int PassStructByValue(
	struct MyStruct myStruct,
	unsigned char expectedByte,
	double expectedDouble,
	const char * expectedInString,
	const char * expectedEmbeddedString,
	int expectedInt32,
	__int64 expectedInt64,
	float expectedX,
	float expectedY,
	struct Point expectedPoint)
{
	int expected = (myStruct.byte == expectedByte);
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

int PassStructByPointer(
	struct MyStruct * myStruct,
	unsigned char expectedByte,
	double expectedDouble,
	const char * expectedInString,
	const char * expectedEmbeddedString,
	int expectedInt32,
	__int64 expectedInt64,
	float expectedX,
	float expectedY,
	struct Point expectedPoint)
{
	int expected = (myStruct->byte == expectedByte);
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

void FillStructByPointer(
	struct MyStruct * myStruct,
	unsigned char newByte,
	double newDouble,
	const char * newInString,
	const char * newEmbeddedString,
	int newInt32,
	__int64 newInt64,
	float newX,
	float newY,
	struct Point newPoint)
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


int __cdecl cdecl_Function(int val) { return val;}
int __stdcall stdcall_Function(int val) { return val;}
int nocall_Function(int val) { return val;}
void * PointerFunction(int * ptr) { return ptr; }
