// 64BitSupportTL.h : main header file for the 64BitSupportTL DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMy64BitSupportTLApp
// See 64BitSupportTL.cpp for the implementation of this class
//

class CMy64BitSupportTLApp : public CWinApp
{
public:
	CMy64BitSupportTLApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
