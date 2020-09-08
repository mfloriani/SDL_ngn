#pragma once

#include "ngnpch.h"
#include "ngn/Core.h"

#include "Event.h"

namespace ngn
{

	class KeyEvent : public Event
	{
	public:
		inline int GetKeyCode() const { return m_keycode; }

		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryKeyboard);
	protected:
		KeyEvent(int keycode) : m_keycode(keycode) {}
		int m_keycode;
	};

	class KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int keycode, int repeat) :
			KeyEvent(keycode),
			m_repeat(repeat)
		{

		}

		inline int GetRepeatCount() const { return m_repeat; }

		virtual std::string ToString() const override
		{ 
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_keycode << " (" << m_repeat << ")";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed);

	private:
		int m_repeat;
	};

	class KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keycode) : KeyEvent(keycode) {}

		virtual std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_keycode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased);
	};

}