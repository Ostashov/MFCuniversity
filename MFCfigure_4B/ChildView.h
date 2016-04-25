
// ChildView.h : ��������� ������ CChildView
//


#pragma once
#include "CMy2DObject.h"
#include "DlgProperties.h"


// ���� CChildView

class CChildView : public CWnd
{
// ��������
public:
	CChildView();

// ��������
public:
	bool m_bCatched;
	CPoint m_MousePos;
protected:
	CMy2DObject4B m_shape;

// ��������
public:

// ���������������
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// ����������
public:
	virtual ~CChildView();

	// ��������� ������� ����� ���������
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
};

