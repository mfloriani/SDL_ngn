#pragma once

#include "Core.h"

#include "events/Event.h"
#include "events/AppEvent.h"

#include "ecs/components/ComponentManager.h"
#include "ecs/components/Sprite.h"

#include "LayerStack.h"

namespace ngn
{
	class Window;
	class AssetManager;
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

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

	private:
		std::unique_ptr<Window> m_window;
		static std::unique_ptr<AssetManager>	m_assetMgr;
		std::unique_ptr<Rendering> m_renderingSys;

		LayerStack m_layers;

		bool m_running;

	private:
		bool OnWindowClose(WindowCloseEvent& e);


	};

	Application* CreateApplication();
}