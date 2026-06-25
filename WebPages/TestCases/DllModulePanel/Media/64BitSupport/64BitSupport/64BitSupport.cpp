// 64BitSupport.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "64BitSupport.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO: If this DLL is dynamically linked against the MFC DLLs,
//		any functions exported from this DLL which call into
//		MFC must have the AFX_MANAGE_STATE macro added at the
//		very beginning of the function.
//
//		For example:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// normal function body here
//		}
//
//		It is very important that this macro appear in each
//		function, prior to any calls into MFC.  This means that
//		it must appear as the first statement within the 
//		function, even before any object variable declarations
//		as their constructors may generate calls into the MFC
//		DLL.
//
//		Please see MFC Technical Notes 33 and 58 for additional
//		details.
//


// CMy64BitSupportApp

BEGIN_MESSAGE_MAP(CMy64BitSupportApp, CWinApp)
END_MESSAGE_MAP()


// CMy64BitSupportApp construction

CMy64BitSupportApp::CMy64BitSupportApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CMy64BitSupportApp object

CMy64BitSupportApp theApp;


// CMy64BitSupportApp initialization

BOOL CMy64BitSupportApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}
//---------------------------------------------------------------------------------
// 64 bit integer constants
//---------------------------------------------------------------------------------
const __int64 _MIN_SIGNED_64BIT_INTEGER_   = -9223372036854775808i64;
const __int64 _MAX_SIGNED_64BIT_INTEGER_   = 9223372036854775807i64;
const __int64 _VAL_SIGNED_64BIT_INTEGER_   = 32i64;
const unsigned __int64 _MIN_UNSIGNED_64BIT_INTEGER_ = 0ui64;
const unsigned __int64 _MAX_UNSIGNED_64BIT_INTEGER_ = 18446744073709551615ui64;
const unsigned __int64 _VAL_UNSIGNED_64BIT_INTEGER_ = 4ui64;

struct StructType_64BitNumbers {
	__int64 int64;
	unsigned __int64 uint64;
};

struct StructType_64BitArrays {
	__int64 int64Array[3];
	unsigned __int64 uint64Array[3];
};

__declspec(dllexport) void  __stdcall Pass64BitNumberStruct(struct StructType_64BitNumbers val1, struct StructType_64BitNumbers *val2)
{
    int error = 0;

	val2->int64 = val1.int64;
	val2->uint64 = val1.uint64;
	    
}

__declspec(dllexport) void __stdcall Pass64BitArraysStruct(struct StructType_64BitArrays val1, struct StructType_64BitArrays *val2)
{
    int error = 0;

	int i;
	for (i = 0; i < 3; i++) {
		val2->int64Array[i] = val1.int64Array[i];
		val2->uint64Array[i] = val1.uint64Array[i];
		
	}   
}

//---------------------------------------------------------------------------------   
__int64 __declspec(dllexport) TestSimple64BitCall(__int64 val)
{
	return val;
}
//---------------------------------------------------------------------------------
__declspec(dllexport) void  __stdcall TestSimple64BitPtrCallMin
	(__int64 *val)
{
		
	*val = _MIN_SIGNED_64BIT_INTEGER_;
}
//---------------------------------------------------------------------------------
__declspec(dllexport) void __stdcall TestSimple64BitPtrCallMax
	(__int64 *val)
{
		
	*val = _MAX_SIGNED_64BIT_INTEGER_;
}
//---------------------------------------------------------------------------------
__declspec(dllexport) unsigned __int64 __stdcall TestSimpleUnsigned64BitCall
	(unsigned __int64 val)
{
		
	return val;
}
//---------------------------------------------------------------------------------
__declspec(dllexport) void __stdcall TestSimpleUnsigned64BitPtrCallMin
	(unsigned __int64 *val)
{
		
	*val = _MIN_UNSIGNED_64BIT_INTEGER_;
}
//---------------------------------------------------------------------------------
__declspec(dllexport) void __stdcall TestSimpleUnsigned64BitPtrCallMax
	(unsigned __int64 *val)
{
		
	*val = _MAX_UNSIGNED_64BIT_INTEGER_;
}

