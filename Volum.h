#if !defined(AFX_VOLUM_H__8F75EE6A_97F4_48FC_8C19_1537D8742EE1__INCLUDED_)
#define AFX_VOLUM_H__8F75EE6A_97F4_48FC_8C19_1537D8742EE1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Volum.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CVolum dialog

class CVolum : public CDialog
{
// Construction
public:
	CVolum(CWnd* pParent = NULL);   // standard constructor
	double Convert(int r1,int r2,double x);
	int r1;
	int r2;
	bool selectTE;
	bool selectDE;
// Dialog Data
	//{{AFX_DATA(CVolum)
	enum { IDD = IDD_Volum };
	CEdit	m_DEdit;
	CEdit	m_TEdit;
	double	m_TE;
	double	m_DE;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVolum)
	public:
	virtual int DoModal();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CVolum)
	afx_msg void OnChangeLDownEdit();
	afx_msg void OnSetfocusLDownEdit();
	afx_msg void OnChangeLTopEdit();
	afx_msg void OnSetfocusLTopEdit();
	afx_msg void OnSelchangeLDownCombo();
	afx_msg void OnSelchangeLTopCombo();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VOLUM_H__8F75EE6A_97F4_48FC_8C19_1537D8742EE1__INCLUDED_)
