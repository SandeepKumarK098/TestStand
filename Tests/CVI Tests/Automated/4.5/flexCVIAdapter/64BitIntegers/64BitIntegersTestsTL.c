#include <utility.h>
#include "stdtst.h"
#include "numConstants.h"

//********************************************************************
//__int64
//********************************************************************

//********************************************************************
//*
//*		 STRUCT TEST
//*
//********************************************************************


//Using type library section begins

//Please uncomment this section if you want to generate the dll using the type library

typedef struct {
	__int64 int64;
	unsigned __int64 uint64;
} StructType_64BitNumbers;

typedef struct {
	__int64 int64Array[3];
	unsigned __int64 uint64Array[3];
} StructType_64BitArrays;


void __declspec(dllexport) __stdcall Pass64BitNumberStruct(StructType_64BitNumbers arg1, StructType_64BitNumbers *arg2)
{
    int error = 0;

	arg2->int64 = arg1.int64;
	arg2->uint64 = arg1.uint64;
	
	
Error:  
    // FREE RESOURCES
    // if (lastUserName != NULL)
    //     CA_FreeMemory(lastUserName);

    // If an error occurred, set the error flag to cause a run-time error in TestStand.
    if (error < 0)
        {
         }
    
    return;    
}

void __declspec(dllexport) __stdcall Pass64BitArraysStruct(StructType_64BitArrays arg1,  StructType_64BitArrays *arg2)
{
    int error = 0;

	int i;
	for (i = 0; i < 3; i++) {
		arg2->int64Array[i] = arg1.int64Array[i];
		arg2->uint64Array[i] = arg1.uint64Array[i];
		
	}
	
	
Error:  
    // FREE RESOURCES
    // if (lastUserName != NULL)
    //     CA_FreeMemory(lastUserName);

    // If an error occurred, set the error flag to cause a run-time error in TestStand.
    if (error < 0)
        {
         }
    
    return;    
}

//Using type library section ends


//*********************************************************************
//*
//*                   NUMERIC TEST FOR ALL DATA TYPES
//*
//*********************************************************************

//--------------------------------------------------------------------------------- 

char __declspec(dllexport) __stdcall Signed64BitIntegerValues
	(__int64 *minValue, __int64 *maxValue, __int64 regValue)
{
	//-----------------------------------------------------------------------------
	// return the minimum and maximum possible signed 32 bit integer values
	//-----------------------------------------------------------------------------
	*minValue = _MIN_SIGNED_64BIT_INTEGER_;
	*maxValue = _MAX_SIGNED_64BIT_INTEGER_;
	DebugPrintf ("numericTests - Signed64BitIntegerValues : Min(%d), Max(%d), Reg(%d)\n", 
		*minValue, *maxValue, regValue);
		
	return (regValue == _REGULAR_VALUE_);
}

//---------------------------------------------------------------------------------

char __declspec(dllexport) __stdcall Unsigned64BitIntegerValues
	(unsigned __int64 *minValue, unsigned __int64 *maxValue, unsigned __int64 regValue)
{
	//-----------------------------------------------------------------------------
	// return the minimum and maximum possible unsigned 32 bit integer values
	//-----------------------------------------------------------------------------
	*minValue = _MIN_UNSIGNED_64BIT_INTEGER_;
	*maxValue = _MAX_UNSIGNED_64BIT_INTEGER_;
	DebugPrintf ("numericTests - Unsigned64BitIntegerValues : Min(%d), Max(%u), Reg(%d)\n", 
		*minValue, *maxValue, regValue);
		
	return (regValue == _REGULAR_VALUE_);
}

//---------------------------------------------------------------------------------
__int64 __declspec(dllexport) __stdcall TestSimple64BitCall
	(__int64 val)
{
		
	return val;
}

//---------------------------------------------------------------------------------
int __declspec(dllexport) __stdcall TestInt
	(int val)
{
		
	return val;
}

//---------------------------------------------------------------------------------
long __declspec(dllexport) __stdcall TestNotInt
	(long val)
{
		
	return val;
}


//---------------------------------------------------------------------------------

void __declspec(dllexport) __stdcall TestSimple64BitPtrCallMin
	(__int64 *val)
{
		
	*val = _MIN_SIGNED_64BIT_INTEGER_;
}

//---------------------------------------------------------------------------------

void __declspec(dllexport) __stdcall TestSimple64BitPtrCallMax
	(__int64 *val)
{
		
	*val = _MAX_SIGNED_64BIT_INTEGER_;
}

//---------------------------------------------------------------------------------

unsigned __int64 __declspec(dllexport) __stdcall TestSimpleUnsigned64BitCall
	(unsigned __int64 val)
{
		
	return val;
}

//---------------------------------------------------------------------------------

