#include "stdtst.h"
#include "tsutil.h"
#include <utility.h>

#define VERIFY_HRESULT(_errorCode_, _errorText_)	\
	if (result<0)									\
	{												\
		error = _errorCode_;						\
		strcpy(errorMsg, _errorText_);				\
		goto Error;									\
	}												\

const GUID clsid_CircleServer = {0x08DB8E0C, 0xC1E4, 0x4072, 0x83, 0x80, 0x25, 0x78, 0x08, 0x9D, 0xA6, 0x2C};
const GUID clsid_SquareServer = {0x7813836B, 0x4718, 0x4EC9, 0x9C, 0x77, 0x13, 0x54, 0xF4, 0xFA, 0x7C, 0xB6};
const GUID iid_CircleObj 	  = {0xB874AEB3, 0x23DD, 0x41D3, 0xBD, 0xD4,0xEF, 0x7C, 0x6A, 0xE4, 0xE7, 0x05};
const GUID iid_SquareObj 	  = {0x1F1ACEC4, 0x7282, 0x4375, 0xAA, 0xFB,0x14, 0x1F, 0x42, 0xC5, 0x59, 0x35};

unsigned int parameterTypes[] = {CAVT_BYREF | CAVT_BSTR};

//*********************************************************************
//*
//*                   OBJECT TEST FOR ALL DATA TYPES
//*
//*********************************************************************

void __declspec(dllexport) __stdcall useObjectsByValue
	(struct IUnknown* unk, struct IDispatch* disp, CAObjHandle cviHandle,
	 short *errorOccurred, long *errorCode, char errorMsg[1024])
{
	CAObjHandle l_UnkCVIHandle = 0;
	CAObjHandle l_DispCVIHandle = 0;
	BSTR 	BSTRIUnknown;
	BSTR 	BSTRIDispatch;
	BSTR 	BSTRCVIHandle;
    int error = 0;	
    ERRORINFO errorInfo;	    
	HRESULT result;	
	
	result = CA_CStringToBSTR ("byValueIU", &BSTRIUnknown);
	VERIFY_HRESULT (-1, "Unable to generate BSTR for IUnknown");
	result = CA_CStringToBSTR ("byValueID", &BSTRIDispatch);
	VERIFY_HRESULT (-2, "Unable to generate BSTR for IDispatch");
	result = CA_CStringToBSTR ("byValueCVI", &BSTRCVIHandle);
	VERIFY_HRESULT (-3, "Unable to generate BSTR for CVIHandle");
	
	//---------------------------------------------------------------------------
	// Use IUnknown object
	//---------------------------------------------------------------------------
	result = CA_CreateObjHandleFromInterface (unk, &iid_CircleObj, 1, LOCALE_NEUTRAL, 0, 1, &l_UnkCVIHandle);
	VERIFY_HRESULT (-12, "Unable to create CVIHandle from IUnknown reference");		
	result = CA_MethodInvoke (l_UnkCVIHandle,&errorInfo, 2,CAVT_EMPTY,NULL,1,parameterTypes, &BSTRIUnknown);
	VERIFY_HRESULT (-6, "Unable to call method from IUnknown CVIHandle");		
	//---------------------------------------------------------------------------
	// Use IDispatch object
	//---------------------------------------------------------------------------
	result = CA_CreateObjHandleFromInterface (disp, &iid_CircleObj, 1, LOCALE_NEUTRAL, 0, 1, &l_DispCVIHandle);
	VERIFY_HRESULT (-13, "Unable to create CVIHandle from IDispatch reference");		
	result = CA_MethodInvoke (l_DispCVIHandle,&errorInfo, 2,CAVT_EMPTY,NULL,1,parameterTypes, &BSTRIDispatch);
	VERIFY_HRESULT (-9, "Unable to call method from IDispatch CVIHandle");		
	//---------------------------------------------------------------------------
	// Use CVIHandle object
	//---------------------------------------------------------------------------
	result = CA_MethodInvoke (cviHandle,&errorInfo, 2,CAVT_EMPTY,NULL,1,parameterTypes, &BSTRCVIHandle);
	VERIFY_HRESULT (-11, "Unable to call method from IDispatch CVIHandle");		

Error:  
    // FREE RESOURCES
	CA_DiscardObjHandle(l_UnkCVIHandle);
	CA_DiscardObjHandle(l_DispCVIHandle);  	
	CA_FreeBSTR (BSTRIUnknown);
	CA_FreeBSTR (BSTRIDispatch);
	CA_FreeBSTR (BSTRCVIHandle);

    // If an error occurred, set the error flag to cause a run-time error in TestStand.
    if (error < 0)
    {
        *errorOccurred = TRUE;
        *errorCode = error;
    }
    return;    
}

