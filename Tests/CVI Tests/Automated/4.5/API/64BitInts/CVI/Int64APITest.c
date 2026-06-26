#include <cviauto.h>	
#include "tsapicvi.h"


__declspec(dllexport) void SetValInteger64 (CAObjHandle obj, char * lookupString, int options, __int64 newValue)
{			
	TS_PropertySetValInteger64 (obj, NULL, lookupString, options, newValue);
}

__declspec(dllexport) __int64 GetValInteger64 (CAObjHandle obj, char * lookupString, int options)
{
	__int64 retVal;
	TS_PropertyGetValInteger64 (obj, NULL, lookupString, options, &retVal);
	return retVal;
}


__declspec(dllexport) void SetValInteger64ByOffset(CAObjHandle obj, int offset, int options, __int64 newValue)
{
	TS_PropertySetValInteger64ByOffset(obj, NULL, offset, options, newValue);
}
 
 __declspec(dllexport) __int64 GetValInteger64ByOffset(CAObjHandle obj, int offset, int options)
{
	__int64 retVal;     
	TS_PropertyGetValInteger64ByOffset(obj, NULL, offset, options, &retVal);
	return retVal;
}
 
 __declspec(dllexport) void SetValUnsignedInteger64 (CAObjHandle obj, char * lookupString, int options, unsigned __int64 newValue)
 {
	 TS_PropertySetValUnsignedInteger64 (obj, NULL, lookupString, options, newValue);
 }
 
__declspec(dllexport) unsigned __int64 GetValUnsignedInteger64 (CAObjHandle obj, char * lookupString, int options)
{
	unsigned __int64 retVal;
	TS_PropertyGetValUnsignedInteger64 (obj, NULL, lookupString, options, &retVal);
	return retVal;
}


__declspec(dllexport) void SetValUnsignedInteger64ByOffset(CAObjHandle obj, int offset, int options, unsigned __int64 newValue)
{
	TS_PropertySetValUnsignedInteger64ByOffset(obj, NULL, offset, options, newValue);
}
 
 __declspec(dllexport) unsigned __int64 GetValUnsignedInteger64ByOffset(CAObjHandle obj, int offset, int options)
{
	unsigned __int64 retVal;     
	TS_PropertyGetValUnsignedInteger64ByOffset(obj, NULL, offset, options, &retVal);
	return retVal;
}
 
 
#if _CVI_ > 900
 
 
 __declspec(dllexport) void CallSetValVariant(CAObjHandle obj, char * lookupString, int options, __int64 newValue)
{
	VARIANT variant;
	variant = CA_VariantLongLong (newValue);
	TS_PropertySetValVariant (obj, NULL, lookupString, options, variant);
	CA_VariantClear (&variant);
}
	 


  
 __declspec(dllexport) __int64 CallGetValVariant(CAObjHandle obj, char * lookupString, int options)
 {
	 VARIANT variant;
	 __int64 retVal;
	 TS_PropertyGetValVariant (obj, NULL, lookupString, options, &variant);
	 CA_VariantGetLongLong (&variant, &retVal);
	 	CA_VariantClear (&variant); 
	 return retVal;
 }
 
 
#else
 
__declspec(dllexport) void CallSetValVariant(CAObjHandle obj, char * lookupString, int options, __int64 newValue)
{	  
	TS_PropertySetValInteger64 (obj, NULL, lookupString, options, newValue);          
}
	 


  
 __declspec(dllexport) __int64 CallGetValVariant(CAObjHandle obj, char * lookupString, int options)
{
	__int64 retVal;
	TS_PropertyGetValInteger64 (obj, NULL, lookupString, options, &retVal);
	return retVal;
}



#endif
