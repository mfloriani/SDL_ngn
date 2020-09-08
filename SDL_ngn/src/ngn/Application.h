#pragma once

#include "Core.h"

#include "events/Event.h"
#include "events/AppEvent.h"

#include "ecs/components/ComponentManager.h"
#include "ecs/components/Sprite.h"


namespace ngn
{
	class NgnWindow;
	class NgnAssetManager;
	class Rendering;
	
	class NGN_API Application
	{

	public:
		Application();
		virtual ~Application();

		bool Init();
		bool Load();
		void Loop();
		void Quit();

		void OnEvent(Event& e);

	private:
		std::unique_ptr<NgnWindow> m_window;
		static std::unique_ptr<NgnAssetManager>	m_assetMgr;
		
		std::unique_ptr<Rendering> m_renderingSys;

		bool m_running;

	private:
		bool OnWindowClose(WindowCloseEvent& e);


	};

	Application* CreateApplication();
}