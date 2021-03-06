// DlgProperties.cpp: ���� ����������
//

#include "stdafx.h"
#include "MFCfigure_4B.h"
#include "DlgProperties.h"
#include "afxdialogex.h"


// ���������� ���� CDlgProperties

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

CDlgProperties::CDlgProperties(double A, double A1, double A2, double A3, double Angle, CMy2DPoint center, CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_PROPERTIES, pParent)
	, m_dAngle(Angle)
	, m_A(A)
	, m_A1(A1)
	, m_A2(A2)
	, m_A3(A3)
	, m_dCenterX(center.m_x)
	, m_dCenterY(center.m_y)
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
	ON_BN_CLICKED(IDOK, &CDlgProperties::OnBnClickedOk)
END_MESSAGE_MAP()


// ����������� ��������� CDlgProperties


void CDlgProperties::OnBnClickedOk()
{
	// TODO: �������� ���� ��� ����������� �����������
	CString str;

	CEdit *pEdit = (CEdit *)GetDlgItem(IDC_E_A);
	pEdit->GetWindowText(str);
	m_A = _wtof(str);

	pEdit = (CEdit *)GetDlgItem(IDC_E_A1);
	pEdit->GetWindowText(str);
	m_A1 = _wtof(str);

	pEdit = (CEdit *)GetDlgItem(IDC_E_A2);
	pEdit->GetWindowText(str);
	m_A2 = _wtof(str);

	pEdit = (CEdit *)GetDlgItem(IDC_E_A3);
	pEdit->GetWindowText(str);
	m_A3 = _wtof(str);

	pEdit = (CEdit *)GetDlgItem(IDC_E_ANGLE);
	pEdit->GetWindowText(str);
	m_dAngle = _wtof(str);

	pEdit = (CEdit *)GetDlgItem(IDC_E_X);
	pEdit->GetWindowText(str);
	m_dCenterX = _wtof(str);

	pEdit = (CEdit *)GetDlgItem(IDC_E_Y);
	pEdit->GetWindowText(str);
	m_dCenterY = _wtof(str);
	//use atof for non Unicode strings
	CDialogEx::OnOK();
}
