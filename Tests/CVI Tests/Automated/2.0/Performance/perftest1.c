#include "tsapicvi.h"
#include "utility.h"
#include "stdtst.h"

#define INSTANTIATE_100(stmt)	\
stmt; stmt; stmt; stmt; stmt; stmt; stmt; stmt; stmt; stmt; \
stmt; stmt; stmt; stmt; stmt; stmt; stmt; stmt; stmt; stmt; \
stmt; stmt; stmt; stmt; stmt; stmt; stmt; stmt; stmt; stmt; \
stmt; stmt; stmt; stmt; stmt; stmt; stmt; stmt; stmt; stmt; \
stmt; stmt; stmt; stmt; stmt; stmt; stmt; stmt; stmt; stmt; \
stmt; stmt; stmt; stmt; stmt; stmt; stmt; stmt; stmt; stmt; \
stmt; stmt; stmt; stmt; stmt; stmt; stmt; stmt; stmt; stmt; \
stmt; stmt; stmt; stmt; stmt; stmt; stmt; stmt; stmt; stmt; \
stmt; stmt; stmt; stmt; stmt; stmt; stmt; stmt; stmt; stmt; \
stmt; stmt; stmt; stmt; stmt; stmt; stmt; stmt; stmt; stmt;

void __declspec(dllexport) CVIStep(tTestData *data, tTestError *error)
{
}



int __declspec(dllexport) ReturnIntFun1(void)
{
	return -1;
}

double __declspec(dllexport) ReturnDoubleFun1(void)
{
	return -1.1;
}

void __declspec(dllexport) VoidFun1(void)
{
}

void __declspec(dllexport) IntFun1(int i)
{
}

void __declspec(dllexport) DoubleFun1(double d)
{
}

void __declspec(dllexport) ContextVoidFun1(CAObjHandle context)
{
}

void __declspec(dllexport) ContextIntFun1(CAObjHandle context, int i)
{
}

void __declspec(dllexport) ContextDoubleFun1(CAObjHandle context, double d)
{
}



void __declspec(dllexport) VoidFun1000(void)
{
	INSTANTIATE_100(VoidFun1())
	INSTANTIATE_100(VoidFun1())
	INSTANTIATE_100(VoidFun1())
	INSTANTIATE_100(VoidFun1())
	INSTANTIATE_100(VoidFun1())
	INSTANTIATE_100(VoidFun1())
	INSTANTIATE_100(VoidFun1())
	INSTANTIATE_100(VoidFun1())
	INSTANTIATE_100(VoidFun1())
	INSTANTIATE_100(VoidFun1())
}

void __declspec(dllexport) IntFun100(int i)
{
	INSTANTIATE_100(IntFun1(i))
}

void __declspec(dllexport) DoubleFun100(double d)
{
	INSTANTIATE_100(DoubleFun1(d))
}

void __declspec(dllexport) VoidFun200(void)
{
	INSTANTIATE_100(VoidFun1())
	INSTANTIATE_100(VoidFun1())
}

void __declspec(dllexport) IntFun200(int i)
{
	INSTANTIATE_100(IntFun1(i))
	INSTANTIATE_100(IntFun1(i))
}

void __declspec(dllexport) DoubleFun200(double d)
{
	INSTANTIATE_100(DoubleFun1(d))
	INSTANTIATE_100(DoubleFun1(d))
}
