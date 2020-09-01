#include "ngnpch.h"
#include "NgnWindow.h"
#include "ngn/events/AppEvent.h"

namespace ngn
{
	SDL_Renderer* NgnWindow::m_renderer = nullptr;

	NgnWindow::NgnWindow(int width, int height): 
		m_offset(SDL_Rect{0, 0, width, height}),
		m_deltaTime(0.0f), 
		m_ticksLastFrame(0)
	{
		Init(width, height);
	}

	NgnWindow::~NgnWindow()
	{
		SDL_DestroyRenderer(m_renderer);
		SDL_DestroyWindow(m_window);
		Mix_Quit();
		TTF_Quit();
		IMG_Quit();
		SDL_Quit();
	}

	bool NgnWindow::Init(int width, int height)
	{
		SDL_SetMainReady();
		if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		{
			NGN_CORE_CRITICAL("Failed to initialize SDL! SDL_Error: {0}", SDL_GetError());
			return false;
		}

		m_window = SDL_CreateWindow("SDL_ngn", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, NULL);
		if (!m_window)
		{
			NGN_CORE_CRITICAL("Failed to create SDL_WINDOW! SDL_Error: {0}", SDL_GetError());
			return false;
		}
		SDL_GetWindowPosition(m_window, &m_offset.x, &m_offset.y);

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

		m_ticksLastFrame = SDL_GetTicks();

		return true;
	}


	void NgnWindow::OnUpdate()
	{
		ProcessFramerate();
		ProcessEvents();

	}
	
	void NgnWindow::ProcessFramerate()
	{
		while (!SDL_TICKS_PASSED(SDL_GetTicks(), m_ticksLastFrame + FRAME_LENGTH));
		m_deltaTime = (SDL_GetTicks() - m_ticksLastFrame) / 1000.f;
		m_ticksLastFrame = SDL_GetTicks();
		if (m_deltaTime > 0.1f) m_deltaTime = 0.1f;
	}


	void NgnWindow::ProcessEvents()
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT || (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE))
			{
				WindowCloseEvent event;
				m_eventCallback(event);
			}
		}
	}
	
}