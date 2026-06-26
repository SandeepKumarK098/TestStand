#include <utility.h>
#include "stdtst.h"
#include "numConstants.h"

//*********************************************************************
//*
//*                   NUMERIC TEST FOR ALL DATA TYPES
//*
//*********************************************************************

char __declspec(dllexport) __stdcall Signed8BitIntegerValues
	(char *minValue, char *maxValue, char regValue)
{
	//-----------------------------------------------------------------------------
	// return the minimum and maximum possible signed 8 bit integer values
	//-----------------------------------------------------------------------------
	*minValue = _MIN_SIGNED_8BIT_INTEGER_;
	*maxValue = _MAX_SIGNED_8BIT_INTEGER_;
	DebugPrintf ("numericTests - Signed8BitIntegerValues : Min(%d), Max(%d), Reg(%d)\n", 
		*minValue, *maxValue, regValue);
		
	return (regValue == _REGULAR_VALUE_);
}

//---------------------------------------------------------------------------------

char __declspec(dllexport) __stdcall Unsigned8BitIntegerValues
	(unsigned char *minValue, unsigned char *maxValue, unsigned char regValue)
{
	//-----------------------------------------------------------------------------
	// return the minimum and maximum possible unsigned 8 bit integer values
	//-----------------------------------------------------------------------------
	*minValue = _MIN_UNSIGNED_8BIT_INTEGER_;
	*maxValue = _MAX_UNSIGNED_8BIT_INTEGER_;
	DebugPrintf ("numericTests - Unsigned8BitIntegerValues : Min(%d), Max(%d), Reg(%d)\n", 
		*minValue, *maxValue, regValue);
		
	return (regValue == _REGULAR_VALUE_);
}

//---------------------------------------------------------------------------------

char __declspec(dllexport) __stdcall Signed16BitIntegerValues
	(short *minValue, short *maxValue, short regValue)
{
	//-----------------------------------------------------------------------------
	// return the minimum and maximum possible signed 16 bit integer values
	//-----------------------------------------------------------------------------
	*minValue = _MIN_SIGNED_16BIT_INTEGER_;
	*maxValue = _MAX_SIGNED_16BIT_INTEGER_;
	DebugPrintf ("numericTests - Signed16BitIntegerValues : Min(%d), Max(%d), Reg(%d)\n", 
		*minValue, *maxValue, regValue);
		
	return (regValue == _REGULAR_VALUE_);
}

//---------------------------------------------------------------------------------

char __declspec(dllexport) __stdcall Unsigned16BitIntegerValues
	(unsigned short *minValue, unsigned short *maxValue, unsigned short regValue)
{
	//-----------------------------------------------------------------------------
	// return the minimum and maximum possible unsigned 16 bit integer values
	//-----------------------------------------------------------------------------
	*minValue = _MIN_UNSIGNED_16BIT_INTEGER_;
	*maxValue = _MAX_UNSIGNED_16BIT_INTEGER_;
	DebugPrintf ("numericTests - Unsigned16BitIntegerValues : Min(%d), Max(%d), Reg(%d)\n", 
		*minValue, *maxValue, regValue);
		
	return (regValue == _REGULAR_VALUE_);
}

//---------------------------------------------------------------------------------

char __declspec(dllexport) __stdcall Signed32BitIntegerValues
	(int *minValue, int *maxValue, int regValue)
{
	//-----------------------------------------------------------------------------
	// return the minimum and maximum possible signed 32 bit integer values
	//-----------------------------------------------------------------------------
	*minValue = _MIN_SIGNED_32BIT_INTEGER_;
	*maxValue = _MAX_SIGNED_32BIT_INTEGER_;
	DebugPrintf ("numericTests - Signed32BitIntegerValues : Min(%d), Max(%d), Reg(%d)\n", 
		*minValue, *maxValue, regValue);
		
	return (regValue == _REGULAR_VALUE_);
}

//---------------------------------------------------------------------------------

char __declspec(dllexport) __stdcall Unsigned32BitIntegerValues
	(unsigned int *minValue, unsigned int *maxValue, unsigned int regValue)
{
	//-----------------------------------------------------------------------------
	// return the minimum and maximum possible unsigned 32 bit integer values
	//-----------------------------------------------------------------------------
	*minValue = _MIN_UNSIGNED_32BIT_INTEGER_;
	*maxValue = _MAX_UNSIGNED_32BIT_INTEGER_;
	DebugPrintf ("numericTests - Unsigned32BitIntegerValues : Min(%d), Max(%u), Reg(%d)\n", 
		*minValue, *maxValue, regValue);
		
	return (regValue == _REGULAR_VALUE_);
}

