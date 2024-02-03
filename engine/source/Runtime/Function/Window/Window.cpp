#include "pch.h"
#include "Window.h"

SPONZA_RENDER_NAMESPACE_BEGIN
	Window::WindowClass Window::WindowClass::m_wndClass;

	const wchar_t* SponzaRender::Window::WindowClass::GetName() noexcept
	{
		return m_wndClassName;
	}

	HINSTANCE SponzaRender::Window::WindowClass::GetInstance() noexcept
	{
		return m_wndClass.m_hInst;
	}

	SponzaRender::Window::WindowClass::WindowClass() noexcept
		:
		m_hInst(GetModuleHandle(nullptr))
	{
		// register window class
		WNDCLASSEX wc = { 0 };
		wc.cbSize = sizeof(wc);
		wc.style = CS_OWNDC;
		wc.lpfnWndProc = HandleMsgSetup;
		wc.cbClsExtra = 0;
		wc.cbWndExtra = 0;
		wc.hInstance = GetInstance();
		wc.hIcon = nullptr;
		wc.hCursor = nullptr;
		wc.hbrBackground = nullptr;
		wc.lpszMenuName = nullptr;
		wc.lpszClassName = GetName();
		wc.hIconSm = nullptr;
		RegisterClassEx(&wc);
	}

	SponzaRender::Window::WindowClass::~WindowClass()
	{
		UnregisterClass(m_wndClassName, GetInstance());
	}

	SponzaRender::Window::Window(const WindowCreateInfo& windowCreateInfo)
		: m_windowCreateInfo(windowCreateInfo)
	{
		RECT wr;
		wr.left = 100;
		wr.right = m_windowCreateInfo.Width + wr.left;
		wr.top = 100;
		wr.bottom = m_windowCreateInfo.Height + wr.top;

		AdjustWindowRect(&wr, WS_OVERLAPPEDWINDOW, FALSE);

		m_hWnd = CreateWindowEx(
			0, WindowClass::GetName(), m_windowCreateInfo.Title,
			WS_OVERLAPPEDWINDOW, wr.left, wr.top, wr.right - wr.left, wr.bottom - wr.top,
			nullptr, nullptr, WindowClass::GetInstance(), this
		);

		::ShowWindow(m_hWnd, SW_SHOWDEFAULT);
		::UpdateWindow(m_hWnd);

		LOG_DEV_INFO("Create Window");
	}

	SponzaRender::Window::~Window()
	{
		::DestroyWindow(m_hWnd);
	}

	unsigned Window::GetWindowWidth() const noexcept
	{
		return m_windowCreateInfo.Width;
	}

	unsigned Window::GetWindowHeight() const noexcept
	{
		return m_windowCreateInfo.Height;
	}

	void Window::ShowMessageBox(const wchar_t* title, const wchar_t* message) const noexcept
	{
		::MessageBox(m_hWnd, title, message, MB_OK | MB_ICONEXCLAMATION);
	}

	void Window::SetTitle(const std::wstring& title)
	{
		::SetWindowText(m_hWnd, title.c_str());
	}

	std::optional<int> Window::ProcessMessages() noexcept
	{
		MSG msg;
		while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
			if (msg.message == WM_QUIT) {
				// convert WPARAM to int
				return static_cast<int>(msg.wParam);
			}
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		return {};
	}

	HWND Window::GetHwnd() const noexcept
	{
		return m_hWnd;
	}

	void Window::CloseWindow() noexcept
	{
		::DestroyWindow(m_hWnd);

		LOG_DEV_INFO("Close Window");
	}

	std::shared_ptr<SponzaRender::Window> SponzaRender::Window::Create(const WindowCreateInfo& windowPorps)
	{
#ifdef SPONZA_RENDER_PLATFORM_WINDOWS
		return std::make_shared<Window>(windowPorps);
#else
	SPONZA_RENDER_ASSERT(false, "Unkown platform.");
	return nullptr;
#endif
	}

	LRESULT SponzaRender::Window::HandleMsgSetup(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept
	{
		if (msg == WM_NCCREATE) {
			// extract ptr to window class from creation data
			const CREATESTRUCTW* const pCreate = reinterpret_cast<CREATESTRUCTW*>(lParam);
			Window* const pWnd = static_cast<Window*>(pCreate->lpCreateParams);
			// set WinAPI-managed user data to store ptr to window class
			SetWindowLongPtr(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(pWnd));
			// set message proc to normal (non-setup) handler now that setup is finished
			SetWindowLongPtr(hwnd, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(&HandleMsgThunk));
			// forward message to window instance handler
			return pWnd->HandleMsg(hwnd, msg, wParam, lParam);
		}

		return DefWindowProcW(hwnd, msg, wParam, lParam);
	}

	LRESULT SponzaRender::Window::HandleMsgThunk(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept
	{
		Window* const pWnd = reinterpret_cast<Window*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));
		return pWnd->HandleMsg(hwnd, msg, wParam, lParam);
	}

	LRESULT Window::HandleMsg(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept
	{
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}

SPONZA_RENDER_NAMESPACE_END
