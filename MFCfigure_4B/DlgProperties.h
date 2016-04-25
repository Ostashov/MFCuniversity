#pragma once


// диалоговое окно CDlgProperties

class CDlgProperties : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgProperties)

public:
	CDlgProperties(CWnd* pParent = NULL);   // стандартный конструктор
	virtual ~CDlgProperties();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PROPERTIES };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
};
