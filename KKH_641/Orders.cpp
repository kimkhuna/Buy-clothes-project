// Orders.h : COrders Ŭ������ �����Դϴ�.



// COrders �����Դϴ�.

// �ڵ� ���� ��ġ 2021�� 11�� 14�� �Ͽ���, ���� 3:54

#include "stdafx.h"
#include "Orders.h"
IMPLEMENT_DYNAMIC(COrders, CRecordset)

COrders::COrders(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_Or_Id = L"";
	m_Or_Name = L"";
	m_Or_Address = L"";
	m_Or_Products = L"";
	m_Or_Count = L"";
	m_Or_Size = L"";
	m_Or_Buy = L"";
	m_nFields = 7;
	m_nDefaultType = dynaset;
}
// #error ���� ����: ���� ���ڿ��� ��ȣ�� ���ԵǾ� ���� �� �ֽ��ϴ�.
// �Ʒ� ���� ���ڿ��� �Ϲ� �ؽ�Ʈ ��ȣ ��/�Ǵ� 
// �ٸ� �߿��� ������ ���ԵǾ� ���� �� �ֽ��ϴ�.
// ���� ���� ������ �ִ��� ���� ���ڿ��� ������ �Ŀ� #error��(��) �����Ͻʽÿ�.
// �ٸ� �������� ��ȣ�� �����ϰų� �ٸ� ����� ������ ����Ͻʽÿ�.
CString COrders::GetDefaultConnect()
{
	return _T("DSN=ORDER_DB;DBQ=C:\\Photo\\641.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString COrders::GetDefaultSQL()
{
	return _T("[Orders]");
}

void COrders::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() ���� ��ũ�δ� �����ͺ��̽��� �ʵ�
// ������ �ƴ϶� ��� ������ ���Ŀ� ���� �޶����ϴ�.
// ODBC������ �ڵ����� �� ���� ��û�� �������� ��ȯ�Ϸ��� �մϴ�
	RFX_Text(pFX, _T("[Or_Id]"), m_Or_Id);
	RFX_Text(pFX, _T("[Or_Name]"), m_Or_Name);
	RFX_Text(pFX, _T("[Or_Address]"), m_Or_Address);
	RFX_Text(pFX, _T("[Or_Products]"), m_Or_Products);
	RFX_Text(pFX, _T("[Or_Count]"), m_Or_Count);
	RFX_Text(pFX, _T("[Or_Size]"), m_Or_Size);
	RFX_Text(pFX, _T("[Or_Buy]"), m_Or_Buy);

}
/////////////////////////////////////////////////////////////////////////////
// COrders ����

#ifdef _DEBUG
void COrders::AssertValid() const
{
	CRecordset::AssertValid();
}

void COrders::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