void __declspec(dllexport) __stdcall TestSimpleUnsigned64BitPtrCallMin
	(unsigned __int64 *val)
{
		
	*val = _MIN_UNSIGNED_64BIT_INTEGER_;
}

//---------------------------------------------------------------------------------

void __declspec(dllexport) __stdcall TestSimpleUnsigned64BitPtrCallMax
	(unsigned __int64 *val)
{
		
	*val = _MAX_UNSIGNED_64BIT_INTEGER_;
}

//*********************************************************************
//*
//*       NUMERIC SINGLE DIMENSION ARRAY TEST FOR ALL DATA TYPES
//*
//*********************************************************************

//---------------------------------------------------------------------------------

char __declspec(dllexport) __stdcall Signed64BitIntegerSingleArrayValues
	(__int64 array[3])
{
	//-----------------------------------------------------------------------------
	// return the minimum and maximum possible signed 32 bit integer values
	//-----------------------------------------------------------------------------
	array[0] = _MIN_SIGNED_64BIT_INTEGER_;
	array[2] = _MAX_SIGNED_64BIT_INTEGER_;
	DebugPrintf ("numericTests - Signed32BitIntegerSingleArrayValues : Min(%d), Max(%d), Reg(%d)\n", 
		array[0], array[2], array[1]);
		
	return (array[1] == (_MAX_SIGNED_64BIT_INTEGER_ - 1));
}

//---------------------------------------------------------------------------------

char __declspec(dllexport) __stdcall Unsigned64BitIntegerSingleArrayValues
	(unsigned __int64 array[3])
{
	//-----------------------------------------------------------------------------
	// return the minimum and maximum possible unsigned 32 bit integer values
	//-----------------------------------------------------------------------------
	array[0] = _MAX_UNSIGNED_64BIT_INTEGER_-2;
	array[2] = _MAX_UNSIGNED_64BIT_INTEGER_;
	DebugPrintf ("numericTests - Unsigned32BitIntegerSingleArrayValues : Min(%d), Max(%u), Reg(%d)\n", 
		array[0], array[2], array[1]);
		
	return (array[1] == (_MAX_UNSIGNED_64BIT_INTEGER_ - 1));
}

//*********************************************************************
//*
//*          NUMERIC MULTIDIMENSION ARRAY TEST FOR ALL DATA TYPES
//*
//*********************************************************************

//---------------------------------------------------------------------------------

char __declspec(dllexport) __stdcall Signed64BitIntegerMultiArrayValues
	(__int64 array[2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2])
{
	//-----------------------------------------------------------------------------
	// return the minimum and maximum possible signed 32 bit integer values
	//-----------------------------------------------------------------------------
	char result;
	
	result = (array[0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0] == _MAX_SIGNED_64BIT_INTEGER_ - 1);
	array[0][0][0][0][0][0][0][0][1][1][1][1][1][1][1][1] = _MIN_SIGNED_64BIT_INTEGER_;
	array[1][1][1][1][1][1][1][1][0][0][0][0][0][0][0][0] = _MAX_SIGNED_64BIT_INTEGER_;
	DebugPrintf ("numericTests - Signed64BitIntegerMultiArrayValues : Min(%d), Max(%d), Max-1(%d)\n", 
		array[0][0][0][0][0][0][0][0][1][1][1][1][1][1][1][1], 
		array[1][1][1][1][1][1][1][1][0][0][0][0][0][0][0][0], 
		array[0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0]);
		
	return result;
}

//---------------------------------------------------------------------------------

char __declspec(dllexport) __stdcall Unsigned64BitIntegerMultiArrayValues
	(unsigned __int64 array[2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2])
{
	//-----------------------------------------------------------------------------
	// return the minimum and maximum possible unsigned 32 bit integer values
	//-----------------------------------------------------------------------------
	char result;
	
	result = (array[0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0] == _MAX_UNSIGNED_64BIT_INTEGER_ - 1);
	array[0][0][0][0][0][0][0][0][1][1][1][1][1][1][1][1] = _MAX_UNSIGNED_64BIT_INTEGER_ - 2;
	array[1][1][1][1][1][1][1][1][0][0][0][0][0][0][0][0] = _MAX_UNSIGNED_64BIT_INTEGER_;
	DebugPrintf ("numericTests - Unsigned32BitIntegerMultiArrayValues : Max-2(%d), Max(%u), Max-1(%d)\n", 
		array[0][0][0][0][0][0][0][0][1][1][1][1][1][1][1][1], 
		array[1][1][1][1][1][1][1][1][0][0][0][0][0][0][0][0], 
		array[0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0]);
		
	return result;
}

//********************************************************************
//long long
//********************************************************************

//********************************************************************
//*
//*		 STRUCT TEST
//*
//********************************************************************

//Using type library section begins

//Please uncomment this section if you want to generate the dll using the type library

typedef struct {
	long long int64;
	unsigned long long uint64;
} StructType_64BitNumbersL;

