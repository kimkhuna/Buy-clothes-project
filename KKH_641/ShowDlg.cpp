// ShowDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "KKH_641.h"
#include "ShowDlg.h"
#include "afxdialogex.h"


// CShowDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CShowDlg, CDialogEx)

CShowDlg::CShowDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_SHOW_641, pParent)
	, m_strResult_641(_T(""))
{

}

CShowDlg::~CShowDlg()
{
}

void CShowDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_RESULT_641, m_strResult_641);
}


BEGIN_MESSAGE_MAP(CShowDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_HOME_641, &CShowDlg::OnClickedButtonHome641)
	ON_STN_CLICKED(IDC_STATIC_BITMAP1_641, &CShowDlg::OnClickedStaticBitmap1641)
	ON_STN_CLICKED(IDC_STATIC_BITMAP2_641, &CShowDlg::OnClickedStaticBitmap2641)
	ON_STN_CLICKED(IDC_STATIC_BITMAP3_641, &CShowDlg::OnClickedStaticBitmap3641)
	ON_STN_CLICKED(IDC_STATIC_BITMAP4_641, &CShowDlg::OnClickedStaticBitmap4641)
	ON_STN_CLICKED(IDC_STATIC_BITMAP5_641, &CShowDlg::OnClickedStaticBitmap5641)
END_MESSAGE_MAP()


// CShowDlg 메시지 처리기입니다.


void CShowDlg::OnClickedButtonHome641()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	OnOK();
}


void CShowDlg::OnClickedStaticBitmap1641()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);

	HDC hMemDC;
	CClientDC dc(this);
	HBITMAP hBmp;
	hBmp = LoadBitmap(AfxGetInstanceHandle(), _T("IDB_BITMAP_CARDIGAN"));

	hMemDC = CreateCompatibleDC(dc);
	SelectObject(hMemDC, hBmp);
	
	m_strResult_641 = _T("가디건");
	UpdateData(FALSE);
	
}


void CShowDlg::OnClickedStaticBitmap2641()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);

	HDC hMemDC;
	CClientDC dc(this);
	HBITMAP hBmp;
	hBmp = LoadBitmap(AfxGetInstanceHandle(), _T("IDB_BITMAP_HOODT"));

	hMemDC = CreateCompatibleDC(dc);
	SelectObject(hMemDC, hBmp);

	m_strResult_641 = _T("후드티");
	UpdateData(FALSE);
}


void CShowDlg::OnClickedStaticBitmap3641()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);

	HDC hMemDC;
	CClientDC dc(this);
	HBITMAP hBmp;
	hBmp = LoadBitmap(AfxGetInstanceHandle(), _T("IDB_BITMAP_MTM"));

	hMemDC = CreateCompatibleDC(dc);
	SelectObject(hMemDC, hBmp);

	m_strResult_641 = _T("맨투맨");
	UpdateData(FALSE);
}


void CShowDlg::OnClickedStaticBitmap4641()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);

	HDC hMemDC;
	CClientDC dc(this);
	HBITMAP hBmp;
	hBmp = LoadBitmap(AfxGetInstanceHandle(), _T("IDB_BITMAP_LONGP"));

	hMemDC = CreateCompatibleDC(dc);
	SelectObject(hMemDC, hBmp);

	m_strResult_641 = _T("롱패딩");
	UpdateData(FALSE);
}


void CShowDlg::OnClickedStaticBitmap5641()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);

	HDC hMemDC;
	CClientDC dc(this);
	HBITMAP hBmp;
	hBmp = LoadBitmap(AfxGetInstanceHandle(), _T("IDB_BITMAP_COAT"));

	hMemDC = CreateCompatibleDC(dc);
	SelectObject(hMemDC, hBmp);

	m_strResult_641 = _T("코트");
	UpdateData(FALSE);
}
