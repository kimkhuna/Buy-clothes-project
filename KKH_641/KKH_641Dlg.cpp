
// KKH_641Dlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "KKH_641.h"
#include "KKH_641Dlg.h"
#include "afxdialogex.h"

COrders m_pSet;


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();


// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CKKH_641Dlg 대화 상자



CKKH_641Dlg::CKKH_641Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_KKH_641_DIALOG, pParent)
	, m_strAddress_641(_T(""))
	, m_strCost_641(_T(""))
	, m_strId_641(_T(""))
	, m_strName_641(_T(""))
	, m_rSize_641(FALSE)
	, m_strCount_641(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CKKH_641Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_ADDRESS_641, m_strAddress_641);
	DDX_Text(pDX, IDC_EDIT_COST_641, m_strCost_641);
	DDX_Text(pDX, IDC_EDIT_ID_641, m_strId_641);
	DDX_Text(pDX, IDC_EDIT_NAME_641, m_strName_641);
	DDX_Radio(pDX, IDC_RADIOS_641, m_rSize_641);
	DDX_Control(pDX, IDC_COMBO_BUY_641, m_cbBuy_641);
	DDX_Control(pDX, IDC_COMBO_PAY_641, m_cbPay_641);
	DDX_Text(pDX, IDC_EDIT_COUNT_641, m_strCount_641);
}

BEGIN_MESSAGE_MAP(CKKH_641Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_LIST_641, &CKKH_641Dlg::OnClickedButtonList641)
	ON_BN_CLICKED(IDC_BUTTON_SHOW_641, &CKKH_641Dlg::OnClickedButtonShow641)
	ON_BN_CLICKED(IDC_BUTTON_CANCEL_641, &CKKH_641Dlg::OnClickedButtonCancel641)
	ON_BN_CLICKED(IDC_BUTTON_BUY_641, &CKKH_641Dlg::OnClickedButtonBuy641)
	ON_BN_CLICKED(IDC_BUTTON_EXIT_641, &CKKH_641Dlg::OnClickedButtonExit641)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR_641, &CKKH_641Dlg::OnClickedButtonClear641)
END_MESSAGE_MAP()


// CKKH_641Dlg 메시지 처리기

BOOL CKKH_641Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	m_cbBuy_641.InsertString(0, _T("가디건"));
	m_cbBuy_641.InsertString(1, _T("후드티"));
	m_cbBuy_641.InsertString(2, _T("맨투맨"));
	m_cbBuy_641.InsertString(3, _T("롱패딩"));
	m_cbBuy_641.InsertString(4, _T("코트"));

	///////////////////////////////////////////
	m_cbPay_641.InsertString(0, _T("신용/체크카드"));
	m_cbPay_641.InsertString(1, _T("휴대폰"));
	m_cbPay_641.InsertString(2, _T("계좌이체"));
	m_cbPay_641.InsertString(3, _T("무통장입금"));

	//////////////////////////////////////////////
	m_pSet.Open();

	if (m_pSet.GetRecordCount() > 0)
	{
		m_pSet.MoveFirst();
		m_strId_641 = m_pSet.m_Or_Id;
		m_strName_641 = m_pSet.m_Or_Name;

		m_strAddress_641 = m_pSet.m_Or_Address;
		

		UpdateData(false);
	}

	





	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CKKH_641Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CKKH_641Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CKKH_641Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CKKH_641Dlg::OnStnClickedBitmapLogo()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CKKH_641Dlg::OnCbnSelchangeCombo1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CKKH_641Dlg::OnEnChangeEdit2()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CKKH_641Dlg::OnClickedButtonList641()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_ListDlg.DoModal();
}


void CKKH_641Dlg::OnClickedButtonShow641()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_ShowDlg.DoModal();
}


void CKKH_641Dlg::OnClickedButtonCancel641()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_CancelDlg.DoModal();
}


void CKKH_641Dlg::DeliveryCost()
{
	if ((m_pSet.m_Or_Count) >= "3")
	{
		m_strCost_641 = _T("무료");
	}
	else if((m_pSet.m_Or_Count) < "3")
	{
		m_strCost_641 = _T("3000원");
	}
}


void CKKH_641Dlg::ProductSize()
{
	if (m_pSet.m_Or_Size.Trim() == "S")
	{
		m_rSize_641 = 0;
	}
	else if (m_pSet.m_Or_Size.Trim() == "M")
	{
		m_rSize_641 = 1;
	}
	else if (m_pSet.m_Or_Size.Trim() == "L")
	{
		m_rSize_641 = 2;
	}
}


void CKKH_641Dlg::Clear()
{
	GetDlgItem(IDC_EDIT_ID_641)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT_NAME_641)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT_ADDRESS_641)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT_COUNT_641)->SetWindowText(_T(""));
}


void CKKH_641Dlg::OnClickedButtonBuy641()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	int a;
	m_pSet.AddNew();
	m_pSet.m_Or_Id = m_strId_641;
	m_pSet.m_Or_Name = m_strName_641;
	m_pSet.m_Or_Address = m_strAddress_641;
	
	m_cbBuy_641.GetLBText(m_cbBuy_641.GetCurSel(), m_pSet.m_Or_Products);
	m_cbPay_641.GetLBText(m_cbPay_641.GetCurSel(), m_pSet.m_Or_Buy);

	m_pSet.m_Or_Count = m_strCount_641;
	DeliveryCost();

	
	if (m_rSize_641 == 0)
	{
		m_pSet.m_Or_Size = _T("S");
	}
	else if (m_rSize_641 == 1)
	{
		m_pSet.m_Or_Size = _T("M");
	}
	else if (m_rSize_641 == 2)
	{
		m_pSet.m_Or_Size = _T("L");
	}

	m_pSet.Update();
	m_pSet.Requery();
	UpdateData(FALSE);

	AfxMessageBox(_T("주문이 완료되었습니다."));
	
}


void CKKH_641Dlg::OnClickedButtonExit641()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	PostQuitMessage(0);
}


BOOL CAboutDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CKKH_641Dlg::OnClickedButtonClear641()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Clear();
}
