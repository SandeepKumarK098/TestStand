// CircleObj.h : Declaration of the CCircleObj

#ifndef __CIRCLEOBJ_H_
#define __CIRCLEOBJ_H_

#include "resource.h"       // main symbols
#include "CObjDlg.h"

/////////////////////////////////////////////////////////////////////////////
// CCircleObj
class ATL_NO_VTABLE CCircleObj : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CCircleObj, &CLSID_CircleObj>,
	public IDispatchImpl<ICircleObj, &IID_ICircleObj, &LIBID_BASICSERVERLib>
{
public:
	CCircleObj();
	~CCircleObj();

DECLARE_REGISTRY_RESOURCEID(IDR_CIRCLEOBJ)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CCircleObj)
	COM_INTERFACE_ENTRY(ICircleObj)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// ICircleObj
public:
	STDMETHOD(getCaption)(/*[in,out]*/ BSTR* caption);
	STDMETHOD(setCaption)(BSTR caption);
	STDMETHOD(enableFillColor)(BOOL enable);

private:
	CCObjDlg * m_pDlg;
};

#endif //__CIRCLEOBJ_H_
