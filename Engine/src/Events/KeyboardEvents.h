#pragma once

#include "Events/Event.h"
#include <sstream>

namespace Toy
{
	class TOY_API KeyPressedEvent : public Event
	{
	public:
		KeyPressedEvent(int keyCode, int repeatNum) :m_keyCode(keyCode), m_repeatNum(repeatNum){}
		
		inline int GetKeyCode() const { return m_keyCode; }

		virtual std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: KeyCode: " << m_keyCode << " RepeatNum: " << m_repeatNum;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)
		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryKeyboard)
	private:
		int m_keyCode;
		int m_repeatNum;
	};

	class TOY_API KeyReleasedEvent : public Event
	{
	public:
		KeyReleasedEvent(int keyCode): m_keyCode(keyCode) {}

		inline int GetKeyCode() const { return m_keyCode; }

		virtual std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: KeyCode: " << m_keyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryKeyboard)
	private:
		int m_keyCode;
	};




}