#include <utility.h>
#include "stdtst.h"
#include "numconstants.h"

//---------------------------------------------------------------------------------

void __declspec(dllexport) __stdcall voidFunc()
{
	//-----------------------------------------------------------------------------
	// Do nothing, just return.
	//-----------------------------------------------------------------------------
	DebugPrintf ("returnValueTests - voidFunc : Does nothing, just return\n");
	
	return;    
}

//---------------------------------------------------------------------------------
// Signed 8 bit integer values
//---------------------------------------------------------------------------------

char __declspec(dllexport) __stdcall Signed8BitIntegerMINValue()
{
	//-----------------------------------------------------------------------------
	// return the minimum possible signed 8 bit integer
	//-----------------------------------------------------------------------------
	char value = _MIN_SIGNED_8BIT_INTEGER_;
	DebugPrintf ("returnValueTests - Signed8BitIntegerMINValue : %d\n", value);
					 
	return value;    
}

//---------------------------------------------------------------------------------

char __declspec(dllexport) __stdcall Signed8BitIntegerMAXValue()
{
	//-----------------------------------------------------------------------------
	// return the minimum possible signed 8 bit integer
	//-----------------------------------------------------------------------------
	char value = _MAX_SIGNED_8BIT_INTEGER_;
	DebugPrintf ("returnValueTests - Signed8BitIntegerMAXValue : %d\n", value);
					 
	return value;    
}

//---------------------------------------------------------------------------------

char __declspec(dllexport) __stdcall Signed8BitIntegerValue()
{
	//-----------------------------------------------------------------------------
	// return the minimum possible signed 8 bit integer
	//-----------------------------------------------------------------------------
	char value = _VAL_SIGNED_8BIT_INTEGER_;
	DebugPrintf ("returnValueTests - Signed8BitIntegerValue : %d\n", value);
					 
	return value;    
}

//---------------------------------------------------------------------------------
// Unsigned 8 bit integer values
//---------------------------------------------------------------------------------

unsigned char __declspec(dllexport) __stdcall Unsigned8BitIntegerMINValue()
{
	//-----------------------------------------------------------------------------
	// return the minimum possible unsigned 8 bit integer
	//-----------------------------------------------------------------------------
	unsigned char value = _MIN_UNSIGNED_8BIT_INTEGER_;
	DebugPrintf ("returnValueTests - Unsigned8BitIntegerMINValue : %d\n", value);
					 
	return value;    
}

//---------------------------------------------------------------------------------

unsigned char __declspec(dllexport) __stdcall Unsigned8BitIntegerMAXValue()
{
	//-----------------------------------------------------------------------------
	// return the minimum possible unsigned 8 bit integer
	//-----------------------------------------------------------------------------
	unsigned char value = _MAX_UNSIGNED_8BIT_INTEGER_;
	DebugPrintf ("returnValueTests - Unsigned8BitIntegerMAXValue : %d\n", value);
					 
	return value;    
}

//---------------------------------------------------------------------------------

unsigned char __declspec(dllexport) __stdcall Unsigned8BitIntegerValue()
{
	//-----------------------------------------------------------------------------
	// return the minimum possible unsigned 8 bit integer
	//-----------------------------------------------------------------------------
	unsigned char value = _VAL_UNSIGNED_8BIT_INTEGER_;
	DebugPrintf ("returnValueTests - Unsigned8BitIntegerValue : %d\n", value);
					 
	return value;    
}

//---------------------------------------------------------------------------------
// Signed 16 bit integer values
//---------------------------------------------------------------------------------

short __declspec(dllexport) __stdcall Signed16BitIntegerMINValue()
{
	//-----------------------------------------------------------------------------
	// return the minimum possible signed 16 bit integer
	//-----------------------------------------------------------------------------
	short value = _MIN_SIGNED_16BIT_INTEGER_;
	DebugPrintf ("returnValueTests - Signed16BitIntegerMINValue : %d\n", value);
					 
	return value;    
}

//---------------------------------------------------------------------------------

short __declspec(dllexport) __stdcall Signed16BitIntegerMAXValue()
{
	//-----------------------------------------------------------------------------
	// return the minimum possible signed 16 bit integer
	//-----------------------------------------------------------------------------
	short value = _MAX_SIGNED_16BIT_INTEGER_;
	DebugPrintf ("returnValueTests - Signed16BitIntegerMAXValue : %d\n", value);
					 
	return value;    
}