//---------------------------------------------------------------------------------

char __declspec(dllexport) __stdcall S32BitFloatValues
	(float *minValue, float *maxValue, float regValue)
{
	//-----------------------------------------------------------------------------
	// return the minimum and maximum possible signed 32 bit float values
	//-----------------------------------------------------------------------------
	float _MIN_32BIT_REAL_   = -3.40282E+38;
	float _MAX_32BIT_REAL_   = 3.40282E+38;	
	*minValue = _MIN_32BIT_REAL_;
	*maxValue = _MAX_32BIT_REAL_;
	DebugPrintf ("numericTests - S32BitFloatValues : Min(%f), Max(%f), Reg(%f)\n", 
		*minValue, *maxValue, regValue);
		
	return (regValue == _REGULAR_VALUE_);
}

//---------------------------------------------------------------------------------

char __declspec(dllexport) __stdcall S64BitDoubleValues
	(double *minValue, double *maxValue, double regValue)
{
	//-----------------------------------------------------------------------------
	// return the minimum and maximum possible signed 64 bit double values
	//-----------------------------------------------------------------------------
	*minValue = _MIN_64BIT_REAL_;
	*maxValue = _MAX_64BIT_REAL_;
	DebugPrintf ("numericTests - S64BitDoubleValues : Min(%f), Max(%f), Reg(%f)\n", 
		*minValue, *maxValue, regValue);
		
	return (regValue == _REGULAR_VALUE_);
}

//*********************************************************************
//*
//*       NUMERIC SINGLE DIMENSION ARRAY TEST FOR ALL DATA TYPES
//*
//*********************************************************************

char __declspec(dllexport) __stdcall Signed8BitIntegerSingleArrayValues
	(char array[3])
{
	//-----------------------------------------------------------------------------
	// return the minimum and maximum possible signed 8 bit integer values
	//-----------------------------------------------------------------------------
	array[0] = _MIN_SIGNED_8BIT_INTEGER_;
	array[2] = _MAX_SIGNED_8BIT_INTEGER_;
	DebugPrintf ("numericTests - Signed8BitIntegerSingleArrayValues : Min(%d), Max(%d), Reg(%d)\n", 
		array[0], array[2], array[1]);
		
	return (array[1] == _REGULAR_VALUE_);
}

//---------------------------------------------------------------------------------

char __declspec(dllexport) __stdcall Unsigned8BitIntegerSingleArrayValues
	(unsigned char array[3])
{
	//-----------------------------------------------------------------------------
	// return the minimum and maximum possible unsigned 8 bit integer values
	//-----------------------------------------------------------------------------
	array[0] = _MIN_UNSIGNED_8BIT_INTEGER_;
	array[2] = _MAX_UNSIGNED_8BIT_INTEGER_;
	DebugPrintf ("numericTests - Unsigned8BitIntegerSingleArrayValues : Min(%d), Max(%d), Reg(%d)\n", 
		array[0], array[2], array[1]);
		
	return (array[1] == _REGULAR_VALUE_);
}

//---------------------------------------------------------------------------------

char __declspec(dllexport) __stdcall Signed16BitIntegerSingleArrayValues
	(short array[3])
{
	//-----------------------------------------------------------------------------
	// return the minimum and maximum possible signed 16 bit integer values
	//-----------------------------------------------------------------------------
	array[0] = _MIN_SIGNED_16BIT_INTEGER_;
	array[2] = _MAX_SIGNED_16BIT_INTEGER_;
	DebugPrintf ("numericTests - Signed16BitIntegerSingleArrayValues : Min(%d), Max(%d), Reg(%d)\n", 
		array[0], array[2], array[1]);
		
	return (array[1] == _REGULAR_VALUE_);
}

//---------------------------------------------------------------------------------

