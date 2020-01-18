// History.cpp : implementation file
//

#include "stdafx.h"
#include "calculator.h"
#include "History.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHistory dialog


CHistory::CHistory(CWnd* pParent /*=NULL*/)
	: CDialog(CHistory::IDD, pParent)
{
	//{{AFX_DATA_INIT(CHistory)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CHistory::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CHistory)
	DDX_Control(pDX, IDC_LIST4, m_list);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CHistory, CDialog)
	//{{AFX_MSG_MAP(CHistory)
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHistory message handlers

int CHistory::DoModal() 
{
	// TODO: Add your specialized code here and/or call the base class
	
	return CDialog::DoModal();
}

BOOL CHistory::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here

	Display();//显示数据

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


void CHistory::Display()
{
	//初始化ListCtrl
	m_list.DeleteAllItems();
	while(m_list.DeleteColumn(0));

	CRecordset *cSet;
	cSet = &m_cal;
	cSet->Open();
	CODBCFieldInfo field;
	for( UINT i=0; i< cSet->m_nFields;i++)
	{
		cSet->GetODBCFieldInfo(i,field);
		m_list.InsertColumn(i,field.m_strName,LVCFMT_LEFT,100);
	}

	int m_nItem=0;
	CString str;
	while( ! cSet->IsEOF())
	{
		for(UINT i=0;i<cSet->m_nFields;i++)
		{
			cSet->GetFieldValue(i,str);
			if(i==0)
				m_list.InsertItem(m_nItem,str);
			else
				m_list.SetItemText(m_nItem,i,str);
		}
		m_nItem++;
		cSet->MoveNext();
	}

	cSet->Close();

}


void CHistory::OnSize(UINT nType, int cx, int cy) 
{
	/*CDialog::OnSize(nType, cx, cy);  
    if(nType==1) return;//最小化则什么都不做  
    // TODO: Add your message handler code here  
    CWnd *pWnd;   
    pWnd = GetDlgItem(IDC_LIST4);  
    ChangeSize(pWnd, cx, cy);  
    GetClientRect(&m_rect);// 将变化后的对话框大小设为旧大小 */
	
}

void CHistory::ChangeSize(CWnd *pWnd, int cx, int cy)
{
    /*if(pWnd)  //判断是否为空，因为对话框创建时会调用此函数，而当时控件还未创建
    {
        CRect rect;   //获取控件变化前的大小 
        pWnd->GetWindowRect(&rect);
        ScreenToClient(&rect);//将控件大小转换为在对话框中的区域坐标
 
        //    cx/m_rect.Width()为对话框在横向的变化比例
        rect.left=rect.left*cx/m_rect.Width();//调整控件大小
        rect.right=rect.right*cx/m_rect.Width();
        rect.top=rect.top*cy/m_rect.Height();
        rect.bottom=rect.bottom*cy/m_rect.Height();
        pWnd->MoveWindow(rect);//设置控件大小
    }*/
}