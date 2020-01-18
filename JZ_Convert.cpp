// JZ_Convert.cpp : implementation file
//

#include "stdafx.h"
#include "calculator.h"
#include "JZ_Convert.h"
#include <string>
#include <sstream>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// JZ_Convert dialog


JZ_Convert::JZ_Convert(CWnd* pParent /*=NULL*/)
	: CDialog(JZ_Convert::IDD, pParent),select16(false),select10(false),select8(false),select2(false)
{
	//{{AFX_DATA_INIT(JZ_Convert)
	m_10 = _T("");
	m_16 = _T("");
	m_2 = _T("");
	m_8 = _T("");
	//}}AFX_DATA_INIT
}


void JZ_Convert::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(JZ_Convert)
	DDX_Control(pDX, IDC_8, m_e8);
	DDX_Control(pDX, IDC_2, m_e2);
	DDX_Control(pDX, IDC_16, m_e16);
	DDX_Control(pDX, IDC_10, m_e10);
	DDX_Text(pDX, IDC_10, m_10);
	DDX_Text(pDX, IDC_16, m_16);
	DDX_Text(pDX, IDC_2, m_2);
	DDX_Text(pDX, IDC_8, m_8);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(JZ_Convert, CDialog)
	//{{AFX_MSG_MAP(JZ_Convert)
	ON_EN_CHANGE(IDC_16, OnChange16)
	ON_EN_CHANGE(IDC_10, OnChange10)
	ON_EN_CHANGE(IDC_8, OnChange8)
	ON_EN_CHANGE(IDC_2, OnChange2)
	ON_EN_UPDATE(IDC_10, OnUpdate10)
	ON_EN_UPDATE(IDC_16, OnUpdate16)
	ON_EN_UPDATE(IDC_2, OnUpdate2)
	ON_EN_UPDATE(IDC_8, OnUpdate8)
	ON_EN_SETFOCUS(IDC_10, OnSetfocus10)
	ON_EN_SETFOCUS(IDC_16, OnSetfocus16)
	ON_EN_SETFOCUS(IDC_2, OnSetfocus2)
	ON_EN_SETFOCUS(IDC_8, OnSetfocus8)
	ON_EN_KILLFOCUS(IDC_10, OnKillfocus10)
	ON_EN_KILLFOCUS(IDC_16, OnKillfocus16)
	ON_EN_KILLFOCUS(IDC_2, OnKillfocus2)
	ON_EN_KILLFOCUS(IDC_8, OnKillfocus8)
	ON_WM_MOVE()
	ON_WM_SIZE()
	ON_WM_LBUTTONDBLCLK()
	ON_BN_CLICKED(IDC_A, OnA)
	ON_BN_CLICKED(IDC_B, OnB)
	ON_BN_CLICKED(IDC_C, OnC)
	ON_BN_CLICKED(IDC_Clear, OnClear)
	ON_BN_CLICKED(IDC_D, OnD)
	ON_BN_CLICKED(IDC_delete, Ondelete)
	ON_BN_CLICKED(IDC_E, OnE)
	ON_BN_CLICKED(IDC_eight, Oneight)
	ON_BN_CLICKED(IDC_F, OnF)
	ON_BN_CLICKED(IDC_five, Onfive)
	ON_BN_CLICKED(IDC_four, Onfour)
	ON_BN_CLICKED(IDC_nine, Onnine)
	ON_BN_CLICKED(IDC_one, Onone)
	ON_BN_CLICKED(IDC_seven, Onseven)
	ON_BN_CLICKED(IDC_six, Onsix)
	ON_BN_CLICKED(IDC_three, Onthree)
	ON_BN_CLICKED(IDC_two, Ontwo)
	ON_BN_CLICKED(IDC_zero, Onzero)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// JZ_Convert message handlers

int JZ_Convert::DoModal() 
{
	// TODO: Add your specialized code here and/or call the base class
	
	return CDialog::DoModal();
}


//任意进制之间的转换

