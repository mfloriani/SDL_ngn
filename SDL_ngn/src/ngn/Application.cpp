#include "ngnpch.h"
#include "Application.h"

#include "platform/Window.h"
#include "platform/AssetManager.h"
#include "platform/Texture.h"

#include "ecs/entities/Entity.h"
#include "ecs/components/Sprite.h"
#include "ecs/components/Transform.h"
#include "ecs/components/ComponentManager.h"
#include "ecs/systems/Rendering.h"

namespace ngn
{
	Application* Application::s_instance = nullptr;
	
	#define BIND_EVENT_FN(fn) std::bind(&Application::fn, this, std::placeholders::_1)

	Application::Application() : 
		m_renderingSys(nullptr),
		m_running(true),
		m_deltaTime(0.0f),
		m_ticksLastFrame(0)
	{
		s_instance = this;

		//TODO: remove fixed resolution
		m_window = std::make_unique<Window>(1440, 900);
		m_window->SetEventCallback(BIND_EVENT_FN(OnEvent));

		m_renderingSys = std::make_unique<Rendering>();
		m_renderingSys->OnStart();

	}

	Application::~Application()
	{
		m_renderingSys->OnQuit();
	}


	bool Application::Load()
	{
		for (Layer* layer : m_layers)
		{
			layer->OnStart();
		}
		
		return true;
	}

	void Application::Loop()
	{
		m_ticksLastFrame = SDL_GetTicks();

		while (m_running)
		{
			while (!SDL_TICKS_PASSED(SDL_GetTicks(), m_ticksLastFrame + FRAME_LENGTH));
			m_deltaTime = (SDL_GetTicks() - m_ticksLastFrame) / 1000.f;
			m_ticksLastFrame = SDL_GetTicks();
			if (m_deltaTime > 0.1f) m_deltaTime = 0.1f;

			m_window->OnUpdate(m_deltaTime);

			for (Layer* layer : m_layers)
			{
				layer->OnUpdate();
			}

			m_renderingSys->OnUpdate(m_deltaTime);
		}
	}


	void Application::OnEvent(Event& e)
	{
		NGN_CORE_TRACE("{0}", e);

		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));


		for (auto it = m_layers.end(); it != m_layers.begin();)
		{
			(*--it)->OnEvent(e);
			if (e.Handled) break;
		}

	}

	void Application::PushLayer(Layer* layer)
	{
		m_layers.PushFirst(layer);
	}

	void Application::PushOverlay(Layer* layer)
	{
		m_layers.PushLast(layer);
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_running = false;
		return true;
	}
}