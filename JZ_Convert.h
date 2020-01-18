#if !defined(AFX_JZ_CONVERT_H__338967B9_8628_45AB_9092_4CE1FEDD5C82__INCLUDED_)
#define AFX_JZ_CONVERT_H__338967B9_8628_45AB_9092_4CE1FEDD5C82__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// JZ_Convert.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// JZ_Convert dialog
#include <string>
using namespace std;
class JZ_Convert : public CDialog
{
// Construction
public:
	JZ_Convert(CWnd* pParent = NULL);// standard constructor
	string getstring(const int n);
	void conversion(string s1,string &s2,long d1,long d2);
	bool select16;
	bool select10;
	bool select8;
	bool select2;
// Dialog Data
	//{{AFX_DATA(JZ_Convert)
	enum { IDD = IDD_JZ_Convert };
	CEdit	m_e8;
	CEdit	m_e2;
	CEdit	m_e16;
	CEdit	m_e10;
	CString	m_10;
	CString	m_16;
	CString	m_2;
	CString	m_8;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(JZ_Convert)
	public:
	virtual int DoModal();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(JZ_Convert)
	afx_msg void OnChange16();
	afx_msg void OnChange10();
	afx_msg void OnChange8();
	afx_msg void OnChange2();
	afx_msg void OnUpdate10();
	afx_msg void OnUpdate16();
	afx_msg void OnUpdate2();
	afx_msg void OnUpdate8();
	afx_msg void OnSetfocus10();
	afx_msg void OnSetfocus16();
	afx_msg void OnSetfocus2();
	afx_msg void OnSetfocus8();
	afx_msg void OnKillfocus10();
	afx_msg void OnKillfocus16();
	afx_msg void OnKillfocus2();
	afx_msg void OnKillfocus8();
	afx_msg void OnMove(int x, int y);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnA();
	afx_msg void OnB();
	afx_msg void OnC();
	afx_msg void OnClear();
	afx_msg void OnD();
	afx_msg void Ondelete();
	afx_msg void OnE();
	afx_msg void Oneight();
	afx_msg void OnF();
	afx_msg void Onfive();
	afx_msg void Onfour();
	afx_msg void Onnine();
	afx_msg void Onone();
	afx_msg void Onseven();
	afx_msg void Onsix();
	afx_msg void Onthree();
	afx_msg void Ontwo();
	afx_msg void Onzero();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_JZ_CONVERT_H__338967B9_8628_45AB_9092_4CE1FEDD5C82__INCLUDED_)