//---------------------------------------------------------------------------------
__declspec(dllexport) char __stdcall Signed64BitIntegerSingleArrayValues
	(__int64 array[3])
{
	//-----------------------------------------------------------------------------
	// return the minimum and maximum possible signed 32 bit integer values
	//-----------------------------------------------------------------------------
	array[0] = _MIN_SIGNED_64BIT_INTEGER_;
	array[2] = _MAX_SIGNED_64BIT_INTEGER_;
	return (array[1] == (_MAX_SIGNED_64BIT_INTEGER_ - 1));
}

//---------------------------------------------------------------------------------

__declspec(dllexport) char __stdcall Unsigned64BitIntegerSingleArrayValues
	(unsigned __int64 array[3])
{
	//-----------------------------------------------------------------------------
	// return the minimum and maximum possible unsigned 32 bit integer values
	//-----------------------------------------------------------------------------
	array[0] = _MAX_UNSIGNED_64BIT_INTEGER_-2;
	array[2] = _MAX_UNSIGNED_64BIT_INTEGER_;
	return (array[1] == (_MAX_UNSIGNED_64BIT_INTEGER_ - 1));
}

__declspec(dllexport) char __stdcall Signed64BitIntegerMultiArrayValues
	(__int64 array[2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2])
{
	//-----------------------------------------------------------------------------
	// return the minimum and maximum possible signed 32 bit integer values
	//-----------------------------------------------------------------------------
	char result;
	
	result = (array[0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0] == _MAX_SIGNED_64BIT_INTEGER_ - 1);
	array[0][0][0][0][0][0][0][0][1][1][1][1][1][1][1][1] = _MIN_SIGNED_64BIT_INTEGER_;
	array[1][1][1][1][1][1][1][1][0][0][0][0][0][0][0][0] = _MAX_SIGNED_64BIT_INTEGER_;
	return result;
}

//---------------------------------------------------------------------------------

