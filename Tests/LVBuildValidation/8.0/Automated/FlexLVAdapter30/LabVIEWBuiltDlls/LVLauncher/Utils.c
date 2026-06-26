#include "Windows.h"
#include "WinDef.h"
#include "WinBase.h"
#include "Utils.h"
#include <utility.h>


////////////////////////////////////////////////////////////

void DoSystemProcessing(void)
{
    int i;
    ProcessSystemEvents();
}


////////////////////////////////////////////////////////////

int GetParentDirectory(char *path, char parentDir[])
{
    int error = 0;
    
    char drive[MAX_DRIVENAME_LEN], dir[MAX_DIRNAME_LEN];
    
    // Parse file path.
    SplitPath (path, drive, dir, NULL);
    
    // Concatenate path elements.
    strcpy (parentDir, drive);
    strcat (parentDir, dir);
    
    if (parentDir[0] != '\0')
        parentDir[strlen(parentDir) - 1] = '\0';    // Remove last slash.
        
Error:
    return error;
}


////////////////////////////////////////////////////////////

struct SecurityStruct
{
    SECURITY_ATTRIBUTES attributes;
    SECURITY_DESCRIPTOR descriptor;
};

void InitializeSecurityStruct(struct SecurityStruct *security)
{
    int         error = 0;
    int         success = FALSE;

    // Initialize security attributes structure.
    security->attributes.nLength = sizeof (SECURITY_ATTRIBUTES);
    security->attributes.bInheritHandle = TRUE;
    
    // Initialize security descriptor.  
    security->attributes.lpSecurityDescriptor = &security->descriptor;
 
    success = InitializeSecurityDescriptor(&security->descriptor, SECURITY_DESCRIPTOR_REVISION);
    if (!success)
        errChk(-1);
 
    // Add an ACL to the security descriptor. 
    success = SetSecurityDescriptorDacl(&security->descriptor, 
							            TRUE,     // fDaclPresent flag   
							            NULL,   // Allow all access
							            FALSE);   // not a default DACL 
    if (!success)
        errChk(-1);

Error:
    return;
}

////////////////////////////////////////////////////////////

int ExecuteCommand(char *path, char *args, char *workingDir, DWORD *exitCode)
{
    int         error = 0;
    int         success;
    char        cmdLine[MAX_PATHNAME_LEN];
    char        parentDir[MAX_PATHNAME_LEN];
    STARTUPINFO startInfo;
    PROCESS_INFORMATION procInfo;
    struct SecurityStruct inputFileSecurity, outputFileSecurity, logFileSecurity;
    struct SecurityStruct procSecurity, threadSecurity, pipeSecurity;

    InitializeSecurityStruct(&inputFileSecurity);
    InitializeSecurityStruct(&outputFileSecurity);
    InitializeSecurityStruct(&logFileSecurity);
    InitializeSecurityStruct(&procSecurity);
    InitializeSecurityStruct(&threadSecurity);
    InitializeSecurityStruct(&pipeSecurity);
    
    SetErrorMode(SEM_FAILCRITICALERRORS);

    // Initialize parameters.
    startInfo.cb = sizeof(STARTUPINFO);
    startInfo.lpReserved = 0;
    startInfo.lpDesktop = 0;
    startInfo.lpTitle = 0;
    startInfo.dwX = 0;
    startInfo.dwY = 0;
    startInfo.dwXSize = 0;
    startInfo.dwYSize = 0;
    startInfo.dwXCountChars = 0;
    startInfo.dwYCountChars = 0;
    startInfo.dwFillAttribute = 0;
    startInfo.dwFlags = 0;
    startInfo.wShowWindow = 0;
    startInfo.cbReserved2 = 0;
    startInfo.lpReserved2 = 0;
    startInfo.hStdInput = 0;
    startInfo.hStdOutput = 0;
    startInfo.hStdError = 0;
    
    procInfo.hProcess = 0;
    procInfo.hThread = 0;
    procInfo.dwProcessId = 0;
    procInfo.dwThreadId = 0;

    // Generate command line string.
    sprintf(cmdLine, "\"%s\" %s", path, args);

    if (!workingDir)
    {
        errChk( GetParentDirectory(path, parentDir));
        if (parentDir[0] != '\0')
            workingDir = parentDir;
        else
            workingDir = NULL;
    }

    success = CreateProcess(NULL, cmdLine, &procSecurity.attributes, &threadSecurity.attributes, TRUE, /*CREATE_NO_WINDOW | */CREATE_NEW_CONSOLE | NORMAL_PRIORITY_CLASS,
                            NULL, workingDir, &startInfo, &procInfo);

    if (!success)
    {
        error = GetLastError();
        if (error >= 0)
            error = -1;
    }
        
    DoSystemProcessing();

    if (!success)
    {
        errChk(error);
    }

    if (procInfo.hProcess == 0)
        goto Error;

	// Wait for LabVIEW to finish launching
    do
    {
        DoSystemProcessing();
        
        success = GetExitCodeProcess(procInfo.hProcess, exitCode);
        if (!success)
        {
            error = GetLastError();
            if (error >= 0)
                error = -1;
            errChk(error);
        }
    }
    while (*exitCode == STILL_ACTIVE);
    
Error:

    if (procInfo.hProcess != 0)
        CloseHandle(procInfo.hProcess);
    if (procInfo.hThread != 0)
        CloseHandle(procInfo.hThread);

    return error;
}
