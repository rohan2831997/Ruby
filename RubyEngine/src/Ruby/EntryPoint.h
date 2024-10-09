#pragma once
#include "Application.h"
#include "Log.h"

#ifdef R_WINDOWS_PLATFORM

extern Ruby::Application* Ruby::CreateApplication();

int main(int argc, char** argv)
{
	Ruby::Log::Init();
	RUBY_LOG_TRACE("This is client debugger");
	APP_LOG_ERROR("This is core debugger");

	auto app = Ruby::CreateApplication();
	app->Run();
	delete app;
}

#endif // R_WINDOWS_PLATFORM


