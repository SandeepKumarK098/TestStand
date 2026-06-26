#include "stdtst.h"
#include <toolbox.h>

#pragma pack(8)

// Note: This is a copy of (except this comment):
//       //TestStand/Tests/TS Automated Tests/2.0/Flexc/StructPassing/PackingTests/structtest.c
// If that file is updated, then this file should also be updated.
// So, if this test fails, then check if that file has been updated since that
// location is probably tested more frequently and so fixes there will typically be done there first.

// CAR 429461 -- We bump into some precision issues with floating
// point numbers in 64-bit builds.  Use the lexicographically
// ordered nature of IEEE to verify that the two numbers are, if not the same,  
// then, at worst, lexicographically sequential for 64-bit builds.
//
// CAR 573310 - With Visual Studio 2015, SSE2 is used more extensively
// and for all practical purposes no longer avoidable.  So, 32-bit code
// will now also have a slight imprecision.  So, the lexicographic 
// adjecency test is now applied for 32-bit code as well instead of an exact
// match.
//
// For an explanation of the 64-bit version of function, see for example:
// http://www.cygnus-software.com/papers/comparingfloats/comparingfloats.htm
static int DoublesAreEqual(double n1, double n2)
{
	__int64 intDiff = 0;
	
	// Get the underlying binary representation of our two numbers.
	__int64 n1Int = *(__int64*)&n1;
	__int64 n2Int = *(__int64*)&n2;
	
	// First, handle exact equality.  Obviously, if the two numbers compare
	// equal, then they should be equal.
	if (n1 == n2)
	{
		return TRUE;
	}
	
	assert( sizeof(n1Int) == 8);
	assert( sizeof(n2Int) == 8);
	assert( sizeof(1ll) == 8);
	assert( sizeof(__int64) == 8);
	assert( sizeof(double) == 8);
	
	// Fix lexicographical ordering to be 2's compliment.  This makes
	// comparisons around 0 work.  (IEEE numbers are naturally ordered
	// as sign-magnitude integers.)
	if (n1Int < 0) { n1Int = (1ll << 63) - n1Int; }
	if (n2Int < 0) { n2Int = (1ll << 63) - n2Int; }

	intDiff = n1Int - n2Int;
	
	// Intdiff is now the number of floating point representations the two
	// values differ by.  If two values differ by 1, then there are no
	// representable values between them; if they differ by two, then
	// there is one value between them; etc.
	intDiff = (intDiff >=0)? intDiff : -intDiff;
	
	return intDiff <= 1; // So far, off by one in the last bit is the worst this test has seen.
}

struct innerStruct1
{
	char c;		// expects 21
	int i;		// expects 7
};

struct innerStruct2
{
	char c;		// expects 32
	double d;	// expects 34.2
};

#define TEST_STRUCT												\
		char c0;	/* expects -1 */							\
		struct innerStruct2 *inner2byref;						\
		struct innerStruct1 *inner1byref;						\
		int i;		/* expects 1 */								\
		char c;		/* expects 2 */								\
		double d;	/* expects 3.4 */							\
		int i2;		/* expects 5 */								\
		int i3;		/* expects 6 */								\
		char c2;	/* expects 7 */								\
		double d2;	/* expects 8.9 */							\
		char c3[3];	/* expects "10" string */					\
		struct innerStruct1 inner1; /* expected (see above) */  \
		char c4;	/* expects 16 */							\
		struct innerStruct2 inner2; /* expected (see above) */

#define VERIFY_TEST_STRUCT_BY_VAL								\
	if(a != 1 || b != 2)										\
		errChk(-1);												\
	if(s.c0 != -1)												\
		errChk(-3);												\
	if(s.inner2byref->c != 32)									\
		errChk(-13);											\
	if(!DoublesAreEqual(s.inner2byref->d, 34.2))				\
		errChk(-14);											\
	if(s.inner1byref->c != 21)									\
		errChk(-10);											\
	if(s.inner1byref->i != 7)									\
		errChk(-11);											\
	if(s.i != 1)												\
		errChk(-2);												\
	if(s.c != 2)												\
		errChk(-3);												\
	if(!DoublesAreEqual(s.d, 3.4))								\
		errChk(-4);												\
	if(s.i2 != 5)												\
		errChk(-5);												\
	if(s.i3 != 6)												\
		errChk(-6);												\
	if(s.c2 != 7)												\
		errChk(-7);												\
	if(!DoublesAreEqual(s.d2, 8.9))								\
		errChk(-8);												\
	if(s.c3[0] != '1' || s.c3[1] != '0' || s.c3[2] != 0)		\
		errChk(-9);												\
	if(s.inner1.c != 21)										\
		errChk(-10);											\
	if(s.inner1.i != 7)											\
		errChk(-11);											\
	if(s.c4 != 16)												\
		errChk(-12);											\
	if(s.inner2.c != 32)										\
		errChk(-13);											\
	if(!DoublesAreEqual(s.inner2.d, 34.2))						\
		errChk(-14);											

