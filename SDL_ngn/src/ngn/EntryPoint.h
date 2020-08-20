#pragma once

#ifdef NGN_PLATFORM_WINDOWS

extern ngn::Application* ngn::CreateApplication();

int main(int argc, char** argv)
{
	auto app = ngn::CreateApplication();
	app->Run();
	delete app;
}

#endif // NGN_PLATFORM_WINDOWS
