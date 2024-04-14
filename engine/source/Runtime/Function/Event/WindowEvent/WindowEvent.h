#pragma once

#include "../Event.h"

SPONZA_RENDER_NAMESPACE_BEGIN
	class WindowResizeEvent : public Event {
	public:
		WindowResizeEvent(unsigned int width, unsigned int height);
		unsigned int GetWidth() const;
		unsigned int GetHeight() const;
		virtual std::string ToString() const override;

		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(EventCategoryEngine)

	private:
		unsigned int m_width;
		unsigned int m_height;
	};

	class WindowCloseEvent : public Event {
	public:
		WindowCloseEvent() = default;

		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(EventCategoryEngine)
	};

SPONZA_RENDER_NAMESPACE_END
