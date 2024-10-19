

#include "RubyPCH.h"
#include "Window.h"
#include "Logger/Log.h"
#include "Platform/Windows/WindowsWindow.h"

namespace Ruby
{
Window* Window::Create(WindowProps & _Props)
{
	return new WindowsWindow(1920,1080,"RUBY",true);
}
}
