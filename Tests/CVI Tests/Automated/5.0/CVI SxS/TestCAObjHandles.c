#include <cviauto.h>
#include "tsapicvi.h"
#include "tsutil.h"
#include "stdtst.h"

 #define CLEAR(__handle, __func)				\
	if(__handle)							\
	{										\
		__func(__handle);					\
		__handle = 0;						\
	}

// This function tests:
// 1) receiving an object (engine) created in TestStand passed via parameter by value
// 2) passing back an object (expression) created in CVI passed via parameter by reference
int __declspec(dllexport) NewExpression(CAObjHandle engine, const char *expressionText, ErrMsg errMsg, TSObj_Expression *expression)
{
	int         error = 0;
	ERRORINFO   errorInfo;

	CLEAR(*expression, CA_DiscardObjHandle);

	tsErrChk(TS_EngineNewExpression(engine, &errorInfo, expression));
	tsErrChk(TS_ExpressionSetText(*expression, &errorInfo, expressionText));

Error:
	return error;
	
}

// This function tests:
// 1) receiving an object (engine) created in TestStand passed via parameter by referemce
// 2) passing back an object (expression) created in CVI passed via parameter by reference
int __declspec(dllexport) NewExpressionPtr(CAObjHandle *engine, const char *expressionText, ErrMsg errMsg, TSObj_Expression *expression)
{
	int         error = 0;
	ERRORINFO   errorInfo;

	CLEAR(*expression, CA_DiscardObjHandle);
	
	tsErrChk(TS_EngineNewExpression(*engine, &errorInfo, expression));
	tsErrChk(TS_ExpressionSetText(*expression, &errorInfo, expressionText));

Error:
	return error;
	
}

typedef struct ExpressionData
{
	const char *expressionText;
	CAObjHandle engine;
	CAObjHandle expression;
	
} ExpressionData;

// This function tests:
// 1) receiving object (engine) created in TestStand passed via struct pointer parameter
// 2) pass back object (expression) created in CVI passed via struct pointer parameter
int __declspec(dllexport) NewExpressionStructPtr(ExpressionData *expressionData, ErrMsg errMsg)
{
	int         error = 0;
	ERRORINFO   errorInfo;
	TSObj_Expression expression;
	
	// DO NOT CLEAR struct member data. TestStand will discard the handle.
	//	CLEAR(expressionData->expression, CA_DiscardObjHandle);
	
	tsErrChk(TS_EngineNewExpression(expressionData->engine, &errorInfo, &expression));
	expressionData->expression = expression;
	
	tsErrChk(TS_ExpressionSetText(expression, &errorInfo, expressionData->expressionText));

Error:
	return error;
}

// This function tests:
// 1) Receiving object (engine) created in TestStand passed via struct parameter by value.
int __declspec(dllexport) NewExpressionStructVal(ExpressionData expressionData, const char *expressionText, ErrMsg errMsg, TSObj_Expression *expression)
{
	int         error = 0;
	ERRORINFO   errorInfo;
  	CLEAR(*expression, CA_DiscardObjHandle);

	tsErrChk(TS_EngineNewExpression(expressionData.engine, &errorInfo, expression));
 	tsErrChk(TS_ExpressionSetText(*expression, &errorInfo, expressionText));

Error:
	return error;
}

// This function tests:
// 1) pass back 1D array of objects (expressions) created in CVI.
int __declspec(dllexport) NewExpressions(CAObjHandle engine, const char *expressionText, int arraySize, ErrMsg errMsg, CAObjHandle expressionArray[])
{
	int         error = 0;
	ERRORINFO   errorInfo;
	int i;

	for (i = 0; i < arraySize; i++)
	{
		// DO NOT CLEAR array element data. TestStand will discard the handles.
		// CLEAR(expressionArray[i], CA_DiscardObjHandle);

		TSObj_Expression expression;
		tsErrChk(TS_EngineNewExpression(engine, &errorInfo, &expression));
		tsErrChk(TS_ExpressionSetText(expression, &errorInfo, expressionText));
		expressionArray[i] = expression;
	}

Error:
	return error;
}

// This function tests:
// 1) passing object (sequence context) created by TestStand passed via standard prototype
void __declspec(dllexport) TX_TEST StandardPrototype(tTestData *testData, tTestError *testError)
{
	int         error = 0;
	ERRORINFO   errorInfo;
	ErrMsg 		errMsg = {'\0'};
	TSObj_Step	step = 0;
	char *		stepName = NULL;
	
	tsErrChk(TS_SeqContextGetStep(testData->seqContextCVI, &errorInfo, &step));
	
	tsErrChk(TS_StepGetName(step, &errorInfo, &stepName));
	testData->replaceStringFuncPtr(&testData->stringMeasurement, stepName);

Error:
	if (step)
		CA_DiscardObjHandle(step);
	if (stepName)
		CA_FreeMemory(stepName);

}