//-------------------------------------------------------------------------------------------

void __declspec(dllexport) __stdcall createObjects
	(struct IUnknown** unk, struct IDispatch** disp, CAObjHandle *cviHandle,
	 short *errorOccurred, long *errorCode, char errorMsg[1024])
{
	CAObjHandle l_UnkCVIHandle = 0;
	CAObjHandle l_DispCVIHandle = 0;
	BSTR 	BSTRIUnknown;
	BSTR 	BSTRIDispatch;
	BSTR 	BSTRCVIHandle;
    int error = 0;	
    ERRORINFO errorInfo;	    
	HRESULT result;	
	
	result = CA_CStringToBSTR ("createIU", &BSTRIUnknown);
	VERIFY_HRESULT (-1, "Unable to generate BSTR for IUnknown");
	result = CA_CStringToBSTR ("createID", &BSTRIDispatch);
	VERIFY_HRESULT (-2, "Unable to generate BSTR for IDispatch");
	result = CA_CStringToBSTR ("createCVI", &BSTRCVIHandle);
	VERIFY_HRESULT (-3, "Unable to generate BSTR for CVIHandle");
	
	//---------------------------------------------------------------------------
	// Create IUnknown object
	//---------------------------------------------------------------------------
	if (unk != NULL)
	{
		result = CA_CreateObjectByClassIdEx 
			(&clsid_CircleServer, NULL, &iid_CircleObj,0, LOCALE_NEUTRAL,0, &l_UnkCVIHandle);
		VERIFY_HRESULT (-4, "Unable to create CVIHandle for IUnknown object");		
		result = CA_GetInterfaceFromObjHandle (l_UnkCVIHandle, &IID_IUnknown, 1, unk, NULL);
		VERIFY_HRESULT (-5, "Unable to get IUnknown from CVIHandle");		
		result = CA_MethodInvoke (l_UnkCVIHandle,&errorInfo, 2,CAVT_EMPTY,NULL,1,parameterTypes, &BSTRIUnknown);
		VERIFY_HRESULT (-6, "Unable to call method from IUnknown CVIHandle");	
	}
	//---------------------------------------------------------------------------
	// Create IDispatch object
	//---------------------------------------------------------------------------
	if (disp != NULL)
	{
		result = CA_CreateObjectByClassIdEx 
			(&clsid_CircleServer, NULL, &iid_CircleObj,0, LOCALE_NEUTRAL,0, &l_DispCVIHandle);
		VERIFY_HRESULT (-7, "Unable to create CVIHandle for IDispatch object");		
		result = CA_GetInterfaceFromObjHandle (l_DispCVIHandle, &IID_IDispatch, 1, disp, NULL);
		VERIFY_HRESULT (-8, "Unable to get IDispatch from CVIHandle");		
		result = CA_MethodInvoke (l_DispCVIHandle,&errorInfo, 2,CAVT_EMPTY,NULL,1,parameterTypes, &BSTRIDispatch);
		VERIFY_HRESULT (-9, "Unable to call method from IDispatch CVIHandle");	
	}
	//---------------------------------------------------------------------------
	// Create CVIHandle object
	//---------------------------------------------------------------------------
	if (cviHandle != NULL)
	{
		result = CA_CreateObjectByClassIdEx 
			(&clsid_CircleServer, NULL, &iid_CircleObj,0, LOCALE_NEUTRAL,0, cviHandle);
		VERIFY_HRESULT (-10, "Unable to create CVIHandle for CVIHandle object");
		result = CA_MethodInvoke (*cviHandle,&errorInfo, 2,CAVT_EMPTY,NULL,1,parameterTypes, &BSTRCVIHandle);
		VERIFY_HRESULT (-11, "Unable to call method from IDispatch CVIHandle");		
	}

Error:  
    // FREE RESOURCES
	CA_DiscardObjHandle(l_UnkCVIHandle);
	CA_DiscardObjHandle(l_DispCVIHandle);  	
	CA_FreeBSTR (BSTRIUnknown);
	CA_FreeBSTR (BSTRIDispatch);
	CA_FreeBSTR (BSTRCVIHandle);

    // If an error occurred, set the error flag to cause a run-time error in TestStand.
    if (error < 0)
    {
        *errorOccurred = TRUE;
        *errorCode = error;
    }
    return;    
}

