#include <ngn.h>

class BattleshipApp : public ngn::Application
{
public:
	BattleshipApp(){}
	~BattleshipApp(){}
};

ngn::Application* ngn::CreateApplication()
{
	return new BattleshipApp();
}
