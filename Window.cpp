#include "stdafx.h"
#include "Window.h"

#include "gmt/View.h"

namespace
{
	const int PanelWidth = 300;
	const int ViewGap = 0;
}

Window::Window(sf::WindowHandle handle) : GMT::Window(handle)
{
	onResize();
}

Window::~Window() = default;

void Window::onResize()
{
	sf::IntRect windowRect(0, 0, getSize().x, getSize().y);

	sf::IntRect mainRect = windowRect;
	mainRect.left += ViewGap;
	mainRect.top += ViewGap;
	mainRect.height -= ViewGap * 2;
	mainRect.width -= PanelWidth + ViewGap * 2;
	m_mainView->SetRect(mainRect);
}