//-------------------------------------------------------------------------------------------

void __declspec(dllexport) __stdcall useObjectsByRef
	(struct IUnknown** unk, struct IDispatch** disp, CAObjHandle *cviHandle,
	 short *errorOccurred, long *errorCode, char errorMsg[1024])
{
	CAObjHandle l_UnkCVIHandle = 0;
	CAObjHandle l_DispCVIHandle = 0;
	BSTR 	BSTRIUnknown;
	BSTR 	BSTRIDispatch;
	BSTR 	BSTRCVIHandle;
    int error = 0;	
    ERRORINFO errorInfo;	    
	HRESULT result;	
	
	result = CA_CStringToBSTR ("byRefIU", &BSTRIUnknown);
	VERIFY_HRESULT (-1, "Unable to generate BSTR for IUnknown");
	result = CA_CStringToBSTR ("byRefID", &BSTRIDispatch);
	VERIFY_HRESULT (-2, "Unable to generate BSTR for IDispatch");
	result = CA_CStringToBSTR ("byRefCVI", &BSTRCVIHandle);
	VERIFY_HRESULT (-3, "Unable to generate BSTR for CVIHandle");
	
	//---------------------------------------------------------------------------
	// Use IUnknown object
	//---------------------------------------------------------------------------
	if ((unk != NULL) && (*unk != NULL))
	{
		result = CA_CreateObjHandleFromInterface (*unk, &iid_CircleObj, 1, LOCALE_NEUTRAL, 0, 1, &l_UnkCVIHandle);
		VERIFY_HRESULT (-12, "Unable to create CVIHandle from IUnknown reference");		
		result = CA_MethodInvoke (l_UnkCVIHandle,&errorInfo, 2,CAVT_EMPTY,NULL,1,parameterTypes, &BSTRIUnknown);
		VERIFY_HRESULT (-6, "Unable to call method from IUnknown CVIHandle");	
	}
	//---------------------------------------------------------------------------
	// Use IDispatch object
	//---------------------------------------------------------------------------
	if ((disp != NULL) && (*disp != NULL))
	{
		result = CA_CreateObjHandleFromInterface (*disp, &iid_CircleObj, 1, LOCALE_NEUTRAL, 0, 1, &l_DispCVIHandle);
		VERIFY_HRESULT (-13, "Unable to create CVIHandle from IDispatch reference");		
		result = CA_MethodInvoke (l_DispCVIHandle,&errorInfo, 2,CAVT_EMPTY,NULL,1,parameterTypes, &BSTRIDispatch);
		VERIFY_HRESULT (-9, "Unable to call method from IDispatch CVIHandle");	
	}
	//---------------------------------------------------------------------------
	// Use CVIHandle object
	//---------------------------------------------------------------------------
	if ((cviHandle != NULL) && (*cviHandle != 0))
	{
		result = CA_MethodInvoke (*cviHandle,&errorInfo, 2,CAVT_EMPTY,NULL,1,parameterTypes, &BSTRCVIHandle);
		VERIFY_HRESULT (-11, "Unable to call method from IDispatch CVIHandle");		
	}

Error:  
    // FREE RESOURCES
	CA_DiscardObjHandle(l_UnkCVIHandle);
	CA_DiscardObjHandle(l_DispCVIHandle);  	
	CA_FreeBSTR (BSTRIUnknown);
	CA_FreeBSTR (BSTRIDispatch);
	CA_FreeBSTR (BSTRCVIHandle);

    // If an error occurred, set the error flag to cause a run-time error in TestStand.
    if (error < 0)
    {
        *errorOccurred = TRUE;
        *errorCode = error;
    }
    return;    
}

//-------------------------------------------------------------------------------------------

