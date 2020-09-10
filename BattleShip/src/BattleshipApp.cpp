#include <ngn.h>

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

	}
	
	virtual void OnEvent(ngn::Event& e) override
	{
		NGN_TRACE("GameLayer: {0}", e);

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
		NGN_TRACE("UILayer: {0}", e);

	}
};

class BattleshipApp : public ngn::Application
{
public:
	BattleshipApp()
	{
		PushOverlay(new UILayer());
		PushLayer(new GameLayer());
	}

	~BattleshipApp()
	{
	
	}

	

};

ngn::Application* ngn::CreateApplication()
{
	return new BattleshipApp();
}
