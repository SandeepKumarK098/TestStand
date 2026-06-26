// CSquareObj.h : Declaration of the CCSquareObj

#ifndef __CSQUAREOBJ_H_
#define __CSQUAREOBJ_H_

#include "resource.h"       // main symbols
#include "CObjDlg.h"

/////////////////////////////////////////////////////////////////////////////
// CCSquareObj
class ATL_NO_VTABLE CCSquareObj : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CCSquareObj, &CLSID_CSquareObj>,
	public IDispatchImpl<ICSquareObj, &IID_ICSquareObj, &LIBID_BASICSERVERLib>
{
public:
	CCSquareObj();
	~CCSquareObj();

DECLARE_REGISTRY_RESOURCEID(IDR_CSQUAREOBJ)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CCSquareObj)
	COM_INTERFACE_ENTRY(ICSquareObj)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// ICSquareObj
public:
	STDMETHOD(getCaption)(/*[in,out]*/ BSTR* caption);
	STDMETHOD(setCaption)(BSTR caption);
	STDMETHOD(enableFillColor)(BOOL enable);

private:
	CCObjDlg * m_pDlg;
};

#endif //__CSQUAREOBJ_H_