/**
* s1  转换之前的数
* s2  转换之后的数
* d1  原进制数
* d2  需要转到的进制数
*     高于9的位数用大写'A'～'Z'表示，2～16位进制通过验证
*/

string JZ_Convert::getstring (const int n)
{
	stringstream newstr;
	newstr<<n;
	return newstr.str();
}

void JZ_Convert::conversion(string s1,string &s2,long d1,long d2){

    //思路，还是将原数转换成十进制数 -> 再由十进制数转换成目标进制的数
    long i,t,num;
    num = 0;
    //先转换成十进制数
    for ( i = 0; i < s1.size(); i++){
        if (s1[i] >= '0'&&s1[i] <= '9'){
            t = s1[i] - '0';
        }
        else t = s1[i] - 'A' + 10;
        //参考十进制的方式
        num = num*d1 + t;
     }
    i = 0;
    s2 = "";
    while (1){

        t = num%d2;
        num /= d2;
        if (t <= 9)s2 = getstring(t)+ s2;
        else s2 = (char)((t - 10 + 'A')) + s2;
        if (num == 0)break;
    }

}


void JZ_Convert::OnChange16() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
	//可输入信息m_mystr.Delete(m_mystr.GetLength()-1,1);
	UpdateData();
	if(m_16==""){
		m_10="";
		m_8="";
		m_2="";
		UpdateData(FALSE);
		return ;
	}
	char x=m_16.GetAt(m_16.GetLength()-1);
	if((x>='A'&&x<='F')||(x>='0'&&x<='9')){
	//16->10
	string str1=m_16.GetBuffer(0);//CString->string
	string str2;
	conversion(str1,str2,16,10);//任意进制转换
	m_10.Format("%s", str2.c_str());//string->CString
	//OnUpdate10();//更新
	//16->8
	conversion(str1,str2,16,8);
	m_8.Format("%s", str2.c_str());
	//OnUpdate8();
	//16->2
	conversion(str1,str2,16,2);
	m_2.Format("%s", str2.c_str());
	//OnUpdate2();
	UpdateData(FALSE);
	m_16.ReleaseBuffer();
	}
	else {
		MessageBox("输入错误,请重新输入!","提示",MB_ICONINFORMATION);
		m_16.Delete(m_16.GetLength()-1,1);
		UpdateData(FALSE);
		int l=m_e16.GetWindowTextLength();
		m_e16.SetSel(l,l,FALSE);
		m_e16.SetFocus();
	}
}

void JZ_Convert::OnChange10() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here

	

	/*//用于储存字符串
	char str[20];	
	//atoi()函数，将字符串转换成Int类型
	int x=atoi(m_10);	
	
	//_itoa(int十进制数,char[]转换后变成字符串储存,int需要转换的进制)
	_itoa(x,str,16);
	//赋值给16进制edit组件变量
	m_16=str;
	OnUpdate16();
	
	_itoa(x,str,8);
	m_8=str;
	OnUpdate8();

	_itoa(x,str,2);
	m_2=str;
	OnUpdate2();*/	
	//((CComboBox*)GetDlgItem(IDC_L_DownCombo))->SetCurSel(0);
	UpdateData();
	if(m_10==""){
		m_16="";
		m_8="";
		m_2="";
		UpdateData(FALSE);
		return ;
	}
	//10->16
	char x=m_10.GetAt(m_10.GetLength()-1);
	if(x>='0'&&x<='9'){
	string str1=m_10.GetBuffer(0);//CString->string
	string str2;
	conversion(str1,str2,10,16);//任意进制转换
	m_16.Format("%s", str2.c_str());//string->CString
	//OnUpdate16();//更新
	//10->8
	conversion(str1,str2,10,8);
	m_8.Format("%s", str2.c_str());
	//OnUpdate8();
	//10->2
	conversion(str1,str2,10,2);
	m_2.Format("%s", str2.c_str());
	//OnUpdate2();
	UpdateData(FALSE);
	m_10.ReleaseBuffer();
	}
	else {
		MessageBox("输入错误,请重新输入!","提示",MB_ICONINFORMATION);
		m_10.Delete(m_10.GetLength()-1,1);
		UpdateData(FALSE);
		int l=m_e10.GetWindowTextLength();
		m_e10.SetSel(l,l,FALSE);
		m_e10.SetFocus();
	}
}

