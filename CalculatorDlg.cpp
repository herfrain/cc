// CalculatorDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Calculator.h"
#include "CalculatorDlg.h"
#include "Dw_Transform.h"
#include "JZ_Convert.h"
#include "History.h" //历史记录窗口 
#include "CalculatorMdb.h" //数据集 
#include "math.h"
#include <String>
#include <CString>
#include <vector>
#include <stack>
#include <time.h>
#include <windows.h>
#include <odbcinst.h>


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	public:
	virtual int DoModal();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCalculatorDlg dialog

CCalculatorDlg::CCalculatorDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCalculatorDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCalculatorDlg)
	m_mystr = _T("");
	m_str = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

/*void CCalculatorDlg::Calculate(){
	//将前一次数据与当前数据进行运算，作为下次的第一操作数，并在编辑框显示。
switch(m_operator.GetAt(0))
{  case '+': m_first+=m_second;break;
case '-': m_first-=m_second;break;
case '*': m_first*=m_second;break;
case '/':
if(fabs(m_second)<=0.000001)
{m_mystr="除数不能为";
UpdateData(false);
return;  }
m_first/=m_second;break;
}
m_second=0.0;
m_coff=1.0;
m_operator=_T("+");
UpdateDisplay(m_first);//更新编辑框显示内容
}

void CCalculatorDlg::UpdateDisplay(double dck){
	m_mystr.Format(_T("%f"),dck);
	int i=m_mystr.GetLength();
	while(m_mystr.GetAt(i-1)=='0') //格式化输出,将输出结果后的零截去
	{  
		m_mystr.Delete(i-1,1);  
		i--; 
	}
	UpdateData(false);//更新编辑框变量m_display
}*/

void CCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCalculatorDlg)
	DDX_Text(pDX, IDC_EDIT1, m_mystr);
	DDX_Text(pDX, IDC_EDIT6, m_str);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCalculatorDlg, CDialog)
	//{{AFX_MSG_MAP(CCalculatorDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_one, Onone)
	ON_BN_CLICKED(IDC_two, Ontwo)
	ON_BN_CLICKED(IDC_three, Onthree)
	ON_BN_CLICKED(IDC_four, Onfour)
	ON_BN_CLICKED(IDC_five, Onfive)
	ON_BN_CLICKED(IDC_six, Onsix)
	ON_BN_CLICKED(IDC_seven, Onseven)
	ON_BN_CLICKED(IDC_eight, Oneight)
	ON_BN_CLICKED(IDC_nine, Onnine)
	ON_BN_CLICKED(IDC_zero, Onzero)
	ON_BN_CLICKED(IDC_and, Onand)
	ON_BN_CLICKED(IDC_except, Onexcept)
	ON_EN_CHANGE(IDC_EDIT1, OnChangeEdit1)
	ON_BN_CLICKED(IDC_equal, Onequal)
	ON_BN_CLICKED(IDC_Decimalconversion, OnDecimalconversion)
	ON_BN_CLICKED(IDC_Unitconversion, OnUnitconversion)
	ON_EN_UPDATE(IDC_EDIT6, OnUpdateEdit6)
	ON_BN_CLICKED(IDC_multiplication, Onmultiplication)
	ON_BN_CLICKED(IDC_Clear, OnClear)
	ON_BN_CLICKED(IDC_subtraction, Onsubtraction)
	ON_BN_CLICKED(IDC_Involution, OnInvolution)
	ON_BN_CLICKED(IDC_percent, Onpercent)
	ON_BN_CLICKED(IDC_square1, Onsquare1)
	ON_BN_CLICKED(IDC_delete, Ondelete)
	ON_BN_CLICKED(IDC_Deg, OnDeg)
	ON_BN_CLICKED(IDC_sin2, Onsin2)
	ON_BN_CLICKED(IDC_cos, Oncos)
	ON_BN_CLICKED(IDC_tan, Ontan)
	ON_BN_CLICKED(IDC_cot, Oncot)
	ON_BN_CLICKED(IDC_arcsin, Onarcsin)
	ON_BN_CLICKED(IDC_arccos, Onarccos)
	ON_BN_CLICKED(IDC_arctan, Onarctan)
	ON_BN_CLICKED(IDC_arccot, Onarccot)
	ON_BN_CLICKED(IDC_point, Onpoint)
	ON_BN_CLICKED(IDC_lg, Onlg)
	ON_BN_CLICKED(IDC_ln, Onln)
	ON_BN_CLICKED(IDC_left, Onleft)
	ON_BN_CLICKED(IDC_right, Onright)
	ON_BN_CLICKED(IDC_BUTTON1, Onfuhao)
	ON_BN_CLICKED(IDC_History, OnHistory)
	ON_BN_CLICKED(IDC_Help, OnHelp)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCalculatorDlg message handlers

