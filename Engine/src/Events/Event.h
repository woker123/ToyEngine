#pragma once

#include <sstream>
#include <functional>
#include "Engine/Core.h"

namespace Toy
{
	enum class EventType
	{
		None = 0,
		WindowsClose, WindowsResize, WindowsFocus, WindowsLostFocus, WindowsMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EventCategory
	{
		None = 0,
		EventCategoryApplication = BIT(1),
		EventCategoryInput = BIT(2),
		EventCategoryKeyboard = BIT(3),
		EventCategoryMouse = BIT(4),
		EventCategoryMouseButton = BIT(5)
	};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticEventType() {return EventType::##type;}\
									virtual EventType GetEventType() const override {return GetStaticEventType();}\
									virtual const char* Name() const override {return #type;}

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override {return category;}

	class TOY_API Event
	{
		friend class EventDispatcher;
	public:
		virtual EventType GetEventType() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual const char* Name() const = 0;
		virtual std::string ToString() const { return Name(); }

		inline bool IsInCategory(EventCategory category) const { return GetCategoryFlags() & category; }
	protected:
		Event() {}

	private:
		bool m_handled;
	};

	class EventDispatcher
	{
		template<typename T>
		using EventFunc = std::function<bool(T& event)>;
	public:
		EventDispatcher(Event& event) : m_event(event){}

		template<typename T>
		inline bool DispatchEvent(EventFunc<T> func)
		{
			if (m_event.GetEventType() == T::GetStaticEventType())
			{
				m_event.m_handled = func(*(T*)&m_event);
				return true;
			}
			else
			{
				return false;
			}
		}

	private:
		Event& m_event;
	};
}




