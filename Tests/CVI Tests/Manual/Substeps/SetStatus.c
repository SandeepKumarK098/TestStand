#include "tsutil.h"
#include "stdtst.h"
#include <analysis.h>

    // This function can be used to set the status of a step.
    // In the default step types, the status is set in the Status Expression at runtime.
void TX_TEST DLLEXPORT SetStatus(tTestData *data,tTestError *testError)    
{
    double          mean;
    double          rmsValue;
    int             error = 0;
    ErrMsg          errMsg = {'\0'};
    ERRORINFO       errorInfo;
    double          highLimit;
    double          lowLimit;
    char            status[512];
    VARIANT         tmpVariant;
    double *        waveform = NULL;
    size_t		    numElements;
    int             i;
    
        // Get high and low limits. 
    tsErrChk (TS_PropertyGetValNumber(data->seqContextCVI, &errorInfo, "Step.Limits.High", 0, &highLimit));
    tsErrChk (TS_PropertyGetValNumber(data->seqContextCVI, &errorInfo, "Step.Limits.Low" , 0, &lowLimit));
    
    tsErrChk (TS_PropertyGetValVariant(data->seqContextCVI, &errorInfo, "Step.Waveform", 0, &tmpVariant));
        
        // Convert the one-dimensional Safe Array passed in the Variant parameter   
        // into a dynamically allocated C-style array.  
    errChk (CA_VariantGet1DArray(&tmpVariant, CAVT_DOUBLE, &waveform, &numElements));
    
        // Determine RMS value = squareroot of the mean of the squares of waveform
    for (i=0; i<numElements; i++)
        waveform[i] = waveform[i] * waveform[i];
        
    errChk (Mean (waveform, numElements, &mean));
    
    rmsValue = sqrt (mean);
    
       // Set RMS Value in step.  This will be displayed in the report.
    tsErrChk (TS_PropertySetValNumber(data->seqContextCVI, &errorInfo, "Step.Result.RMSvalue" , 0, rmsValue));

        // Compare RMS value to limits
    strcpy(status, (rmsValue >= lowLimit && rmsValue < highLimit) ? "Passed" : "Failed");
    
        // Set status in step
    tsErrChk (TS_PropertySetValString(data->seqContextCVI, &errorInfo, "Step.Result.Status", 0, status));

Error:  
        // Free the allocated array 
    CA_FreeMemory(waveform);
    CA_VariantClear(&tmpVariant);

    // If an error occurred, set the error flag to cause a run-time error in TestStand.
    if (error < 0)
        TS_SetStepError (data->seqContextCVI, error, errMsg);
    return;    
}