BOOL CCalculatorDlg::OnInitDialog()
{
	CString sPath;
	GetModuleFileName(NULL,sPath.GetBufferSetLength(MAX_PATH+1),MAX_PATH);
	int nPos;
	nPos = sPath.ReverseFind('\\');
	sPath = sPath.Left(nPos);
	nPos = sPath.ReverseFind('\\');
	sPath = sPath.Left(nPos);

	CString lpszFile = sPath + "\\cal.mdb";

	char * szDesc = new char[256];
	int len;
//	sprintf(szDesc,"DSN=%s? DESCRIPTION=TOC support source? DBQ=%s? FIL=MicrosoftAccess? DEFAULTDIR=%s?? ","student",lpszFile,sPath);
	sprintf(szDesc,"DSN=%s? DBQ=%s?? ","calculator",lpszFile);
	//sprintf:字串格式化命令，主要功能是把格式化的数据写入某个字符串中。

	len = strlen(szDesc);
	for(int i=0; i<len;i++)
	{
		if(szDesc[i]=='?')
			szDesc[i]='\0';
	}

	if(false==SQLConfigDataSource(NULL,ODBC_ADD_DSN,"Microsoft Access Driver (*.mdb)\0",(LPCSTR)szDesc))
		AfxMessageBox("SQLConfigDataSource Failed");


	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	CEdit *pEdit1=(CEdit*)GetDlgItem(IDC_EDIT1);
	CEdit *pEdit2=(CEdit*)GetDlgItem(IDC_EDIT6); 
    //CFont  pFont ;//= pEdit->GetFont(); 
    LOGFONT lf; 
    // clear out structure. 
    memset(&lf,0, sizeof(LOGFONT)); 
	// request a 12-pixel-height font 
	lf.lfHeight=180; 
	// request a face name "Arial". 
	strcpy((LPSTR)&lf.lfFaceName, "宋体");  
	m_editFont.CreatePointFontIndirect(&lf); 
	pEdit1->SetFont(&m_editFont,TRUE); 
	pEdit2->SetFont(&m_editFont,TRUE); 
	((CButton *)GetDlgItem(IDC_Deg))->SetCheck(TRUE);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCalculatorDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCalculatorDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
/*
void CCalculatorDlg::onButtonN(int n){
	if( m_coff == 1.0)
m_second = m_second*10 + n;//作为整数输入数字时
else  
{ m_second = m_second + n*m_coff; //作为小数输入数字
m_coff *= 0.1; }
UpdateDisplay(m_second);//更新编辑框的数字显示
}*/

void CCalculatorDlg::Onone() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	m_mystr+="1";
	UpdateData(FALSE);
}

void CCalculatorDlg::Ontwo() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	m_mystr+="2";
	UpdateData(FALSE);
}

void CCalculatorDlg::Onthree() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	m_mystr+=L"3";
	UpdateData(FALSE);
	//onButtonN(3);
}

void CCalculatorDlg::Onfour() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	m_mystr+=L"4";
	UpdateData(FALSE);
	//onButtonN(4);
}

void CCalculatorDlg::Onfive() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	m_mystr+=L"5";
	UpdateData(FALSE);
	//onButtonN(5);
}

void CCalculatorDlg::Onsix() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	m_mystr+=L"6";
	UpdateData(FALSE);
	//onButtonN(6);
}

void CCalculatorDlg::Onseven() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	m_mystr+=L"7";
	UpdateData(FALSE);
	//onButtonN(7);
}

void CCalculatorDlg::Oneight() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	m_mystr+=L"8";
	UpdateData(FALSE);
	//onButtonN(8);
}

void CCalculatorDlg::Onnine() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	m_mystr+=L"9";
	UpdateData(FALSE);
	//onButtonN(9);
}

