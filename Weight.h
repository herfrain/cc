#if !defined(AFX_WEIGHT_H__DD247D20_4486_4B8A_A40C_9567D4E1E973__INCLUDED_)
#define AFX_WEIGHT_H__DD247D20_4486_4B8A_A40C_9567D4E1E973__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Weight.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CWeight dialog

class CWeight : public CDialog
{
// Construction
public:
	CWeight(CWnd* pParent = NULL);   // standard constructor
	double Convert(int r1,int r2,double x);
	int r1;
	int r2;
	bool selectTE;
	bool selectDE;
// Dialog Data
	//{{AFX_DATA(CWeight)
	enum { IDD = IDD_Weight };
	CEdit	m_DEdit;
	CEdit	m_TEdit;
	double	m_TE;
	double	m_DE;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWeight)
	public:
	virtual int DoModal();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CWeight)
	virtual BOOL OnInitDialog();
	afx_msg void OnChangeLDownEdit();
	afx_msg void OnSetfocusLDownEdit();
	afx_msg void OnChangeLTopEdit();
	afx_msg void OnSetfocusLTopEdit();
	afx_msg void OnSelchangeLDownCombo();
	afx_msg void OnSelchangeLTopCombo();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WEIGHT_H__DD247D20_4486_4B8A_A40C_9567D4E1E973__INCLUDED_)
