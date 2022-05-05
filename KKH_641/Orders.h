// Orders.h : COrders�� �����Դϴ�.

#pragma once

// �ڵ� ���� ��ġ 2021�� 11�� 14�� �Ͽ���, ���� 3:54

class COrders : public CRecordset
{
public:
	COrders(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(COrders)

// �ʵ�/�Ű� ���� ������

// �Ʒ��� ���ڿ� ����(���� ���)�� �����ͺ��̽� �ʵ��� ���� ������ ������
// ��Ÿ���ϴ�(CStringA:
// ANSI ������ ����, CStringW: �����ڵ� ������ ����).
// �̰��� ODBC ����̹����� ���ʿ��� ��ȯ�� ������ �� ������ �մϴ�.  // ���� ��� �̵� ����� CString �������� ��ȯ�� �� ������
// �׷� ��� ODBC ����̹����� ��� �ʿ��� ��ȯ�� �����մϴ�.
// (����: �����ڵ�� �̵� ��ȯ�� ��� �����Ϸ���  ODBC ����̹�
// ���� 3.5 �̻��� ����ؾ� �մϴ�).

	CString	m_Or_Id;	//�ֹ��� ���̵�
	CString	m_Or_Name;	//�ֹ��� ����
	CString	m_Or_Address;	//�ֹ��� �ּ�
	CString	m_Or_Products;	//�ֹ��� ��ǰ
	CString	m_Or_Count;	//����
	CString	m_Or_Size;	//������
	CString	m_Or_Buy;	//���� ���

// ������
	// �����翡�� ������ ���� �Լ� ������
	public:
	virtual CString GetDefaultConnect();	// �⺻ ���� ���ڿ�

	virtual CString GetDefaultSQL(); 	// ���ڵ� ������ �⺻ SQL
	virtual void DoFieldExchange(CFieldExchange* pFX);	// RFX ����

// ����
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

};