void CCalculatorDlg::Onzero() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	m_mystr+=L"0";
	UpdateData(FALSE);
	//onButtonN(0);
}

//+
void CCalculatorDlg::Onand() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	m_mystr+=L"+";
	UpdateData(FALSE);
	/*Calculate();
	m_operator="+"; */
}


//-
void CCalculatorDlg::Onsubtraction() 
{
	// TODO: Add your control notification handler code here
	/*Calculate();
	m_operator="-"; */
	UpdateData();
	m_mystr+=L"-";
	UpdateData(FALSE);
}

//*
void CCalculatorDlg::Onmultiplication() 
{
	// TODO: Add your control notification handler code here
	/*Calculate();
	m_operator="*"; */
	UpdateData();
	m_mystr+=L"*";
	UpdateData(FALSE);
}

//C
void CCalculatorDlg::OnClear() 
{
	// TODO: Add your control notification handler code here
	/*m_first=0.0;
	m_second=0.0;
	m_operator = "+";
	m_coff = 1.0;
	UpdateDisplay(0.0);*/
	m_mystr="";
	UpdateData(FALSE);
}


///
void CCalculatorDlg::Onexcept() 
{
	// TODO: Add your control notification handler code here
	/*Calculate();
	m_operator.Format(_T("%s"),"/"); */
	UpdateData();
	m_mystr+=L"/";
	UpdateData(FALSE);
}

void CCalculatorDlg::OnChangeEdit1() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}

