#if !defined(AFX_DW_TRANSFORM_H__8539DCC7_6E72_4551_890A_144D920CA02A__INCLUDED_)
#define AFX_DW_TRANSFORM_H__8539DCC7_6E72_4551_890A_144D920CA02A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dw_Transform.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Dw_Transform dialog

class Dw_Transform : public CDialog
{
// Construction
public:
	Dw_Transform(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Dw_Transform)
	enum { IDD = IDD_Dw_Transform };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Dw_Transform)
	public:
	virtual int DoModal();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Dw_Transform)
	afx_msg void OnDWBLength();
	afx_msg void OnDWBArea();
	afx_msg void OnDWBVolum();
	afx_msg void OnDWBWeight();
	afx_msg void OnDWBTime();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DW_TRANSFORM_H__8539DCC7_6E72_4551_890A_144D920CA02A__INCLUDED_)