void JZ_Convert::OnChange8() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here

	//8->16
	UpdateData();
	if(m_8==""){
		m_16="";
		m_10="";
		m_2="";
		UpdateData(FALSE);
		return ;
	}
	char x=m_8.GetAt(m_8.GetLength()-1);
	if(x>='0'&&x<='7'){
	string str1=m_8.GetBuffer(0);//CString->string
	string str2;
	conversion(str1,str2,8,16);//任意进制转换
	m_16.Format("%s", str2.c_str());//string->CString
	//OnUpdate16();//更新
	//8->10
	conversion(str1,str2,8,10);
	m_10.Format("%s", str2.c_str());
	//OnUpdate10();
	//8->2
	conversion(str1,str2,8,2);
	m_2.Format("%s", str2.c_str());
	//OnUpdate2();
	UpdateData(FALSE);
	m_8.ReleaseBuffer();
	}
	else {
		MessageBox("输入错误,请重新输入!","提示",MB_ICONINFORMATION);
		m_8.Delete(m_8.GetLength()-1,1);
		UpdateData(FALSE);
		int l=m_e8.GetWindowTextLength();
		m_e8.SetSel(l,l,FALSE);
		m_e8.SetFocus();
	}
}

void JZ_Convert::OnChange2()
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	UpdateData();
	if(m_2==""){
		m_16="";
		m_10="";
		m_8="";
		UpdateData(FALSE);
		return ;
	}
	char x=m_2.GetAt(m_2.GetLength()-1);
	if(x>='0'&&x<='1'){
	string str1=m_2.GetBuffer(0);//CString->string
	string str2;
	//2->16
	conversion(str1,str2,2,16);//任意进制转换
	m_16.Format("%s", str2.c_str());//string->CString
	//OnUpdate16();//更新
	//2->10
	conversion(str1,str2,2,10);
	m_10.Format("%s", str2.c_str());
	//OnUpdate10();
	//2->8
	conversion(str1,str2,2,8);
	m_8.Format("%s", str2.c_str());
	//OnUpdate8();
	UpdateData(FALSE);
	m_2.ReleaseBuffer();
	}
	else {
		MessageBox("输入错误,请重新输入!","提示",MB_ICONINFORMATION);
		m_2.Delete(m_2.GetLength()-1,1);
		UpdateData(FALSE);
		int l=m_e2.GetWindowTextLength();
		m_e2.SetSel(l,l,FALSE);
		m_e2.SetFocus();
	}
}

void JZ_Convert::OnUpdate10()
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function to send the EM_SETEVENTMASK message to the control
	// with the ENM_UPDATE flag ORed into the lParam mask.
	
	// TODO: Add your control notification handler code here
	/*if(!select10)
	UpdateData(FALSE);*/
}

void JZ_Convert::OnUpdate16() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function to send the EM_SETEVENTMASK message to the control
	// with the ENM_UPDATE flag ORed into the lParam mask.
	
	// TODO: Add your control notification handler code here
	if(!select16)
	UpdateData(FALSE);
}

void JZ_Convert::OnUpdate2() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function to send the EM_SETEVENTMASK message to the control
	// with the ENM_UPDATE flag ORed into the lParam mask.
	
	// TODO: Add your control notification handler code here
	if(!select2)
	UpdateData(FALSE);
}

void JZ_Convert::OnUpdate8() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function to send the EM_SETEVENTMASK message to the control
	// with the ENM_UPDATE flag ORed into the lParam mask.
	
	// TODO: Add your control notification handler code here
	if(!select8)
	UpdateData(FALSE);
}

