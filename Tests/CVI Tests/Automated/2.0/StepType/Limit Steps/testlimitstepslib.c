#include <cvirte.h>		/* Needed if linking in external compiler; harmless otherwise */
#include "tsutil.h" 

void _stdcall _export ReturnTrue (VBOOL *boolVal) 
{
	*boolVal = VTRUE;
}

void _stdcall _export ReturnFalse (VBOOL *boolVal) 
{
	*boolVal = VFALSE;
}

void _stdcall _export ReturnOne (int *intVal) 
{
	*intVal = 1;
}

void _stdcall _export ReturnZero (int *intVal) 
{
	*intVal = 0;
}

void _stdcall _export ReturnNegativeOne (int *intVal) 
{
	*intVal = -1;
}

void _stdcall _export ReturnFooString (char *charVal) 
{
	strcpy(charVal, "Foo");
}

void _stdcall _export ReturnfooString (char *charVal) 
{
	strcpy(charVal, "foo");
}

void _stdcall _export ReturnBarString (char *charVal) 
{
	strcpy(charVal, "Bar");
}
