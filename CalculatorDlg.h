// CalculatorDlg.h : header file
//

#if !defined(AFX_CALCULATORDLG_H__9AD39A1F_C27A_44BB_B7D6_5B7579538DF1__INCLUDED_)
#define AFX_CALCULATORDLG_H__9AD39A1F_C27A_44BB_B7D6_5B7579538DF1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCalculatorDlg dialog
#include "CalculatorMdb.h"

class CCalculatorDlg : public CDialog
{
// Construction
public:
	int m_duType;//��ʼֵΪ0��������Ϊ�ж����Ȼ��ǽǶȵı�׼��
	double m_first;//�洢һ������ĵ�һ����������һ������Ľ��
	double m_second;//�洢һ������ĵڶ���������
	CString m_operator;//�洢�����
	double m_coff;//�洢С�����ϵ��Ȩֵ
	CString time;

	CCalculatorDlg(CWnd* pParent = NULL);	// standard constructor
	void UpdateDisplay(double dck);//���ڱ༭����ʾ����
	void Calculate(void);//���ڼ�����  
	void onButtonN(int n);
	void Save();//������ʷ��¼
	
// Dialog Data
	//{{AFX_DATA(CCalculatorDlg)
	enum { IDD = IDD_CALCULATOR_DIALOG };
	CString	m_mystr;
	CString	m_str;
	CCalculatorMdb m_cal;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCalculatorDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL
// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCalculatorDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void Onone();
	afx_msg void Ontwo();
	afx_msg void Onthree();
	afx_msg void Onfour();
	afx_msg void Onfive();
	afx_msg void Onsix();
	afx_msg void Onseven();
	afx_msg void Oneight();
	afx_msg void Onnine();
	afx_msg void Onzero();
	afx_msg void Onand();
	afx_msg void Onexcept();
	afx_msg void OnChangeEdit1();
	afx_msg void OnClickRichedit1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void Onequal();
	afx_msg void OnDecimalconversion();
	afx_msg void OnUnitconversion();
	afx_msg void OnUpdateEdit6();
	afx_msg void Onmultiplication();
	afx_msg void OnClear();
	afx_msg void Onsubtraction();
	afx_msg void OnInvolution();
	afx_msg void Onpercent();
	afx_msg void Onsquare1();
	afx_msg void Ondelete();
	afx_msg void OnDeg();
	afx_msg void Onsin2();
	afx_msg void Oncos();
	afx_msg void Ontan();
	afx_msg void Oncot();
	afx_msg void Onarcsin();
	afx_msg void Onarccos();
	afx_msg void Onarctan();
	afx_msg void Onarccot();
	afx_msg void Onpoint();
	afx_msg void Onlg();
	afx_msg void Onln();
	afx_msg void Onleft();
	afx_msg void Onright();
	afx_msg void Onfan();
	afx_msg void Onfuhao();
	afx_msg void OnHistory();
	afx_msg void OnHelp();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	CFont m_editFont;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CALCULATORDLG_H__9AD39A1F_C27A_44BB_B7D6_5B7579538DF1__INCLUDED_)
