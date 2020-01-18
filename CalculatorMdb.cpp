// CalculatorMdb.cpp : implementation file
//

#include "stdafx.h"
#include "calculator.h"
#include "CalculatorMdb.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCalculatorMdb

IMPLEMENT_DYNAMIC(CCalculatorMdb, CRecordset)

CCalculatorMdb::CCalculatorMdb(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CCalculatorMdb)
	m_ID = 0;
	m_column1 = _T("");
	m_column2 = _T("");
	m_column3 = _T("");
	m_nFields = 4;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CCalculatorMdb::GetDefaultConnect()
{
	return _T("ODBC;DSN=calculator");
}

CString CCalculatorMdb::GetDefaultSQL()
{
	return _T("[历史记录]");
}

void CCalculatorMdb::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CCalculatorMdb)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[表达式]"), m_column1);
	RFX_Text(pFX, _T("[答案]"), m_column2);
	RFX_Text(pFX, _T("[时间]"), m_column3);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CCalculatorMdb diagnostics

#ifdef _DEBUG
void CCalculatorMdb::AssertValid() const
{
	CRecordset::AssertValid();
}

void CCalculatorMdb::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