void JZ_Convert::OnSetfocus10() 
{
	// TODO: Add your control notification handler code here
	((CButton *)GetDlgItem(IDC_A))->EnableWindow(FALSE);
	((CButton *)GetDlgItem(IDC_B))->EnableWindow(FALSE);
	((CButton *)GetDlgItem(IDC_C))->EnableWindow(FALSE);
	((CButton *)GetDlgItem(IDC_D))->EnableWindow(FALSE);
	((CButton *)GetDlgItem(IDC_E))->EnableWindow(FALSE);
	((CButton *)GetDlgItem(IDC_F))->EnableWindow(FALSE);

	((CButton *)GetDlgItem(IDC_zero))->EnableWindow(TRUE);
	((CButton *)GetDlgItem(IDC_one))->EnableWindow(TRUE);
	((CButton *)GetDlgItem(IDC_two))->EnableWindow(TRUE);
	((CButton *)GetDlgItem(IDC_three))->EnableWindow(TRUE);
	((CButton *)GetDlgItem(IDC_four))->EnableWindow(TRUE);
	((CButton *)GetDlgItem(IDC_five))->EnableWindow(TRUE);
	((CButton *)GetDlgItem(IDC_six))->EnableWindow(TRUE);
	((CButton *)GetDlgItem(IDC_seven))->EnableWindow(TRUE);
	((CButton *)GetDlgItem(IDC_eight))->EnableWindow(TRUE);
	((CButton *)GetDlgItem(IDC_nine))->EnableWindow(TRUE);
    /*int l=m_e10.GetWindowTextLength();
    m_e10.SetSel(l,l,FALSE);
    m_e10.SetFocus();*/
	select10=true;
	select2=false;
	select8=false;
	select16=false;
}

void JZ_Convert::OnSetfocus16()
{
	// TODO: Add your control notification handler code here
	/*int l=m_e16.GetWindowTextLength();
    m_e16.SetSel(l,l,FALSE);
    m_e16.SetFocus();*/
	((CButton *)GetDlgItem(IDC_A))->EnableWindow(TRUE);
	((CButton *)GetDlgItem(IDC_B))->EnableWindow(TRUE);
	((CButton *)GetDlgItem(IDC_C))->EnableWindow(TRUE);
	((CButton *)GetDlgItem(IDC_D))->EnableWindow(TRUE);
	((CButton *)GetDlgItem(IDC_E))->EnableWindow(TRUE);
	((CButton *)GetDlgItem(IDC_F))->EnableWindow(TRUE);
	((CButton *)GetDlgItem(IDC_zero))->EnableWindow(TRUE);
	((CButton *)GetDlgItem(IDC_one))->EnableWindow(TRUE);
	((CButton *)GetDlgItem(IDC_two))->EnableWindow(TRUE);
	((CButton *)GetDlgItem(IDC_three))->EnableWindow(TRUE);
	((CButton *)GetDlgItem(IDC_four))->EnableWindow(TRUE);
	((CButton *)GetDlgItem(IDC_five))->EnableWindow(TRUE);
	((CButton *)GetDlgItem(IDC_six))->EnableWindow(TRUE);
	((CButton *)GetDlgItem(IDC_seven))->EnableWindow(TRUE);
	((CButton *)GetDlgItem(IDC_eight))->EnableWindow(TRUE);
	((CButton *)GetDlgItem(IDC_nine))->EnableWindow(TRUE);
	select16=true;
	select2=false;
	select8=false;
	select10=false;
}

