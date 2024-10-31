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

		void OnRecieveEvent(Event& E);

	};

	//TO BE DEFINED ON CLIENT SIDE
	Application* CreateApplication();
	

}


