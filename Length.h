#if !defined(AFX_LENGTH_H__097DEC80_6EBA_4C48_8364_364C21E50B2C__INCLUDED_)
#define AFX_LENGTH_H__097DEC80_6EBA_4C48_8364_364C21E50B2C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Length.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLength dialog

class CLength : public CDialog
{
// Construction
public:
	CLength(CWnd* pParent = NULL);   // standard constructor
	double Convert(int r1,int r2,double x);
	int r1;
	int r2;
	bool selectTE;
	bool selectDE;
	/*bool selectTC;
	bool selectDC;*/
// Dialog Data
	//{{AFX_DATA(CLength)
	enum { IDD = IDD_Length };
	CEdit	m_TEdit;
	CEdit	m_DEdit;
	double	m_DE;
	double	m_TE;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLength)
	public:
	virtual int DoModal();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLength)
	afx_msg void OnSelchangeLTopCombo();
	afx_msg void OnSelchangeLDownCombo();
	afx_msg void OnChangeLTopEdit();
	afx_msg void OnChangeLDownEdit();
	afx_msg void OnUpdateLDownEdit();
	afx_msg void OnUpdateLTopEdit();
	afx_msg void OnSetfocusLDownEdit();
	afx_msg void OnSetfocusLTopEdit();
	afx_msg void OnKillfocusLDownEdit();
	afx_msg void OnKillfocusLTopEdit();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LENGTH_H__097DEC80_6EBA_4C48_8364_364C21E50B2C__INCLUDED_)
