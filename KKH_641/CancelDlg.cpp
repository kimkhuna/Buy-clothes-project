// CancelDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "KKH_641.h"
#include "CancelDlg.h"
#include "afxdialogex.h"





// CCancelDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CCancelDlg, CDialogEx)

CCancelDlg::CCancelDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_CANCEL_641, pParent)
	, m_strPay_641(_T(""))
	, m_strBuy_641(_T(""))
	, m_strFind_641(_T(""))
	, m_nSelected_641(0)
	, m_strOutCount_641(_T(""))
	, m_strOutId_641(_T(""))
	, m_strOutName_641(_T(""))
	, m_strOutCost_641(_T(""))
	, m_strOutAddress_641(_T(""))
	, m_strOutPay_641(_T(""))
	, m_strOutBuy_641(_T(""))
{

}

CCancelDlg::~CCancelDlg()
{
}

void CCancelDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_FIND_641, m_cbFind_641);
	DDX_Text(pDX, IDC_EDIT_COUNT_641, m_strOutCount_641);
	DDX_Text(pDX, IDC_EDIT_ID_641, m_strOutId_641);
	DDX_Text(pDX, IDC_EDIT_NAME_641, m_strOutName_641);
	DDX_Text(pDX, IDC_EDIT_ADDRESS_641, m_strOutAddress_641);
	DDX_Text(pDX, IDC_EDIT_PAY_641, m_strOutPay_641);
	DDX_Text(pDX, IDC_EDIT_BUY_641, m_strOutBuy_641);
}


BEGIN_MESSAGE_MAP(CCancelDlg, CDialogEx)
ON_BN_CLICKED(IDC_BUTTON_HOME_641, &CCancelDlg::OnClickedButtonHome641)
ON_BN_CLICKED(IDC_BUTTON_FIRST_641, &CCancelDlg::OnClickedButtonFirst641)
ON_BN_CLICKED(IDC_BUTTON_PREV_641, &CCancelDlg::OnClickedButtonPrev641)
ON_BN_CLICKED(IDC_BUTTON_NEXT_641, &CCancelDlg::OnClickedButtonNext641)
ON_CBN_SELCHANGE(IDC_COMBO_FIND_641, &CCancelDlg::OnSelchangeComboFind641)
ON_BN_CLICKED(IDC_BUTTON_FIND_641, &CCancelDlg::OnClickedButtonFind641)
ON_BN_CLICKED(IDC_BUTTON_CANCEL_641, &CCancelDlg::OnClickedButtonCancel641)
ON_BN_CLICKED(IDC_BUTTON_LAST_641, &CCancelDlg::OnClickedButtonLast641)
END_MESSAGE_MAP()


// CCancelDlg �޽��� ó�����Դϴ�.



void CCancelDlg::OnClickedButtonHome641()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	OnOK();
}


BOOL CCancelDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	///

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

	//


	COrders m_pSet;
	
	

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.


	if (!m_pSet.Open())
	{
		AfxMessageBox(_T("������ �ҽ��� ���� ����"));
	}

	int i = 0;
	CString str;

	if (m_pSet.GetRecordCount() > 0)
	{

		m_pSet.MoveFirst();
		m_strOutId_641 = m_pSet.m_Or_Id;
		m_strOutName_641 = m_pSet.m_Or_Name;
		m_strOutAddress_641 = m_pSet.m_Or_Address;
		m_strOutCount_641 = m_pSet.m_Or_Count;
		m_strOutBuy_641 = m_pSet.m_Or_Products;
		m_strOutPay_641 = m_pSet.m_Or_Buy;


		UpdateData(false);
	}



	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void CCancelDlg::OnClickedButtonFirst641()
{

	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.


	COrders m_pSet;
	

	m_pSet.Open();

	m_pSet.MoveFirst();


	m_strOutId_641 = m_pSet.m_Or_Id;
	m_strOutName_641 = m_pSet.m_Or_Name;
	m_strOutAddress_641 = m_pSet.m_Or_Address;
	m_strOutCount_641 = m_pSet.m_Or_Count;
	m_strOutBuy_641 = m_pSet.m_Or_Products;
	m_strOutPay_641 = m_pSet.m_Or_Buy;

	UpdateData(false);
	
}


void CCancelDlg::OnClickedButtonPrev641()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	COrders m_pSet;

	m_pSet.Open();

	m_pSet.m_strSort = "m_Or_ID";
	m_pSet.Requery();


	if (m_pSet.IsBOF())
	{
		AfxMessageBox(_T("ù��° �������Դϴ�."));
		m_pSet.MoveNext();
	}
	else
	{
		m_pSet.MovePrev();
	}
	m_strOutId_641 = m_pSet.m_Or_Id;
	m_strOutName_641 = m_pSet.m_Or_Name;

	m_strOutAddress_641 = m_pSet.m_Or_Address;
	m_strOutCount_641 = m_pSet.m_Or_Count;
	m_strOutBuy_641 = m_pSet.m_Or_Products;
	m_strOutPay_641 = m_pSet.m_Or_Buy;

	UpdateData(false);

}


