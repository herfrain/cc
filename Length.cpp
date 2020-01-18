// Length.cpp : implementation file
//

#include "stdafx.h"
#include "calculator.h"
#include "Length.h"
#include "math.h"
//#include <CEdit.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLength dialog


CLength::CLength(CWnd* pParent /*=NULL*/)
	: CDialog(CLength::IDD, pParent),selectTE(false),selectDE(false)
{
	//{{AFX_DATA_INIT(CLength)
	m_DE = 0.0;
	m_TE = 0.0;
	//}}AFX_DATA_INIT
	//(CEdit*)GetDlgItem(IDC_L_DownEdit)->SetReadOnly(TRUE);
	//CEdit::SetReadOnly(TRUE);
	/*m_TEdit.EnableWindow(false);
	m_DEdit.EnableWindow(false);*/
}


void CLength::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLength)
	DDX_Control(pDX, IDC_L_TopEdit, m_TEdit);
	DDX_Control(pDX, IDC_L_DownEdit, m_DEdit);
	DDX_Text(pDX, IDC_L_DownEdit, m_DE);
	DDX_Text(pDX, IDC_L_TopEdit, m_TE);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLength, CDialog)
	//{{AFX_MSG_MAP(CLength)
	ON_CBN_SELCHANGE(IDC_L_TopCombo, OnSelchangeLTopCombo)
	ON_CBN_SELCHANGE(IDC_L_DownCombo, OnSelchangeLDownCombo)
	ON_EN_CHANGE(IDC_L_TopEdit, OnChangeLTopEdit)
	ON_EN_CHANGE(IDC_L_DownEdit, OnChangeLDownEdit)
	ON_EN_UPDATE(IDC_L_DownEdit, OnUpdateLDownEdit)
	ON_EN_UPDATE(IDC_L_TopEdit, OnUpdateLTopEdit)
	ON_EN_SETFOCUS(IDC_L_DownEdit, OnSetfocusLDownEdit)
	ON_EN_SETFOCUS(IDC_L_TopEdit, OnSetfocusLTopEdit)
	//ON_EN_KILLFOCUS(IDC_L_DownEdit, OnKillfocusLDownEdit)
	//ON_EN_KILLFOCUS(IDC_L_TopEdit, OnKillfocusLTopEdit)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLength message handlers

int CLength::DoModal()
{
	// TODO: Add your specialized code here and/or call the base class
	return CDialog::DoModal();
}


