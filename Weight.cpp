// Weight.cpp : implementation file
//

#include "stdafx.h"
#include "calculator.h"
#include "Weight.h"
#include "math.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWeight dialog


CWeight::CWeight(CWnd* pParent /*=NULL*/)
	: CDialog(CWeight::IDD, pParent),selectTE(false),selectDE(false)
{
	//{{AFX_DATA_INIT(CWeight)
	m_TE = 0.0;
	m_DE = 0.0;
	//}}AFX_DATA_INIT
}


void CWeight::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWeight)
	DDX_Control(pDX, IDC_L_DownEdit, m_DEdit);
	DDX_Control(pDX, IDC_L_TopEdit, m_TEdit);
	DDX_Text(pDX, IDC_L_TopEdit, m_TE);
	DDX_Text(pDX, IDC_L_DownEdit, m_DE);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CWeight, CDialog)
	//{{AFX_MSG_MAP(CWeight)
	ON_EN_CHANGE(IDC_L_DownEdit, OnChangeLDownEdit)
	ON_EN_SETFOCUS(IDC_L_DownEdit, OnSetfocusLDownEdit)
	ON_EN_CHANGE(IDC_L_TopEdit, OnChangeLTopEdit)
	ON_EN_SETFOCUS(IDC_L_TopEdit, OnSetfocusLTopEdit)
	ON_CBN_SELCHANGE(IDC_L_DownCombo, OnSelchangeLDownCombo)
	ON_CBN_SELCHANGE(IDC_L_TopCombo, OnSelchangeLTopCombo)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWeight message handlers

int CWeight::DoModal() 
{
	// TODO: Add your specialized code here and/or call the base class
	
	return CDialog::DoModal();
}


