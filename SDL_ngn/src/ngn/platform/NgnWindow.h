#pragma once

#include "ngnpch.h"
#include "ngn/Core.h"
#include "ngn/events/Event.h"

namespace ngn
{
	class NGN_API NgnWindow
	{
	public:
		using EventCallback = std::function<void(Event&)>;

		NgnWindow(int width, int height);
		~NgnWindow();

		inline static SDL_Renderer* Renderer() { return m_renderer; }
		inline float DeltaTime() const { return m_deltaTime; }

		void OnUpdate();
		
		inline void SetEventCallback(const EventCallback& callback) { m_eventCallback = callback; }

	private:
		bool Init(int width, int height);
		void ProcessFramerate();
		void ProcessEvents();

	private:
		SDL_Window*				m_window;
		static SDL_Renderer*	m_renderer;

		SDL_Rect		m_offset;
		float			m_deltaTime;
		uint32_t		m_ticksLastFrame;

		EventCallback	m_eventCallback;

	};
}