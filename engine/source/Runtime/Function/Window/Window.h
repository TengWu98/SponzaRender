#pragma once

#include "Runtime/Function/Input/Keyboard.h"
#include "Runtime/Function/Input/Mouse.h"

SPONZA_RENDER_NAMESPACE_BEGIN
	struct WindowProps {
		const wchar_t* Title;
		unsigned int Width;
		unsigned int Height;
		bool IsFullscreen;

		WindowProps(const wchar_t* title = L"Sponza Render",
		            unsigned int width = 1280,
		            unsigned int height = 720)
			: Title(title), Width(width), Height(height), IsFullscreen(false)
		{
		}
	};

	class Window;

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

	class Window {
		friend WindowClass;

	public:
		Window(const WindowProps& windowProps);
		~Window();
		unsigned int GetWindowWidth() const noexcept;
		unsigned int GetWindowHeight() const noexcept;

		static std::shared_ptr<Window> Create(const WindowProps& windowPorps = WindowProps());

	private:
		Window() = delete;
		Window(const Window&) = delete;
		Window& operator=(const Window&) = delete;
	private:
		LRESULT HandleMsg(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept;

	private:
		WindowProps m_windowProps;
		HWND m_hWnd;
		bool m_bindedImgui = false;
		std::vector<char> m_rawInputBuffer;
	};

SPONZA_RENDER_NAMESPACE_END
