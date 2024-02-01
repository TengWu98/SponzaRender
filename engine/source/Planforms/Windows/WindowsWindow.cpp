#include "pch.h"
#include "WindowsWindow.h"

SPONZA_RENDER_NAMESPACE_BEGIN

WindowClass WindowClass::m_wndClass;

const wchar_t* SponzaRender::WindowClass::GetName() noexcept
{
	return m_wndClassName;
}

HINSTANCE SponzaRender::WindowClass::GetInstance() noexcept
{
	return m_wndClass.m_hInst;
}

LRESULT SponzaRender::WindowClass::HandleMsgSetup(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept
{
	if (msg == WM_NCCREATE) {
		// extract ptr to window class from creation data
		const CREATESTRUCTW* const pCreate = reinterpret_cast<CREATESTRUCTW*>(lParam);
		WindowsWindow* const pWnd = static_cast<WindowsWindow*>(pCreate->lpCreateParams);
		// set WinAPI-managed user data to store ptr to window class
		SetWindowLongPtr(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(pWnd));
		// set message proc to normal (non-setup) handler now that setup is finished
		SetWindowLongPtr(hwnd, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(&HandleMsgThunk));
		// forward message to window instance handler
		return pWnd->HandleMsg(hwnd, msg, wParam, lParam);
	}

	return DefWindowProcW(hwnd, msg, wParam, lParam);
}

LRESULT SponzaRender::WindowClass::HandleMsgThunk(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept
{
	WindowsWindow* const pWnd = reinterpret_cast<WindowsWindow*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));
	return pWnd->HandleMsg(hwnd, msg, wParam, lParam);
}

SponzaRender::WindowClass::WindowClass() noexcept
	:
	m_hInst(GetModuleHandle(nullptr))
{
	LOG_DEV_INFO("Construct WindowClass...");
	WNDCLASSEXW wc = {
		sizeof(wc), CS_CLASSDC, HandleMsgSetup, 0L, 0L, GetInstance(), nullptr, nullptr, nullptr, nullptr,
		m_wndClassName,
		nullptr
	};
	RegisterClassExW(&wc);
	LOG_DEV_INFO("Construct WindowClass... Done");
}

SponzaRender::WindowClass::~WindowClass()
{
	UnregisterClassW(m_wndClassName, GetInstance());
}

LRESULT SponzaRender::WindowClass::HandleWindowMsg(Window*& wnd, HWND hwnd, UINT msg, WPARAM wParam,
                                                   LPARAM lParam) noexcept
{
	return DefWindowProcW(hwnd, msg, wParam, lParam);
}

SponzaRender::WindowsWindow::WindowsWindow(const WindowProps& windowProps)
	: Window(windowProps)
{
	LOG_DEV_INFO("Construct Window...");
	RECT wr;
	wr.left = 100;
	wr.right = m_windowProps.Width + wr.left;
	wr.top = 100;
	wr.bottom = m_windowProps.Height + wr.top;

	AdjustWindowRect(&wr, WS_OVERLAPPEDWINDOW, FALSE);

	m_hWnd = CreateWindowExW(
		0, WindowClass::GetName(), m_windowProps.Title,
		WS_OVERLAPPEDWINDOW, wr.left, wr.top, wr.right - wr.left, wr.bottom - wr.top,
		nullptr, nullptr, WindowClass::GetInstance(), this
	);

	::ShowWindow(m_hWnd, SW_SHOWDEFAULT);
	::UpdateWindow(m_hWnd);

	LOG_DEV_INFO("Construct Window...  done");
}

SponzaRender::WindowsWindow::~WindowsWindow()
{
}

unsigned SponzaRender::WindowsWindow::GetWindowWidth() const noexcept
{
	return m_windowProps.Width;
}

unsigned SponzaRender::WindowsWindow::GetWindowHeight() const noexcept
{
	return m_windowProps.Height;
}

LRESULT SponzaRender::WindowsWindow::HandleMsg(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept
{
	return DefWindowProcW(hwnd, msg, wParam, lParam);
}

SPONZA_RENDER_NAMESPACE_END