#define VERIFY_TEST_STRUCT_BY_REF								\
	if(a != 1 || b != 2)										\
		errChk(-1);												\
	if(s->c0 != -1)												\
		errChk(-3);												\
	if(s->inner2byref->c != 32)									\
		errChk(-13);											\
	if(!DoublesAreEqual(s->inner2byref->d,34.2))				\
		errChk(-14);											\
	if(s->inner1byref->c != 21)									\
		errChk(-10);											\
	if(s->inner1byref->i != 7)									\
		errChk(-11);											\
	if(s->i != 1)												\
		errChk(-2);												\
	if(s->c != 2)												\
		errChk(-3);												\
	if(!DoublesAreEqual(s->d, 3.4))								\
		errChk(-4);												\
	if(s->i2 != 5)												\
		errChk(-5);												\
	if(s->i3 != 6)												\
		errChk(-6);												\
	if(s->c2 != 7)												\
		errChk(-7);												\
	if(!DoublesAreEqual(s->d2, 8.9))							\
		errChk(-8);												\
	if(s->c3[0] != '1' || s->c3[1] != '0' || s->c3[2] != 0)		\
		errChk(-9);												\
	if(s->inner1.c != 21)										\
		errChk(-10);											\
	if(s->inner1.i != 7)										\
		errChk(-11);											\
	if(s->c4 != 16)												\
		errChk(-12);											\
	if(s->inner2.c != 32)										\
		errChk(-13);											\
	if(!DoublesAreEqual(s->inner2.d, 34.2))						\
		errChk(-14);											

#pragma pack(16)
struct pack16 {
TEST_STRUCT
};

#pragma pack(8)
struct pack8 {
TEST_STRUCT
};

#pragma pack(4)
struct pack4 {
TEST_STRUCT
};

#pragma pack(2)
struct pack2 {
TEST_STRUCT
};

#pragma pack(1)
struct pack1 {
TEST_STRUCT
};

#pragma pack()

int __declspec(dllexport) __stdcall TestStructByValPack16(char a, struct pack16 s, char b)
{
	int error = 0;
	
	VERIFY_TEST_STRUCT_BY_VAL

Error:

	return (error >= 0); // returns true on success (pass)
}

int __declspec(dllexport) __stdcall TestStructByRefPack16(char a, struct pack16 *s, char b)
{
	int error = 0;
	
	VERIFY_TEST_STRUCT_BY_REF

Error:

	return (error >= 0); // returns true on success (pass)
}

int __declspec(dllexport) __stdcall TestStructByValPack8(char a, struct pack8 s, char b)
{
	int error = 0;
	
	VERIFY_TEST_STRUCT_BY_VAL

Error:

	return (error >= 0); // returns true on success (pass)
}

int __declspec(dllexport) __stdcall TestStructByRefPack8(char a, struct pack8 *s, char b)
{
	int error = 0;
	
	VERIFY_TEST_STRUCT_BY_REF

Error:

	return (error >= 0); // returns true on success (pass)
}

int __declspec(dllexport) __stdcall TestStructByValPack4(char a, struct pack4 s, char b)
{
	int error = 0;
	
	VERIFY_TEST_STRUCT_BY_VAL

Error:

	return (error >= 0); // returns true on success (pass)
}

int __declspec(dllexport) __stdcall TestStructByRefPack4(char a, struct pack4 *s, char b)
{
	int error = 0;
	
	VERIFY_TEST_STRUCT_BY_REF

Error:

	return (error >= 0); // returns true on success (pass)
}

int __declspec(dllexport) __stdcall TestStructByValPack2(char a, struct pack2 s, char b)
{
	int error = 0;
	
	VERIFY_TEST_STRUCT_BY_VAL

Error:

	return (error >= 0); // returns true on success (pass)
}

int __declspec(dllexport) __stdcall TestStructByRefPack2(char a, struct pack2 *s, char b)
{
	int error = 0;
	
	VERIFY_TEST_STRUCT_BY_REF

Error:

	return (error >= 0); // returns true on success (pass)
}

int __declspec(dllexport) __stdcall TestStructByValPack1(char a, struct pack1 s, char b)
{
	int error = 0;
	
	VERIFY_TEST_STRUCT_BY_VAL

Error:

	return (error >= 0); // returns true on success (pass)
}

int __declspec(dllexport) __stdcall TestStructByRefPack1(char a, struct pack1 *s, char b)
{
	int error = 0;
	
	VERIFY_TEST_STRUCT_BY_REF

Error:

	return (error >= 0); // returns true on success (pass)
}


int __declspec(dllexport) __stdcall TestStructByValPack1_FieldModification(char a, struct pack1 s, char b)
{
	int error = 0;
	
	s.inner2byref->c = 0;
	s.inner2.c = 0;
	
	strcpy(s.c3, "hi");

Error:

	return (error >= 0); // returns true on success (pass)
}

int __declspec(dllexport) __stdcall TestStructByRefPack1_FieldModification(char a, struct pack1 *s, char b)
{
	int error = 0;
	
	s->inner2byref->c = 0;
	s->inner2.c = 0;
	
	strcpy(s->c3, "hi");
	
Error:

	return (error >= 0); // returns true on success (pass)
}