void __declspec(dllexport) __stdcall deleteAndCreateObjects
	(struct IUnknown** unk, struct IDispatch** disp, CAObjHandle *cviHandle,
	 short *errorOccurred, long *errorCode, char errorMsg[1024])
{
	CAObjHandle l_UnkCVIHandle = 0;
	CAObjHandle l_DispCVIHandle = 0;
	BSTR 	BSTRIUnknown;
	BSTR 	BSTRIDispatch;
	BSTR 	BSTRCVIHandle;
    int error = 0;	
    ERRORINFO errorInfo;	    
	HRESULT result;	
	
	result = CA_CStringToBSTR ("delCreIU", &BSTRIUnknown);
	VERIFY_HRESULT (-1, "Unable to generate BSTR for IUnknown");
	result = CA_CStringToBSTR ("delCreID", &BSTRIDispatch);
	VERIFY_HRESULT (-2, "Unable to generate BSTR for IDispatch");
	result = CA_CStringToBSTR ("delCreCVI", &BSTRCVIHandle);
	VERIFY_HRESULT (-3, "Unable to generate BSTR for CVIHandle");
	
	//---------------------------------------------------------------------------
	// Release IUnknown object
	//---------------------------------------------------------------------------
	if ((unk != NULL) && (*unk != NULL))
		(*unk)->lpVtbl->Release (*unk);
	//---------------------------------------------------------------------------
	// Release IDispatch object
	//---------------------------------------------------------------------------
	if ((disp != NULL) && (*disp != NULL))
		(*disp)->lpVtbl->Release (*disp);
	//---------------------------------------------------------------------------
	// Release CVIObject object
	//---------------------------------------------------------------------------
	if ((cviHandle != NULL) && (*cviHandle != 0))
	{
		result = CA_DiscardObjHandle(*cviHandle);
		VERIFY_HRESULT (-14, "Unable to release CVIHandle");		
	}

	//---------------------------------------------------------------------------
	// Create IUnknown object
	//---------------------------------------------------------------------------
	if ((unk != NULL) && (*unk != NULL))
	{
		result = CA_CreateObjectByClassIdEx 
			(&clsid_SquareServer, NULL, &iid_SquareObj,0, LOCALE_NEUTRAL,0, &l_UnkCVIHandle);
		VERIFY_HRESULT (-4, "Unable to create CVIHandle for IUnknown object");		
		result = CA_GetInterfaceFromObjHandle (l_UnkCVIHandle, &IID_IUnknown, 1, unk, NULL);
		VERIFY_HRESULT (-5, "Unable to get IUnknown from CVIHandle");		
		result = CA_MethodInvoke (l_UnkCVIHandle,&errorInfo, 2,CAVT_EMPTY,NULL,1,parameterTypes, &BSTRIUnknown);
		VERIFY_HRESULT (-6, "Unable to call method from IUnknown CVIHandle");	
	}
	//---------------------------------------------------------------------------
	// Create IDispatch object
	//---------------------------------------------------------------------------
	if ((disp != NULL) && (*disp != NULL))
	{
		result = CA_CreateObjectByClassIdEx 
			(&clsid_SquareServer, NULL, &iid_SquareObj,0, LOCALE_NEUTRAL,0, &l_DispCVIHandle);
		VERIFY_HRESULT (-7, "Unable to create CVIHandle for IDispatch object");		
		result = CA_GetInterfaceFromObjHandle (l_DispCVIHandle, &IID_IDispatch, 1, disp, NULL);
		VERIFY_HRESULT (-8, "Unable to get IDispatch from CVIHandle");		
		result = CA_MethodInvoke (l_DispCVIHandle,&errorInfo, 2,CAVT_EMPTY,NULL,1,parameterTypes, &BSTRIDispatch);
		VERIFY_HRESULT (-9, "Unable to call method from IDispatch CVIHandle");	
	}
	//---------------------------------------------------------------------------
	// Create CVIHandle object
	//---------------------------------------------------------------------------
	if ((cviHandle != NULL) && (*cviHandle != 0))
	{
		result = CA_CreateObjectByClassIdEx 
			(&clsid_SquareServer, NULL, &iid_SquareObj,0, LOCALE_NEUTRAL,0, cviHandle);
		VERIFY_HRESULT (-10, "Unable to create CVIHandle for CVIHandle object");
		result = CA_MethodInvoke (*cviHandle,&errorInfo, 2,CAVT_EMPTY,NULL,1,parameterTypes, &BSTRCVIHandle);
		VERIFY_HRESULT (-11, "Unable to call method from IDispatch CVIHandle");		
	}
	
Error:  
    // FREE RESOURCES
	CA_DiscardObjHandle(l_UnkCVIHandle);
	CA_DiscardObjHandle(l_DispCVIHandle);  	
	CA_FreeBSTR (BSTRIUnknown);
	CA_FreeBSTR (BSTRIDispatch);
	CA_FreeBSTR (BSTRCVIHandle);

    // If an error occurred, set the error flag to cause a run-time error in TestStand.
    if (error < 0)
    {
        *errorOccurred = TRUE;
        *errorCode = error;
    }
    return;    
}

