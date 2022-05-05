
// KKH_641Dlg.h : 헤더 파일
//

#pragma once


#include "afxwin.h"

#include "Orders.h"
#include "ListDlg.h"
#include "ShowDlg.h"
#include "CancelDlg.h"
/////////////////////

//////////////////



// CKKH_641Dlg 대화 상자
class CKKH_641Dlg : public CDialogEx
{
// 생성입니다.
public:
	CKKH_641Dlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

	
	CListDlg m_ListDlg;
	CShowDlg m_ShowDlg;
	CCancelDlg m_CancelDlg;
	

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_KKH_641_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnStnClickedBitmapLogo();
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnEnChangeEdit2();
	CString m_strAddress_641;
	CString m_strCost_641;
	CString m_strId_641;
	CString m_strName_641;
	BOOL m_rSize_641;
	afx_msg void OnClickedButtonList641();
	afx_msg void OnClickedButtonShow641();
	afx_msg void OnClickedButtonCancel641();
	void DeliveryCost();
	void ProductSize();
	void Clear();
	afx_msg void OnClickedButtonBuy641();
	CComboBox m_cbBuy_641;
	CComboBox m_cbPay_641;
//	LONG m_strCount_641;
	afx_msg void OnClickedButtonExit641();


	afx_msg void OnClickedButtonClear641();
	CString m_strCount_641;
};
