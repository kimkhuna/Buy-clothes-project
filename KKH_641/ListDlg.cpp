// ListDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "KKH_641.h"
#include "ListDlg.h"
#include "afxdialogex.h"

#include "XLAutomation.h"
#include "XLEzAutomation.h"
#include <afxdao.h>




// CListDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CListDlg, CDialogEx)

CListDlg::CListDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_LIST_641, pParent)
{

}

CListDlg::~CListDlg()
{
}

void CListDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_OUT_641, m_listOut_641);
	DDX_Control(pDX, IDC_TREE_OUT_641, m_treeOut_641);
}


BEGIN_MESSAGE_MAP(CListDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_HOME_641, &CListDlg::OnClickedButtonHome641)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_OUT_641, &CListDlg::OnDblclkListOut641)
	ON_BN_CLICKED(IDC_BUTTON_EXCEL_641, &CListDlg::OnClickedButtonExcel641)
END_MESSAGE_MAP()


// CListDlg 메시지 처리기입니다.


BOOL CListDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	m_listOut_641.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);

	m_listOut_641.InsertColumn(0, _T("ID"), LVCFMT_LEFT, 50);
	m_listOut_641.InsertColumn(1, _T("이름"), LVCFMT_LEFT, 70);
	m_listOut_641.InsertColumn(2, _T("주소"), LVCFMT_LEFT, 150);
	m_listOut_641.InsertColumn(3, _T("주문상품"), LVCFMT_LEFT, 90);
	m_listOut_641.InsertColumn(4, _T("사이즈"), LVCFMT_LEFT, 50);
	m_listOut_641.InsertColumn(5, _T("수량"), LVCFMT_LEFT, 40);
	m_listOut_641.InsertColumn(6, _T("결제수단"), LVCFMT_LEFT, 150);


	COrders m_pSet;
{
	if (!m_pSet.Open()) {

		AfxMessageBox(_T("데이터 소스와 연결 못함"));
	}

	int  i = 0;
	CString str;

	while (!m_pSet.IsEOF())
	{

		//////////////////////////////////////////////
		m_listOut_641.InsertItem(i, m_pSet.m_Or_Id);

		m_listOut_641.SetItemText(i, 1, m_pSet.m_Or_Name);

		/////////////////////////////////////////////

		str.Format(_T("%s"), m_pSet.m_Or_Address);

		m_listOut_641.SetItemText(i, 2, str);

		str.Format(_T("%s"), m_pSet.m_Or_Products);

		m_listOut_641.SetItemText(i, 3, str);

		m_listOut_641.SetItemText(i, 4, m_pSet.m_Or_Size);

		str.Format(_T("%s"), m_pSet.m_Or_Count);

		m_listOut_641.SetItemText(i, 5, str);

		m_listOut_641.SetItemText(i, 6, m_pSet.m_Or_Buy);


		m_pSet.MoveNext();

		i++;



	}
	m_pSet.Close();
	
	//////////////////////////////////////

	int cnt = m_listOut_641.GetItemCount();
	CString sText;
	sText.Format(TEXT("%d"), cnt);
	SetDlgItemText(IDC_EDIT_LIST_COUNT_641, sText);



}

	m_treeOut_641.DeleteAllItems();
	CString id, name, grade;
	int point;
	////////  최상위 목록 /////////////////////

	tInsert.hParent = 0;
	tInsert.item.mask = TVIF_TEXT;
	tInsert.item.pszText = _T("주문상품");
	hBuy = m_treeOut_641.InsertItem(&tInsert);

	/////////////////////////////////////////
	tInsert.hParent = hBuy;
	tInsert.item.pszText = _T("가디건");
	hCardigan = m_treeOut_641.InsertItem(&tInsert);

	tInsert.hParent = hBuy;
	tInsert.item.pszText = _T("롱패딩");
	hLongP = m_treeOut_641.InsertItem(&tInsert);

	tInsert.hParent = hBuy;
	tInsert.item.pszText = _T("코트");
	hCoat = m_treeOut_641.InsertItem(&tInsert);

	tInsert.hParent = hBuy;
	tInsert.item.pszText = _T("맨투맨");
	hMtM = m_treeOut_641.InsertItem(&tInsert);

	tInsert.hParent = hBuy;
	tInsert.item.pszText = _T("후드티");
	hHoodT = m_treeOut_641.InsertItem(&tInsert);

	if (m_pSet.Open()) {
	
	}

	// m_pSet.m_strFilter.Empty();
	// m_pSet.Requery();

	while (!m_pSet.IsEOF())
	{
		if (m_pSet.m_Or_Products == "가디건")
		{
			strParent = "가디건";
			m_treeOut_641.InsertItem(m_pSet.m_Or_Id + ";" + m_pSet.m_Or_Name + ", " + m_pSet.m_Or_Size, hCardigan, TVI_LAST);
		}
		else if (m_pSet.m_Or_Products == "롱패딩")
		{
			strParent = "롱패딩";
			m_treeOut_641.InsertItem(m_pSet.m_Or_Id + ";" + m_pSet.m_Or_Name + ", " + m_pSet.m_Or_Size, hLongP, TVI_LAST);
		}
		else if (m_pSet.m_Or_Products == "코트")
		{
			strParent = "코트";
			m_treeOut_641.InsertItem(m_pSet.m_Or_Id + ";" + m_pSet.m_Or_Name + ", " + m_pSet.m_Or_Size, hCoat, TVI_LAST);
		}
		else if (m_pSet.m_Or_Products == "맨투맨")
		{
			strParent = "맨투맨";
			m_treeOut_641.InsertItem(m_pSet.m_Or_Id + ";" + m_pSet.m_Or_Name + ", " + m_pSet.m_Or_Size, hMtM, TVI_LAST);
		}
		else if (m_pSet.m_Or_Products == "후드티")
		{
			strParent = "후드티";
			m_treeOut_641.InsertItem(m_pSet.m_Or_Id + ";" + m_pSet.m_Or_Name + ", " + m_pSet.m_Or_Size, hHoodT, TVI_LAST);
		}
		m_pSet.MoveNext();
	}

	m_treeOut_641.Expand(hBuy, TVE_EXPAND);

	hCardigan = m_treeOut_641.GetNextItem(hBuy, TVGN_CHILD);
	m_treeOut_641.Expand(hCardigan, TVE_EXPAND);
	while (hCardigan != NULL)
	{
		hCardigan = m_treeOut_641.GetNextItem(hCardigan, TVGN_NEXT);
		m_treeOut_641.Expand(hCardigan, TVE_EXPAND);
	}

	

	
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CListDlg::OnClickedButtonHome641()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	OnOK();
}


