#if !defined(AFX_AREA_H__D0FB605A_58F9_44B7_9035_1004F620B02F__INCLUDED_)
#define AFX_AREA_H__D0FB605A_58F9_44B7_9035_1004F620B02F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Area.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CArea dialog

class CArea : public CDialog
{
// Construction
public:
	CArea(CWnd* pParent = NULL);   // standard constructor
	double Convert(int r1,int r2,double x);
	int r1;
	int r2;
	bool selectTE;
	bool selectDE;
	/*bool selectTC;
	bool selectDC;*/
// Dialog Data
	//{{AFX_DATA(CArea)
	enum { IDD = IDD_Area };
	CEdit	m_DEdit;
	CEdit	m_TEdit;
	double	m_TE;
	double	m_DE;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CArea)
	public:
	virtual int DoModal();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CArea)
	afx_msg void OnSelendcancelLTopCombo();
	afx_msg void OnSelchangeLDownCombo();
	afx_msg void OnChangeLTopEdit();
	afx_msg void OnChangeLDownEdit();
	afx_msg void OnSelchangeLTopCombo();
	afx_msg void OnSetfocusLTopEdit();
	afx_msg void OnSetfocusLDownEdit();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AREA_H__D0FB605A_58F9_44B7_9035_1004F620B02F__INCLUDED_)
