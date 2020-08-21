#pragma once

#include "Core.h"

#define SDL_MAIN_HANDLED
#include "SDL.h"

namespace ngn
{	
	class NGN_API Application
	{
	public:
		Application();
		virtual ~Application();

		bool Init();
		void Run();
		void Quit();

	private:
		SDL_Window*		m_window;
		SDL_Renderer*	m_renderer;
		
		bool			m_running;
	};

	Application* CreateApplication();

}