//-------------------------------------------------------------------------------------------

void __declspec(dllexport) __stdcall deleteObjects
	(struct IUnknown** unk, struct IDispatch** disp, CAObjHandle *cviHandle,
	 short *errorOccurred, long *errorCode, char errorMsg[1024])
{
    int error = 0;	
    ERRORINFO errorInfo;	    
	HRESULT result;	
	
	//---------------------------------------------------------------------------
	// Release IUnknown object
	//---------------------------------------------------------------------------
	if ((unk != NULL) && (*unk != NULL))
	{
		(*unk)->lpVtbl->Release (*unk);
		*unk = 0;
	}
	//---------------------------------------------------------------------------
	// Release IDispatch object
	//---------------------------------------------------------------------------
	if ((disp != NULL) && (*disp != NULL))
	{
		(*disp)->lpVtbl->Release (*disp);
		*disp = 0;
	}
	//---------------------------------------------------------------------------
	// Release CVIObject object
	//---------------------------------------------------------------------------
	if ((cviHandle != NULL) && (*cviHandle != 0))
	{
		result = CA_DiscardObjHandle(*cviHandle);
		VERIFY_HRESULT (-14, "Unable to release CVIHandle");
		*cviHandle = 0;	
	}
	
Error:  

    // If an error occurred, set the error flag to cause a run-time error in TestStand.
    if (error < 0)
    {
        *errorOccurred = TRUE;
        *errorCode = error;
    }
    return;    
}

//*********************************************************************
//*
//*        SINGLE DIMENSION ARRAY OBJECT TEST FOR ALL DATA TYPES
//*
//*********************************************************************

#define MAX_SINGLE_ARRAY_ELEMENTS 10

void __declspec(dllexport) __stdcall createObjectsSingleArray
	(struct IUnknown* unk[MAX_SINGLE_ARRAY_ELEMENTS], 
	 struct IDispatch* disp[MAX_SINGLE_ARRAY_ELEMENTS], 
	 CAObjHandle cviHandle[MAX_SINGLE_ARRAY_ELEMENTS],
	 short *errorOccurred, long *errorCode, char errorMsg[1024])
{
	int i;
	
	for (i = 0; i<MAX_SINGLE_ARRAY_ELEMENTS; i++)
	{
		createObjects (&unk[i], &disp[i], &cviHandle[i], errorOccurred, errorCode, errorMsg);
		if (*errorOccurred)
			return;
	}
	
	return;
}

//-------------------------------------------------------------------------------------------

void __declspec(dllexport) __stdcall useObjectsByRefSingleArray
	(struct IUnknown* unk[MAX_SINGLE_ARRAY_ELEMENTS], 
	 struct IDispatch* disp[MAX_SINGLE_ARRAY_ELEMENTS], 
	 CAObjHandle cviHandle[MAX_SINGLE_ARRAY_ELEMENTS],
	 short *errorOccurred, long *errorCode, char errorMsg[1024])
{
	int i;
	
	for (i = 0; i<MAX_SINGLE_ARRAY_ELEMENTS; i++)
	{
		useObjectsByRef (&unk[i], &disp[i], &cviHandle[i], errorOccurred, errorCode, errorMsg);
		if (*errorOccurred)
			return;
	}
	
	return;
}

//-------------------------------------------------------------------------------------------

