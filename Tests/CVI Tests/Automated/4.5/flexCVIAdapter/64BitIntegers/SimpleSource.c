struct StructType_64BitArrays {
	__int64 int64Array[3];
	unsigned __int64 uint64Array[3];
};

char __declspec(dllexport) SimpleArray(__int64 array[1024])
{
	return 0;	
}

unsigned long long   __declspec(dllexport) __stdcall TestUnsignedLongLongInt(unsigned long long  val)
{
	return val;
}

char __declspec(dllexport) MyNewFunction(__int64 *array)
{
	return 0;
}

unsigned __int64 __declspec(dllexport) FiFa(unsigned __int64 array[1024])
{
	return 0;
}

void __declspec(dllexport) Pass64BitArraysStructFake(struct StructType_64BitArrays arg1, struct StructType_64BitArrays arg2[3])
{
	//Insert function body here.
}

void __declspec(dllexport) Aracnida(__int64 arg1, unsigned __int64 arg2, __int64 arg3[1024], unsigned __int64 arg4[1024])
{
	//Insert function body here.
}
