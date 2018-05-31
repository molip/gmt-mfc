#pragma once

#include <memory>

namespace sf
{
	class RenderWindow;
	class Clock;
}

class View;
class Window;

class ChildView : public CWnd
{
public:
	ChildView();
	virtual ~ChildView();

	void Pump();
	static ChildView* s_instance;

protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

private:
	std::unique_ptr<Window> m_window;

public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	DECLARE_MESSAGE_MAP()
};

