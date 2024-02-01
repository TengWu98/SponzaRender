#pragma once

#include "Runtime/Function/Window/Window.h"

SPONZA_RENDER_NAMESPACE_BEGIN
	class WindowClass {
	public:
		static const wchar_t* GetName() noexcept;
		static HINSTANCE GetInstance() noexcept;

		static LRESULT WINAPI HandleMsgSetup(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept;
		static LRESULT WINAPI HandleMsgThunk(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept;

	private:
		WindowClass() noexcept;
		~WindowClass();
		WindowClass(const WindowClass&) = delete;
		WindowClass& operator=(const WindowClass&) = delete;
		HINSTANCE m_hInst;

		static LRESULT WINAPI HandleWindowMsg(Window*& wnd, HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept;
		static constexpr const wchar_t* m_wndClassName = L"SponzaRender Window";
		static WindowClass m_wndClass;
	};

	class WindowsWindow : public Window {
		friend WindowClass;

	public:
		WindowsWindow(const WindowProps& windowProps);
		virtual ~WindowsWindow() override;

		virtual unsigned int GetWindowWidth() const noexcept override;
		virtual unsigned int GetWindowHeight() const noexcept override;
	private:
		LRESULT HandleMsg(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept;
		HWND m_hWnd;
		bool m_bindedImgui = false;
		std::vector<char> m_rawInputBuffer;
	};

SPONZA_RENDER_NAMESPACE_END
