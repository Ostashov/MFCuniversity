// DlgProperties.cpp: файл реализации
//

#include "stdafx.h"
#include "MFCfigure_4B.h"
#include "DlgProperties.h"
#include "afxdialogex.h"


// диалоговое окно CDlgProperties

IMPLEMENT_DYNAMIC(CDlgProperties, CDialogEx)

CDlgProperties::CDlgProperties(CWnd* pParent)
	: CDialogEx(IDD_PROPERTIES, pParent)
	, m_dAngle(0)
	, m_A(0)
	, m_A1(0)
	, m_A2(0)
	, m_A3(0)
	, m_dCenterX(0)
	, m_dCenterY(0)
{

}

CDlgProperties::CDlgProperties(double A, double A1, double A2, double A3, double Angle, CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_PROPERTIES, pParent)
	, m_dAngle(Angle)
	, m_A(A)
	, m_A1(A1)
	, m_A2(A2)
	, m_A3(A3)
{

}

CDlgProperties::~CDlgProperties()
{
}

void CDlgProperties::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_E_ANGLE, m_dAngle);
	DDX_Text(pDX, IDC_E_A, m_A);
	DDX_Text(pDX, IDC_E_A1, m_A1);
	DDX_Text(pDX, IDC_E_A2, m_A2);
	DDX_Text(pDX, IDC_E_A3, m_A3);
	DDX_Text(pDX, IDC_E_X, m_dCenterX);
	DDX_Text(pDX, IDC_E_Y, m_dCenterY);
}


BEGIN_MESSAGE_MAP(CDlgProperties, CDialogEx)
END_MESSAGE_MAP()


// обработчики сообщений CDlgProperties
