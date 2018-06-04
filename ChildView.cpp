#include "stdafx.h"
#include "ChildView.h"
#include "Window.h"

#include "gmt/View.h"

#define _OLD_MSC_VER _MSC_VER
#undef _MSC_VER
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#define _MSC_VER _OLD_MSC_VER 

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

BEGIN_MESSAGE_MAP(ChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_SIZE()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()

ChildView* ChildView::s_instance;

ChildView::ChildView()
{
	s_instance = this;
}

ChildView::~ChildView()
{
	s_instance = nullptr;
}

void ChildView::Pump()
{
	if (!m_window)
		return;
		
	m_window->PumpEvents();
	m_window->clear();
	m_window->Draw();
}

BOOL ChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS, ::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), nullptr);

	return TRUE;
}

void ChildView::OnPaint() 
{
	CPaintDC dc(this);
}

void ChildView::OnTimer(UINT_PTR nIDEvent)
{
	CWnd::OnTimer(nIDEvent);

	Invalidate();
}

void ChildView::OnSize(UINT nType, int cx, int cy)
{
	CWnd::OnSize(nType, cx, cy);

	if (cx && cy && !m_window)
	{
		m_window = std::make_unique<Window>(GetSafeHwnd());
	}
}

BOOL ChildView::OnEraseBkgnd(CDC* pDC)
{
	return true;
}
