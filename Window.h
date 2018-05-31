#pragma once

#include "gmt/Window.h"

class Window : public GMT::Window
{
public:
	Window(sf::WindowHandle handle);
	virtual ~Window();

private:
	virtual void onResize() override;
};

