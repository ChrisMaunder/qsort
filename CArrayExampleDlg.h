// CArrayExampleDlg.h : header file
//

#if !defined(AFX_CARRAYEXAMPLEDLG_H__0F49BDE6_C91A_11D3_A4A8_444553540000__INCLUDED_)
#define AFX_CARRAYEXAMPLEDLG_H__0F49BDE6_C91A_11D3_A4A8_444553540000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

/////////////////////////////////////////////////////////////////////////////
// CCArrayExampleDlg dialog

#include "Afxtempl.h"
#include "ArrayClass.h"

class CCArrayExampleDlg : public CDialog
{
// Construction
public:
	CCArrayExampleDlg(CWnd* pParent = NULL);	// standard constructor

	typedef CArray<CArrayClass, CArrayClass&> Type_aCArrayClass;

	Type_aCArrayClass m_aCArrayClass;

	static int SortTheArray(void* p1,void* p2);
	void CopyTheArrayToTheListBox();

// Dialog Data
	//{{AFX_DATA(CCArrayExampleDlg)
	enum { IDD = IDD_CARRAYEXAMPLE_DIALOG };
	CStatic	m_lblSortTime;
	CListBox	m_lstList;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCArrayExampleDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCArrayExampleDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnLoad();
	afx_msg void OnSort();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CARRAYEXAMPLEDLG_H__0F49BDE6_C91A_11D3_A4A8_444553540000__INCLUDED_)