void __declspec(dllexport) __stdcall deleteAndCreateObjectsSingleArray
	(struct IUnknown* unk[MAX_SINGLE_ARRAY_ELEMENTS], 
	 struct IDispatch* disp[MAX_SINGLE_ARRAY_ELEMENTS], 
	 CAObjHandle cviHandle[MAX_SINGLE_ARRAY_ELEMENTS],
	 short *errorOccurred, long *errorCode, char errorMsg[1024])
{
	int i;
	
	for (i = 0; i<MAX_SINGLE_ARRAY_ELEMENTS; i++)
	{
		deleteAndCreateObjects (&unk[i], &disp[i], &cviHandle[i], errorOccurred, errorCode, errorMsg);
		if (*errorOccurred)
			return;
	}
	
	return;
}

//-------------------------------------------------------------------------------------------

void __declspec(dllexport) __stdcall deleteObjectsSingleArray
	(struct IUnknown* unk[MAX_SINGLE_ARRAY_ELEMENTS], 
	 struct IDispatch* disp[MAX_SINGLE_ARRAY_ELEMENTS], 
	 CAObjHandle cviHandle[MAX_SINGLE_ARRAY_ELEMENTS],
	 short *errorOccurred, long *errorCode, char errorMsg[1024])
{
	int i;
	
	for (i = 0; i<MAX_SINGLE_ARRAY_ELEMENTS; i++)
	{
		deleteObjects (&unk[i], &disp[i], &cviHandle[i], errorOccurred, errorCode, errorMsg);
		if (*errorOccurred)
			return;
	}
	
	return;
}

//*********************************************************************
//*
//*       MULTIPLE DIMENSION ARRAY OBJECT TEST FOR ALL DATA TYPES
//*
//*********************************************************************

void __declspec(dllexport) __stdcall createObjectsMultiArray
	(struct IUnknown* unk[2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2], 
	 struct IDispatch* disp[2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2], 
	 CAObjHandle cviHandle[2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2],
	 short *errorOccurred, long *errorCode, char errorMsg[1024])
{
	createObjects (&unk[0][0][0][0][0][0][0][0][1][1][1][1][1][1][1][1], 
				   &disp[0][1][0][1][0][1][0][1][0][1][0][1][0][1][0][1], 
				   &cviHandle[1][1][1][1][1][1][1][1][0][0][0][0][0][0][0][0], 
				   errorOccurred, errorCode, errorMsg);
	return;
}

//-------------------------------------------------------------------------------------------

void __declspec(dllexport) __stdcall useObjectsByRefMultiArray
	(struct IUnknown* unk[2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2], 
	 struct IDispatch* disp[2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2], 
	 CAObjHandle cviHandle[2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2],
	 short *errorOccurred, long *errorCode, char errorMsg[1024])
{
	useObjectsByRef(&unk[0][0][0][0][0][0][0][0][1][1][1][1][1][1][1][1], 
				    &disp[0][1][0][1][0][1][0][1][0][1][0][1][0][1][0][1], 
				    &cviHandle[1][1][1][1][1][1][1][1][0][0][0][0][0][0][0][0], 
				    errorOccurred, errorCode, errorMsg);
	return;
}

//-------------------------------------------------------------------------------------------

void __declspec(dllexport) __stdcall deleteAndCreateObjectsMultiArray
	(struct IUnknown* unk[2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2], 
	 struct IDispatch* disp[2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2], 
	 CAObjHandle cviHandle[2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2],
	 short *errorOccurred, long *errorCode, char errorMsg[1024])
{
	deleteAndCreateObjects(&unk[0][0][0][0][0][0][0][0][1][1][1][1][1][1][1][1], 
				    	   &disp[0][1][0][1][0][1][0][1][0][1][0][1][0][1][0][1], 
				    	   &cviHandle[1][1][1][1][1][1][1][1][0][0][0][0][0][0][0][0], 
				    	   errorOccurred, errorCode, errorMsg);
	return;
}

//-------------------------------------------------------------------------------------------

void __declspec(dllexport) __stdcall deleteObjectsMultiArray
	(struct IUnknown* unk[2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2], 
	 struct IDispatch* disp[2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2], 
	 CAObjHandle cviHandle[2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2],
	 short *errorOccurred, long *errorCode, char errorMsg[1024])
{
	deleteObjects(&unk[0][0][0][0][0][0][0][0][1][1][1][1][1][1][1][1], 
				  &disp[0][1][0][1][0][1][0][1][0][1][0][1][0][1][0][1], 
				  &cviHandle[1][1][1][1][1][1][1][1][0][0][0][0][0][0][0][0], 
				  errorOccurred, errorCode, errorMsg);
	
	return;
}