typedef struct {
	long long int64Array[3];
	unsigned long long uint64Array[3];
} StructType_64BitArraysL;


void __declspec(dllexport) __stdcall Pass64BitNumberStructL(StructType_64BitNumbersL arg1, StructType_64BitNumbersL *arg2)
{
    int error = 0;

	arg2->int64 = arg1.int64;
	arg2->uint64 = arg1.uint64;
	
	
Error:  
    // FREE RESOURCES
    // if (lastUserName != NULL)
    //     CA_FreeMemory(lastUserName);

    // If an error occurred, set the error flag to cause a run-time error in TestStand.
    if (error < 0)
        {
         }
    
    return;    
}

void __declspec(dllexport) __stdcall Pass64BitArraysStructL(StructType_64BitArraysL arg1,  StructType_64BitArraysL *arg2)
{
    int error = 0;

	int i;
	for (i = 0; i < 3; i++) {
		arg2->int64Array[i] = arg1.int64Array[i];
		arg2->uint64Array[i] = arg1.uint64Array[i];
		
	}
	
	
Error:  
    // FREE RESOURCES
    // if (lastUserName != NULL)
    //     CA_FreeMemory(lastUserName);

    // If an error occurred, set the error flag to cause a run-time error in TestStand.
    if (error < 0)
        {
         }
    
    return;    
}

//Using type library section ends

//*********************************************************************
//*
//*                   NUMERIC TEST FOR ALL DATA TYPES
//*
//*********************************************************************

//--------------------------------------------------------------------------------- 

char __declspec(dllexport) __stdcall Signed64BitIntegerValuesL
	(long long *minValue, long long *maxValue, long long regValue)
{
	//-----------------------------------------------------------------------------
	// return the minimum and maximum possible signed 32 bit integer values
	//-----------------------------------------------------------------------------
	*minValue = _MIN_SIGNED_64BIT_INTEGER_;
	*maxValue = _MAX_SIGNED_64BIT_INTEGER_;
	DebugPrintf ("numericTests - Signed64BitIntegerValues : Min(%d), Max(%d), Reg(%d)\n", 
		*minValue, *maxValue, regValue);
		
	return (regValue == _REGULAR_VALUE_);
}

//---------------------------------------------------------------------------------

char __declspec(dllexport) __stdcall Unsigned64BitIntegerValuesL
	(unsigned long long *minValue, unsigned long long *maxValue, unsigned long long regValue)
{
	//-----------------------------------------------------------------------------
	// return the minimum and maximum possible unsigned 32 bit integer values
	//-----------------------------------------------------------------------------
	*minValue = _MIN_UNSIGNED_64BIT_INTEGER_;
	*maxValue = _MAX_UNSIGNED_64BIT_INTEGER_;
	DebugPrintf ("numericTests - Unsigned64BitIntegerValues : Min(%d), Max(%u), Reg(%d)\n", 
		*minValue, *maxValue, regValue);
		
	return (regValue == _REGULAR_VALUE_);
}

//---------------------------------------------------------------------------------
long long __declspec(dllexport) __stdcall TestSimple64BitCallL
	(long long val)
{
		
	return val;
}

//---------------------------------------------------------------------------------

void __declspec(dllexport) __stdcall TestSimple64BitPtrCallMinL
	(long long *val)
{
		
	*val = _MIN_SIGNED_64BIT_INTEGER_;
}

//---------------------------------------------------------------------------------

void __declspec(dllexport) __stdcall TestSimple64BitPtrCallMaxL
	(long long *val)
{
		
	*val = _MAX_SIGNED_64BIT_INTEGER_;
}

//---------------------------------------------------------------------------------

unsigned long long __declspec(dllexport) __stdcall TestSimpleUnsigned64BitCallL
	(unsigned long long val)
{
		
	return val;
}

//---------------------------------------------------------------------------------

void __declspec(dllexport) __stdcall TestSimpleUnsigned64BitPtrCallMinL
	(unsigned long long *val)
{
		
	*val = _MIN_UNSIGNED_64BIT_INTEGER_;
}

//---------------------------------------------------------------------------------

void __declspec(dllexport) __stdcall TestSimpleUnsigned64BitPtrCallMaxL
	(unsigned long long *val)
{
		
	*val = _MAX_UNSIGNED_64BIT_INTEGER_;
}

//*********************************************************************
//*
//*       NUMERIC SINGLE DIMENSION ARRAY TEST FOR ALL DATA TYPES
//*
//*********************************************************************

//---------------------------------------------------------------------------------

