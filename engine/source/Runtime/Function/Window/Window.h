#pragma once

SPONZA_RENDER_NAMESPACE_BEGIN
	struct WindowCreateInfo {
		const wchar_t* Title;
		unsigned int Width;
		unsigned int Height;
		bool IsFullscreen;

		WindowCreateInfo(const wchar_t* title = L"Sponza Render",
		                 unsigned int width = 1280,
		                 unsigned int height = 720)
			: Title(title), Width(width), Height(height), IsFullscreen(false)
		{
		}
	};

	class Window {
	private:
		class WindowClass {
			friend Window;

		public:
			static const wchar_t* GetName() noexcept;
			static HINSTANCE GetInstance() noexcept;

		private:
			WindowClass() noexcept;
			~WindowClass();
			WindowClass(const WindowClass&) = delete;
			WindowClass& operator=(const WindowClass&) = delete;

		private:
			HINSTANCE m_hInst;
			static constexpr const wchar_t* m_wndClassName = L"Sponza Render Window";
			static WindowClass m_wndClass;
		};

	public:
		Window(const WindowCreateInfo& windowCreateInfo);
		~Window();
		unsigned int GetWindowWidth() const noexcept;
		unsigned int GetWindowHeight() const noexcept;

		void ShowMessageBox(const wchar_t* title, const wchar_t* message) const noexcept;
		void SetTitle(const std::wstring& title);
		std::optional<int> ProcessMessages() noexcept;
		HWND GetHwnd() const noexcept;

		void CloseWindow() noexcept;

		static std::shared_ptr<Window> Create(const WindowCreateInfo& windowCreateInfo = WindowCreateInfo());

	private:
		static LRESULT WINAPI HandleMsgSetup(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept;
		static LRESULT WINAPI HandleMsgThunk(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept;
		LRESULT HandleMsg(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept;

	private:
		Window() = delete;
		Window(const Window&) = delete;
		Window& operator=(const Window&) = delete;

	private:
		WindowCreateInfo m_windowCreateInfo;
		HWND m_hWnd;
	};

SPONZA_RENDER_NAMESPACE_END
