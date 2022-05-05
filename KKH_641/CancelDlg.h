#pragma once
#include "Orders.h"
#include "afxwin.h"


// CCancelDlg 대화 상자입니다.

class CCancelDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CCancelDlg)

public:
	CCancelDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CCancelDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_CANCEL_641 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnButtonExit641();
	afx_msg void OnClickedButtonHome641();
	virtual BOOL OnInitDialog();
	afx_msg void OnClickedButtonFirst641();
	CString m_strPay_641;
	CString m_strBuy_641;
	afx_msg void OnClickedButtonPrev641();
	afx_msg void OnClickedButtonNext641();
	CComboBox m_cb_OutBuy_641;
	CComboBox m_cb_OutPay_641;
	CComboBox m_cbFind_641;
	CString m_strFind_641;
	int m_nSelected_641;
	afx_msg void OnSelchangeComboFind641();
	afx_msg void OnClickedButtonFind641();
	afx_msg void OnClickedButtonCancel641();
	CString m_strOutCount_641;
	CString m_strOutId_641;
	CString m_strOutName_641;
	CString m_strOutCost_641;
	CString m_strOutAddress_641;
	void ProductSize();
	CString m_strOutPay_641;
	CString m_strOutBuy_641;
	void DeliveryCost();
	afx_msg void OnClickedButtonLast641();
};
