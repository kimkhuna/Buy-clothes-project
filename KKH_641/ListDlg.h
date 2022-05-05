#pragma once
#include "afxcmn.h"
#include "Orders.h"

// CListDlg ��ȭ �����Դϴ�.

class CListDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CListDlg)

public:
	CListDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CListDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_LIST_641 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_listOut_641;
	virtual BOOL OnInitDialog();
	afx_msg void OnClickedButtonHome641();
	CTreeCtrl m_treeOut_641;

	//////////////////////////// TREE ����
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
