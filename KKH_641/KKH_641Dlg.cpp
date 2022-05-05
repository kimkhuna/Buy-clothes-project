
// KKH_641Dlg.cpp : ���� ����
//

#include "stdafx.h"
#include "KKH_641.h"
#include "KKH_641Dlg.h"
#include "afxdialogex.h"

COrders m_pSet;


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();


// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
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


// CKKH_641Dlg ��ȭ ����



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


// CKKH_641Dlg �޽��� ó����

BOOL CKKH_641Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
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

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	m_cbBuy_641.InsertString(0, _T("�����"));
	m_cbBuy_641.InsertString(1, _T("�ĵ�Ƽ"));
	m_cbBuy_641.InsertString(2, _T("������"));
	m_cbBuy_641.InsertString(3, _T("���е�"));
	m_cbBuy_641.InsertString(4, _T("��Ʈ"));

	///////////////////////////////////////////
	m_cbPay_641.InsertString(0, _T("�ſ�/üũī��"));
	m_cbPay_641.InsertString(1, _T("�޴���"));
	m_cbPay_641.InsertString(2, _T("������ü"));
	m_cbPay_641.InsertString(3, _T("�������Ա�"));

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

	





	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CKKH_641Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CKKH_641Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CKKH_641Dlg::OnStnClickedBitmapLogo()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CKKH_641Dlg::OnCbnSelchangeCombo1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CKKH_641Dlg::OnEnChangeEdit2()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CKKH_641Dlg::OnClickedButtonList641()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_ListDlg.DoModal();
}


void CKKH_641Dlg::OnClickedButtonShow641()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_ShowDlg.DoModal();
}


void CKKH_641Dlg::OnClickedButtonCancel641()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_CancelDlg.DoModal();
}


void CKKH_641Dlg::DeliveryCost()
{
	if ((m_pSet.m_Or_Count) >= "3")
	{
		m_strCost_641 = _T("����");
	}
	else if((m_pSet.m_Or_Count) < "3")
	{
		m_strCost_641 = _T("3000��");
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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

	AfxMessageBox(_T("�ֹ��� �Ϸ�Ǿ����ϴ�."));
	
}


void CKKH_641Dlg::OnClickedButtonExit641()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	PostQuitMessage(0);
}


BOOL CAboutDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void CKKH_641Dlg::OnClickedButtonClear641()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	Clear();
}