//---------------------------------------------------------------------------------

short __declspec(dllexport) __stdcall Signed16BitIntegerValue()
{
	//-----------------------------------------------------------------------------
	// return the minimum possible signed 16 bit integer
	//-----------------------------------------------------------------------------
	short value = _VAL_SIGNED_16BIT_INTEGER_;
	DebugPrintf ("returnValueTests - Signed16BitIntegerValue : %d\n", value);
					 
	return value;    
}

//---------------------------------------------------------------------------------
// Unsigned 16 bit integer values
//---------------------------------------------------------------------------------

unsigned short __declspec(dllexport) __stdcall Unsigned16BitIntegerMINValue()
{
	//-----------------------------------------------------------------------------
	// return the minimum possible unsigned 16 bit integer
	//-----------------------------------------------------------------------------
	unsigned short value = _MIN_UNSIGNED_16BIT_INTEGER_;
	DebugPrintf ("returnValueTests - Unsigned16BitIntegerMINValue : %d\n", value);
					 
	return value;    
}

//---------------------------------------------------------------------------------

unsigned short __declspec(dllexport) __stdcall Unsigned16BitIntegerMAXValue()
{
	//-----------------------------------------------------------------------------
	// return the minimum possible unsigned 16 bit integer
	//-----------------------------------------------------------------------------
	unsigned short value = _MAX_UNSIGNED_16BIT_INTEGER_;
	DebugPrintf ("returnValueTests - Unsigned16BitIntegerMAXValue : %d\n", value);
					 
	return value;    
}

//---------------------------------------------------------------------------------

unsigned short __declspec(dllexport) __stdcall Unsigned16BitIntegerValue()
{
	//-----------------------------------------------------------------------------
	// return the minimum possible unsigned 16 bit integer
	//-----------------------------------------------------------------------------
	unsigned short value = _VAL_UNSIGNED_16BIT_INTEGER_;
	DebugPrintf ("returnValueTests - Unsigned16BitIntegerValue : %d\n", value);
					 
	return value;    
}

//---------------------------------------------------------------------------------
// Signed 32 bit integer values
//---------------------------------------------------------------------------------

int __declspec(dllexport) __stdcall Signed32BitIntegerMINValue()
{
	//-----------------------------------------------------------------------------
	// return the minimum possible signed 32 bit integer
	//-----------------------------------------------------------------------------
	int value = _MIN_SIGNED_32BIT_INTEGER_;
	DebugPrintf ("returnValueTests - Signed32BitIntegerMINValue : %d\n", value);
					 
	return value;    
}

//---------------------------------------------------------------------------------

int __declspec(dllexport) __stdcall Signed32BitIntegerMAXValue()
{
	//-----------------------------------------------------------------------------
	// return the minimum possible signed 32 bit integer
	//-----------------------------------------------------------------------------
	int value = _MAX_SIGNED_32BIT_INTEGER_;
	DebugPrintf ("returnValueTests - Signed32BitIntegerMAXValue : %d\n", value);
					 
	return value;    
}

//---------------------------------------------------------------------------------

int __declspec(dllexport) __stdcall Signed32BitIntegerValue()
{
	//-----------------------------------------------------------------------------
	// return the minimum possible signed 32 bit integer
	//-----------------------------------------------------------------------------
	int value = _VAL_SIGNED_32BIT_INTEGER_;
	DebugPrintf ("returnValueTests - Signed32BitIntegerValue : %d\n", value);
					 
	return value;    
}

//---------------------------------------------------------------------------------
// Unsigned 32 bit integer values
//---------------------------------------------------------------------------------

unsigned int __declspec(dllexport) __stdcall Unsigned32BitIntegerMINValue()
{
	//-----------------------------------------------------------------------------
	// return the minimum possible unsigned 32 bit integer
	//-----------------------------------------------------------------------------
	unsigned int value = _MIN_UNSIGNED_32BIT_INTEGER_;
	DebugPrintf ("returnValueTests - Unsigned32BitIntegerMINValue : %u\n", value);
					 
	return value;    
}

//---------------------------------------------------------------------------------

