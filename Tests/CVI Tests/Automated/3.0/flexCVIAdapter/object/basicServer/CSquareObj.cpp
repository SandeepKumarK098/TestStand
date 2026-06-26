// CSquareObj.cpp : Implementation of CCSquareObj
#include "stdafx.h"
#include "BasicServer.h"
#include "CSquareObj.h"
#include <comdef.h>

/////////////////////////////////////////////////////////////////////////////
// CCSquareObj

CCSquareObj::CCSquareObj()
	: m_pDlg(0)
{
	m_pDlg = new CCObjDlg (_SQUARE_);
	m_pDlg->Create (NULL);

	m_pDlg->ShowWindow (SW_SHOWNORMAL);
}

CCSquareObj::~CCSquareObj()
{
	if (m_pDlg)
		m_pDlg->DestroyWindow ();

	delete m_pDlg;
}


STDMETHODIMP CCSquareObj::enableFillColor(BOOL enable)
{
	if (m_pDlg)
		m_pDlg->enableFillColor (enable == 1);

	return S_OK;
}

STDMETHODIMP CCSquareObj::setCaption(BSTR caption)
{
	_bstr_t strCaption (caption);
	if (m_pDlg)
		m_pDlg->SetCaption (strCaption);

	return S_OK;
}


STDMETHODIMP CCSquareObj::getCaption(BSTR* caption)
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
