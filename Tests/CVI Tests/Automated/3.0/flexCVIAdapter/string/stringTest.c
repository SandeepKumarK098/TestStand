#include <utility.h>
#include <ansi_c.h>
#include "stdtst.h"

void exchangeCharacters (char *Str)
{
	//-----------------------------------------------------------------------------
	// This function exchanges the last and first character
	//-----------------------------------------------------------------------------
	int l = strlen (Str);
	if (l >= 2)
	{
		char keep;
		
		keep = Str[l-1];
		Str[l-1] = Str[0];
		Str[0] = keep;
	}
}

//*********************************************************************
//*
//*                   STRING TEST FOR ALL DATA TYPES
//*
//*********************************************************************

//---------------------------------------------------------------------------------

void __declspec(dllexport) __stdcall CStringConst (const char *strValue)
{
	DebugPrintf ("stringTest - CStringConst - Value ('%s')\n", strValue);
    return;    
}

//---------------------------------------------------------------------------------

void __declspec(dllexport) __stdcall UnicodeStringConst (const wchar_t *strValue)
{
	//-----------------------------------------------------------------------------
	// Do nothing, CVI currently does not support Unicode
	//-----------------------------------------------------------------------------
	DebugPrintf ("stringTest - UnicodeStringConst - Not yet supported\n");	
    return;    
}

//---------------------------------------------------------------------------------

void __declspec(dllexport) __stdcall CStringBuffer (char strValue[5])
{
	DebugPrintf ("stringTest - CStringBuffer - Before ('%s')\n", strValue);
	exchangeCharacters (strValue);
	DebugPrintf ("stringTest - CStringBuffer - After  ('%s')\n", strValue);	
    return;    
}

//---------------------------------------------------------------------------------

void __declspec(dllexport) __stdcall CStringBufferUndefinedSize (char strValue[])
{
	DebugPrintf ("stringTest - CStringBufferUndefinedSize - Before ('%s')\n", strValue);
	exchangeCharacters (strValue);
	DebugPrintf ("stringTest - CStringBufferUndefinedSize - After  ('%s')\n", strValue);	
    return;    
}

//---------------------------------------------------------------------------------

void __declspec(dllexport) __stdcall UnicodeStringBuffer (wchar_t strValue[5])
{
	//-----------------------------------------------------------------------------
	// Do nothing, CVI currently does not support Unicode
	//-----------------------------------------------------------------------------
	DebugPrintf ("stringTest - UnicodeStringBuffer - Not yet supported\n");
    return;    
}

//---------------------------------------------------------------------------------

void __declspec(dllexport) __stdcall UnicodeStringBufferUndefinedSize (wchar_t strValue[])
{
	//-----------------------------------------------------------------------------
	// Do nothing, CVI currently does not support Unicode
	//-----------------------------------------------------------------------------
	DebugPrintf ("stringTest - UnicodeStringBufferUndefinedSize - Not yet supported\n");	
    return;    
}

//*********************************************************************
//*
//*       STRING SINGLE DIMENSION ARRAY TEST FOR ALL DATA TYPES
//*
//*********************************************************************

//---------------------------------------------------------------------------------

void __declspec(dllexport) __stdcall CStringConstSingleDimension(const char *array[3])
{
	DebugPrintf ("stringTest - CStringConstSingleDimension - array('%s','%s','%s')\n", 
		array[0], array[1], array[2]);	
    return;    
}

//---------------------------------------------------------------------------------

void __declspec(dllexport) __stdcall UnicodeStringConstSingleDimension(const wchar_t *array[3])
{
	//-----------------------------------------------------------------------------
	// Do nothing, CVI currently does not support Unicode
	//-----------------------------------------------------------------------------
	DebugPrintf ("stringTest - UnicodeStringConstSingleDimension - Not yet supported\n");	
    return;    
}

//---------------------------------------------------------------------------------

void __declspec(dllexport) __stdcall CStringBufferSingleDimension(char array[3][512])
{
	char buffer[512];

	DebugPrintf ("stringTest - CStringBufferSingleDimension - array('%s','%s','%s')\n", 
		array[0], array[1], array[2]);	
	strcpy (buffer, array[2]);
	strcpy (array[2], array[0]);
	strcpy (array[0], buffer);
	DebugPrintf ("stringTest - CStringBufferSingleDimension - array('%s','%s','%s')\n", 
		array[0], array[1], array[2]);	
}

//---------------------------------------------------------------------------------

void __declspec(dllexport) __stdcall UnicodeStringBufferSingleDimension(wchar_t array[3][512])
{
	//-----------------------------------------------------------------------------
	// Do nothing, CVI currently does not support Unicode
	//-----------------------------------------------------------------------------
	DebugPrintf ("stringTest - UnicodeStringBufferSingleDimension - Not yet supported\n");	
    return;    
}

//*********************************************************************
//*
//*       STRING MULTIPLE DIMENSION ARRAY TEST FOR ALL DATA TYPES
//*
//*********************************************************************

//---------------------------------------------------------------------------------

void __declspec(dllexport) __stdcall CStringConstMultipleDimension
	(const char *array[2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2])
{
	DebugPrintf ("stringTest - CStringConstMultipleDimension - values('%s','%s')\n", 
		array[0][0][0][0][0][0][0][0][1][1][1][1][1][1][1][1], array[1][1][1][1][1][1][1][1][0][0][0][0][0][0][0][0]);	
    return;    
}

//---------------------------------------------------------------------------------

void __declspec(dllexport) __stdcall UnicodeStringConstMultipleDimension
	(const wchar_t *array[2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2])
{
	//-----------------------------------------------------------------------------
	// Do nothing, CVI currently does not support Unicode
	//-----------------------------------------------------------------------------
	DebugPrintf ("stringTest - UnicodeStringConstMultipleDimension - Not yet supported\n");	
    return;    
}

//---------------------------------------------------------------------------------

void __declspec(dllexport) __stdcall CStringBufferMultipleDimension
	(char array[2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][512])
{
	char buffer[512];

	DebugPrintf ("stringTest - CStringBufferMultipleDimension - values('%s','%s')\n", 
		array[0][0][0][0][0][0][0][0][1][1][1][1][1][1][1][1], array[1][1][1][1][1][1][1][1][0][0][0][0][0][0][0][0]);	
	strcpy (buffer, array[1][1][1][1][1][1][1][1][0][0][0][0][0][0][0][0]);
	strcpy (array[1][1][1][1][1][1][1][1][0][0][0][0][0][0][0][0], array[0][0][0][0][0][0][0][0][1][1][1][1][1][1][1][1]);
	strcpy (array[0][0][0][0][0][0][0][0][1][1][1][1][1][1][1][1], buffer);
	DebugPrintf ("stringTest - CStringBufferMultipleDimension - values('%s','%s')\n", 
		array[0][0][0][0][0][0][0][0][1][1][1][1][1][1][1][1], array[1][1][1][1][1][1][1][1][0][0][0][0][0][0][0][0]);	
}

//---------------------------------------------------------------------------------

void __declspec(dllexport) __stdcall UnicodeStringBufferMultipleDimension
	(wchar_t array[2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][512])
{
	//-----------------------------------------------------------------------------
	// Do nothing, CVI currently does not support Unicode
	//-----------------------------------------------------------------------------
	DebugPrintf ("stringTest - UnicodeStringBufferMultipleDimension - Not yet supported\n");	
    return;    
}