double CWeight::Convert(int r1,int r2,double x){
	double xx=x;
		//=atof(x);//CString->double
	double yy;
	CString cstr;
	switch(r1){
	//ug
	case 0:
		switch(r2){
		case 0:yy=xx;break;
		case 1:yy=xx*pow(10,-3);break;
		case 2:yy=xx*pow(10,-6);break;
		case 3:yy=xx*pow(10,-9);break;
		case 4:yy=xx*pow(10,-12);break;
		case 5:yy=xx*pow(10,-9)*2.2046;break;
		case 6:yy=xx*pow(10,-9)*2.2046*16;break;
		case 7:yy=xx*pow(10,-9)*2;break;
		case 8:yy=xx*pow(10,-9)*20;break;
		case 9:yy=xx*pow(10,-9)*200;break;
		}
		break;
		//mg
	case 1:
		switch(r2){
		case 0:yy=xx*pow(10,3);break;
		case 1:yy=xx;break;
		case 2:yy=xx*pow(10,-3);break;
		case 3:yy=xx*pow(10,-6);break;
		case 4:yy=xx*pow(10,-9);break;
		case 5:yy=xx*pow(10,-6)*2.2046;break;
		case 6:yy=xx*pow(10,-6)*2.2046*16;break;
		case 7:yy=xx*pow(10,-6)*2;break;
		case 8:yy=xx*pow(10,-6)*20;break;
		case 9:yy=xx*pow(10,-6)*200;break;
		}
		break;
	//g
	case 2:
		switch(r2){
		case 0:yy=xx*pow(10,6);break;
		case 1:yy=xx*pow(10,3);break;
		case 2:yy=xx;break;
		case 3:yy=xx*pow(10,-3);break;
		case 4:yy=xx*pow(10,-6);break;
		case 5:yy=xx*pow(10,-3)*2.2046;break;
		case 6:yy=xx*pow(10,-3)*2.2046*16;break;
		case 7:yy=xx*pow(10,-3)*2;break;
		case 8:yy=xx*pow(10,-3)*20;break;
		case 9:yy=xx*pow(10,-3)*200;break;
		}
		break;
	//kg
	case 3:
		switch(r2){
		case 0:yy=xx*pow(10,9);break;
		case 1:yy=xx*pow(10,6);break;
		case 2:yy=xx*pow(10,3);break;
		case 3:yy=xx;break;
		case 4:yy=xx*pow(10,-3);break;
		case 5:yy=xx*2.2046;break;
		case 6:yy=xx*2.2046*16;break;
		case 7:yy=xx*2;break;
		case 8:yy=xx*20;break;
		case 9:yy=xx*200;break;
		}
		break;
	//t
	case 4:
		switch(r2){
		case 0:yy=xx*pow(10,12);break;
		case 1:yy=xx*pow(10,9);break;
		case 2:yy=xx*pow(10,6);break;
		case 3:yy=xx*pow(10,3);break;
		case 4:yy=xx;break;
		case 5:yy=xx*pow(10,3)*2.2046;break;
		case 6:yy=xx*pow(10,3)*2.2046*16;break;
		case 7:yy=xx*pow(10,3)*2;break;
		case 8:yy=xx*pow(10,3)*20;break;
		case 9:yy=xx*pow(10,3)*200;break;
		}
		break;
	//lb
	case 5:
		xx/=2.2046;
		switch(r2){
		case 0:yy=xx*pow(10,9);break;
		case 1:yy=xx*pow(10,6);break;
		case 2:yy=xx*pow(10,3);break;
		case 3:yy=xx;break;
		case 4:yy=xx*pow(10,-3);break;
		case 5:yy=xx*2.2046;break;
		case 6:yy=xx*2.2046*16;break;
		case 7:yy=xx*2;break;
		case 8:yy=xx*20;break;
		case 9:yy=xx*200;break;
		}
		break;
	//oz
	case 6:
		xx=xx/2.2046*16;
		switch(r2){
		case 0:yy=xx*pow(10,9);break;
		case 1:yy=xx*pow(10,6);break;
		case 2:yy=xx*pow(10,3);break;
		case 3:yy=xx;break;
		case 4:yy=xx*pow(10,-3);break;
		case 5:yy=xx*2.2046;break;
		case 6:yy=xx*2.2046*16;break;
		case 7:yy=xx*2;break;
		case 8:yy=xx*20;break;
		case 9:yy=xx*200;break;
		}
		break;
	//jin
	case 7:
		xx/=2;
		switch(r2){
		case 0:yy=xx*pow(10,9);break;
		case 1:yy=xx*pow(10,6);break;
		case 2:yy=xx*pow(10,3);break;
		case 3:yy=xx;break;
		case 4:yy=xx*pow(10,-3);break;
		case 5:yy=xx*2.2046;break;
		case 6:yy=xx*2.2046*16;break;
		case 7:yy=xx*2;break;
		case 8:yy=xx*20;break;
		case 9:yy=xx*200;break;
		}
		break;
	//liang
	case 8:
		x/=20;
		switch(r2){
		case 0:yy=xx*pow(10,9);break;
		case 1:yy=xx*pow(10,6);break;
		case 2:yy=xx*pow(10,3);break;
		case 3:yy=xx;break;
		case 4:yy=xx*pow(10,-3);break;
		case 5:yy=xx*2.2046;break;
		case 6:yy=xx*2.2046*16;break;
		case 7:yy=xx*2;break;
		case 8:yy=xx*20;break;
		case 9:yy=xx*200;break;
		}
		break;
	//qian
	case 9:
		x/=200;
		switch(r2){
		case 0:yy=xx*pow(10,9);break;
		case 1:yy=xx*pow(10,6);break;
		case 2:yy=xx*pow(10,3);break;
		case 3:yy=xx;break;
		case 4:yy=xx*pow(10,-3);break;
		case 5:yy=xx*2.2046;break;
		case 6:yy=xx*2.2046*16;break;
		case 7:yy=xx*2;break;
		case 8:yy=xx*20;break;
		case 9:yy=xx*200;break;
		}
		break;
	}
	 //cstr.Format("%f",yy);//double->CString
	 return yy;
}