double CLength::Convert(int r1,int r2,double x){
	double xx=x;
		//=atof(x);//CString->double
	double q;
	double yy;
	CString cstr;
	/*if(r1<=2&&r2<=2){
		if(r1<=r2) yy=xx*pow(10,-3*abs(r1-r2));
		else yy=xx*pow(10,3*abs(r1-r2))
	}
	else if()*/
	switch(r1){
	//nm
	case 0:
		switch(r2){
			//nm
		case 0: yy=xx;break;
			//um
		case 1: yy=xx*pow(10,-3);break;
			//mm
		case 2: yy=xx*pow(10,-6);break; 
			//cm
		case 3: yy=xx*pow(10,-7);break;
			//dm
		case 4: yy=xx*pow(10,-8);break;
			//m
		case 5: yy=xx*pow(10,-9);break;
			//英尺 ft
		case 6: yy=xx*pow(10,-9)*3.2808399;break;
			//英寸 in
		case 7: yy=xx*pow(10,-9)*39.3700787;break;
			//丈 zhang
		case 8: yy=xx*pow(10,-9)*0.3;break;
			//尺 chi
		case 9: yy=xx*pow(10,-9)*3;break;
			//km
		case 10: yy=xx*pow(10,-12);break;
			//海里 nmi
		case 11: yy=xx*pow(10,-12)*0.539956803;break;
			//英里 mi
		case 12: yy=xx*pow(10,-12)*0.621371192;break;
		}
		break;
		//um
	case 1:
		switch(r2){
		case 0:yy=xx*pow(10,3);break;
		case 1:yy=xx;break;
		case 2:yy=xx*pow(10,-3);break;
		case 3:yy=xx*pow(10,-4);break;
		case 4:yy=xx*pow(10,-5);break;
		case 5:yy=xx*pow(10,-6);break;
		case 6:yy=xx*pow(10,-6)*3.2808399;break;
		case 7:yy=xx*pow(10,-6)*39.3700787;break;
		case 8:yy=xx*pow(10,-6)*0.3;break;
		case 9:yy=xx*pow(10,-6)*3;break;
		case 10:yy=xx*pow(10,-9);break;
		case 11:yy=xx*pow(10,-9)*0.539956803;break;
		case 12:yy=xx*pow(10,-9)*0.621371192;break;
		}
		break;
	//mm
	case 2:
		switch(r2){
		case 0:yy=xx*pow(10,6);break;
		case 1:yy=xx*pow(10,3);break;
		case 2:yy=xx;break;
		case 3:yy=xx*pow(10,-1);break;
		case 4:yy=xx*pow(10,-2);break;
		case 5:yy=xx*pow(10,-3);break;
		case 6:yy=xx*pow(10,-3)*3.2808399;break;
		case 7:yy=xx*pow(10,-3)*39.3700787;break;
		case 8:yy=xx*pow(10,-3)*0.3;break;
		case 9:yy=xx*pow(10,-3)*3;break;
		case 10:yy=xx*pow(10,-6);break;
		case 11:yy=xx*pow(10,-6)*0.539956803;break;
		case 12:yy=xx*pow(10,-6)*0.621371192;break;
		}
		break;
	//cm
	case 3:
		switch(r2){
		case 0:yy=xx*pow(10,7);break;
		case 1:yy=xx*pow(10,4);break;
		case 2:yy=xx*pow(10,1);break;
		case 3:yy=xx;break;
		case 4:yy=xx*pow(10,-1);break;
		case 5:yy=xx*pow(10,-2);break;
		case 6:yy=xx*pow(10,-2)*3.2808399;break;
		case 7:yy=xx*pow(10,-2)*39.3700787;break;
		case 8:yy=xx*pow(10,-2)*0.3;break;
		case 9:yy=xx*pow(10,-2)*3;break;
		case 10:yy=xx*pow(10,-2);break;
		case 11:yy=xx*pow(10,-2)*0.539956803;break;
		case 12:yy=xx*pow(10,-2)*0.621371192;break;
		}
		break;
	//dm
	case 4:
		switch(r2){
		case 0:yy=xx*pow(10,8);break;
		case 1:yy=xx*pow(10,5);break;
		case 2:yy=xx*pow(10,2);break;
		case 3:yy=xx*pow(10,1);break;
		case 4:yy=xx;break;
		case 5:yy=xx*pow(10,-1);break;
		case 6:yy=xx*pow(10,-1)*3.2808399;break;
		case 7:yy=xx*pow(10,-1)*39.3700787;break;
		case 8:yy=xx*pow(10,-1)*0.3;break;
		case 9:yy=xx*pow(10,-1)*3;break;
		case 10:yy=xx*pow(10,-4);break;
		case 11:yy=xx*pow(10,-4)*0.539956803;break;
		case 12:yy=xx*pow(10,-4)*0.621371192;break;
		}
		break;

	//m
	case 5:
		switch(r2){
		case 0:yy=xx*pow(10,9);break;
		case 1:yy=xx*pow(10,6);break;
		case 2:yy=xx*pow(10,3);break;
		case 3:yy=xx*pow(10,2);break;
		case 4:yy=xx*pow(10,1);break;
		case 5:yy=xx;break;
		case 6:yy=xx*3.2808399;break;
		case 7:yy=xx*39.3700787;break;
		case 8:yy=xx*0.3;break;
		case 9:yy=xx*3;break;
		case 10:yy=xx*pow(10,-3);break;
		case 11:yy=xx*pow(10,-3)*0.539956803;break;
		case 12:yy=xx*pow(10,-3)*0.621371192;break;
		}
		break;
	
	//ft
	case 6:
		q=xx;
		xx/=3.2808399;
		switch(r2){
		case 0:yy=xx*pow(10,9);break;
		case 1:yy=xx*pow(10,6);break;
		case 2:yy=xx*pow(10,3);break;
		case 3:yy=xx*pow(10,2);break;
		case 4:yy=xx*pow(10,1);break;
		case 5:yy=xx;break;
		case 6:yy=q;break;
		case 7:yy=xx*39.3700787;break;
		case 8:yy=xx*0.3;break;
		case 9:yy=xx*3;break;
		case 10:yy=xx*pow(10,-4);break;
		case 11:yy=xx*pow(10,-4)*0.539956803;break;
		case 12:yy=xx*pow(10,-4)*0.621371192;break;
		}
		break;
	
	//in
	case 7:
		q=xx;
		xx/=39.3700787;
		switch(r2){
		case 0:yy=xx*pow(10,9);break;
		case 1:yy=xx*pow(10,6);break;
		case 2:yy=xx*pow(10,3);break;
		case 3:yy=xx*pow(10,2);break;
		case 4:yy=xx*pow(10,1);break;
		case 5:yy=xx;break;
		case 6:yy=xx*3.2808399;break;
		case 7:yy=q;break;
		case 8:yy=xx*0.3;break;
		case 9:yy=xx*3;break;
		case 10:yy=xx*pow(10,-3);break;
		case 11:yy=xx*pow(10,-3)*0.539956803;break;
		case 12:yy=xx*pow(10,-3)*0.621371192;break;
		}
		break;
	
	//zhang
	case 8:
		q=xx;
		xx/=0.3;
		switch(r2){
		case 0:yy=xx*pow(10,9);break;
		case 1:yy=xx*pow(10,6);break;
		case 2:yy=xx*pow(10,3);break;
		case 3:yy=xx*pow(10,2);break;
		case 4:yy=xx*pow(10,1);break;
		case 5:yy=xx;break;
		case 6:yy=xx*3.2808399;break;
		case 7:yy=xx*39.3700787;break;
		case 8:yy=q;break;
		case 9:yy=xx*3;break;
		case 10:yy=xx*pow(10,-3);break;
		case 11:yy=xx*pow(10,-3)*0.539956803;break;
		case 12:yy=xx*pow(10,-3)*0.621371192;break;
		}
		break;
	
	//chi
	case 9:
		q=xx;
		xx/=3;
		switch(r2){
		case 0:yy=xx*pow(10,9);break;
		case 1:yy=xx*pow(10,6);break;
		case 2:yy=xx*pow(10,3);break;
		case 3:yy=xx*pow(10,2);break;
		case 4:yy=xx*pow(10,1);break;
		case 5:yy=xx;break;
		case 6:yy=xx*3.2808399;break;
		case 7:yy=xx*39.3700787;break;
		case 8:yy=xx*0.3;break;
		case 9:yy=q;break;
		case 10:yy=xx*pow(10,-3);break;
		case 11:yy=xx*pow(10,-3)*0.539956803;break;
		case 12:yy=xx*pow(10,-3)*0.621371192;break;
		}
		break;
	
	//km
	case 10:
		q=xx;
		xx*=1000;
		switch(r2){
		case 0:yy=xx*pow(10,9);break;
		case 1:yy=xx*pow(10,6);break;
		case 2:yy=xx*pow(10,3);break;
		case 3:yy=xx*pow(10,2);break;
		case 4:yy=xx*pow(10,1);break;
		case 5:yy=xx;break;
		case 6:yy=xx*3.2808399;break;
		case 7:yy=xx*39.3700787;break;
		case 8:yy=xx*0.3;break;
		case 9:yy=xx*3;break;
		case 10:yy=q;break;
		case 11:yy=xx*pow(10,-3)*0.539956803;break;
		case 12:yy=xx*pow(10,-3)*0.621371192;break;
		}
		break;
	
	//nmi
	case 11:
		q=xx;
		xx=xx*1000/0.539956803;
		switch(r2){
		case 0:yy=xx*pow(10,9);break;
		case 1:yy=xx*pow(10,6);break;
		case 2:yy=xx*pow(10,3);break;
		case 3:yy=xx*pow(10,2);break;
		case 4:yy=xx*pow(10,1);break;
		case 5:yy=xx;break;
		case 6:yy=xx*3.2808399;break;
		case 7:yy=xx*39.3700787;break;
		case 8:yy=xx*0.3;break;
		case 9:yy=xx*3;break;
		case 10:yy=xx*pow(10,-3);break;
		case 11:yy=q;break;
		case 12:yy=xx*pow(10,-3)*0.621371192;break;
		}
		break;

	case 12 :
		q=xx;
		xx=xx*1000/0.621371192;
		switch(r2){
		case 0:yy=xx*pow(10,9);break;
		case 1:yy=xx*pow(10,6);break;
		case 2:yy=xx*pow(10,3);break;
		case 3:yy=xx*pow(10,2);break;
		case 4:yy=xx*pow(10,1);break;
		case 5:yy=xx;break;
		case 6:yy=xx*3.2808399;break;
		case 7:yy=xx*39.3700787;break;
		case 8:yy=xx*0.3;break;
		case 9:yy=xx*3;break;
		case 10:yy=xx*pow(10,-3);break;
		case 11:yy=xx*pow(10,-3)*0.539956803;break;
		case 12:q;break;
		}
		break;
	}
	 //cstr.Format("%f",yy);//double->CString
	 return yy;
}