void CCalculatorDlg::Onequal() 
{
	// TODO: Add your control notification handler code here
	/*stack<char> s1;
	vector<char> s2;
	s1.push('#');
	char flag[]={'#','+','*','-','/'};
	for(int i=0;i<m_mystr.GetLength();i++){
		if(m_mystr[i]!='+'&&m_mystr[i]!='-'&&m_mystr[i]!='*'&&m_mystr[i]!='/'){
			s2.insert(m_mystr[i])
		}
		else if(m_mystr[i]=='('){
			s1.push(m_mystr[i]);
		}
		else if(m_mystr[i]==')'){
			while(s1.top()!='(')
				s2.insert(s1.pop());
			s1.pop();
		}
		
	}*/
	//Calculate();
	stack<char> s1;
	stack<char> s2;
	stack<char> s3;
	stack<double> d;
	double x,y,z,result;
	string mm=m_mystr.GetBuffer(0);
	string str;
	char *p;
	for(int i=0;i<mm.length();i++){
		switch(mm[i]){
			case'(':
				s1.push(mm[i]);
				break;
			case')':
				while(s1.top()!='('){
					s2.push(s1.top());
					s1.pop();
				}
				s1.pop();
				break;
			case '_':
				s2.push('0');
				s2.push(' ');
				while(!s1.empty()&&s1.top()!='('){
					s2.push(s1.top());
					s1.pop();
				}
				s1.push('-');
				break;
			case '+':
			case '-':
				while(!s1.empty()&&s1.top()!='('){
					s2.push(s1.top());
					s1.pop();
				}
				s1.push(mm[i]);
				break;
			case '*':
			case '/':
				while(!s1.empty()&&(s1.top()=='*'||s1.top()=='/'||s1.top()=='g'||s1.top()=='n'||s1.top()=='^'||s1.top()=='$'||s1.top()=='%')){
					s2.push(s1.top());
					s1.pop();
				}
				s1.push(mm[i]);
				break;
			case ' ':
				break;
			case '^':
			case '$':
				while(!s1.empty()&&(s1.top()=='^'||s1.top()=='$'||s1.top()=='g'||s1.top()=='n'||s1.top()=='^'||s1.top()=='%')){
					s2.push(s1.top());
					s1.pop();
				}
				s1.push(mm[i]);
				break;
			case 'g':
			case 'n':
				while(!s1.empty()&&(s1.top()=='^'||s1.top()=='$'||s1.top()=='g'||s1.top()=='n'||s1.top()=='^'||s1.top()=='%')){
					s2.push(s1.top());
					s1.pop();
				}
				s1.push(mm[i]);
				break;
			case '%':
				while(!s1.empty()&&(s1.top()=='^'||s1.top()=='$'||s1.top()=='g'||s1.top()=='n'||s1.top()=='^'||s1.top()=='%')){
					s2.push(s1.top());
					s1.pop();
				}
				s1.push(mm[i]);
				break;
			case '#':
				while(!s1.empty()&&(s1.top()=='^'||s1.top()=='$'||s1.top()=='g'||s1.top()=='n'||s1.top()=='^'||s1.top()=='%'||s1.top()=='#')){
					s2.push(s1.top());
					s1.pop();
				}
				s1.push(mm[i]);
				break;
			default:
				while((mm[i]>='0'&&mm[i]<='9')||mm[i]=='.'){
					s2.push(mm[i]);
					i++;
				}
				i--;
				s2.push(' ');
		}
	}
	while(!s1.empty()){
		s2.push(s1.top());
		s1.pop();
	}
	while(!s2.empty()){
		s3.push(s2.top());
		s2.pop();
	}
	while(!s3.empty()){
		if(s3.top()==' '){
			p=(char*)str.c_str();
			x=atof(p);
			//cout<<"111"<<endl;
			d.push(x);
			str="";
			if(!s3.empty()&&s3.top()==' ') 
				s3.pop();
		}
		else if(s3.top()=='+'||s3.top()=='-'||s3.top()=='*'||s3.top()=='/'||s3.top()=='^'||s3.top()=='$'||s3.top()=='g'||s3.top()=='n'){
			if(d.size()>=2){
				y=d.top();
				d.pop();
				z=d.top();
				d.pop();
			}
			else{
				y=d.top();
				d.pop();
				z=0;
			}
			switch(s3.top()){
				case '+':
					result=z+y;
					d.push(result);
					break;
				case '-':
					result=0-y+z;
					d.push(result);
					break;
				case '*':
					result=z*y;
					d.push(result);
					break;
				case '/':
					if(y==0){
						MessageBox("输入错误,请重新输入!","提示",MB_ICONINFORMATION);
						m_mystr="";
						UpdateData(FALSE);
						while(!d.empty())
							d.pop();
					}
					else {
						result=z/y;
						d.push(result);
					}
					break;
				case '^':
					result=pow(z,y);
					d.push(result);
					break;
				case '$':
					result=pow(y,1.0/z);
					d.push(result);
					break;
				case '%':
					d.push(z);
					result=y/100;
					d.push(result);
					break;
				case 'n':
					d.push(z);
					result=log(y);
					d.push(result);
					break;
				case 'g':
					d.push(z);
					result=log(y)/log(10);
					d.push(result);
					break;
			}
			if(!s3.empty()) 
				s3.pop();
		}
		else{
			str+=s3.top();
			if(!s3.empty()) 
				s3.pop();
		}
	}
	if(!d.empty()){
	sprintf(p,"%g",d.top());
	m_str=p;
	UpdateData(FALSE);
	SYSTEMTIME sys; 
	GetLocalTime( &sys );
	
	sprintf(p,"%4d-%02d-%02d %02d:%02d:%02d ms:%03d",sys.wYear,sys.wMonth,sys.wDay,sys.wHour,sys.wMinute,sys.wSecond,sys.wMilliseconds); 
    time=p;
    Save();
	}
}

void CCalculatorDlg::Save(){
			/*
			m_CourseSet.Open();
			m_CourseSet.AddNew();
			m_CourseSet.m_coursename=dlg.m_coursename;
			m_CourseSet.m_courseno=dlg.m_courseno;
			m_CourseSet.m_special=dlg.m_special;
			m_CourseSet.m_coursetype=dlg.m_coursetype;
			m_CourseSet.m_openterm = dlg.m_openterm;
			m_CourseSet.m_hours = dlg.m_hours;
			m_CourseSet.m_credit = dlg.m_credit;
			
			m_CourseSet.Update();
			m_CourseSet.Requery();
			m_CourseSet.Close();*/
	m_cal.Open();
	m_cal.AddNew();
	m_cal.m_column1=m_mystr;
	m_cal.m_column2=m_str;
	m_cal.m_column3=time;
	m_cal.Update();
	m_cal.Requery();
	m_cal.Close();
}

void CCalculatorDlg::OnHistory() 
{
	// TODO: Add your control notification handler code here
	CHistory dlg;
	dlg.DoModal();
}

void CCalculatorDlg::OnDecimalconversion() 
{
	// TODO: Add your control notification handler code here
	JZ_Convert dlg;
	dlg.DoModal();
}