void CListDlg::OnDblclkListOut641(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (pNMItemActivate->iItem != -1)
	{
		CString strSelectedId = m_listOut_641.GetItemText(pNMItemActivate->iItem, 0);
		CString strSelectedName = m_listOut_641.GetItemText(pNMItemActivate->iItem, 1);
		CString strSelectedAddress = m_listOut_641.GetItemText(pNMItemActivate->iItem, 2);
		CString strSelectedProducts = m_listOut_641.GetItemText(pNMItemActivate->iItem, 3);
		CString strSelectedSize = m_listOut_641.GetItemText(pNMItemActivate->iItem, 4);
		CString strSelectedCount = m_listOut_641.GetItemText(pNMItemActivate->iItem, 5);

		CString strResult = "아이디: " + strSelectedId + "\n" + "이름: " + strSelectedName + "\n" + "주소: " + strSelectedAddress + "\n" + "상품: " + strSelectedProducts + "\n" + "사이즈: " + strSelectedSize + "\n" + "수량: " + strSelectedCount;
		MessageBox(strResult);

	}
	*pResult = 0;
}


void CListDlg::OnClickedButtonExcel641()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int m_iMax;
	int nColumncount = m_listOut_641.GetItemCount();
	int columnNum = 0;
	CString m_strFileName;

	m_iMax = nColumncount;
	CXLEzAutomation XL(FALSE);

	m_strFileName = "주문목록";

	XL.SetCellValue(++columnNum, 1, "ID");
	XL.SetCellValue(++columnNum, 1, "주문자 성함");
	XL.SetCellValue(++columnNum, 1, "주소");
	XL.SetCellValue(++columnNum, 1, "주문한 상품");
	XL.SetCellValue(++columnNum, 1, "사이즈");
	XL.SetCellValue(++columnNum, 1, "수량");
	XL.SetCellValue(++columnNum, 1, "결제방법");

	for (int i = 1; i <= m_iMax; i++)
	{
		XL.SetCellValue(1, i + 1, m_listOut_641.GetItemText(i - 1, 0));

		for (int j = 1; j <= columnNum; j++)
			XL.SetCellValue(j + 1, i + 1, m_listOut_641.GetItemText(i - 1, j));
	}

	CFileDialog dlg(false, "xlsx", m_strFileName + ".xlsx", OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT | OFN_NOCHANGEDIR, "xlsx 파일 (*.xlsx)|*.xlsx|", NULL);

	if (dlg.DoModal() == IDOK)
		XL.SaveFileAs(dlg.GetPathName());

	XL.ReleaseExcel();
}
