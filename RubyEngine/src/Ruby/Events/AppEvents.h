#pragma once

#include<sstream>

#include "core.h"
#include "Event.h"

namespace Ruby
{

	class RUBY_API WindowResizeEvent : public Event
	{
	public:
		EVENT_CATEGORY_TYPE(EventApplication)
		EVENT_CLASS_TYPE(WindowResize)
		
		std::string ToString() const override
		{
			std::stringstream os;

			os << "WindowResizeEvent, Width : " << Width << " Height : " << Height;
			return os.str();
		}

		WindowResizeEvent(int _Width, int _Height) : Width(_Width), Height(_Height) {};


	private:
		int Width;
		int Height;

	};

	

	

}