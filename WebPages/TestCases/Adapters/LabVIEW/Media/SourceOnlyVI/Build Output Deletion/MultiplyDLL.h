#include "extcode.h"
#ifdef __cplusplus
extern "C" {
#endif

/*!
 * MultiplyVI
 */
double __cdecl MultiplyVI(double A, double B);

MgErr __cdecl LVDLLStatus(char *errStr, int errStrLen, void *module);

void __cdecl SetExecuteVIsInPrivateExecutionSystem(Bool32 value);

#ifdef __cplusplus
} // extern "C"
#endif

