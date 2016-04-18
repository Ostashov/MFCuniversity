
// MFCfigure_4B.h : главный файл заголовка для приложения MFCfigure_4B
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CMFCfigure_4BApp:
// О реализации данного класса см. MFCfigure_4B.cpp
//

class CMFCfigure_4BApp : public CWinApp
{
public:
	CMFCfigure_4BApp();


// Переопределение
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Реализация

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCfigure_4BApp theApp;
