#include "stdtst.h"
#include "tsutil.h"

void __declspec(dllexport) __stdcall TestLoadPrototype(int *result, int thirtyFive, const char *fred)
{
    int error = 0;
	
	*result = (strcmp(fred, "fred") == 0 && thirtyFive == 35) ? 1 : 0;
	
    

}
