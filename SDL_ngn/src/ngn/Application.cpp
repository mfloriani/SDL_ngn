#include "ngnpch.h"
#include "Application.h"

#include "platform/NgnWindow.h"

#include "platform/NgnAssetManager.h"
#include "platform/NgnTextureManager.h"
#include "platform/NgnTexture.h"

#include "ecs/entities/Entity.h"
#include "ecs/components/Sprite.h"
#include "ecs/systems/Rendering.h"

namespace ngn
{
	std::unique_ptr<NgnAssetManager>		  Application::m_assetMgr;
	std::unique_ptr<ComponentManager<Sprite>> Application::m_spriteCMgr;

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
		NGN_CORE_TRACE("Application::Init");
		
		//TODO: remove fixed resolution
		m_window = std::make_unique<NgnWindow>(1440, 900);
		m_window->SetEventCallback(BIND_EVENT_FN(OnEvent));

		m_assetMgr = std::make_unique<NgnAssetManager>();
		m_spriteCMgr = std::make_unique<ComponentManager<Sprite>>();

		m_renderingSys = std::make_unique<Rendering>();
		m_renderingSys->OnStart();

		return true;
	}

	bool Application::Load()
	{
		NGN_CORE_TRACE("Application::Load");

		
		auto e1 = EntityManager::GetNewID();
		
		if (!m_assetMgr->AddTexture("ship", "./assets/ship1.png"))
		{
			NGN_CORE_ERROR("Failed to load texture");
			m_running = false;
		}
		
		NgnTexture texture;
		texture.m_texture = m_assetMgr->GetTexture("ship");
		texture.m_srcrect = { 0, 0, 32, 32 };
		texture.m_dstrect = { 0, 0, 32, 32 };
		
		m_spriteCMgr->Add(Sprite(texture));

		auto e2 = EntityManager::GetNewID();
		auto e3 = EntityManager::GetNewID();

		NGN_CORE_TRACE("{0},{1},{2}", e1, e2, e3);
		
		return true;
	}

	void Application::Loop()
	{
		NGN_CORE_TRACE("Application::Loop");
		while (m_running)
		{
			m_window->OnUpdate();
			m_renderingSys->OnUpdate(m_window->DeltaTime());
		}
	}

	void Application::Quit()
	{
		NGN_CORE_TRACE("Application::Quit");

		m_renderingSys->OnQuit();
	}

	void Application::OnEvent(Event& e)
	{
		NGN_CORE_TRACE("Application::OnEvent");

		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));


	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_running = false;
		return true;
	}
}