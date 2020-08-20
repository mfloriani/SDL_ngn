#pragma once

#ifdef NGN_PLATFORM_WINDOWS

extern ngn::Application* ngn::CreateApplication();

int main(int argc, char** argv)
{
	ngn::Log::Init();
	NGN_CORE_WARN("Initialized log!");
	NGN_INFO("Hello from App!");
	int v = 1009;
	NGN_ERROR("code={0}", v);

	auto app = ngn::CreateApplication();
	app->Run();
	delete app;
}

#endif // NGN_PLATFORM_WINDOWS