unsigned int __declspec(dllexport) __stdcall Unsigned32BitIntegerMAXValue()
{
	//-----------------------------------------------------------------------------
	// return the minimum possible unsigned 32 bit integer
	//-----------------------------------------------------------------------------
	unsigned int value = _MAX_UNSIGNED_32BIT_INTEGER_;
	DebugPrintf ("returnValueTests - Unsigned32BitIntegerMAXValue : %u\n", value);
					 
	return value;    
}

//---------------------------------------------------------------------------------

unsigned int __declspec(dllexport) __stdcall Unsigned32BitIntegerValue()
{
	//-----------------------------------------------------------------------------
	// return the minimum possible unsigned 32 bit integer
	//-----------------------------------------------------------------------------
	unsigned int value = _VAL_UNSIGNED_32BIT_INTEGER_;
	DebugPrintf ("returnValueTests - Unsigned32BitIntegerValue : %u\n", value);
					 
	return value;    
}

//---------------------------------------------------------------------------------
// 32 bit Float values
//---------------------------------------------------------------------------------

float __declspec(dllexport) __stdcall S32BitFloatMINValue()
{
	//-----------------------------------------------------------------------------
	// return the minimum possible 32 bit float
	//-----------------------------------------------------------------------------
	float _MIN_32BIT_REAL_   = -3.40282E+38;	
	float  value = _MIN_32BIT_REAL_;
	DebugPrintf ("returnValueTests - S32BitFloatMINValue : %f\n", value);
					 
	return value;    
}

//---------------------------------------------------------------------------------

float __declspec(dllexport) __stdcall S32BitFloatMAXValue()
{
	//-----------------------------------------------------------------------------
	// return the minimum possible 32 bit float
	//-----------------------------------------------------------------------------
	float _MAX_32BIT_REAL_   = 3.40282E+38;	
	float value = _MAX_32BIT_REAL_;
	DebugPrintf ("returnValueTests - S32BitFloatMAXValue : %f\n", value);
					 
	return value;    
}

//---------------------------------------------------------------------------------

float __declspec(dllexport) __stdcall S32BitFloatValue()
{
	//-----------------------------------------------------------------------------
	// return the minimum possible 32 bit float
	//-----------------------------------------------------------------------------
	float value = _VAL_32BIT_REAL_;
	DebugPrintf ("returnValueTests - S32BitFloatValue : %f\n", value);
					 
	return value;    
}

//---------------------------------------------------------------------------------
// 64 bit Double values
//---------------------------------------------------------------------------------

double __declspec(dllexport) __stdcall S64BitDoubleMINValue()
{
	//-----------------------------------------------------------------------------
	// return the minimum possible 64 bit Double
	//-----------------------------------------------------------------------------
	double  value = _MIN_64BIT_REAL_;
	DebugPrintf ("returnValueTests - S64BitDoubleMINValue : %f\n", value);
					 
	return value;    
}

//---------------------------------------------------------------------------------

double __declspec(dllexport) __stdcall S64BitDoubleMAXValue()
{
	//-----------------------------------------------------------------------------
	// return the minimum possible 64 bit Double
	//-----------------------------------------------------------------------------
	double value = _MAX_64BIT_REAL_;
	DebugPrintf ("returnValueTests - S64BitDoubleMAXValue : %f\n", value);
					 
	return value;    
}

//---------------------------------------------------------------------------------

double __declspec(dllexport) __stdcall S64BitDoubleValue()
{
	//-----------------------------------------------------------------------------
	// return the minimum possible 64 bit Double
	//-----------------------------------------------------------------------------
	double value = _VAL_64BIT_REAL_;
	DebugPrintf ("returnValueTests - S64BitDoubleValue : %f\n", value);
					 
	return value;    
}

//---------------------------------------------------------------------------------
// Return value test
//---------------------------------------------------------------------------------

int __declspec(dllexport) __stdcall returnPositive()
{
	int value = 32;
	DebugPrintf ("returnValueTests - returnPositive : %d\n", value);
					 
	return value;    
}

//---------------------------------------------------------------------------------

int __declspec(dllexport) __stdcall returnNegative()
{
	int value = -32;
	DebugPrintf ("returnValueTests - returnNegative : %d\n", value);
					 
	return value;    
}

//---------------------------------------------------------------------------------

int __declspec(dllexport) __stdcall returnZero()
{
	int value = 0;
	DebugPrintf ("returnValueTests - returnZero : %d\n", value);
					 
	return value;    
}