char __declspec(dllexport) __stdcall Unsigned16BitIntegerSingleArrayValues
	(unsigned short array[3])
{
	//-----------------------------------------------------------------------------
	// return the minimum and maximum possible unsigned 16 bit integer values
	//-----------------------------------------------------------------------------
	array[0] = _MIN_UNSIGNED_16BIT_INTEGER_;
	array[2] = _MAX_UNSIGNED_16BIT_INTEGER_;
	DebugPrintf ("numericTests - Unsigned16BitIntegerSingleArrayValues : Min(%d), Max(%d), Reg(%d)\n", 
		array[0], array[2], array[1]);
		
	return (array[1] == _REGULAR_VALUE_);
}

//---------------------------------------------------------------------------------

char __declspec(dllexport) __stdcall Signed32BitIntegerSingleArrayValues
	(int array[3])
{
	//-----------------------------------------------------------------------------
	// return the minimum and maximum possible signed 32 bit integer values
	//-----------------------------------------------------------------------------
	array[0] = _MIN_SIGNED_32BIT_INTEGER_;
	array[2] = _MAX_SIGNED_32BIT_INTEGER_;
	DebugPrintf ("numericTests - Signed32BitIntegerSingleArrayValues : Min(%d), Max(%d), Reg(%d)\n", 
		array[0], array[2], array[1]);
		
	return (array[1] == _REGULAR_VALUE_);
}

//---------------------------------------------------------------------------------

char __declspec(dllexport) __stdcall Unsigned32BitIntegerSingleArrayValues
	(unsigned int array[3])
{
	//-----------------------------------------------------------------------------
	// return the minimum and maximum possible unsigned 32 bit integer values
	//-----------------------------------------------------------------------------
	array[0] = _MIN_UNSIGNED_32BIT_INTEGER_;
	array[2] = _MAX_UNSIGNED_32BIT_INTEGER_;
	DebugPrintf ("numericTests - Unsigned32BitIntegerSingleArrayValues : Min(%d), Max(%u), Reg(%d)\n", 
		array[0], array[2], array[1]);
		
	return (array[1] == _REGULAR_VALUE_);
}

//---------------------------------------------------------------------------------

char __declspec(dllexport) __stdcall S32BitFloatSingleArrayValues
	(float array[3])
{
	//-----------------------------------------------------------------------------
	// return the minimum and maximum possible signed 32 bit float values
	//-----------------------------------------------------------------------------
	float _MIN_32BIT_REAL_   = -3.40282E+38;
	float _MAX_32BIT_REAL_   = 3.40282E+38;	
	array[0] = _MIN_32BIT_REAL_;
	array[2] = _MAX_32BIT_REAL_;
	DebugPrintf ("numericTests - S32BitFloatSingleArrayValues : Min(%f), Max(%f), Reg(%f)\n", 
		array[0], array[2], array[1]);
		
	return (array[1] == _REGULAR_VALUE_);
}

//---------------------------------------------------------------------------------

char __declspec(dllexport) __stdcall S64BitDoubleSingleArrayValues
	(double array[3])
{
	//-----------------------------------------------------------------------------
	// return the minimum and maximum possible signed 64 bit double values
	//-----------------------------------------------------------------------------
	array[0] = _MIN_64BIT_REAL_;
	array[2] = _MAX_64BIT_REAL_;
	DebugPrintf ("numericTests - S64BitDoubleSingleArrayValues : Min(%f), Max(%f), Reg(%f)\n", 
		array[0], array[2], array[1]);
		
	return (array[1] == _REGULAR_VALUE_);
}

//---------------------------------------------------------------------------------

char __declspec(dllexport) __stdcall TestSingleArraySize
	(char array[3])
{
	//-----------------------------------------------------------------------------
	// return the minimum and maximum possible signed 8 bit integer values
	//-----------------------------------------------------------------------------
	char keepValue;

	DebugPrintf ("numericTests - TestSingleArraySize (%d,%d,%d)\n", 
		array[0], array[1], array[2]);
	keepValue = array[2];
	array[2] = array[0];
	array[0] = keepValue;
	DebugPrintf ("numericTests - TestSingleArraySize inverted (%d,%d,%d)\n", 
		array[0], array[1], array[2]);
		
	return (array[1] == _REGULAR_VALUE_);
}

//*********************************************************************
//*
//*          NUMERIC MULTIDIMENSION ARRAY TEST FOR ALL DATA TYPES
//*
//*********************************************************************

