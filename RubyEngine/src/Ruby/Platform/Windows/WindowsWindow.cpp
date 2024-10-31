#pragma once
#include "RubyPCH.h"
#include "WindowsWindow.h"
#include "Events/MouseEvent.h"
#include "Logger/Log.h"



Ruby::WindowsWindow::WindowsWindow(int&& _Width, int&& _Height, std::string&& _Title, bool&& _VSync)
{
	if (!bGraphicsInitialized)
	{
		bool Success = glfwInit();
		R_ASSERT(Success, "GLFW NOT INITIALIZED");
		RUBY_LOG_TRACE("RUBY : GLFW init Success")
		bGraphicsInitialized = true;
	}

	Props.Width = _Width;
	Props.Height = _Height;
	Props.Title = _Title;
	Props.bVSync = _VSync;

	gl_Window = glfwCreateWindow(_Width, _Height, _Title.c_str(), nullptr, nullptr);
	glfwMakeContextCurrent(gl_Window);
	glfwSetWindowUserPointer(gl_Window, &Props);
	SetVSync(_VSync);

	glfwSetCursorPosCallback(gl_Window, [](GLFWwindow* _window, double _xPos, double _yPos)
		{
			WindowsWindowProps* WinProps = (WindowsWindowProps*)glfwGetWindowUserPointer(_window);
			MouseMovedEvent E((int)_xPos, (int)_yPos);

			WinProps->CallBackFunc(E);
		});
}

Ruby::WindowsWindow::WindowsWindow(int& _Width, int& _Height, std::string& _Title, bool& _VSync)
{
	if (!bGraphicsInitialized)
	{
		bool Success = glfwInit();
		R_ASSERT(Success, "GLFW NOT INITIALIZED");
		RUBY_LOG_TRACE("RUBY : GLFW init Success")
		bGraphicsInitialized = true;
	}

	Props.Width = _Width;
	Props.Height = _Height;
	Props.Title = _Title;
	Props.bVSync = _VSync;

	gl_Window = glfwCreateWindow(_Width, _Height, _Title.c_str(), nullptr, nullptr);
	glfwMakeContextCurrent(gl_Window);
	glfwSetWindowUserPointer(gl_Window, &Props);
	SetVSync(_VSync);
}

Ruby::WindowsWindow::WindowsWindow(WindowProps& Props)
{
	Ruby::WindowsWindow::WindowsWindow(Props.Width, Props.Height, Props.Title, Props.bVSync);
}

Ruby::WindowsWindow::~WindowsWindow()
{
	//glfwDestroyWindow(gl_Window.get());
	glfwDestroyWindow(gl_Window);
}

void Ruby::WindowsWindow::Update()
{
	glfwPollEvents();
	//glfwSwapBuffers(gl_Window.get());
	glfwSwapBuffers(gl_Window);
}

void Ruby::WindowsWindow::SetEventCallBack(std::function<void(Event& E)> CallBackFun)
{
	Props.CallBackFunc = CallBackFun;
}

void Ruby::WindowsWindow::SetVSync(bool _Enable)
{

	if (_Enable)
		glfwSwapInterval(1);
	else
		glfwSwapInterval(0);

	Props.bVSync = _Enable;
}

bool Ruby::WindowsWindow::IsVSync()
{
	return false;
}