char __declspec(dllexport) __stdcall Signed64BitIntegerSingleArrayValuesL
	(long long array[3])
{
	//-----------------------------------------------------------------------------
	// return the minimum and maximum possible signed 32 bit integer values
	//-----------------------------------------------------------------------------
	array[0] = _MIN_SIGNED_64BIT_INTEGER_;
	array[2] = _MAX_SIGNED_64BIT_INTEGER_;
	DebugPrintf ("numericTests - Signed32BitIntegerSingleArrayValues : Min(%d), Max(%d), Reg(%d)\n", 
		array[0], array[2], array[1]);
		
	return (array[1] == (_MAX_SIGNED_64BIT_INTEGER_ - 1));
}

//---------------------------------------------------------------------------------

char __declspec(dllexport) __stdcall Unsigned64BitIntegerSingleArrayValuesL
	(unsigned long long array[3])
{
	//-----------------------------------------------------------------------------
	// return the minimum and maximum possible unsigned 32 bit integer values
	//-----------------------------------------------------------------------------
	array[0] = _MAX_UNSIGNED_64BIT_INTEGER_-2;
	array[2] = _MAX_UNSIGNED_64BIT_INTEGER_;
	DebugPrintf ("numericTests - Unsigned32BitIntegerSingleArrayValues : Min(%d), Max(%u), Reg(%d)\n", 
		array[0], array[2], array[1]);
		
	return (array[1] == (_MAX_UNSIGNED_64BIT_INTEGER_ - 1));
}

//*********************************************************************
//*
//*          NUMERIC MULTIDIMENSION ARRAY TEST FOR ALL DATA TYPES
//*
//*********************************************************************

//---------------------------------------------------------------------------------

char __declspec(dllexport) __stdcall Signed64BitIntegerMultiArrayValuesL
	(long long array[2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2])
{
	//-----------------------------------------------------------------------------
	// return the minimum and maximum possible signed 32 bit integer values
	//-----------------------------------------------------------------------------
	char result;
	
	result = (array[0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0] == _MAX_SIGNED_64BIT_INTEGER_ - 1);
	array[0][0][0][0][0][0][0][0][1][1][1][1][1][1][1][1] = _MIN_SIGNED_64BIT_INTEGER_;
	array[1][1][1][1][1][1][1][1][0][0][0][0][0][0][0][0] = _MAX_SIGNED_64BIT_INTEGER_;
	DebugPrintf ("numericTests - Signed64BitIntegerMultiArrayValues : Min(%d), Max(%d), Max-1(%d)\n", 
		array[0][0][0][0][0][0][0][0][1][1][1][1][1][1][1][1], 
		array[1][1][1][1][1][1][1][1][0][0][0][0][0][0][0][0], 
		array[0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0]);
		
	return result;
}

//---------------------------------------------------------------------------------

char __declspec(dllexport) __stdcall Unsigned64BitIntegerMultiArrayValuesL
	(unsigned long long array[2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2])
{
	//-----------------------------------------------------------------------------
	// return the minimum and maximum possible unsigned 32 bit integer values
	//-----------------------------------------------------------------------------
	char result;
	
	result = (array[0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0] == _MAX_UNSIGNED_64BIT_INTEGER_ - 1);
	array[0][0][0][0][0][0][0][0][1][1][1][1][1][1][1][1] = _MAX_UNSIGNED_64BIT_INTEGER_ - 2;
	array[1][1][1][1][1][1][1][1][0][0][0][0][0][0][0][0] = _MAX_UNSIGNED_64BIT_INTEGER_;
	DebugPrintf ("numericTests - Unsigned32BitIntegerMultiArrayValues : Max-2(%d), Max(%u), Max-1(%d)\n", 
		array[0][0][0][0][0][0][0][0][1][1][1][1][1][1][1][1], 
		array[1][1][1][1][1][1][1][1][0][0][0][0][0][0][0][0], 
		array[0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0]);
		
	return result;
}

//Void Pointers
void* __declspec(dllexport) __stdcall AllocateVoidPtr()
{
	 return (void*) malloc(5);	
}

void* __declspec(dllexport) __stdcall TakeAndReturnVoidPtr(void* ptrIn)
{
	 return ptrIn;
}

void __declspec(dllexport) __stdcall FreeVoidPtr(void* ptr)
{
	free(ptr);
}

//numeric pointers
void* __declspec(dllexport) __stdcall AllocateIntPtr()
{
	 return (void*) malloc(sizeof(int));	
}

void* __declspec(dllexport) __stdcall TakeAndReturnIntPtr(int* ptrIn)
{
	 return (void*)ptrIn;
}

void __declspec(dllexport) __stdcall FreeIntPtr(int* ptr)
{
	free(ptr);
}

//arays
void* __declspec(dllexport) __stdcall AllocateArrayPtr()
{
	return (void*)malloc(sizeof(char)*3);
}

void* __declspec(dllexport) __stdcall TakeAndReturnArrayPtr(char arr[3])
{
	return  (void*)arr;
}

void __declspec(dllexport) __stdcall FreeArrayPtr(char arr[3])
{
  free(arr);
}
