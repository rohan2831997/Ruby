#pragma once

#include "Application.h"
#include "Logger/Log.h"
#include "Events/AppEvents.h"

#ifdef R_WINDOWS_PLATFORM

extern Ruby::Application* Ruby::CreateApplication();

int main(int argc, char** argv)
{
	Ruby::Log::Init();
	RUBY_LOG_TRACE("This is client debugger");
	APP_LOG_ERROR("This is core debugger");
	//::Ruby::Log("ABC");
	Ruby::WindowResizeEvent E(100, 150);



	if (E.ImplementsCategory(Ruby::EventApplication))
		APP_LOG_ERROR(E.ToString());
	

	if (E.ImplementsCategory(Ruby::EventKeyboard))
	{
		RUBY_LOG_TRACE(E.ToString());
	}

	auto app = Ruby::CreateApplication();
	app->Run();
	delete app;
}

#endif // R_WINDOWS_PLATFORM


