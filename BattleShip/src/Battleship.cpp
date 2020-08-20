#include <ngn.h>

class Battleship : public ngn::Application
{
public:
	Battleship()
	{

	}

	~Battleship()
	{

	}
};

ngn::Application* ngn::CreateApplication()
{
	return new Battleship();
}
