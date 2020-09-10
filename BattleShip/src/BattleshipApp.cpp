#include "ngn.h"

#include "ngn/events/KeyEvent.h"

class GameLayer : public ngn::Layer
{
public:
	virtual void OnStart() override
	{

	}

	virtual void OnQuit() override
	{

	}

	virtual void OnUpdate() override
	{
		if (ngn::Input::IsKeyPressed(SDLK_RETURN))
		{
			NGN_TRACE("Enter pressed");
		}

		if (ngn::Input::IsMouseButtonPressed(SDL_BUTTON_RIGHT))
		{
			auto [x,y] = ngn::Input::GetMousePosition();
			NGN_TRACE("Right button pressed at ({0},{1})", x, y);
		}
	}
	
	virtual void OnEvent(ngn::Event& e) override
	{
		//NGN_TRACE("GameLayer: {0}", e);

		if (e.GetEventType() == ngn::EventType::KeyPressed)
		{
			ngn::KeyPressedEvent event = (ngn::KeyPressedEvent&)e;
			
		}

		

	}
};


class UILayer : public ngn::Layer
{
public:
	virtual void OnStart() override
	{

	}

	virtual void OnQuit() override
	{

	}

	virtual void OnUpdate() override
	{

	}

	virtual void OnEvent(ngn::Event& e) override
	{
		//NGN_TRACE("UILayer: {0}", e);

	}
};

class BattleshipApp : public ngn::Application
{
public:
	BattleshipApp()
	{
		PushLayer(new GameLayer());
		PushOverlay(new UILayer());
	}

	~BattleshipApp()
	{
	
	}

	

};

ngn::Application* ngn::CreateApplication()
{
	return new BattleshipApp();
}
