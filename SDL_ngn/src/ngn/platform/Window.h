#pragma once

#include "ngnpch.h"
#include "ngn/Core.h"
#include "ngn/events/Event.h"

namespace ngn
{
	class NGN_API Window
	{
	public:
		using EventCallback = std::function<void(Event&)>;

		Window(int width, int height);
		~Window();

		void OnUpdate(float dt);		

		inline void SetEventCallback(const EventCallback& callback) { m_eventCallback = callback; }

		inline SDL_Window* GetInternalWindow() const { return m_window; }

	private:
		void ProcessEvents();

	private:
		SDL_Window*	  m_window;
		SDL_Rect	  m_offset;
		EventCallback m_eventCallback;

	};
}