void CWeight::OnSelchangeLTopCombo() 
{
	// TODO: Add your control notification handler code here
	/*selectTC=true;
	m_TEdit.EnableWindow(TRUE);//选择了一项后，使编辑框变亮*/

	r1=((CComboBox*)GetDlgItem(IDC_L_TopCombo))->GetCurSel();
	//r2=m_DCombo.GetCurSel();
	//m_TCombo.SetCurSel(r1);
	if(selectTE){
	m_DE=Convert(r1,r2,m_TE);
	//OnUpdateLDownEdit();
	UpdateData(FALSE);
	}
	else{
	m_TE=Convert(r2,r1,m_DE);
	//OnUpdateLTopEdit();
	UpdateData(FALSE);
	}
}

void CWeight::OnSelchangeLDownCombo() 
{
	// TODO: Add your control notification handler code here
	/*selectDC=true;
	//GetDlgItem(IDC_L_DownEdit)->EnableWindow(false);//只读
	
	m_DEdit.EnableWindow(TRUE);//选择了一项后，使编辑框变亮*/

	//r1=m_TCombo.GetCurSel();
	r2=((CComboBox*)GetDlgItem(IDC_L_DownCombo))->GetCurSel();
	//m_DCombo.SetCurSel(r2);
	if(selectTE){
	m_DE=Convert(r1,r2,m_TE);
	//OnUpdateLDownEdit();
	UpdateData(FALSE);
	}
	else{
	m_TE=Convert(r2,r1,m_DE);
	//OnUpdateLTopEdit();
	UpdateData(FALSE);
	}
}

void CWeight::OnChangeLTopEdit() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	/*switch(m_TC){
	
	}*/

	/*int r1=m_TCombo.GetEditSel();
	int r2=m_DCombo.GetEditSel();*/
	UpdateData();
	/*r1=m_TCombo.GetCurSel();
	r2=m_DCombo.GetCurSel();*/
	/*m_TCombo.SetCurSel(r1);
	m_DCombo.SetCurSel(r2);*/
	m_DE=Convert(r1,r2,m_TE);
	UpdateData(FALSE);
}

void CWeight::OnChangeLDownEdit()
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here

	UpdateData();
	/*r1=m_TCombo.GetCurSel();
	r2=m_DCombo.GetCurSel();*/
	/*m_TCombo.SetCurSel(r1);
	m_DCombo.SetCurSel(r2);*/
	
	m_TE=Convert(r2,r1,m_DE);
	UpdateData(FALSE);
}


void CWeight::OnSetfocusLTopEdit() 
{
	// TODO: Add your control notification handler code here
	/*m_TE=0;
	m_DE=0;
	UpdateData(FALSE);*/
	selectTE=true;
	selectDE=false;
}

void CWeight::OnSetfocusLDownEdit() 
{
	// TODO: Add your control notific ation handler code here
	/*m_TE=0;
	m_DE=0;
	UpdateData(FALSE);*/
	selectDE=true;
	selectTE=false;
}



BOOL CWeight::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	//初始化，使编辑框变灰
	/*m_TEdit.EnableWindow(FALSE);
	m_DEdit.EnableWindow(FALSE);*/
	((CComboBox*)GetDlgItem(IDC_L_TopCombo))->SetCurSel(0);
	((CComboBox*)GetDlgItem(IDC_L_DownCombo))->SetCurSel(0);
	/*m_TCombo.SetCurSel(0);
	m_DCombo.SetCurSel(0);*/
	r1=0;
	r2=0;
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

//全选edit
BOOL CWeight::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	if (WM_LBUTTONUP==pMsg->message)  
    {  
        if (m_TEdit.m_hWnd == pMsg->hwnd)  
        {  
            SendDlgItemMessage(IDC_L_TopEdit, EM_SETSEL, 0, -1);  
        }
		if (m_DEdit.m_hWnd == pMsg->hwnd)  
        {  
            SendDlgItemMessage(IDC_L_DownEdit, EM_SETSEL, 0, -1);  
        }
    }
	return CDialog::PreTranslateMessage(pMsg);
}