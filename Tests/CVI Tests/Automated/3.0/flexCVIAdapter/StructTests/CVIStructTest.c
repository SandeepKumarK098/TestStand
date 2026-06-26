#include "stdtst.h"
#include "tsutil.h"

struct StructType_5bytes {
	char chars[5];
};

void __declspec(dllexport) AddStruct5bytes(struct StructType_5bytes arg1,  struct StructType_5bytes arg2,  struct StructType_5bytes *arg3)
{
    int error = 0;

	int i;
	for (i = 0; i < 5; i++) {
		arg3->chars[i] = arg1.chars[i] + arg2.chars[i];
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

void __declspec(dllexport) AddStructPtr5bytes(struct StructType_5bytes *arg1,  struct StructType_5bytes *arg2,  struct StructType_5bytes *arg3)
{
    int error = 0;
    
	int i;
	for (i = 0; i < 5; i++) {
		arg3->chars[i] = arg1->chars[i] + arg2->chars[i];
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

void __declspec(dllexport) AddStructArray5bytes(struct StructType_5bytes arg1[1024],  struct StructType_5bytes arg2[1024],  struct StructType_5bytes arg3[1024])
{
    int error = 0;
 
 	int i;
 	int j;
 	for (j = 0; j < 10; j++) {
		for (i = 0; i < 5; i++) {
			arg3[j].chars[i] = arg1[j].chars[i] + arg2[j].chars[i];
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
    
    return;    
}

void __declspec(dllexport) AddStructArrayPtr5bytes(struct StructType_5bytes *arg1[1024],  struct StructType_5bytes *arg2[1024],  struct StructType_5bytes *arg3[1024])
{
    int error = 0;

 	int i;
 	int j;
 	for (j = 0; j < 10; j++) {
		for (i = 0; i < 5; i++) {
			arg3[j]->chars[i] = arg1[j]->chars[i] + arg2[j]->chars[i];
		}
	}

Error:  
    // FREE RESOURCES
    // if (lastUserName != NULL)
    //     CA_FreeMemory(lastUserName);

    // If an error occurred, set the error flag to cause a run-time error in TestStand.
    if (error < 0)
        {
        // strcpy(errorMsg, errMsg);
        }
    
    return;    
}

void __declspec(dllexport) AddStructArray2d5bytes(struct StructType_5bytes arg1[10][10],  struct StructType_5bytes arg2[10][10],  struct StructType_5bytes arg3[10][10])
{
    int error = 0;
    
 	int i;
 	int j;
 	int k;
 	for (k = 0; k < 10; k++) {
 		for (j = 0; j < 10; j++) {
			for (i = 0; i < 5; i++) {
				arg3[j][k].chars[i] = arg1[j][k].chars[i] + arg2[j][k].chars[i];
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
       }
    
    return;    
}

void __declspec(dllexport) AddStructArray2dPtr5bytes(struct StructType_5bytes *arg1[10][10],  struct StructType_5bytes *arg2[10][10],  struct StructType_5bytes *arg3[10][10])
{
    int error = 0;
 	int i;
 	int j;
 	int k;
 	for (k = 0; k < 10; k++) {
 		for (j = 0; j < 10; j++) {
			for (i = 0; i < 5; i++) {
				arg3[j][k]->chars[i] = arg1[j][k]->chars[i] + arg2[j][k]->chars[i];
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
      
        }
    
    return;    
}
