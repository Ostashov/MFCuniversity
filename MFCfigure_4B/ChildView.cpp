
// ChildView.cpp : реализация класса CChildView
//

#include "stdafx.h"
#include "MFCfigure_4B.h"
#include "ChildView.h"
#include "CMy2DPoint.h"

#define M_PI 3.1415926535897932384626433832795

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

/* CMy2DPoint rotatedPoint(const CMy2DPoint &point, const CMy2DPoint &centerPoint, double dAngle) {
	CMy2DPoint result(centerPoint.m_x + (point.m_x - centerPoint.m_x) * cos(180 * dAngle / M_PI) - (point.m_y - centerPoint.m_y) * sin(180 * dAngle / M_PI),
		centerPoint.m_y + (point.m_y - centerPoint.m_y) * cos(180 * dAngle / M_PI) + (point.m_x - centerPoint.m_x) * sin(180 * dAngle / M_PI));
	return result;
}; */


// CChildView

CChildView::CChildView()
{
	double A = 200.0;
	double A1 = 40.0;
	double A2 = 60.0;
	double A3 = 60.0;
	double size = 1.0;
	CMy2DPoint center(200.0, 200.0);
	double angle = -20.0;
	m_bCatched = false;

	CMy2DObject4B shape(size * A, size * A1, size * A2, size * A3, center, angle);
	m_shape = shape;
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()



// обработчики сообщений CChildView

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // контекст устройства для рисования
	
	
	m_shape.draw(dc);
	
	// TODO: Добавьте код обработки сообщений
	
	// Не вызывайте CWnd::OnPaint() для сообщений рисования
}



void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
	if (m_shape.isInside(point.x, point.y)) {
		m_bCatched = true;
		m_MousePos = point;
		SetCapture();
	}

	CWnd::OnLButtonDown(nFlags, point);
}


void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
	m_bCatched = false;
	ReleaseCapture();
	CWnd::OnLButtonUp(nFlags, point);
}


void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
	if(m_bCatched){
		CRect rect;
		GetClientRect(&rect);
		point.x = min(rect.right, max(rect.left, point.x));
		point.y = min(rect.bottom, max(rect.top, point.y));
		CPoint Delta = point - m_MousePos;
		m_shape.move(Delta.x, Delta.y, 0);
		m_MousePos = point;
		Invalidate();
	}
	CWnd::OnMouseMove(nFlags, point);
}


void CChildView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
	if (m_shape.isInside(point.x, point.y)) {
		CDlgProperties Dlg(m_shape.getA(0), m_shape.getA(1), m_shape.getA(2), m_shape.getA(3), m_shape.getAngle(), m_shape.getCenter(), NULL);
		//Dlg.DoModal();
		if (Dlg.DoModal()) {
			CMy2DPoint newCenter(Dlg.m_dCenterX, Dlg.m_dCenterY);
			if (testProperties(Dlg.m_A, Dlg.m_A1, Dlg.m_A2, Dlg.m_A3, Dlg.m_dAngle, newCenter)) {
				m_shape.setA(Dlg.m_A);
				m_shape.setA1(Dlg.m_A1);
				m_shape.setA2(Dlg.m_A2);
				m_shape.setA3(Dlg.m_A3);
				m_shape.setAngle(Dlg.m_dAngle);
				m_shape.setCenter(newCenter);
			}
			Invalidate();
		}
	}

	CWnd::OnLButtonDblClk(nFlags, point);
}
