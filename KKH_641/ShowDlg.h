#pragma once


// CShowDlg ��ȭ �����Դϴ�.

class CShowDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CShowDlg)

public:
	CShowDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CShowDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_SHOW_641 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

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
