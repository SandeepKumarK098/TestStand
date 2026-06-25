

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0366 */
/* at Fri Dec 11 08:08:48 2009
 */
/* Compiler settings for .\64BBitSupportTL.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__


#ifndef ___64BBitSupportTL_h_h__
#define ___64BBitSupportTL_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 


#ifndef __TypeLibTest_LIBRARY_DEFINED__
#define __TypeLibTest_LIBRARY_DEFINED__

/* library TypeLibTest */
/* [uuid] */ 

typedef struct StructType_64BitNumbers
    {
    __int64 int64;
    unsigned __int64 uint64;
    } 	StructType_64BitNumbers;

typedef struct StructType_64BitArrays
    {
    __int64 int64Array[ 3 ];
    unsigned __int64 uint64Array[ 3 ];
    } 	StructType_64BitArrays;

typedef struct StructType_64BitNumbersL
    {
    long long int64;
    unsigned long long uint64;
    } 	StructType_64BitNumbersL;

typedef struct StructType_64BitArraysL
    {
    long long int64Array[ 3 ];
    unsigned long long uint64Array[ 3 ];
    } 	StructType_64BitArraysL;


EXTERN_C const IID LIBID_TypeLibTest;


#ifndef __TLFunctions_MODULE_DEFINED__
#define __TLFunctions_MODULE_DEFINED__


/* module TLFunctions */
/* [dllname] */ 

/* [entry] */ void Pass64BitNumberStruct( 
    /* [in] */ StructType_64BitNumbers val1,
    /* [out] */ StructType_64BitNumbers *val2);

/* [entry] */ void Pass64BitArraysStruct( 
    StructType_64BitArrays val1,
    StructType_64BitArrays *val2);

/* [entry] */ __int64 TestSimple64BitCall( 
    /* [in] */ __int64 val);

/* [entry] */ void TestSimple64BitPtrCallMin( 
    /* [out] */ __int64 *val);

/* [entry] */ void TestSimple64BitPtrCallMax( 
    /* [out] */ __int64 *val);

/* [entry] */ unsigned __int64 __stdcall TestSimpleUnsigned64BitCall( 
    /* [in] */ unsigned __int64 val);

/* [entry] */ void TestSimpleUnsigned64BitPtrCallMin( 
    /* [out] */ unsigned __int64 *val);

/* [entry] */ void TestSimpleUnsigned64BitPtrCallMax( 
    /* [out] */ unsigned __int64 *val);

/* [entry] */ unsigned char Signed64BitIntegerSingleArrayValues( 
    /* [out][in] */ __int64 array[ 3 ]);

/* [entry] */ unsigned char Unsigned64BitIntegerSingleArrayValues( 
    /* [out][in] */ unsigned __int64 array[ 3 ]);

/* [entry] */ unsigned char Signed64BitIntegerMultiArrayValues( 
    __int64 array[ 2 ][ 2 ][ 2 ][ 2 ][ 2 ][ 2 ][ 2 ][ 2 ][ 2 ][ 2 ][ 2 ][ 2 ][ 2 ][ 2 ][ 2 ][ 2 ]);

/* [entry] */ unsigned char Unsigned64BitIntegerMultiArrayValues( 
    unsigned __int64 array[ 2 ][ 2 ][ 2 ][ 2 ][ 2 ][ 2 ][ 2 ][ 2 ][ 2 ][ 2 ][ 2 ][ 2 ][ 2 ][ 2 ][ 2 ][ 2 ]);

/* [entry] */ void Pass64BitNumberStructL( 
    /* [in] */ StructType_64BitNumbersL val1,
    /* [out] */ StructType_64BitNumbersL *val2);

/* [entry] */ void Pass64BitArraysStructL( 
    StructType_64BitArraysL val1,
    StructType_64BitArraysL *val2);

/* [entry] */ long long TestSimple64BitCallL( 
    /* [in] */ long long val);

/* [entry] */ void TestSimple64BitPtrCallMinL( 
    /* [out] */ long long *val);

/* [entry] */ void TestSimple64BitPtrCallMaxL( 
    /* [out] */ long long *val);

/* [entry] */ unsigned long long __stdcall TestSimpleUnsigned64BitCallL( 
    /* [in] */ unsigned long long val);

/* [entry] */ void TestSimpleUnsigned64BitPtrCallMinL( 
    /* [out] */ unsigned long long *val);

/* [entry] */ void TestSimpleUnsigned64BitPtrCallMaxL( 
    /* [out] */ unsigned long long *val);

/* [entry] */ unsigned char Signed64BitIntegerSingleArrayValuesL( 
    /* [out][in] */ long long array[ 3 ]);

/* [entry] */ unsigned char Unsigned64BitIntegerSingleArrayValuesL( 
    /* [out][in] */ unsigned long long array[ 3 ]);

/* [entry] */ unsigned char Signed64BitIntegerMultiArrayValuesL( 
    long long array[ 2 ][ 2 ][ 2 ][ 2 ][ 2 ][ 2 ][ 2 ][ 2 ][ 2 ][ 2 ][ 2 ][ 2 ][ 2 ][ 2 ][ 2 ][ 2 ]);

/* [entry] */ unsigned char Unsigned64BitIntegerMultiArrayValuesL( 
    unsigned long long array[ 2 ][ 2 ][ 2 ][ 2 ][ 2 ][ 2 ][ 2 ][ 2 ][ 2 ][ 2 ][ 2 ][ 2 ][ 2 ][ 2 ][ 2 ][ 2 ]);

#endif /* __TLFunctions_MODULE_DEFINED__ */
#endif /* __TypeLibTest_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


