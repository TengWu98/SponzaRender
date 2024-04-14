#include "pch.h"
#include "WindowEvent.h"

SPONZA_RENDER_NAMESPACE_BEGIN
	WindowResizeEvent::WindowResizeEvent(unsigned width, unsigned height)
		: m_width(width), m_height(height)
	{
	}

	unsigned WindowResizeEvent::GetWidth() const
	{
		return m_width;
	}

	unsigned WindowResizeEvent::GetHeight() const
	{
		return m_height;
	}

	std::string WindowResizeEvent::ToString() const
	{
		std::stringstream ss;
		ss << "WindowResizeEvent: " << m_width << " , " << m_height;
		return ss.str();
	}

SPONZA_RENDER_NAMESPACE_END
