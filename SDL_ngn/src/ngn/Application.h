#pragma once

#include "Core.h"
#include "events/Event.h"
#include "events/AppEvent.h"

namespace ngn
{
	class NgnWindow;
	
	class NGN_API Application
	{
	public:
		Application();
		virtual ~Application();

		bool Init();
		void Loop();
		void Quit();

		void OnEvent(Event& e);

	private:
		std::unique_ptr<NgnWindow> m_window;
		bool m_running;

	private:
		bool OnWindowClose(WindowCloseEvent& e);


	};

	Application* CreateApplication();
}