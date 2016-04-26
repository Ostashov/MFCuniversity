#pragma once
#include "CMy2DPoint.h"

// диалоговое окно CDlgProperties

class CDlgProperties : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgProperties)

public:
	CDlgProperties(CWnd* pParent = NULL);   // стандартный конструктор
	CDlgProperties(double A, double A1, double A2, double A3, double Angle, CMy2DPoint center, CWnd* pParent /*=NULL*/);
	virtual ~CDlgProperties();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PROPERTIES };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	double m_dAngle;
	double m_A;
	double m_A1;
	double m_A2;
	double m_A3;
	double m_dCenterX;
	double m_dCenterY;
};