__declspec(dllexport) char __stdcall Unsigned64BitIntegerMultiArrayValues
	(unsigned __int64 array[2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2])
{
	//-----------------------------------------------------------------------------
	// return the minimum and maximum possible unsigned 32 bit integer values
	//-----------------------------------------------------------------------------
	char result;
	
	result = (array[0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0] == _MAX_UNSIGNED_64BIT_INTEGER_ - 1);
	array[0][0][0][0][0][0][0][0][1][1][1][1][1][1][1][1] = _MAX_UNSIGNED_64BIT_INTEGER_ - 2;
	array[1][1][1][1][1][1][1][1][0][0][0][0][0][0][0][0] = _MAX_UNSIGNED_64BIT_INTEGER_;
	return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//long long
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct StructType_64BitNumbersL {
	long long int64;
	unsigned long long uint64;
};

struct StructType_64BitArraysL {
	long long int64Array[3];
	unsigned long long uint64Array[3];
};

void __declspec(dllexport) __stdcall Pass64BitNumberStructL(struct StructType_64BitNumbersL val1,struct StructType_64BitNumbersL *val2)
{
    int error = 0;

	val2->int64 = val1.int64;
	val2->uint64 = val1.uint64;
	    
}

void __declspec(dllexport) __stdcall Pass64BitArraysStructL(struct StructType_64BitArraysL val1, struct StructType_64BitArraysL *val2)
{
    int error = 0;

	int i;
	for (i = 0; i < 3; i++) {
		val2->int64Array[i] = val1.int64Array[i];
		val2->uint64Array[i] = val1.uint64Array[i];
		
	}   
}

//---------------------------------------------------------------------------------   
_declspec(dllexport) long long __stdcall TestSimple64BitCallL(long long val)
{
	return val;
}
//---------------------------------------------------------------------------------
__declspec(dllexport) void  __stdcall TestSimple64BitPtrCallMinL
	(long long *val)
{
		
	*val = _MIN_SIGNED_64BIT_INTEGER_;
}
//---------------------------------------------------------------------------------
__declspec(dllexport) void __stdcall TestSimple64BitPtrCallMaxL
	(long long *val)
{
		
	*val = _MAX_SIGNED_64BIT_INTEGER_;
}
//---------------------------------------------------------------------------------
__declspec(dllexport) unsigned __int64 __stdcall TestSimpleUnsigned64BitCallL
	(unsigned long long val)
{
		
	return val;
}
//---------------------------------------------------------------------------------
__declspec(dllexport) void __stdcall TestSimpleUnsigned64BitPtrCallMinL
	(unsigned long long *val)
{
		
	*val = _MIN_UNSIGNED_64BIT_INTEGER_;
}
//---------------------------------------------------------------------------------
__declspec(dllexport) void __stdcall TestSimpleUnsigned64BitPtrCallMaxL
	(unsigned long long *val)
{
		
	*val = _MAX_UNSIGNED_64BIT_INTEGER_;
}

//---------------------------------------------------------------------------------
__declspec(dllexport) char __stdcall Signed64BitIntegerSingleArrayValuesL
	(long long array[3])
{
	//-----------------------------------------------------------------------------
	// return the minimum and maximum possible signed 32 bit integer values
	//-----------------------------------------------------------------------------
	array[0] = _MIN_SIGNED_64BIT_INTEGER_;
	array[2] = _MAX_SIGNED_64BIT_INTEGER_;
	return (array[1] == (_MAX_SIGNED_64BIT_INTEGER_ - 1));
}

//---------------------------------------------------------------------------------

__declspec(dllexport) char __stdcall Unsigned64BitIntegerSingleArrayValuesL
	(unsigned long long array[3])
{
	//-----------------------------------------------------------------------------
	// return the minimum and maximum possible unsigned 32 bit integer values
	//-----------------------------------------------------------------------------
	array[0] = _MAX_UNSIGNED_64BIT_INTEGER_-2;
	array[2] = _MAX_UNSIGNED_64BIT_INTEGER_;
	return (array[1] == (_MAX_UNSIGNED_64BIT_INTEGER_ - 1));
}

__declspec(dllexport) char __stdcall Signed64BitIntegerMultiArrayValuesL
	(long long array[2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2])
{
	//-----------------------------------------------------------------------------
	// return the minimum and maximum possible signed 32 bit integer values
	//-----------------------------------------------------------------------------
	char result;
	
	result = (array[0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0] == _MAX_SIGNED_64BIT_INTEGER_ - 1);
	array[0][0][0][0][0][0][0][0][1][1][1][1][1][1][1][1] = _MIN_SIGNED_64BIT_INTEGER_;
	array[1][1][1][1][1][1][1][1][0][0][0][0][0][0][0][0] = _MAX_SIGNED_64BIT_INTEGER_;
	return result;
}

//---------------------------------------------------------------------------------

__declspec(dllexport) char __stdcall Unsigned64BitIntegerMultiArrayValuesL
	(unsigned long long array[2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2])
{
	//-----------------------------------------------------------------------------
	// return the minimum and maximum possible unsigned 32 bit integer values
	//-----------------------------------------------------------------------------
	char result;
	
	result = (array[0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0] == _MAX_UNSIGNED_64BIT_INTEGER_ - 1);
	array[0][0][0][0][0][0][0][0][1][1][1][1][1][1][1][1] = _MAX_UNSIGNED_64BIT_INTEGER_ - 2;
	array[1][1][1][1][1][1][1][1][0][0][0][0][0][0][0][0] = _MAX_UNSIGNED_64BIT_INTEGER_;
	return result;
}
