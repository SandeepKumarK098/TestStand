#include "stdtst.h"
#include "tsutil.h"

void __declspec(dllexport) __stdcall TestActionStructurePacking(tTestData *testData, tTestError *testError)
{
    int error = 0;
    testData->replaceStringFuncPtr(&testData->outBuffer, "testData->outBuffer");

Error:  
    return;    
}

void __declspec(dllexport) __stdcall TestActionStructurePackingChangeViaSeqContext(tTestData *testData, tTestError *testError)
{
    int error = 0;
    ErrMsg errMsg = {'\0'};
    ERRORINFO errorInfo;
    
    testData->replaceStringFuncPtr(&testData->outBuffer, "testData->outBuffer");
    tsErrChk (TS_PropertySetValString(testData->seqContextCVI, &errorInfo, "RunState.Step.Result.ReportText",
    								  0, "changed via sequence context"));

Error:  
    if (error < 0)
        {
        testError->errorFlag = TRUE;
        }
    
    return;    
}

int __declspec(dllexport) __stdcall TestActionStructurePackingPassParams(char *params, tTestData *testData, tTestError *testError)
{
    int retVal = TRUE;

    if (strcmp (params, "parameters") != 0)
        {
        retVal = FALSE;
        }
    
    return retVal;    
}

void __declspec(dllexport) __stdcall TestPassFailStructurePackingPass(tTestData *testData, tTestError *testError)
{
    int error = 0;
	testData->result = PASS;
    testData->replaceStringFuncPtr(&testData->outBuffer, "testData->outBuffer");

Error:  
    return;    
}

void __declspec(dllexport) __stdcall TestPassFailStructurePackingFail(tTestData *testData, tTestError *testError)
{
    int error = 0;
	testData->result = FAIL;
    testData->replaceStringFuncPtr(&testData->outBuffer, "testData->outBuffer");

Error:  
    return;    
}

void __declspec(dllexport) __stdcall TestNumLimStructurePacking(tTestData *testData, tTestError *testError)
{
    int error = 0;
    testData->replaceStringFuncPtr(&testData->outBuffer, "testData->outBuffer");
    testData->measurement = .08;
	
Error:  
    return;    
}

void __declspec(dllexport) __stdcall TestNumLimStructurePackingChangeViaSeqContext(tTestData *testData, tTestError *testError)
{
    int error = 0;
    ErrMsg errMsg = {'\0'};
    ERRORINFO errorInfo;
    
    testData->replaceStringFuncPtr(&testData->outBuffer, "testData->outBuffer");
    testData->measurement = .08;
    tsErrChk (TS_PropertySetValNumber(testData->seqContextCVI, &errorInfo, "RunState.Step.Result.Numeric",
    								  0, .39));

Error:  
    if (error < 0)
        {
        testError->errorFlag = TRUE;
        }
    
    return;    
}

void __declspec(dllexport) __stdcall TestStringValueStructurePacking(tTestData *testData, tTestError *testError)
{
    int error = 0;
    ErrMsg errMsg = {'\0'};
    ERRORINFO errorInfo;

    char *stringValue = "String value from test.";
    
    testData->replaceStringFuncPtr(&testData->outBuffer, "testData->outBuffer");
    tsNullChk (testData->replaceStringFuncPtr(&testData->stringMeasurement, stringValue));


Error:  
    // If an error occurred, set the error flag to cause a run-time error in TestStand.
    if (error < 0)
        {
        testError->errorFlag = TRUE;
        }
    
    return;    
}

void __declspec(dllexport) __stdcall TestStringValueStructurePackingChangeViaSeqContext(tTestData *testData, tTestError *testError)
{
    int error = 0;
    ErrMsg errMsg = {'\0'};
    ERRORINFO errorInfo;

    char *stringValue = "String value from test.";
    
    testData->replaceStringFuncPtr(&testData->outBuffer, "testData->outBuffer");
    tsNullChk (testData->replaceStringFuncPtr(&testData->stringMeasurement, stringValue));
    
    
	tsErrChk (TS_PropertySetValString(testData->seqContextCVI, &errorInfo, "Step.Result.String",
    								  0, "changed via sequence context"));


Error:  
    // If an error occurred, set the error flag to cause a run-time error in TestStand.
    if (error < 0)
        {
        testError->errorFlag = TRUE;
        }
    
    return;    
}

void __declspec(dllexport) __stdcall TestErrorMsgStructurePacking(tTestData *testData, tTestError *testError)
{
    int error = 0;

Error:  
    testData->replaceStringFuncPtr(&testError->errorMessage, "testError->errorMessage");
    return;    
}

void __declspec(dllexport) __stdcall TestErrorMsgStructurePackingChangeViaSeqContext(tTestData *testData, tTestError *testError)
{
    int error = 0;
    ErrMsg errMsg = {'\0'};
    ERRORINFO errorInfo;

	tsErrChk (TS_PropertySetValString(testData->seqContextCVI, &errorInfo, "Step.Result.Error.Msg",
    								  0, "changed via sequence context"));

    testData->replaceStringFuncPtr(&testError->errorMessage, "testError->errorMessage");

Error:  
    // If an error occurred, set the error flag to cause a run-time error in TestStand.
    if (error < 0)
        {
        testError->errorFlag = TRUE;
        }

    return;    
}

void __declspec(dllexport) __stdcall TestPlusErrorCodeStructurePacking(tTestData *testData, tTestError *testError)
{
    int error = 88;
    testError->errorCode = error;
   
    return;    
}

void __declspec(dllexport) __stdcall TestMinusErrorCodeStructurePacking(tTestData *testData, tTestError *testError)
{
    int error = -99;
    testError->errorCode = error;
   
    return;    
}

void __declspec(dllexport) __stdcall TestMinusErrorCodeStructurePackingChangeViaSeqContext(tTestData *testData, tTestError *testError)
{
    int error = -99;
    ErrMsg errMsg = {'\0'};
    ERRORINFO errorInfo;
    int errorOccurred = TRUE;
    
    testError->errorCode = error;

   	tsErrChk (TS_PropertySetValNumber(testData->seqContextCVI, &errorInfo, "Step.Result.Error.Code",
    								  0, -88.99));
    errorOccurred = FALSE;

Error:
    if (errorOccurred)
        {
        testError->errorFlag = TRUE;
        }

    return;    
}

void __declspec(dllexport) __stdcall TestErrorOccurredStructurePackingTrue(tTestData *testData, tTestError *testError)
{
    testError->errorFlag = TRUE;
    
    return;    
}

void __declspec(dllexport) __stdcall TestErrorOccurredStructurePackingTrueChangeViaSeqContext(tTestData *testData, tTestError *testError)
{
    int error = 0;
    ErrMsg errMsg = {'\0'};
    ERRORINFO errorInfo;
    int errorOccurred = TRUE;
    
   	tsErrChk (TS_PropertySetValBoolean(testData->seqContextCVI, &errorInfo, "Step.Result.Error.Occurred",
    								   0, FALSE));
    testError->errorFlag = TRUE;

Error:
    return;    
}

void __declspec(dllexport) __stdcall TestErrorOccurredStructurePackingFalse(tTestData *testData, tTestError *testError)
{
    testError->errorFlag = FALSE;
    
    return;    
}

void __declspec(dllexport) __stdcall DerefNULLPointer(tTestData *testData, tTestError *testError)
{
    int error = 0;
    char **explode = NULL;
    
    *explode = (char *)&DerefNULLPointer;
    
    return;    
}