void CCancelDlg::OnClickedButtonNext641()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	COrders m_pSet;

	m_pSet.Open();
	
	m_pSet.MoveNext();

	m_strOutId_641 = m_pSet.m_Or_Id;
	m_strOutName_641 = m_pSet.m_Or_Name;

	m_strOutAddress_641 = m_pSet.m_Or_Address;
	m_strOutCount_641 = m_pSet.m_Or_Count;
	m_strOutBuy_641 = m_pSet.m_Or_Products;
	m_strOutPay_641 = m_pSet.m_Or_Buy;

	UpdateData(false);

}


void CCancelDlg::OnSelchangeComboFind641()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_nSelected_641 = ((CComboBox *)GetDlgItem(IDC_COMBO_FIND_641))->GetCurSel();
	
}


void CCancelDlg::OnClickedButtonFind641()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	
	COrders m_pSet;

	m_pSet.Open();

	char m_strFind_641[500];

	memset(m_strFind_641, 0x00, sizeof(m_strFind_641));
	::GetDlgItemText(this->m_hWnd, IDC_EDIT_FIND_641, m_strFind_641, sizeof(m_strFind_641));

	switch (m_nSelected_641)
	{
	case 0:

		m_pSet.m_strFilter.Format("Or_Id='%s'", m_strFind_641);
		m_pSet.Requery();

		m_strOutId_641 = m_pSet.m_Or_Id;
		m_strOutName_641 = m_pSet.m_Or_Name;

		m_strOutAddress_641 = m_pSet.m_Or_Address;
		m_strOutCount_641 = m_pSet.m_Or_Count;
		m_strOutBuy_641 = m_pSet.m_Or_Products;
		m_strOutPay_641 = m_pSet.m_Or_Buy;


		UpdateData(FALSE);

		m_pSet.m_strFilter.Empty();
		m_pSet.Requery();

		break;


	case 1:

		m_pSet.m_strFilter.Format("Or_Name='%s'", m_strFind_641);
		m_pSet.Requery();

		m_strOutId_641 = m_pSet.m_Or_Id;
		m_strOutName_641 = m_pSet.m_Or_Name;

		m_strOutAddress_641 = m_pSet.m_Or_Address;
		m_strOutCount_641 = m_pSet.m_Or_Count;
		m_strOutBuy_641 = m_pSet.m_Or_Products;
		m_strOutPay_641 = m_pSet.m_Or_Buy;

		UpdateData(FALSE);

		m_pSet.m_strFilter.Empty();
		m_pSet.Requery();

		break;
	}
}


void CCancelDlg::OnClickedButtonCancel641()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	COrders m_pSet;

	m_pSet.Open();

	if (MessageBox("�����Ͻðڽ��ϱ�?", "����", MB_ICONQUESTION | MB_YESNO) == IDNO)
		return;

	if (m_pSet.IsEOF())
	{
		m_pSet.MovePrev();
		m_pSet.Delete();
		AfxMessageBox(_T("�����Ͱ� �����Ǿ����ϴ�."));
		m_pSet.MovePrev();
	}

	else if (m_pSet.IsBOF())
	{
		m_pSet.MoveNext();
		m_pSet.Delete();
		AfxMessageBox(_T("�����Ͱ� �����Ǿ����ϴ�."));
		m_pSet.MoveNext();
	}

	else 
	{	
		m_pSet.Delete();
		AfxMessageBox(_T("�����Ͱ� �����Ǿ����ϴ�."));
		m_pSet.MoveNext();
	}

	m_strOutId_641 = m_pSet.m_Or_Id;
	m_strOutName_641 = m_pSet.m_Or_Name;

	m_strOutAddress_641 = m_pSet.m_Or_Address;
	m_strOutCount_641 = m_pSet.m_Or_Count;
	m_strOutBuy_641 = m_pSet.m_Or_Products;
	m_strOutPay_641 = m_pSet.m_Or_Buy;


	m_pSet.m_strFilter.Empty();
	m_pSet.Requery();

	UpdateData(false);

	m_pSet.Close();
	

	
}


void CCancelDlg::ProductSize()
{

}


void CCancelDlg::DeliveryCost()
{
}


void CCancelDlg::OnClickedButtonLast641()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.


	COrders m_pSet;

	m_pSet.Open();

	m_pSet.MoveLast();

	m_strOutId_641 = m_pSet.m_Or_Id;
	m_strOutName_641 = m_pSet.m_Or_Name;

	m_strOutAddress_641 = m_pSet.m_Or_Address;
	m_strOutCount_641 = m_pSet.m_Or_Count;
	m_strOutBuy_641 = m_pSet.m_Or_Products;
	m_strOutPay_641 = m_pSet.m_Or_Buy;

	UpdateData(false);
	m_pSet.Close();
}