void CCalculatorDlg::OnUnitconversion() 
{
	// TODO: Add your control notification handler code here
	Dw_Transform dlg;
	dlg.DoModal();
}


void CCalculatorDlg::OnUpdateEdit6() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function to send the EM_SETEVENTMASK message to the control
	// with the ENM_UPDATE flag ORed into the lParam mask.
	
	// TODO: Add your control notification handler code here
	UpdateData(FALSE);
}

void CCalculatorDlg::OnInvolution() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	m_mystr+=L"^";
	UpdateData(FALSE);
}

void CCalculatorDlg::Onpercent() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	m_mystr+=L"%";
	UpdateData(FALSE);
}

void CCalculatorDlg::Onsquare1() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	m_mystr+=L"$";
	UpdateData(FALSE);
}

void CCalculatorDlg::Ondelete() 
{
	// TODO: Add your control notification handler code here
	m_mystr.Delete(m_mystr.GetLength()-1,1);
	UpdateData(FALSE);
}

void CCalculatorDlg::OnDeg() 
{
	// TODO: Add your control notification handler code here
	
}

void CCalculatorDlg::Onsin2() 
{
	// TODO: Add your control notification handler code here
	double x,y;
	char *p;
	string mm;
	if(((CButton *)GetDlgItem(IDC_Deg))->GetCheck()){
		mm=m_mystr.GetBuffer(0);
		p=(char*)mm.data();
		x=atof(p);
		if((int)x%180==0)
			y=0;
		else
			y=sin((x/180)*acos(-1.0));
		sprintf(p,"%g",y);
		m_str=p;
		OnUpdateEdit6();
	}
	else{
		mm=m_mystr.GetBuffer(0);
		p=(char*)mm.data();
		x=atof(p);
		y=sin(x);
		sprintf(p,"%g",y);
		m_str=p;
		OnUpdateEdit6();
	}
}

void CCalculatorDlg::Oncos() 
{
	// TODO: Add your control notification handler code here
	double x,y;
	char *p;
	string mm;
	if(((CButton *)GetDlgItem(IDC_Deg))->GetCheck()){
		mm=m_mystr.GetBuffer(0);
		p=(char*)mm.data();
		x=atof(p);
		if((int)x%180==90)
			y=0;
		else
			y=cos((x/180)*acos(-1.0));
		sprintf(p,"%g",y);
		m_str=p;
		OnUpdateEdit6();
	}
	else{
		mm=m_mystr.GetBuffer(0);
		p=(char*)mm.data();
		x=atof(p);
		y=cos(x);
		sprintf(p,"%g",y);
		m_str=p;
		OnUpdateEdit6();
	}
}

void CCalculatorDlg::Ontan() 
{
	// TODO: Add your control notification handler code here
	double x,y;
	char *p;
	string mm;
	if(((CButton *)GetDlgItem(IDC_Deg))->GetCheck()){
		mm=m_mystr.GetBuffer(0);
		p=(char*)mm.data();
		x=atof(p);
		if(x==(int)x&&(int)x%180==90){
			MessageBox("输入错误,请重新输入!","提示",MB_ICONINFORMATION);
			m_mystr="";
			UpdateData(FALSE);
		}
		else{
			y=tan((x/180)*acos(-1.0));
			sprintf(p,"%g",y);
			m_str=p;
			OnUpdateEdit6();
		}
	}
	else{
		mm=m_mystr.GetBuffer(0);
		p=(char*)mm.data();
		x=atof(p);
		y=tan(x);
		sprintf(p,"%g",y);
		m_str=p;
		OnUpdateEdit6();
	}
}

void CCalculatorDlg::Oncot() 
{
	// TODO: Add your control notification handler code here
	double x,y;
	char *p;
	string mm;
	if(((CButton *)GetDlgItem(IDC_Deg))->GetCheck()){
		mm=m_mystr.GetBuffer(0);
		p=(char*)mm.data();
		x=atof(p);
		if(x==(int)x&&(int)x%180==0){
			MessageBox("输入错误,请重新输入!","提示",MB_ICONINFORMATION);
			m_mystr="";
			//m_str="";
			UpdateData(FALSE);
		}
		else{
			y=1/(tan((x/180)*acos(-1.0)));
			sprintf(p,"%g",y);
			m_str=p;
			OnUpdateEdit6();
		}
	}
	else{
		mm=m_mystr.GetBuffer(0);
		p=(char*)mm.data();
		x=atof(p);
		y=1/tan(x);
		sprintf(p,"%g",y);
		m_str=p;
		OnUpdateEdit6();
	}
}

