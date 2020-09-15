#pragma once

#ifdef NGN_PLATFORM_WINDOWS

extern ngn::Application* ngn::CreateApplication();

int main(int argc, char* argv[])
{	
	ngn::Log::Init();

	NGN_CORE_TRACE("libSDL::init()");
	ngn::LibSDL::Init();
	
	NGN_CORE_TRACE("createApplication()");
	auto app = ngn::CreateApplication();
	NGN_CORE_TRACE("app::load()");
	if (app->Load())
	{
		NGN_CORE_TRACE("app::loop()");
		app->Loop();
	}
	NGN_CORE_TRACE("delete app");
	delete app;

	NGN_CORE_TRACE("libSDL::quit()");
	ngn::LibSDL::Quit();
	return 0;
}

#endif // NGN_PLATFORM_WINDOWS