void CLength::OnSelchangeLTopCombo() 
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

void CLength::OnSelchangeLDownCombo() 
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

void CLength::OnChangeLTopEdit() 
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

void CLength::OnChangeLDownEdit()
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

void CLength::OnUpdateLDownEdit() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function to send the EM_SETEVENTMASK message to the control
	// with the ENM_UPDATE flag ORed into the lParam mask.
	
	// TODO: Add your control notification handler code here
	
	if(!selectDE)
	UpdateData(FALSE);
}

void CLength::OnUpdateLTopEdit() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function to send the EM_SETEVENTMASK message to the control
	// with the ENM_UPDATE flag ORed into the lParam mask.
	
	// TODO: Add your control notification handler code here

	if(!selectTE)
	UpdateData(FALSE);
}

void CLength::OnSetfocusLTopEdit() 
{
	// TODO: Add your control notification handler code here
	/*m_TE=0;
	m_DE=0;
	UpdateData(FALSE);*/
	selectTE=true;
	selectDE=false;
}

void CLength::OnSetfocusLDownEdit() 
{
	// TODO: Add your control notific ation handler code here
	/*m_TE=0;
	m_DE=0;
	UpdateData(FALSE);*/
	selectDE=true;
	selectTE=false;
}


/*
void CLength::OnKillfocusLDownEdit() 
{
	// TODO: Add your control notification handler code here
	selectDE=false;
}

void CLength::OnKillfocusLTopEdit() 
{
	// TODO: Add your control notification handler code here
	selectTE=false;
}*/

int CLength::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	/*m_TEdit.EnableWindow(FALSE);
	m_DEdit.EnableWindow(FALSE);*/
	return 0;
}


BOOL CLength::OnInitDialog() 
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
BOOL CLength::PreTranslateMessage(MSG* pMsg) 
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
