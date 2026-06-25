//==============================================================================
//
// Title:		CviDll.h
// Purpose:		A short description of the interface.
//
// Created on:	6/24/2013 at 4:40:04 PM by Jed Beach.
// Copyright:	ni. All Rights Reserved.
//
//==============================================================================

#ifndef __CviDll_H__
#define __CviDll_H__

#ifdef __cplusplus
    extern "C" {
#endif

//==============================================================================
// Include files

#include "cvidef.h"

//==============================================================================
// Constants

//==============================================================================
// Types

//==============================================================================
// External variables

//==============================================================================
// Global functions

SprintfWrapper( char * buffer, const char * format, ...);

unsigned int PointerSize(void);

void ReturnVoid() {}
int ReturnBoolUsingInt(int val1, int val2) { return val1 && !val2; }
int ReturnInt32(int val1, int val2) { return val1 + val2; }
long long ReturnInt64(long long val1, long long val2) { return val1 + val2; }
float ReturnFloat(float val1, float val2) { return val1 + val2; }
double ReturnDouble(double val1, double val2) { return val1 + val2; }
void * ReturnPointer();
int CheckPointer(void * ptr);

unsigned char SumUnt8s(const unsigned char * array, unsigned int size);
int SumInt32s(const int * array, unsigned int size);
double SumDoubles(const double * array, unsigned int size);


void OutputNumberSizes(char * sbyte, short * word, int * dword, long long * qword, float * real, double * dreal);

void ThrowException();

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
	struct Point point;
	struct Point * pPoint;
};

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
	struct Point expectedPoint);

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
	struct Point expectedPoint);

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
	struct Point newPoint);

int __cdecl cdecl_Function(int val);
int __stdcall stdcall_Function(int val);
int nocall_Function(int val);

void * PointerFunction(int * ptr);


#ifdef __cplusplus
    }
#endif

#endif  /* ndef __CviDll_H__ */
