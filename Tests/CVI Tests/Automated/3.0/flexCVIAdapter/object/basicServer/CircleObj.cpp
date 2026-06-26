// CircleObj.cpp : Implementation of CCircleObj
#include "stdafx.h"
#include "BasicServer.h"
#include "CircleObj.h"
#include <comdef.h>

/////////////////////////////////////////////////////////////////////////////
// CCircleObj

CCircleObj::CCircleObj()
	: m_pDlg(0)
{
	m_pDlg = new CCObjDlg (_CIRCLE_);
	m_pDlg->Create (NULL);

	m_pDlg->ShowWindow (SW_SHOWNORMAL);
}

CCircleObj::~CCircleObj()
{
	if (m_pDlg)
		m_pDlg->DestroyWindow ();

	delete m_pDlg;
}

STDMETHODIMP CCircleObj::enableFillColor(BOOL enable)
{
	if (m_pDlg)
		m_pDlg->enableFillColor (enable == 1);

	return S_OK;
}

STDMETHODIMP CCircleObj::setCaption(BSTR caption)
{
	_bstr_t strCaption (caption);
	if (m_pDlg)
		m_pDlg->SetCaption (strCaption);

	return S_OK;
}

STDMETHODIMP CCircleObj::getCaption(BSTR* caption)
{
	char txtCaption[100];

	_bstr_t strCaption (*caption);
	if (m_pDlg)
	{
		m_pDlg->GetCaption (txtCaption);
		strCaption = txtCaption;
		*caption = strCaption;
	}

	return S_OK;
}
