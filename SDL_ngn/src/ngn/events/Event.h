#pragma once

#include "ngnpch.h"
#include "ngn/Core.h"

namespace ngn
{
	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus,
		KeyPressed, KeyReleased,
		MouseMoved, MouseButtonPressed, MouseButtonReleased, MouseScrolled
	};

	enum EventCategory
	{
		None = 0,
		EventCategoryApp		= BIT(0),
		EventCategoryInput		= BIT(1),
		EventCategoryKeyboard	= BIT(2),
		EventCategoryMouse		= BIT(3)
	};

	#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
	virtual EventType GetEventType() const override { return GetStaticType(); }\
	virtual const char* GetName() const override { return #type; }
	
	#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	class NGN_API Event
	{
	public:
		bool Handled{ false };

		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;

		virtual std::string ToString() const 
		{ 
			std::stringstream ss;
			ss << "Event: " << GetName();
			return ss.str(); 
		}

		inline bool IsInCategory(EventCategory category) { return GetCategoryFlags() & category; }
	
	};

	class EventDispatcher
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>;

	public:
		EventDispatcher(Event& e) : m_event(e) {}

		template<typename T>
		bool Dispatch(EventFn<T> func)
		{
			if (m_event.GetEventType() == T::GetStaticType())
			{
				m_event.Handled = func(*(T*)&m_event);
				return true;
			}
			return false;
		}

	private:
		Event& m_event;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}
}