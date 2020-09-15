#include "ngnpch.h"
#include "Renderer.h"
#include "ngn/Application.h"

namespace ngn
{
	Renderer::Renderer()
	{
		NGN_CORE_INFO("Renderer singleton created");
		auto window = Application::Get().GetWindow()->GetInternalWindow();
		m_renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if (!m_renderer)
		{
			NGN_CORE_CRITICAL("Failed to create SDL_RENDERER! SDL_Error: {0}", SDL_GetError());
		}
		SDL_SetRenderDrawBlendMode(m_renderer, SDL_BLENDMODE_BLEND);
	}

	Renderer::~Renderer()
	{

	}

	void Renderer::Quit()
	{
		SDL_DestroyRenderer(m_renderer);
	}

}