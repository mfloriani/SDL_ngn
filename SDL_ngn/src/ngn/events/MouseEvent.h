#pragma once

#include "ngnpch.h"
#include "ngn/Core.h"

#include "Event.h"

namespace ngn
{
	class MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(int x , int y) :
			m_posX(x),
			m_posY(y)
		{}

		EVENT_CLASS_TYPE(MouseMoved);
		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse);

		virtual std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent: " << m_posX << "," << m_posY;
			return ss.str();
		}

	private:
		int m_posX, m_posY;
	};

	class MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(float offsetX, float offsetY) :
			m_offsetX(offsetX),
			m_offsetY(offsetY)
		{}

		EVENT_CLASS_TYPE(MouseScrolled);
		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse);

		virtual std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << m_offsetX << "," << m_offsetY;
			return ss.str();
		}

	private:
		float m_offsetX, m_offsetY;
	};

	class MouseButtonEvent : public Event
	{
	public:
		inline int GetMouseButton() const { return m_button; }

		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse);

	protected:
		MouseButtonEvent(int button) : m_button(button) {}
		int m_button;
	};

	class MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int button, int clicks) : 
			MouseButtonEvent(button),
			m_clicks(clicks)
		{}

		EVENT_CLASS_TYPE(MouseButtonPressed);

		virtual std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << m_button << "(" << m_clicks << " clicks)";
			return ss.str();
		}
	private:
		int m_clicks;
	};

	class MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int button) : MouseButtonEvent(button) {}

		EVENT_CLASS_TYPE(MouseButtonReleased);

		virtual std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << m_button;
			return ss.str();
		}
	};

}