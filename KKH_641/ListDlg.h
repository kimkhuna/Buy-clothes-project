#pragma once
#include "afxcmn.h"
#include "Orders.h"

// CListDlg 대화 상자입니다.

class CListDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CListDlg)

public:
	CListDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CListDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_LIST_641 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_listOut_641;
	virtual BOOL OnInitDialog();
	afx_msg void OnClickedButtonHome641();
	CTreeCtrl m_treeOut_641;

	//////////////////////////// TREE 변수
	TVINSERTSTRUCT tInsert;
	HTREEITEM hBuy;
	HTREEITEM hCardigan;
	HTREEITEM hLongP;
	HTREEITEM hCoat;
	HTREEITEM hMtM;
	HTREEITEM hHoodT;

	CString strParent;
	CString strChild;
	afx_msg void OnDblclkListOut641(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnClickedButtonExcel641();
};
