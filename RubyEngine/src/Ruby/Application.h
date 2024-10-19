#pragma once

#include "core.h"
#include "Events/AppEvents.h"
#include "Window.h"

namespace Ruby
{


	class RUBY_API Application
	{
	public:
		Application();
		~Application();
	
		void Run();

	private:
		std::unique_ptr<Window> Window;

	};

	//TO BE DEFINED ON CLIENT SIDE
	Application* CreateApplication();
	

}


