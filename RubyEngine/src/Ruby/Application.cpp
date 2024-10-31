#pragma once
#include "RubyPCH.h"
#include "Application.h"
#include "Window.h"
#include "Logger/Log.h"


namespace Ruby
{
#define BIND_FUN(Name) std::bind(&Application::##Name, this, std::placeholders::_1)

	Application::Application()
	{
		WindowProps _Props;
		_Props.Width = 1280;
		_Props.Height = 720;
		_Props.Title = "RUBY";

		Window = std::unique_ptr<Ruby::Window> (Ruby::Window::Create(_Props));
		Window->SetEventCallBack(BIND_FUN(OnRecieveEvent));

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
	void Application::OnRecieveEvent(Event& _E)
	{
		RUBY_LOG_TRACE("{0}", _E.ToString());

	}
}