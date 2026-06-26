// Utils.h
#ifndef HEADER_Utils_h
#define HEADER_Utils_h

#include <toolbox.h>
#include <cviauto.h>

void DoSystemProcessing(void);
int GetParentDirectory(char *path, char parentDir[]);

int ExecuteCommand(char *path, char *args, char *workingDir, DWORD *exitCode);


#endif // HEADER_Utils_h
