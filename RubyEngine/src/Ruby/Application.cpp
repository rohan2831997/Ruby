#pragma once
#include "RubyPCH.h"
#include "Application.h"
#include "Window.h"


namespace Ruby
{
	Application::Application()
	{
		WindowProps _Props;
		_Props.Width = 1280;
		_Props.Height = 720;
		_Props.Title = "RUBY";

		Window = std::unique_ptr<Ruby::Window> (Ruby::Window::Create(_Props));
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		while (true)
		{
			Window.get()->Update();
		}
	}
}