#if !defined(AFX_CALCULATORMDB_H__F9774BAD_83D2_4D1D_845F_E1727DAFC9B5__INCLUDED_)
#define AFX_CALCULATORMDB_H__F9774BAD_83D2_4D1D_845F_E1727DAFC9B5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CalculatorMdb.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCalculatorMdb recordset

class CCalculatorMdb : public CRecordset
{
public:
	CCalculatorMdb(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CCalculatorMdb)

// Field/Param Data
	//{{AFX_FIELD(CCalculatorMdb, CRecordset)
	long	m_ID;
	CString	m_column1;
	CString	m_column2;
	CString	m_column3;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCalculatorMdb)
	public:
	virtual CString GetDefaultConnect();    // Default connection string
	virtual CString GetDefaultSQL();    // Default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);  // RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CALCULATORMDB_H__F9774BAD_83D2_4D1D_845F_E1727DAFC9B5__INCLUDED_)