void JZ_Convert::OnSetfocus2() 
{
	// TODO: Add your control notification handler code here
	((CButton *)GetDlgItem(IDC_A))->EnableWindow(FALSE);
	((CButton *)GetDlgItem(IDC_B))->EnableWindow(FALSE);
	((CButton *)GetDlgItem(IDC_C))->EnableWindow(FALSE);
	((CButton *)GetDlgItem(IDC_D))->EnableWindow(FALSE);
	((CButton *)GetDlgItem(IDC_E))->EnableWindow(FALSE);
	((CButton *)GetDlgItem(IDC_F))->EnableWindow(FALSE);
	((CButton *)GetDlgItem(IDC_two))->EnableWindow(FALSE);
	((CButton *)GetDlgItem(IDC_three))->EnableWindow(FALSE);
	((CButton *)GetDlgItem(IDC_four))->EnableWindow(FALSE);
	((CButton *)GetDlgItem(IDC_five))->EnableWindow(FALSE);
	((CButton *)GetDlgItem(IDC_six))->EnableWindow(FALSE);
	((CButton *)GetDlgItem(IDC_seven))->EnableWindow(FALSE);
	((CButton *)GetDlgItem(IDC_eight))->EnableWindow(FALSE);
	((CButton *)GetDlgItem(IDC_nine))->EnableWindow(FALSE);

	((CButton *)GetDlgItem(IDC_zero))->EnableWindow(TRUE);
	((CButton *)GetDlgItem(IDC_one))->EnableWindow(TRUE);
	/*int l=m_e2.GetWindowTextLength();
    m_e2.SetSel(l,l,FALSE);
    m_e2.SetFocus();*/
	select2=true;
	select8=false;
	select10=false;
	select16=false;
}

void JZ_Convert::OnSetfocus8() 
{
	// TODO: Add your control notification handler code here
	((CButton *)GetDlgItem(IDC_A))->EnableWindow(FALSE);
	((CButton *)GetDlgItem(IDC_B))->EnableWindow(FALSE);
	((CButton *)GetDlgItem(IDC_C))->EnableWindow(FALSE);
	((CButton *)GetDlgItem(IDC_D))->EnableWindow(FALSE);
	((CButton *)GetDlgItem(IDC_E))->EnableWindow(FALSE);
	((CButton *)GetDlgItem(IDC_F))->EnableWindow(FALSE);
	((CButton *)GetDlgItem(IDC_eight))->EnableWindow(FALSE);
	((CButton *)GetDlgItem(IDC_nine))->EnableWindow(FALSE);

	((CButton *)GetDlgItem(IDC_zero))->EnableWindow(TRUE);
	((CButton *)GetDlgItem(IDC_one))->EnableWindow(TRUE);
	((CButton *)GetDlgItem(IDC_two))->EnableWindow(TRUE);
	((CButton *)GetDlgItem(IDC_three))->EnableWindow(TRUE);
	((CButton *)GetDlgItem(IDC_four))->EnableWindow(TRUE);
	((CButton *)GetDlgItem(IDC_five))->EnableWindow(TRUE);
	((CButton *)GetDlgItem(IDC_six))->EnableWindow(TRUE);
	((CButton *)GetDlgItem(IDC_seven))->EnableWindow(TRUE);
	/*int l=m_e8.GetWindowTextLength();
    m_e8.SetSel(l,l,FALSE);
    m_e8.SetFocus();*/
	select8=true;
	select2=false;
	select10=false;
	select16=false;
}

void JZ_Convert::OnKillfocus10() 
{
	// TODO: Add your control notification handler code here
	/*((CButton *)GetDlgItem(IDC_A))->EnableWindow(TRUE);
	((CButton *)GetDlgItem(IDC_B))->EnableWindow(TRUE);
	((CButton *)GetDlgItem(IDC_C))->EnableWindow(TRUE);
	((CButton *)GetDlgItem(IDC_D))->EnableWindow(TRUE);
	((CButton *)GetDlgItem(IDC_E))->EnableWindow(TRUE);
	((CButton *)GetDlgItem(IDC_F))->EnableWindow(TRUE);*/
}

void JZ_Convert::OnKillfocus16() 
{
	// TODO: Add your control notification handler code here
	//select16=false;
}

