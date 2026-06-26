// CObjDlg.h : Declaration of the CCObjDlg

#ifndef __CObjDLG_H_
#define __CObjDLG_H_

#include "resource.h"       // main symbols
#include <atlhost.h>

const _CIRCLE_ = 0;
const _SQUARE_ = 1;

/////////////////////////////////////////////////////////////////////////////
// CCObjDlg
class CCObjDlg : 
	public CAxDialogImpl<CCObjDlg>
{
public:
	CCObjDlg(short p_Figure) :
	  m_bFillColor(false)
	{
		m_NumObjects++;
		m_Figure = p_Figure;
	}

	~CCObjDlg()
	{
		m_NumObjects--;
	}

	enum { IDD = IDD_COBJDLG };

BEGIN_MSG_MAP(CCObjDlg)
	MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
END_MSG_MAP()
// Handler prototypes:
//  LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
//  LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
//  LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);

	LRESULT OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		RECT windowRect;
		long x, y, dx, dy;

		y = (m_NumObjects-1) / 12;
		x = (m_NumObjects-1) % 12;

		GetWindowRect (&windowRect);
		dx = windowRect.right - windowRect.left+25;
		dy = windowRect.bottom - windowRect.top;
		windowRect.left = x * dx;
		windowRect.right = windowRect.left + dy;
		windowRect.top = y * dx;
		windowRect.bottom = windowRect.top + dy;

		SetWindowPos (HWND_TOPMOST, &windowRect,SWP_SHOWWINDOW);

		Draw ();

		return 1;  // Let the system set the focus
	}

	void Draw ()
	{
		HDC l_wDC;
		double red = (rand()*255.0)/RAND_MAX;
		double green = (rand()*255.0)/RAND_MAX;
		double blue = (rand()*255.0)/RAND_MAX;
		HBRUSH localBrush = CreateSolidBrush (RGB(red, green,blue));
		HGDIOBJ currentBrush;

		l_wDC = GetDC ();
		if (l_wDC)
		{
			currentBrush = SelectObject (l_wDC, localBrush);
			switch (m_Figure)
			{
				case _CIRCLE_:
					Ellipse (l_wDC, 15,15,60,60);
					break;
				case _SQUARE_:
					Rectangle (l_wDC, 15,15,60,60);
					break;
			}
			SelectObject (l_wDC, currentBrush);
			DeleteObject (localBrush);
			ReleaseDC (l_wDC);	
		}
	}

	void enableFillColor (bool p_bFillColor)
	{
		m_bFillColor = p_bFillColor;
		Draw ();
	}

	void SetCaption (LPSTR strText)
	{
		SetDlgItemText (IDC_LBL_OBJ, strText);
	}

	void GetCaption (LPSTR strText)	
	{
		GetDlgItemText (IDC_LBL_OBJ, strText, 100);
		strcat (strText,"OK");
	}

protected:
	bool  m_bFillColor;
	short m_Figure;

	static long m_NumObjects;
};

#endif //__CObjDLG_H_


