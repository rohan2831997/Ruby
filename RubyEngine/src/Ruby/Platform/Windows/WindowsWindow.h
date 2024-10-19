#pragma once

#include "core.h"
#include "Window.h"
#include "GLFW/glfw3.h"

namespace Ruby
{
	class RUBY_API WindowsWindow : public Window
	{
		struct WindowsWindowProps
		{
			int Width;
			int Height;
			std::string Title;

			bool bVSync;
		};

	public:
		WindowsWindow(int&& _Width, int&& _Height, std::string&& _Title, bool&& _VSync);
		WindowsWindow(int& _Width, int& _Height, std::string& _Title, bool& _VSync);
		WindowsWindow(WindowProps& Props);
		~WindowsWindow() override;

		void Update() override;
		
		void SetVSync(bool _Enable) override;
		bool IsVSync();

	private:
		//std::unique_ptr<GLFWwindow, DestroyglfwWin> gl_Window;
		GLFWwindow* gl_Window;
		WindowsWindowProps Props;
	};

}
	