
// MFCfigure_4B.h : ������� ���� ��������� ��� ���������� MFCfigure_4B
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"       // �������� �������


// CMFCfigure_4BApp:
// � ���������� ������� ������ ��. MFCfigure_4B.cpp
//

class CMFCfigure_4BApp : public CWinApp
{
public:
	CMFCfigure_4BApp();


// ���������������
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ����������

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCfigure_4BApp theApp;
