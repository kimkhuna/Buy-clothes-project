#pragma once


// CShowDlg 대화 상자입니다.

class CShowDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CShowDlg)

public:
	CShowDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CShowDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_SHOW_641 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClickedButtonHome641();
	afx_msg void OnClickedStaticBitmap1641();
	afx_msg void OnClickedStaticBitmap2641();
	afx_msg void OnClickedStaticBitmap3641();
	afx_msg void OnClickedStaticBitmap4641();
	afx_msg void OnClickedStaticBitmap5641();
	CString m_strResult_641;
};
