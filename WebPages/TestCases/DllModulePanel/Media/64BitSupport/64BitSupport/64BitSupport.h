// 64BitSupport.h : main header file for the 64BitSupport DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMy64BitSupportApp
// See 64BitSupport.cpp for the implementation of this class
//

class CMy64BitSupportApp : public CWinApp
{
public:
	CMy64BitSupportApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