void JZ_Convert::OnKillfocus2() 
{
	// TODO: Add your control notification handler code here
	/*((CButton *)GetDlgItem(IDC_A))->EnableWindow(TRUE);
	((CButton *)GetDlgItem(IDC_B))->EnableWindow(TRUE);
	((CButton *)GetDlgItem(IDC_C))->EnableWindow(TRUE);
	((CButton *)GetDlgItem(IDC_D))->EnableWindow(TRUE);
	((CButton *)GetDlgItem(IDC_E))->EnableWindow(TRUE);
	((CButton *)GetDlgItem(IDC_F))->EnableWindow(TRUE);
	((CButton *)GetDlgItem(IDC_two))->EnableWindow(TRUE);
	((CButton *)GetDlgItem(IDC_three))->EnableWindow(TRUE);
	((CButton *)GetDlgItem(IDC_four))->EnableWindow(TRUE);
	((CButton *)GetDlgItem(IDC_five))->EnableWindow(TRUE);
	((CButton *)GetDlgItem(IDC_six))->EnableWindow(TRUE);
	((CButton *)GetDlgItem(IDC_seven))->EnableWindow(TRUE);
	((CButton *)GetDlgItem(IDC_eight))->EnableWindow(TRUE);
	((CButton *)GetDlgItem(IDC_nine))->EnableWindow(TRUE);*/
	//select2=false;
}

void JZ_Convert::OnKillfocus8() 
{
	// TODO: Add your control notification handler code here
	/*((CButton *)GetDlgItem(IDC_A))->EnableWindow(TRUE);
	((CButton *)GetDlgItem(IDC_B))->EnableWindow(TRUE);
	((CButton *)GetDlgItem(IDC_C))->EnableWindow(TRUE);
	((CButton *)GetDlgItem(IDC_D))->EnableWindow(TRUE);
	((CButton *)GetDlgItem(IDC_E))->EnableWindow(TRUE);
	((CButton *)GetDlgItem(IDC_F))->EnableWindow(TRUE);
	((CButton *)GetDlgItem(IDC_eight))->EnableWindow(TRUE);
	((CButton *)GetDlgItem(IDC_nine))->EnableWindow(TRUE);
	select8=false;*/
}

void JZ_Convert::OnMove(int x, int y) 
{
	CDialog::OnMove(x, y);
	
	// TODO: Add your message handler code here
	
}

void JZ_Convert::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
	
}

void JZ_Convert::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CDialog::OnLButtonDblClk(nFlags, point);
}

BOOL JZ_Convert::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	//全选edit
	// TODO: Add your specialized code here and/or call the base class
	if (WM_LBUTTONUP==pMsg->message)  
    {  
        if (m_e16.m_hWnd == pMsg->hwnd)  
        {  
            SendDlgItemMessage(IDC_16, EM_SETSEL, 0, -1);  
        }
		if (m_e10.m_hWnd == pMsg->hwnd)  
        {  
            SendDlgItemMessage(IDC_10, EM_SETSEL, 0, -1);  
        }
		if (m_e8.m_hWnd == pMsg->hwnd)  
        {  
            SendDlgItemMessage(IDC_8, EM_SETSEL, 0, -1);  
        }
		if (m_e2.m_hWnd == pMsg->hwnd)  
        {  
            SendDlgItemMessage(IDC_2, EM_SETSEL, 0, -1);  
        }
    }
	return CDialog::PreTranslateMessage(pMsg);
}

void JZ_Convert::Onone() 
{
	// TODO: Add your control notification handler code here
	
	if(select16){
		m_16+=L"1";
		UpdateData(FALSE);
		OnChange16();
	}
	else if(select10){
		m_10+=L"1";
		UpdateData(FALSE);
		OnChange10();
	}
	else if(select8){
		m_8+=L"1";
		UpdateData(FALSE);
		OnChange8();
	}
	else if(select2){
		m_2+=L"1";
		UpdateData(FALSE);
		OnChange2();
	}
}

void JZ_Convert::Ontwo() 
{
	// TODO: Add your control notification handler code here
	if(select16){
		m_16+=L"2";
		UpdateData(FALSE);
		OnChange16();
	}
	else if(select10){
		m_10+=L"2";
		UpdateData(FALSE);
		OnChange10();
	}
	else if(select8){
		m_8+=L"2";
		UpdateData(FALSE);
		OnChange8();
	}
	else if(select2){
		m_2+=L"2";
		UpdateData(FALSE);
		OnChange2();
	}
}

