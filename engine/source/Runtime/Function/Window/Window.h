#pragma once

#include "Runtime/Function/Input/Keyboard.h"
#include "Runtime/Function/Input/Mouse.h"

SPONZA_RENDER_NAMESPACE_BEGIN
	struct WindowProps {
		const wchar_t* Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const wchar_t* title = L"Sponza Render",
		            unsigned int width = 1280,
		            unsigned int height = 720)
			: Title(title), Width(width), Height(height)
		{
		}
	};

	class Window {
	protected:
		Window(const WindowProps& windowProps);

	public:
		virtual ~Window();
		virtual unsigned int GetWindowWidth() const noexcept = 0;
		virtual unsigned int GetWindowHeight() const noexcept = 0;

		static std::shared_ptr<Window> Create(const WindowProps& windowPorps = WindowProps());

	private:
		Window() = delete;
		Window(const Window&) = delete;
		Window& operator=(const Window&) = delete;

	protected:
		WindowProps m_windowProps;
	};

SPONZA_RENDER_NAMESPACE_END
