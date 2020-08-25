#pragma once

#include "ngnpch.h"
#include "ngn/Core.h"

namespace ngn
{
	enum class EventType
	{
		None = 0,
		WindowClose
	};

	#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
	virtual EventType GetEventType() const override { return GetStaticType(); }
	

	class NGN_API Event
	{
		friend class EventDispatcher;
	public:
		virtual EventType GetEventType() const = 0;
	private:
		bool m_handled{ false };
	};


	class EventDispatcher
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>;

	public:
		EventDispatcher(Event& e) : m_event(e)
		{}

		template<typename T>
		bool Dispatch(EventFn<T> func)
		{
			if (m_event.GetEventType() == T::GetStaticType())
			{
				m_event.m_handled = func(*(T*)&m_event);
				return true;
			}
			return false;
		}

	private:
		Event& m_event;
	};
}