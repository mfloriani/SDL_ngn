#pragma once

#ifdef NGN_PLATFORM_WINDOWS

extern ngn::Application* ngn::CreateApplication();

int main(int argc, char* argv[])
{
	ngn::Log::Init();
		
	auto app = ngn::CreateApplication();

	if (!app->Init())
	{
		app->Quit();
		return 1;
	}

	if (!app->Load())
	{
		app->Quit();
		return 1;
	}

	app->Loop();
	app->Quit();

	delete app;

	return 0;
}

#endif // NGN_PLATFORM_WINDOWS
