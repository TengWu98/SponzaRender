#include "pch.h"
#include "Window.h"
#include "Planforms/Windows/WindowsWindow.h"

SPONZA_RENDER_NAMESPACE_BEGIN
	SponzaRender::Window::Window(const WindowProps& windowProps)
		: m_windowProps(windowProps)
	{
	}

	SponzaRender::Window::~Window()
	{
	}

	std::shared_ptr<SponzaRender::Window> SponzaRender::Window::Create(const WindowProps& windowPorps)
	{
#ifdef SPONZA_RENDER_PLATFORM_WINDOWS
		return std::make_shared<WindowsWindow>(windowPorps);
#else
	SPONZA_RENDER_ASSERT(false, "Unkown platform");
	return nullptr;
#endif
	}

SPONZA_RENDER_NAMESPACE_END