char __declspec(dllexport) __stdcall Signed8BitIntegerMultiArrayValues
	(char array[2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2])
{
	//-----------------------------------------------------------------------------
	// return the minimum and maximum possible signed 8 bit integer values
	//-----------------------------------------------------------------------------
	char result;
	
	result = (array[0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0] == _REGULAR_VALUE_);
	array[0][0][0][0][0][0][0][0][1][1][1][1][1][1][1][1] = _MIN_SIGNED_8BIT_INTEGER_;
	array[1][1][1][1][1][1][1][1][0][0][0][0][0][0][0][0] = _MAX_SIGNED_8BIT_INTEGER_;
	DebugPrintf ("numericTests - Signed8BitIntegerMultiArrayValues : Min(%d), Max(%d), Reg(%d)\n", 
		array[0][0][0][0][0][0][0][0][1][1][1][1][1][1][1][1], 
		array[1][1][1][1][1][1][1][1][0][0][0][0][0][0][0][0], 
		array[0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0]);
		
	return result;
}

//---------------------------------------------------------------------------------

char __declspec(dllexport) __stdcall Unsigned8BitIntegerMultiArrayValues
	(unsigned char array[2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2])
{
	//-----------------------------------------------------------------------------
	// return the minimum and maximum possible unsigned 8 bit integer values
	//-----------------------------------------------------------------------------
	char result;
	
	result = (array[0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0] == _REGULAR_VALUE_);
	array[0][0][0][0][0][0][0][0][1][1][1][1][1][1][1][1] = _MIN_UNSIGNED_8BIT_INTEGER_;
	array[1][1][1][1][1][1][1][1][0][0][0][0][0][0][0][0] = _MAX_UNSIGNED_8BIT_INTEGER_;
	DebugPrintf ("numericTests - Unsigned8BitIntegerMultiArrayValues : Min(%d), Max(%d), Reg(%d)\n", 
		array[0][0][0][0][0][0][0][0][1][1][1][1][1][1][1][1], 
		array[1][1][1][1][1][1][1][1][0][0][0][0][0][0][0][0], 
		array[0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0]);
		
	return result;
}

//---------------------------------------------------------------------------------

char __declspec(dllexport) __stdcall Signed16BitIntegerMultiArrayValues
	(short array[2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2])
{
	//-----------------------------------------------------------------------------
	// return the minimum and maximum possible signed 16 bit integer values
	//-----------------------------------------------------------------------------
	char result;
	
	result = (array[0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0] == _REGULAR_VALUE_);
	array[0][0][0][0][0][0][0][0][1][1][1][1][1][1][1][1] = _MIN_SIGNED_16BIT_INTEGER_;
	array[1][1][1][1][1][1][1][1][0][0][0][0][0][0][0][0] = _MAX_SIGNED_16BIT_INTEGER_;
	DebugPrintf ("numericTests - Signed16BitIntegerMultiArrayValues : Min(%d), Max(%d), Reg(%d)\n", 
		array[0][0][0][0][0][0][0][0][1][1][1][1][1][1][1][1], 
		array[1][1][1][1][1][1][1][1][0][0][0][0][0][0][0][0], 
		array[0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0]);
		
	return result;
}

//---------------------------------------------------------------------------------

char __declspec(dllexport) __stdcall Unsigned16BitIntegerMultiArrayValues
	(unsigned short array[2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2])
{
	//-----------------------------------------------------------------------------
	// return the minimum and maximum possible unsigned 16 bit integer values
	//-----------------------------------------------------------------------------
	char result;
	
	result = (array[0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0] == _REGULAR_VALUE_);
	array[0][0][0][0][0][0][0][0][1][1][1][1][1][1][1][1] = _MIN_UNSIGNED_16BIT_INTEGER_;
	array[1][1][1][1][1][1][1][1][0][0][0][0][0][0][0][0] = _MAX_UNSIGNED_16BIT_INTEGER_;
	DebugPrintf ("numericTests - Unsigned16BitIntegerMultiArrayValues : Min(%d), Max(%d), Reg(%d)\n", 
		array[0][0][0][0][0][0][0][0][1][1][1][1][1][1][1][1], 
		array[1][1][1][1][1][1][1][1][0][0][0][0][0][0][0][0], 
		array[0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0]);
		
	return result;
}

//---------------------------------------------------------------------------------

