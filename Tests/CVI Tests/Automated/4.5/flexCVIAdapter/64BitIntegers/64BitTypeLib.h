typedef struct {
	__int64 int64;
	unsigned __int64 uint64;
} StructType_64BitNumbers;

typedef struct {
	__int64 int64Array[3];
	unsigned __int64 uint64Array[3];
} StructType_64BitArrays;

typedef struct {
	long long int64;
	unsigned long long uint64;
} StructType_64BitNumbersL;

typedef struct {
	long long int64Array[3];
	unsigned long long uint64Array[3];
} StructType_64BitArraysL;


///ADDT __int64 [3]
///ADDT unsigned __int64 [3] 
///ADDT __int64 [2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2]
///ADDT unsigned __int64 [2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2]
///ADDT long long [3]
///ADDT unsigned long long [3] 
///ADDT long long [2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2]
///ADDT unsigned long long [2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2]


///OUT 2
void __stdcall Pass64BitNumberStruct(StructType_64BitNumbers arg1, StructType_64BitNumbers *arg2);
/// OUT 2 
void __stdcall Pass64BitArraysStruct(StructType_64BitArrays arg1, StructType_64BitArrays *arg2);
///OUT 1,2
char __stdcall Signed64BitIntegerValues(__int64 *minValue, __int64 *maxValue, __int64 regValue); 
///OUT 1,2
char __stdcall Unsigned64BitIntegerValues(unsigned __int64 *minValue, unsigned __int64 *maxValue, unsigned __int64 regValue);
__int64 __stdcall TestSimple64BitCall(__int64 val);
//---------------------------------------------------------------------------------
int __stdcall TestInt(int val);
long __stdcall TestNotInt(long val);
///OUT 1
void __stdcall TestSimple64BitPtrCallMin(__int64 *val);
///OUT 1
void __stdcall TestSimple64BitPtrCallMax(__int64 *val);
unsigned __int64 __stdcall TestSimpleUnsigned64BitCall(unsigned __int64 val);
///OUT 1
void __stdcall TestSimpleUnsigned64BitPtrCallMin(unsigned __int64 *val);
///OUT 1
void __stdcall TestSimpleUnsigned64BitPtrCallMax(unsigned __int64 *val);
///PTYP 1/__int64 [3]
char __stdcall Signed64BitIntegerSingleArrayValues(__int64 array[3]);
///PTYP 1/unsigned __int64 [3] 
char __stdcall Unsigned64BitIntegerSingleArrayValues(unsigned __int64 array[3]);
///PTYP 1/__int64 [2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2]
char __stdcall Signed64BitIntegerMultiArrayValues(__int64 array[2]);
///PTYP 1/unsigned __int64 [2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2] 
char __stdcall Unsigned64BitIntegerMultiArrayValues(unsigned __int64 array[2]);

///OUT 2
void __stdcall Pass64BitNumberStructL(StructType_64BitNumbersL arg1, StructType_64BitNumbersL *arg2);
/// OUT 2 
void __stdcall Pass64BitArraysStructL(StructType_64BitArraysL arg1, StructType_64BitArraysL *arg2);
///OUT 1,2
char __stdcall Signed64BitIntegerValuesL(long long *minValue, long long *maxValue, long long regValue); 
///OUT 1,2
char __stdcall Unsigned64BitIntegerValuesL(unsigned long long *minValue, unsigned long long *maxValue, unsigned long long regValue);
long long __stdcall TestSimple64BitCallL(long long val);
///OUT 1
void __stdcall TestSimple64BitPtrCallMinL(long long *val);
///OUT 1
void __stdcall TestSimple64BitPtrCallMaxL(long long *val);
unsigned long long __stdcall TestSimpleUnsigned64BitCallL(unsigned long long val);
///OUT 1
void __stdcall TestSimpleUnsigned64BitPtrCallMinL(unsigned long long *val);
///OUT 1
void __stdcall TestSimpleUnsigned64BitPtrCallMaxL(unsigned long long *val);
///PTYP 1/long long [3]
char __stdcall Signed64BitIntegerSingleArrayValuesL(long long array[3]);
///PTYP 1/unsigned long long [3] 
char __stdcall Unsigned64BitIntegerSingleArrayValuesL(unsigned long long array[3]);
///PTYP 1/long long [2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2]
char __stdcall Signed64BitIntegerMultiArrayValuesL(long long array[2]);
///PTYP 1/unsigned long long [2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2] 
char __stdcall Unsigned64BitIntegerMultiArrayValuesL(unsigned long long array[2]);
//Void Pointers
void*  __stdcall AllocateVoidPtr();
void*  __stdcall TakeAndReturnVoidPtr(void* ptrIn);
void   __stdcall FreeVoidPtr(void* ptr);
void*   __stdcall AllocateIntPtr();
void*   __stdcall TakeAndReturnIntPtr(int* ptrIn);
void   __stdcall FreeIntPtr(int* ptr);
void*  __stdcall AllocateArrayPtr();
void*  __stdcall TakeAndReturnArrayPtr(char arr[3]);
void   __stdcall FreeArrayPtr(char arr[3]);

