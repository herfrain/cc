// Dw_Transform.cpp : implementation file
//

#include "stdafx.h"
#include "calculator.h"
#include "Dw_Transform.h"
#include "Length.h"
#include "Area.h"
#include "Weight.h"
#include "Volum.h"
#include "_Time.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Dw_Transform dialog


Dw_Transform::Dw_Transform(CWnd* pParent /*=NULL*/)
	: CDialog(Dw_Transform::IDD, pParent)
{
	//{{AFX_DATA_INIT(Dw_Transform)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void Dw_Transform::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Dw_Transform)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Dw_Transform, CDialog)
	//{{AFX_MSG_MAP(Dw_Transform)
	ON_BN_CLICKED(IDC_DW_B_Length, OnDWBLength)
	ON_BN_CLICKED(IDC_DW_B_Area, OnDWBArea)
	ON_BN_CLICKED(IDC_DW_B_Volum, OnDWBVolum)
	ON_BN_CLICKED(IDC_DW_B_Weight, OnDWBWeight)
	ON_BN_CLICKED(IDC_DW_B_Time, OnDWBTime)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Dw_Transform message handlers

int Dw_Transform::DoModal() 
{
	// TODO: Add your specialized code here and/or call the base class
	
	return CDialog::DoModal();
}

void Dw_Transform::OnDWBLength() 
{
	// TODO: Add your control notification handler code here
	CLength dlg;
	dlg.DoModal();
}

void Dw_Transform::OnDWBArea() 
{
	// TODO: Add your control notification handler code here
	CArea dlg;
	dlg.DoModal();
}

void Dw_Transform::OnDWBVolum() 
{
	// TODO: Add your control notification handler code here
	CVolum dlg;
	dlg.DoModal();
}

void Dw_Transform::OnDWBWeight() 
{
	// TODO: Add your control notification handler code here
	CWeight dlg;
	dlg.DoModal();
}

void Dw_Transform::OnDWBTime() 
{
	// TODO: Add your control notification handler code here
	C_Time dlg;
	dlg.DoModal();
}
