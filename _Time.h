#if !defined(AFX__TIME_H__F5EE7850_4EC0_430E_924C_3DE297F363B7__INCLUDED_)
#define AFX__TIME_H__F5EE7850_4EC0_430E_924C_3DE297F363B7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// _Time.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// C_Time dialog

class C_Time : public CDialog
{
// Construction
public:
	C_Time(CWnd* pParent = NULL);   // standard constructor
	double Convert(int r1,int r2,double x);
	int r1;
	int r2;
	bool selectTE;
	bool selectDE;
// Dialog Data
	//{{AFX_DATA(C_Time)
	enum { IDD = IDD_Time };
	CEdit	m_DEdit;
	CEdit	m_TEdit;
	double	m_TE;
	double	m_DE;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(C_Time)
	public:
	virtual int DoModal();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(C_Time)
	afx_msg void OnChangeLDownEdit();
	afx_msg void OnChangeLTopEdit();
	afx_msg void OnSetfocusLDownEdit();
	afx_msg void OnSetfocusLTopEdit();
	afx_msg void OnSelchangeLTopCombo();
	afx_msg void OnSelchangeLDownCombo();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX__TIME_H__F5EE7850_4EC0_430E_924C_3DE297F363B7__INCLUDED_)
