#include "ngnpch.h"
#include "Application.h"
#include "platform/NgnWindow.h"

namespace ngn
{
	#define BIND_EVENT_FN(fn) std::bind(&Application::fn, this, std::placeholders::_1)

	Application::Application()
		: m_window(nullptr), m_running(true)
	{
		
	}

	Application::~Application()
	{
		
	}

	bool Application::Init()
	{
		m_window = std::make_unique<NgnWindow>(1440, 900);
		m_window->SetEventCallback(BIND_EVENT_FN(OnEvent));
		return true;
	}

	void Application::Loop()
	{
		while (m_running)
		{
			m_window->OnUpdate();

		}
	}

	void Application::Quit()
	{
		
	}

	void Application::OnEvent(Event& e)
	{
		NGN_CORE_TRACE("Event received");

		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		NGN_CORE_TRACE("WindoCloseEvent received");
		m_running = false;
		return true;
	}
}