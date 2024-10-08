#pragma once
#include"Application.h"

#ifdef R_WINDOWS_PLATFORM

extern Ruby::Application* Ruby::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Ruby::CreateApplication();
	app->Run();
	delete app;
}

#endif // R_WINDOWS_PLATFORM


