#pragma once

#include "Events/Event.h"

namespace Toy
{
	class TOY_API WindowsCloseEvent : public Event
	{
	public:
		WindowsCloseEvent() {};

		EVENT_CLASS_TYPE(WindowsClose)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class TOY_API WindowsResizeEvent : public Event
	{
	public:
		WindowsResizeEvent(unsigned int newWidth, unsigned int newHeight): m_newWidth(newWidth), m_newHeight(newHeight) {}
		
		inline unsigned int GetWidth() const { return m_newWidth; }
		
		inline unsigned int GetHeight() const { return m_newHeight; }

		virtual std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowsResizeEvent: " << m_newWidth << " " << m_newHeight;
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowsResize)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	private:
		unsigned int m_newWidth;
		unsigned int m_newHeight;
	};

	class TOY_API WindowsFocusEvent : public Event
	{
	public:
		WindowsFocusEvent() {}
		
		EVENT_CLASS_TYPE(WindowsFocus)
		EVENT_CLASS_CATEGORY(EventCategoryApplication )
	};

	class TOY_API WindowsLostFocusEvent : public Event
	{
	public:
		WindowsLostFocusEvent() {}

		EVENT_CLASS_TYPE(WindowsLostFocus)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class TOY_API WindowsMovedEvent : public Event
	{
	public:
		WindowsMovedEvent(int newPosX, int newPosY) : m_newPosX(newPosX), m_newPosY(newPosY) {}
		
		virtual std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowsMovedEvent: " << m_newPosX << " " << m_newPosY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowsMoved)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	private:
		int m_newPosX;
		int m_newPosY;
	};

	class TOY_API AppTickEvent : public Event
	{
	public:
		AppTickEvent(float deltaTime) : m_deltaTime(deltaTime) {}

		virtual std::string ToString() const override
		{
			std::stringstream ss;
			ss << "AppTickEvent: " << m_deltaTime;
			return ss.str();
		}

	EVENT_CLASS_TYPE(AppTick)
	EVENT_CLASS_CATEGORY(EventCategoryApplication)
	private:
		float m_deltaTime;
	};

	class TOY_API AppUpdateEvent : public Event
	{
	public:
		AppUpdateEvent(float deltaTime) : m_deltaTime(deltaTime) {}

		virtual std::string ToString() const override
		{
			std::stringstream ss;
			ss << "AppUpdateEvent: " << m_deltaTime;
			return ss.str();
		}

		EVENT_CLASS_TYPE(AppUpdate)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	private:
		float m_deltaTime;
	};

	class TOY_API AppRenderEvent : public Event
	{
	public:
		AppRenderEvent(float deltaTime) : m_deltaTime(deltaTime) {}

		virtual std::string ToString() const override
		{
			std::stringstream ss;
			ss << "AppRenderEvent: " << m_deltaTime;
			return ss.str();
		}

		EVENT_CLASS_TYPE(AppRender)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	private:
		float m_deltaTime;
	};
}