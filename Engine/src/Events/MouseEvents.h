#pragma once

#include "Events/Event.h"

namespace Toy
{
	class TOY_API MouseButtonPressedEvent : public Event
	{
	public:
		MouseButtonPressedEvent(int button):m_button(button) {}

		inline int GetButton() const { return m_button; }

		virtual std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: Button: " << m_button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse | EventCategoryMouseButton)
	private:
		int m_button;
	};

	class TOY_API MouseButtonReleasedEvent : public Event
	{
	public:
		MouseButtonReleasedEvent(int button) :m_button(button) {}

		inline int GetButton() const { return m_button; }

		virtual std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: Button: " << m_button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse | EventCategoryMouseButton)
	private:
		int m_button;
	};

	class TOY_API MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(int newPosX, int newPosY) : m_newPosX(newPosX), m_newPosY(newPosY) {}

		inline int GetNewPosX() const { return m_newPosX; }

		inline int GetNewPosY() const { return m_newPosY; }

		virtual std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent: NewPosX: " << m_newPosX << " NewPosY: " << m_newPosY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse | EventCategoryMouseButton)
	private:
		int m_newPosX, m_newPosY;
	};

	class TOY_API MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(int scrollBiasX, int scrollBiasY) : m_scrollBiasX(scrollBiasX), m_scrollBiasY(scrollBiasY) {}

		inline int GetScrollBiasX() const { return m_scrollBiasX; }

		inline int GetScrollBiasY() const { return m_scrollBiasY; }

		virtual std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent: ScrollBiasX: " << m_scrollBiasX << " ScrollBiasY: " << m_scrollBiasY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse | EventCategoryMouseButton)
	private:
		int m_scrollBiasX, m_scrollBiasY;
	};
}