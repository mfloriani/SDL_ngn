#include "ngnpch.h"
#include "Application.h"

#include "platform/Window.h"

#include "platform/AssetManager.h"
#include "platform/TextureManager.h"
#include "platform/Texture.h"

#include "ecs/entities/Entity.h"
#include "ecs/components/Sprite.h"
#include "ecs/components/Transform.h"
#include "ecs/components/ComponentManager.h"
#include "ecs/systems/Rendering.h"

namespace ngn
{
	//TODO: move assetManager to a singleton and remove the ref inside Application
	std::unique_ptr<AssetManager> Application::m_assetMgr;

	#define BIND_EVENT_FN(fn) std::bind(&Application::fn, this, std::placeholders::_1)

	Application::Application() : 
		m_renderingSys(nullptr),
		m_running(true)
	{
		
	}

	Application::~Application()
	{
		
	}

	bool Application::Init()
	{
		//NGN_CORE_TRACE("Application::Init");
		
		//TODO: remove fixed resolution
		m_window = std::make_unique<Window>(1440, 900);
		m_window->SetEventCallback(BIND_EVENT_FN(OnEvent));

		m_assetMgr = std::make_unique<AssetManager>();

		m_renderingSys = std::make_unique<Rendering>();
		m_renderingSys->OnStart();

		return true;
	}

	bool Application::Load()
	{
		//NGN_CORE_TRACE("Application::Load");

		if (!m_assetMgr->AddTexture("ship", "./assets/ship1.png"))
		{
			NGN_CORE_ERROR("Failed to load texture");
			m_running = false;
		}
		
		auto e1 = EntityManager::GetNewID();

		COMPONENT_MGR(Transform).Add(e1, glm::vec2{ 200, 400 });

		Texture texture;
		texture.m_texture = m_assetMgr->GetTexture("ship");
		texture.m_srcrect = { 0, 0, 32, 32 };
		texture.m_dstrect = { 100, 100, 32, 32 };
		
		COMPONENT_MGR(Sprite).Add(e1, texture);

		//COMPONENT_MGR(Script).Add(e1, )


		auto e2 = EntityManager::GetNewID();
		auto e3 = EntityManager::GetNewID();

		NGN_CORE_TRACE("{0},{1},{2}", e1, e2, e3);
		
		return true;
	}

	void Application::Loop()
	{
		//NGN_CORE_TRACE("Application::Loop");
		while (m_running)
		{
			m_window->OnUpdate();
			auto dt = m_window->DeltaTime();

			for (Layer* layer : m_layers)
			{
				layer->OnUpdate();
			}

			m_renderingSys->OnUpdate(dt);
		}
	}

	void Application::Quit()
	{
		//NGN_CORE_TRACE("Application::Quit");

		m_renderingSys->OnQuit();
	}

	void Application::OnEvent(Event& e)
	{
		//NGN_CORE_TRACE("Application::OnEvent");

		NGN_CORE_TRACE(e);

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