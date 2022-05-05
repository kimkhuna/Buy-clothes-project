// ShowDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "KKH_641.h"
#include "ShowDlg.h"
#include "afxdialogex.h"


// CShowDlg ��ȭ �����Դϴ�.

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


// CShowDlg �޽��� ó�����Դϴ�.


void CShowDlg::OnClickedButtonHome641()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	OnOK();
}


void CShowDlg::OnClickedStaticBitmap1641()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);

	HDC hMemDC;
	CClientDC dc(this);
	HBITMAP hBmp;
	hBmp = LoadBitmap(AfxGetInstanceHandle(), _T("IDB_BITMAP_CARDIGAN"));

	hMemDC = CreateCompatibleDC(dc);
	SelectObject(hMemDC, hBmp);
	
	m_strResult_641 = _T("�����");
	UpdateData(FALSE);
	
}


void CShowDlg::OnClickedStaticBitmap2641()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);

	HDC hMemDC;
	CClientDC dc(this);
	HBITMAP hBmp;
	hBmp = LoadBitmap(AfxGetInstanceHandle(), _T("IDB_BITMAP_HOODT"));

	hMemDC = CreateCompatibleDC(dc);
	SelectObject(hMemDC, hBmp);

	m_strResult_641 = _T("�ĵ�Ƽ");
	UpdateData(FALSE);
}


void CShowDlg::OnClickedStaticBitmap3641()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);

	HDC hMemDC;
	CClientDC dc(this);
	HBITMAP hBmp;
	hBmp = LoadBitmap(AfxGetInstanceHandle(), _T("IDB_BITMAP_MTM"));

	hMemDC = CreateCompatibleDC(dc);
	SelectObject(hMemDC, hBmp);

	m_strResult_641 = _T("������");
	UpdateData(FALSE);
}


void CShowDlg::OnClickedStaticBitmap4641()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);

	HDC hMemDC;
	CClientDC dc(this);
	HBITMAP hBmp;
	hBmp = LoadBitmap(AfxGetInstanceHandle(), _T("IDB_BITMAP_LONGP"));

	hMemDC = CreateCompatibleDC(dc);
	SelectObject(hMemDC, hBmp);

	m_strResult_641 = _T("���е�");
	UpdateData(FALSE);
}


void CShowDlg::OnClickedStaticBitmap5641()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);

	HDC hMemDC;
	CClientDC dc(this);
	HBITMAP hBmp;
	hBmp = LoadBitmap(AfxGetInstanceHandle(), _T("IDB_BITMAP_COAT"));

	hMemDC = CreateCompatibleDC(dc);
	SelectObject(hMemDC, hBmp);

	m_strResult_641 = _T("��Ʈ");
	UpdateData(FALSE);
}