void CCalculatorDlg::Onarcsin() 
{
	// TODO: Add your control notification handler code here
	double x,y;
	char *p;
	string mm;
	if(((CButton *)GetDlgItem(IDC_Deg))->GetCheck()){
		mm=m_mystr.GetBuffer(0);
		p=(char*)mm.data();
		x=atof(p);
		y=180*asin(x)/acos(-1.0);
		sprintf(p,"%g",y);
		m_str=p;
		OnUpdateEdit6();
	}
	else{
		mm=m_mystr.GetBuffer(0);
		p=(char*)mm.data();
		x=atof(p);
		y=asin(x);
		sprintf(p,"%g",y);
		m_str=p;
		OnUpdateEdit6();
	}
}

void CCalculatorDlg::Onarccos() 
{
	// TODO: Add your control notification handler code here
		double x,y;
	char *p;
	string mm;
	if(((CButton *)GetDlgItem(IDC_Deg))->GetCheck()){
		mm=m_mystr.GetBuffer(0);
		p=(char*)mm.data();
		x=atof(p);
		y=180*acos(x)/acos(-1.0);
		sprintf(p,"%g",y);
		m_str=p;
		OnUpdateEdit6();
	}
	else{
		mm=m_mystr.GetBuffer(0);
		p=(char*)mm.data();
		x=atof(p);
		y=acos(x);
		sprintf(p,"%g",y);
		m_str=p;
		OnUpdateEdit6();
	}
}

void CCalculatorDlg::Onarctan() 
{
	// TODO: Add your control notification handler code here
		double x,y;
	char *p;
	string mm;
	if(((CButton *)GetDlgItem(IDC_Deg))->GetCheck()){
		mm=m_mystr.GetBuffer(0);
		p=(char*)mm.data();
		x=atof(p);
		y=180*atan(x)/acos(-1.0);
		sprintf(p,"%g",y);
		m_str=p;
		OnUpdateEdit6();
	}
	else{
		mm=m_mystr.GetBuffer(0);
		p=(char*)mm.data();
		x=atof(p);
		y=atan(x);
		sprintf(p,"%g",y);
		m_str=p;
		OnUpdateEdit6();
	}
}

void CCalculatorDlg::Onarccot() 
{
	// TODO: Add your control notification handler code here
	double x,y;
	char *p;
	string mm;
	if(((CButton *)GetDlgItem(IDC_Deg))->GetCheck()){
		mm=m_mystr.GetBuffer(0);
		p=(char*)mm.data();
		x=atof(p);
		y=180*(1/atan(x))/acos(-1.0);
		sprintf(p,"%g",y);
		m_str=p;
		OnUpdateEdit6();
	}
	else{
		mm=m_mystr.GetBuffer(0);
		p=(char*)mm.data();
		x=atof(p);
		y=(1/atan(x));
		sprintf(p,"%g",y);
		m_str=p;
		OnUpdateEdit6();
	}
}

void CCalculatorDlg::Onpoint() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	m_mystr+=L".";
	UpdateData(FALSE);
}

void CCalculatorDlg::Onlg() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	m_mystr+=L"g";
	UpdateData(FALSE);
}

void CCalculatorDlg::Onln() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	m_mystr+=L"n";
	UpdateData(FALSE);
}

void CCalculatorDlg::Onleft() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	m_mystr+=L"(";
	UpdateData(FALSE);
}

void CCalculatorDlg::Onright() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	m_mystr+=L")";
	UpdateData(FALSE);
}

void CCalculatorDlg::Onfan() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	m_mystr+=L"_";
	UpdateData(FALSE);
}

void CCalculatorDlg::Onfuhao() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	m_mystr+=L"_";
	UpdateData(FALSE);
}

int CAboutDlg::DoModal() 
{
	// TODO: Add your specialized code here and/or call the base class
	
	return CDialog::DoModal();
}

void CCalculatorDlg::OnHelp() 
{
	// TODO: Add your control notification handler code here
	CAboutDlg dlg;
	dlg.DoModal();
}
