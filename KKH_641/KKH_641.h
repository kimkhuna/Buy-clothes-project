
// KKH_641.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CKKH_641App:
// �� Ŭ������ ������ ���ؼ��� KKH_641.cpp�� �����Ͻʽÿ�.
//

class CKKH_641App : public CWinApp
{
public:
	CKKH_641App();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CKKH_641App theApp;