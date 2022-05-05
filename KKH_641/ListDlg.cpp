// ListDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "KKH_641.h"
#include "ListDlg.h"
#include "afxdialogex.h"

#include "XLAutomation.h"
#include "XLEzAutomation.h"
#include <afxdao.h>




// CListDlg ��ȭ �����Դϴ�.

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


// CListDlg �޽��� ó�����Դϴ�.


BOOL CListDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	m_listOut_641.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);

	m_listOut_641.InsertColumn(0, _T("ID"), LVCFMT_LEFT, 50);
	m_listOut_641.InsertColumn(1, _T("�̸�"), LVCFMT_LEFT, 70);
	m_listOut_641.InsertColumn(2, _T("�ּ�"), LVCFMT_LEFT, 150);
	m_listOut_641.InsertColumn(3, _T("�ֹ���ǰ"), LVCFMT_LEFT, 90);
	m_listOut_641.InsertColumn(4, _T("������"), LVCFMT_LEFT, 50);
	m_listOut_641.InsertColumn(5, _T("����"), LVCFMT_LEFT, 40);
	m_listOut_641.InsertColumn(6, _T("��������"), LVCFMT_LEFT, 150);


	COrders m_pSet;
{
	if (!m_pSet.Open()) {

		AfxMessageBox(_T("������ �ҽ��� ���� ����"));
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
	////////  �ֻ��� ��� /////////////////////

	tInsert.hParent = 0;
	tInsert.item.mask = TVIF_TEXT;
	tInsert.item.pszText = _T("�ֹ���ǰ");
	hBuy = m_treeOut_641.InsertItem(&tInsert);

	/////////////////////////////////////////
	tInsert.hParent = hBuy;
	tInsert.item.pszText = _T("�����");
	hCardigan = m_treeOut_641.InsertItem(&tInsert);

	tInsert.hParent = hBuy;
	tInsert.item.pszText = _T("���е�");
	hLongP = m_treeOut_641.InsertItem(&tInsert);

	tInsert.hParent = hBuy;
	tInsert.item.pszText = _T("��Ʈ");
	hCoat = m_treeOut_641.InsertItem(&tInsert);

	tInsert.hParent = hBuy;
	tInsert.item.pszText = _T("������");
	hMtM = m_treeOut_641.InsertItem(&tInsert);

	tInsert.hParent = hBuy;
	tInsert.item.pszText = _T("�ĵ�Ƽ");
	hHoodT = m_treeOut_641.InsertItem(&tInsert);

	if (m_pSet.Open()) {
	
	}

	// m_pSet.m_strFilter.Empty();
	// m_pSet.Requery();

	while (!m_pSet.IsEOF())
	{
		if (m_pSet.m_Or_Products == "�����")
		{
			strParent = "�����";
			m_treeOut_641.InsertItem(m_pSet.m_Or_Id + ";" + m_pSet.m_Or_Name + ", " + m_pSet.m_Or_Size, hCardigan, TVI_LAST);
		}
		else if (m_pSet.m_Or_Products == "���е�")
		{
			strParent = "���е�";
			m_treeOut_641.InsertItem(m_pSet.m_Or_Id + ";" + m_pSet.m_Or_Name + ", " + m_pSet.m_Or_Size, hLongP, TVI_LAST);
		}
		else if (m_pSet.m_Or_Products == "��Ʈ")
		{
			strParent = "��Ʈ";
			m_treeOut_641.InsertItem(m_pSet.m_Or_Id + ";" + m_pSet.m_Or_Name + ", " + m_pSet.m_Or_Size, hCoat, TVI_LAST);
		}
		else if (m_pSet.m_Or_Products == "������")
		{
			strParent = "������";
			m_treeOut_641.InsertItem(m_pSet.m_Or_Id + ";" + m_pSet.m_Or_Name + ", " + m_pSet.m_Or_Size, hMtM, TVI_LAST);
		}
		else if (m_pSet.m_Or_Products == "�ĵ�Ƽ")
		{
			strParent = "�ĵ�Ƽ";
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
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void CListDlg::OnClickedButtonHome641()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	OnOK();
}


void CListDlg::OnDblclkListOut641(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (pNMItemActivate->iItem != -1)
	{
		CString strSelectedId = m_listOut_641.GetItemText(pNMItemActivate->iItem, 0);
		CString strSelectedName = m_listOut_641.GetItemText(pNMItemActivate->iItem, 1);
		CString strSelectedAddress = m_listOut_641.GetItemText(pNMItemActivate->iItem, 2);
		CString strSelectedProducts = m_listOut_641.GetItemText(pNMItemActivate->iItem, 3);
		CString strSelectedSize = m_listOut_641.GetItemText(pNMItemActivate->iItem, 4);
		CString strSelectedCount = m_listOut_641.GetItemText(pNMItemActivate->iItem, 5);

		CString strResult = "���̵�: " + strSelectedId + "\n" + "�̸�: " + strSelectedName + "\n" + "�ּ�: " + strSelectedAddress + "\n" + "��ǰ: " + strSelectedProducts + "\n" + "������: " + strSelectedSize + "\n" + "����: " + strSelectedCount;
		MessageBox(strResult);

	}
	*pResult = 0;
}


void CListDlg::OnClickedButtonExcel641()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	int m_iMax;
	int nColumncount = m_listOut_641.GetItemCount();
	int columnNum = 0;
	CString m_strFileName;

	m_iMax = nColumncount;
	CXLEzAutomation XL(FALSE);

	m_strFileName = "�ֹ����";

	XL.SetCellValue(++columnNum, 1, "ID");
	XL.SetCellValue(++columnNum, 1, "�ֹ��� ����");
	XL.SetCellValue(++columnNum, 1, "�ּ�");
	XL.SetCellValue(++columnNum, 1, "�ֹ��� ��ǰ");
	XL.SetCellValue(++columnNum, 1, "������");
	XL.SetCellValue(++columnNum, 1, "����");
	XL.SetCellValue(++columnNum, 1, "�������");

	for (int i = 1; i <= m_iMax; i++)
	{
		XL.SetCellValue(1, i + 1, m_listOut_641.GetItemText(i - 1, 0));

		for (int j = 1; j <= columnNum; j++)
			XL.SetCellValue(j + 1, i + 1, m_listOut_641.GetItemText(i - 1, j));
	}

	CFileDialog dlg(false, "xlsx", m_strFileName + ".xlsx", OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT | OFN_NOCHANGEDIR, "xlsx ���� (*.xlsx)|*.xlsx|", NULL);

	if (dlg.DoModal() == IDOK)
		XL.SaveFileAs(dlg.GetPathName());

	XL.ReleaseExcel();
}
