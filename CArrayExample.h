// CArrayExample.h : main header file for the CARRAYEXAMPLE application
//

#if !defined(AFX_CARRAYEXAMPLE_H__0F49BDE4_C91A_11D3_A4A8_444553540000__INCLUDED_)
#define AFX_CARRAYEXAMPLE_H__0F49BDE4_C91A_11D3_A4A8_444553540000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCArrayExampleApp:
// See CArrayExample.cpp for the implementation of this class
//

class CCArrayExampleApp : public CWinApp
{
public:
	CCArrayExampleApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCArrayExampleApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCArrayExampleApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CARRAYEXAMPLE_H__0F49BDE4_C91A_11D3_A4A8_444553540000__INCLUDED_)
