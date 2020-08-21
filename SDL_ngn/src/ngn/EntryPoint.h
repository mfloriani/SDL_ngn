#pragma once

#ifdef NGN_PLATFORM_WINDOWS

extern ngn::Application* ngn::CreateApplication();

int main(int argc, char* argv[])
{
	ngn::Log::Init();
	NGN_CORE_WARN("Engine running");
	NGN_INFO("App running");
	
	auto app = ngn::CreateApplication();
	if (!app->Init())
	{
		app->Quit();
		return 1;
	}
	app->Run();
	//app->Quit();
	delete app;

	return 0;
}

#endif // NGN_PLATFORM_WINDOWS
