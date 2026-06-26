#include "stdtst.h"
#include "tsutil.h"

long __declspec(dllexport) Test1DArrays(char arg1[100],  short arg2[100],  long arg3[100],  float arg4[100],  double arg5[100])
{
    int error = 0;
	int i;
	long passed = 1;
	
	
	for (i = 0; i < 100; i++) {
		if (arg1[i] != i
			|| arg2[i] != 10*i
			|| arg3[i] != 100*i
			|| arg4[i] != 10.5 * i
			|| arg5[i] != 123.123 * i) {
			
			passed = 0;
			break;
		}
	}
Error:  
    // FREE RESOURCES
    // if (lastUserName != NULL)
    //     CA_FreeMemory(lastUserName);

    // If an error occurred, set the error flag to cause a run-time error in TestStand.
    if (error < 0)
        {
        }
    
    return passed;    
}

long __declspec(dllexport) Test2DArrays(char arg1[100][100],  short arg2[100][100],  long arg3[100][100],  float arg4[100][100],  double arg5[100][100])
{
    int error = 0;
 	int i,j;

	long passed = 1;
	
	for (i = 0; i < 100; i++) {
		for (j = 0; j < 100; j++) {
		
			if (arg1[i][j] != j
				|| arg2[i][j] != 100*i + j
				|| arg3[i][j] != 1000*i + 10*j
				|| arg4[i][j] != 10.5 * j
				|| arg5[i][j] != 123.123 * j) {
			
				passed = 0;
				goto Error;
			}
		}
	}
	
Error:  
    // FREE RESOURCES
    // if (lastUserName != NULL)
    //     CA_FreeMemory(lastUserName);

    // If an error occurred, set the error flag to cause a run-time error in TestStand.
    if (error < 0)
        {
    
        // OPTIONALLY SET THE ERROR CODE AND STRING
        // *errorCode = error;
        // strcpy(errorMsg, errMsg);
        }
    
    return passed;    
}
