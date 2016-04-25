// DlgProperties.cpp: файл реализации
//

#include "stdafx.h"
#include "MFCfigure_4B.h"
#include "DlgProperties.h"
#include "afxdialogex.h"


// диалоговое окно CDlgProperties

IMPLEMENT_DYNAMIC(CDlgProperties, CDialogEx)

CDlgProperties::CDlgProperties(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_PROPERTIES, pParent)
	, m_dAngle(0)
{

}

CDlgProperties::~CDlgProperties()
{
}

void CDlgProperties::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_E_ANGLE, m_dAngle);
}


BEGIN_MESSAGE_MAP(CDlgProperties, CDialogEx)
END_MESSAGE_MAP()


// обработчики сообщений CDlgProperties
