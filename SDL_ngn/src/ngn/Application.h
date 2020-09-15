#pragma once

#include "Core.h"

#include "platform/Window.h"

#include "events/Event.h"
#include "events/AppEvent.h"

#include "ecs/components/ComponentManager.h"
#include "ecs/components/Sprite.h"

#include "LayerStack.h"

namespace ngn
{	
	class Rendering;
	
	class NGN_API Application
	{

	public:
		Application();
		virtual ~Application();

		bool Load();
		void Loop();
		
		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline Window* GetWindow() const { return m_window.get(); }
		inline static Application& Get() { return *s_instance; }


	private:
		static Application* s_instance;
		
		std::unique_ptr<Window> m_window;		
		std::unique_ptr<Rendering> m_renderingSys;

		LayerStack m_layers;

		bool m_running;
		float m_deltaTime;
		uint32_t m_ticksLastFrame;

	private:		
		bool OnWindowClose(WindowCloseEvent& e);

	};

	Application* CreateApplication();
}