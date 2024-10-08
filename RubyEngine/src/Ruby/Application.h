#pragma once

#include "core.h"

namespace Ruby
{


	class RUBY_API Application
	{
	public:
		Application();
		~Application();
	
		void Run();

	};

	//TO BE DEFINED ON CLIENT SIDE
	Application* CreateApplication();

}


