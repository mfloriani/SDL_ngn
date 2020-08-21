#include "ngnpch.h"
#include "Application.h"

namespace ngn
{
	Application::Application()
		: //m_window(nullptr), m_renderer(nullptr), 
		m_running(true)
	{
		
	}

	Application::~Application()
	{
		
	}

	bool Application::Init()
	{
		
		//TODO: create a Window class to abstract SDL
		SDL_SetMainReady();
		if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		{
			NGN_CORE_CRITICAL("Failed to initialize SDL! SDL_Error: {0}", SDL_GetError());
			return false;
		}

		m_window = SDL_CreateWindow("SDL_ngn", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, NULL);
		if (!m_window)
		{
			NGN_CORE_CRITICAL("Failed to create SDL_WINDOW! SDL_Error: {0}", SDL_GetError());
			return false;
		}

		m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if (!m_renderer)
		{
			NGN_CORE_CRITICAL("Failed to create SDL_RENDERER! SDL_Error: {0}", SDL_GetError());
			return false;
		}
		SDL_SetRenderDrawBlendMode(m_renderer, SDL_BLENDMODE_BLEND);

		if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
		{
			NGN_CORE_CRITICAL("Failed to initialize SDL_IMAGE! SDL_Error: {0}", IMG_GetError());
			return false;
		}
		if (TTF_Init() == -1)
		{
			NGN_CORE_CRITICAL("Failed to initialize SDL_TTF! SDL_Error: {0}", TTF_GetError());
			return false;
		}
		if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
		{
			NGN_CORE_CRITICAL("Failed to initialize SDL_MIXER! SDL_Error: {0}", Mix_GetError());
			return false;
		}
		return true;
	}

	void Application::Run()
	{
		while (m_running)
		{
			SDL_Event event;
			SDL_PollEvent(&event);

			if (event.type == SDL_QUIT || (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE))
			{
				m_running = false;
			}
		}
	}

	void Application::Quit()
	{
		SDL_DestroyRenderer(m_renderer);
		SDL_DestroyWindow(m_window);
		Mix_Quit();
		TTF_Quit();
		IMG_Quit();
		SDL_Quit();
	}
}