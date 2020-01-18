#if !defined(AFX_HISTORY_H__5DFB664B_D990_4A10_9559_0AD11F25363F__INCLUDED_)
#define AFX_HISTORY_H__5DFB664B_D990_4A10_9559_0AD11F25363F__INCLUDED_


#include "CalculatorMdb.h"
#include <afxwin.h>

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// History.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CHistory dialog

class CHistory : public CDialog
{
// Construction
public:
	CHistory(CWnd* pParent = NULL);   // standard constructor
	void ChangeSize(CWnd *pWnd, int cx, int cy);
	CRect m_rect;
	void Display();
// Dialog Data
	//{{AFX_DATA(CHistory)
	enum { IDD = IDD_History };
	CListCtrl	m_list;
	CCalculatorMdb m_cal;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHistory)
	//public:
	virtual int DoModal();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CHistory)
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HISTORY_H__5DFB664B_D990_4A10_9559_0AD11F25363F__INCLUDED_)
