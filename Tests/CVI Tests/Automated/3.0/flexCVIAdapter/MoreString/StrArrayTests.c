#include "stdtst.h"
#include "tsutil.h"

void __declspec(dllexport) Test1(char arg[100][1024])
{
	char buffer[1024];
	
	int i;
	for (i = 0; i < 10; i++) {
		strcpy(buffer, arg[i]);
		MessagePopup("array", buffer);
	}
	
}

void __declspec(dllexport) Test2(wchar_t arg[100][1024])
{
	char buffer[2048];
	
	int i;
	for (i = 0; i < 10; i++) {
		wcstombs(buffer, arg[i], 1024);
		MessagePopup("array", buffer);
	}
}

void __declspec(dllexport) Test2a(wchar_t arg[1024])
{
	char buffer[2048];
	
	wcstombs(buffer, arg, 1024);
	MessagePopup("array", buffer);
}


void __declspec(dllexport) Test3(char arg1[100][1024], wchar_t arg2[100][1024])
{
	char buffer2[2048];
	char buffer1[1024];
	
	int i;
	for (i = 0; i < 10; i++) {
		strcpy(buffer1, arg1[i]);
		wcstombs(buffer2, arg2[i], 1024);
		
		MessagePopup("array1", buffer1);
		MessagePopup("array2", buffer2);
	}
}

long __declspec(dllexport) Test1DStrArrays(const char *arg1[100],  const wchar_t *arg2[100],  char arg3[100][1024],  wchar_t arg4[100][1024])
{
    int error = 0;
	int passed = 1;
	int i;
	char arg1buffer[1024];
	char arg2buffer[1024];
	char arg3buffer[1024];
	char arg4buffer[1024];
	
	char arg2mb[2048];
	char arg4mb[2048];
	
	for (i = 0; i < 10; i++) {
		sprintf(arg1buffer, "%d", i);
		sprintf(arg2buffer, "%d", 10 * i);
		sprintf(arg3buffer, "%d", 100* i);
		sprintf(arg4buffer, "%d", 1000*i);
		
		wcstombs(arg2mb, arg2[i], 2048);
		wcstombs(arg4mb, arg4[i], 2048);
		
		if (strcmp(arg1buffer, arg1[i]) != 0) {
			passed = 0;
			break;
		}
		if (_mbscmp(arg2buffer, arg2mb) != 0) {
			passed = 0;
			break;
		}
		if (strcmp(arg3buffer, arg3[i]) != 0) {
			passed = 0;
			break;
		}
		if (_mbscmp(arg4buffer, arg4mb) != 0) {
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
    
        // OPTIONALLY SET THE ERROR CODE AND STRING
        // *errorCode = error;
        // strcpy(errorMsg, errMsg);
        }
    
    return passed;    
}

long __declspec(dllexport) Test2DStrArrays(const char *arg1[10][10],  const wchar_t *arg2[10][10],  char arg3[10][10][1024],  wchar_t arg4[10][10][1024])
{
    int error = 0;
	int passed = 1;
	int i, j;
	char arg1buffer[1024];
	char arg2buffer[1024];
	char arg3buffer[1024];
	char arg4buffer[1024];
	
	char arg2mb[2048];
	char arg4mb[2048];
	
	for (j = 0; j < 10; j++) {
	
		for (i = 0; i < 10; i++) {
			sprintf(arg1buffer, "%d", 10*j + i);
			sprintf(arg2buffer, "%d", 100*j + 10*i);
			sprintf(arg3buffer, "%d", 1000*j + 100*i);
			sprintf(arg4buffer, "%d", 10000*j + 1000*i);
		
			wcstombs(arg2mb, arg2[j][i], 2048);
			wcstombs(arg4mb, arg4[j][i], 2048);
		
			if (strcmp(arg1buffer, arg1[j][i]) != 0) {
				passed = 0;
				goto Error;
			}
			if (_mbscmp(arg2buffer, arg2mb) != 0) {
				passed = 0;
				goto Error;
			}
			if (strcmp(arg3buffer, arg3[j][i]) != 0) {
				passed = 0;
				goto Error;
			}
			if (_mbscmp(arg4buffer, arg4mb) != 0) {
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
        }
    
    return passed;    
}