char __declspec(dllexport) __stdcall Signed32BitIntegerMultiArrayValues
	(int array[2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2])
{
	//-----------------------------------------------------------------------------
	// return the minimum and maximum possible signed 32 bit integer values
	//-----------------------------------------------------------------------------
	char result;
	
	result = (array[0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0] == _REGULAR_VALUE_);
	array[0][0][0][0][0][0][0][0][1][1][1][1][1][1][1][1] = _MIN_SIGNED_32BIT_INTEGER_;
	array[1][1][1][1][1][1][1][1][0][0][0][0][0][0][0][0] = _MAX_SIGNED_32BIT_INTEGER_;
	DebugPrintf ("numericTests - Signed32BitIntegerMultiArrayValues : Min(%d), Max(%d), Reg(%d)\n", 
		array[0][0][0][0][0][0][0][0][1][1][1][1][1][1][1][1], 
		array[1][1][1][1][1][1][1][1][0][0][0][0][0][0][0][0], 
		array[0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0]);
		
	return result;
}

//---------------------------------------------------------------------------------

char __declspec(dllexport) __stdcall Unsigned32BitIntegerMultiArrayValues
	(unsigned int array[2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2])
{
	//-----------------------------------------------------------------------------
	// return the minimum and maximum possible unsigned 32 bit integer values
	//-----------------------------------------------------------------------------
	char result;
	
	result = (array[0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0] == _REGULAR_VALUE_);
	array[0][0][0][0][0][0][0][0][1][1][1][1][1][1][1][1] = _MIN_UNSIGNED_32BIT_INTEGER_;
	array[1][1][1][1][1][1][1][1][0][0][0][0][0][0][0][0] = _MAX_UNSIGNED_32BIT_INTEGER_;
	DebugPrintf ("numericTests - Unsigned32BitIntegerMultiArrayValues : Min(%d), Max(%u), Reg(%d)\n", 
		array[0][0][0][0][0][0][0][0][1][1][1][1][1][1][1][1], 
		array[1][1][1][1][1][1][1][1][0][0][0][0][0][0][0][0], 
		array[0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0]);
		
	return result;
}

//---------------------------------------------------------------------------------

char __declspec(dllexport) __stdcall S32BitFloatMultiArrayValues
	(float array[2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2])
{
	//-----------------------------------------------------------------------------
	// return the minimum and maximum possible signed 32 bit float values
	//-----------------------------------------------------------------------------
	float _MIN_32BIT_REAL_   = -3.40282E+38;
	float _MAX_32BIT_REAL_   = 3.40282E+38;	
	char result;
	
	result = (array[0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0] == _REGULAR_VALUE_);
	array[0][0][0][0][0][0][0][0][1][1][1][1][1][1][1][1] = _MIN_32BIT_REAL_;
	array[1][1][1][1][1][1][1][1][0][0][0][0][0][0][0][0] = _MAX_32BIT_REAL_;
	DebugPrintf ("numericTests - S32BitFloatMultiArrayValues : Min(%f), Max(%f), Reg(%f)\n", 
		array[0][0][0][0][0][0][0][0][1][1][1][1][1][1][1][1], 
		array[1][1][1][1][1][1][1][1][0][0][0][0][0][0][0][0], 
		array[0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0]);
		
	return result;
}

//---------------------------------------------------------------------------------

char __declspec(dllexport) __stdcall S64BitDoubleMultiArrayValues
	(double array[2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2])
{
	//-----------------------------------------------------------------------------
	// return the minimum and maximum possible signed 64 bit double values
	//-----------------------------------------------------------------------------
	char result;
	
	result = (array[0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0] == _REGULAR_VALUE_);
	array[0][0][0][0][0][0][0][0][1][1][1][1][1][1][1][1] = _MIN_64BIT_REAL_;
	array[1][1][1][1][1][1][1][1][0][0][0][0][0][0][0][0] = _MAX_64BIT_REAL_;
	DebugPrintf ("numericTests - S64BitDoubleMultiArrayValues : Min(%f), Max(%f), Reg(%f)\n", 
		array[0][0][0][0][0][0][0][0][1][1][1][1][1][1][1][1], 
		array[1][1][1][1][1][1][1][1][0][0][0][0][0][0][0][0], 
		array[0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0]);
		
	return result;
}