void JZ_Convert::Onthree() 
{
	// TODO: Add your control notification handler code here
	if(select16){
		m_16+=L"3";
		UpdateData(FALSE);
		OnChange16();
	}
	else if(select10){
		m_10+=L"3";
		UpdateData(FALSE);
		OnChange10();
	}
	else if(select8){
		m_8+=L"3";
		UpdateData(FALSE);
		OnChange8();
	}
	else if(select2){
		m_2+=L"3";
		UpdateData(FALSE);
		OnChange2();
	}
}

void JZ_Convert::Onfour() 
{
	// TODO: Add your control notification handler code here
	if(select16){
		m_16+=L"4";
		UpdateData(FALSE);
		OnChange16();
	}
	else if(select10){
		m_10+=L"4";
		UpdateData(FALSE);
		OnChange10();
	}
	else if(select8){
		m_8+=L"4";
		UpdateData(FALSE);
		OnChange8();
	}
	else if(select2){
		m_2+=L"4";
		UpdateData(FALSE);
		OnChange2();
	}
}

void JZ_Convert::Onfive() 
{
	// TODO: Add your control notification handler code here
	if(select16){
		m_16+=L"5";
		UpdateData(FALSE);
		OnChange16();
	}
	else if(select10){
		m_10+=L"5";
		UpdateData(FALSE);
		OnChange10();
	}
	else if(select8){
		m_8+=L"5";
		UpdateData(FALSE);
		OnChange8();
	}
	else if(select2){
		m_2+=L"5";
		UpdateData(FALSE);
		OnChange2();
	}
}

void JZ_Convert::Onsix() 
{
	// TODO: Add your control notification handler code here
	if(select16){
		m_16+=L"6";
		UpdateData(FALSE);
		OnChange16();
	}
	else if(select10){
		m_10+=L"6";
		UpdateData(FALSE);
		OnChange10();
	}
	else if(select8){
		m_8+=L"6";
		UpdateData(FALSE);
		OnChange8();
	}
	else if(select2){
		m_2+=L"6";
		UpdateData(FALSE);
		OnChange2();
	}
}

void JZ_Convert::Onseven() 
{
	// TODO: Add your control notification handler code here
	if(select16){
		m_16+=L"7";
		UpdateData(FALSE);
		OnChange16();
	}
	else if(select10){
		m_10+=L"7";
		UpdateData(FALSE);
		OnChange10();
	}
	else if(select8){
		m_8+=L"7";
		UpdateData(FALSE);
		OnChange8();
	}
	else if(select2){
		m_2+=L"7";
		UpdateData(FALSE);
		OnChange2();
	}
}

void JZ_Convert::Oneight() 
{
	// TODO: Add your control notification handler code here
	if(select16){
		m_16+=L"8";
		UpdateData(FALSE);
		OnChange16();
	}
	else if(select10){
		m_10+=L"8";
		UpdateData(FALSE);
		OnChange10();
	}
	else if(select8){
		m_8+=L"8";
		UpdateData(FALSE);
		OnChange8();
	}
	else if(select2){
		m_2+=L"8";
		UpdateData(FALSE);
		OnChange2();
	}
}

void JZ_Convert::Onnine() 
{
	// TODO: Add your control notification handler code here
	if(select16){
		m_16+=L"9";
		UpdateData(FALSE);
		OnChange16();
	}
	else if(select10){
		m_10+=L"9";
		UpdateData(FALSE);
		OnChange10();
	}
	else if(select8){
		m_8+=L"9";
		UpdateData(FALSE);
		OnChange8();
	}
	else if(select2){
		m_2+=L"9";
		UpdateData(FALSE);
		OnChange2();
	}
}

void JZ_Convert::Onzero() 
{
	// TODO: Add your control notification handler code here
	if(select16){
		m_16+=L"0";
		UpdateData(FALSE);
		OnChange16();
	}
	else if(select10){
		m_10+=L"0";
		UpdateData(FALSE);
		OnChange10();
	}
	else if(select8){
		m_8+=L"0";
		UpdateData(FALSE);
		OnChange8();
	}
	else if(select2){
		m_2+=L"0";
		UpdateData(FALSE);
		OnChange2();
	}
}

