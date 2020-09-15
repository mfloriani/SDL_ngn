#include "ngn.h"

class GameLayer : public ngn::Layer
{
public:
	virtual void OnStart() override
	{
		ASSET_MANAGER(ngn::Texture).Add("ship", "./assets/ship1.png");
		auto texture = ASSET_MANAGER(ngn::Texture).Get("ship");

		auto e1 = ngn::EntityManager::GetNewID();
		COMPONENT_MGR(ngn::Transform).Add(e1, glm::vec2{ 200, 400 });
		COMPONENT_MGR(ngn::Sprite).Add(e1, texture);

		
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
