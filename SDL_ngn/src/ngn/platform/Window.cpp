#include "ngnpch.h"
#include "Window.h"
#include "ngn/events/AppEvent.h"
#include "ngn/events/KeyEvent.h"
#include "ngn/events/MouseEvent.h"

namespace ngn
{	
	Window::Window(int width, int height): 
		m_offset(SDL_Rect{0, 0, width, height})		
	{
		m_window = SDL_CreateWindow("SDL_ngn", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, NULL);
		if (!m_window)
		{
			NGN_CORE_CRITICAL("Failed to create SDL_WINDOW! SDL_Error: {0}", SDL_GetError());
		}
		SDL_GetWindowPosition(m_window, &m_offset.x, &m_offset.y);
	}

	Window::~Window()
	{		
		SDL_DestroyWindow(m_window);
	}

	void Window::OnUpdate(float dt)
	{
		ProcessEvents();
	}
	
	void Window::ProcessEvents()
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT || (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE))
			{
				WindowCloseEvent e;
				m_eventCallback(e);
			}
			switch (event.type)
			{
			case SDL_KEYDOWN:
			{
				//auto keyname = SDL_GetKeyName(event.key.keysym.sym);
				//NGN_CORE_INFO("{0}",keyname);
				KeyPressedEvent e((int)event.key.keysym.sym, event.key.repeat);
				m_eventCallback(e);
				break;
			}
			case SDL_KEYUP:
			{
				KeyReleasedEvent e((int)event.key.keysym.sym);
				m_eventCallback(e);
				break;
			}
			case SDL_MOUSEMOTION:
			{
				MouseMovedEvent e(event.motion.x, event.motion.y);
				m_eventCallback(e);
				break;
			}
			case SDL_MOUSEBUTTONDOWN:
			{
				MouseButtonPressedEvent e(event.button.button, event.button.clicks);
				m_eventCallback(e);
				break;
			}
			case SDL_MOUSEBUTTONUP:
			{
				MouseButtonReleasedEvent e(event.button.button);
				m_eventCallback(e);
				break;
			}
			case SDL_MOUSEWHEEL:
			{
				MouseScrolledEvent e(event.wheel.x, event.wheel.y);
				m_eventCallback(e);
				break;
			}
			} 
		}
	}
	
}