void JZ_Convert::OnA() 
{
	// TODO: Add your control notification handler code here
	if(select16){
		m_16+=L"A";
		UpdateData(FALSE);
		OnChange16();
	}
	else if(select10){
		m_10+=L"A";
		UpdateData(FALSE);
		OnChange10();
	}
	else if(select8){
		m_8+=L"A";
		UpdateData(FALSE);
		OnChange8();
	}
	else if(select2){
		m_2+=L"A";
		UpdateData(FALSE);
		OnChange2();
	}
}

void JZ_Convert::OnB() 
{
	// TODO: Add your control notification handler code here
	if(select16){
		m_16+=L"B";
		UpdateData(FALSE);
		OnChange16();
	}
	else if(select10){
		m_10+=L"B";
		UpdateData(FALSE);
		OnChange10();
	}
	else if(select8){
		m_8+=L"B";
		UpdateData(FALSE);
		OnChange8();
	}
	else if(select2){
		m_2+=L"B";
		UpdateData(FALSE);
		OnChange2();
	}
}

void JZ_Convert::OnC() 
{
	// TODO: Add your control notification handler code here
	if(select16){
		m_16+=L"C";
		UpdateData(FALSE);
		OnChange16();
	}
	else if(select10){
		m_10+=L"C";
		UpdateData(FALSE);
		OnChange10();
	}
	else if(select8){
		m_8+=L"C";
		UpdateData(FALSE);
		OnChange8();
	}
	else if(select2){
		m_2+=L"C";
		UpdateData(FALSE);
		OnChange2();
	}
}



void JZ_Convert::OnD() 
{
	// TODO: Add your control notification handler code here
	if(select16){
		m_16+=L"D";
		UpdateData(FALSE);
		OnChange16();
	}
	else if(select10){
		m_10+=L"D";
		UpdateData(FALSE);
		OnChange10();
	}
	else if(select8){
		m_8+=L"D";
		UpdateData(FALSE);
		OnChange8();
	}
	else if(select2){
		m_2+=L"D";
		UpdateData(FALSE);
		OnChange2();
	}
}


void JZ_Convert::OnE() 
{
	// TODO: Add your control notification handler code here
	if(select16){
		m_16+=L"E";
		UpdateData(FALSE);
		OnChange16();
	}
	else if(select10){
		m_10+=L"E";
		UpdateData(FALSE);
		OnChange10();
	}
	else if(select8){
		m_8+=L"E";
		UpdateData(FALSE);
		OnChange8();
	}
	else if(select2){
		m_2+=L"E";
		UpdateData(FALSE);
		OnChange2();
	}
}


void JZ_Convert::OnF() 
{
	// TODO: Add your control notification handler code here
	if(select16){
		m_16+=L"F";
		UpdateData(FALSE);
		OnChange16();
	}
	else if(select10){
		m_10+=L"F";
		UpdateData(FALSE);
		OnChange10();
	}
	else if(select8){
		m_8+=L"F";
		UpdateData(FALSE);
		OnChange8();
	}
	else if(select2){
		m_2+=L"F";
		UpdateData(FALSE);
		OnChange2();
	}
}

void JZ_Convert::Ondelete() 
{
	// TODO: Add your control notification handler code here
	if(select16){
		m_16.Delete(m_16.GetLength()-1,1);
		UpdateData(FALSE);
		OnChange16();
	}
	else if(select10){
		m_10.Delete(m_10.GetLength()-1,1);
		UpdateData(FALSE);
		OnChange10();
	}
	else if(select8){
		m_8.Delete(m_8.GetLength()-1,1);
		UpdateData(FALSE);
		OnChange8();
	}
	else if(select2){
		m_2.Delete(m_2.GetLength()-1,1);
		UpdateData(FALSE);
		OnChange2();
	}
}

void JZ_Convert::OnClear() 
{
	// TODO: Add your control notification handler code here
	m_16="";
	m_10="";
	m_8="";
	m_2="";
	UpdateData(FALSE);
}
