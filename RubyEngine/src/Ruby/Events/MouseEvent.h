#pragma once

#include "core.h"
#include "Event.h"
namespace Ruby
{

	class RUBY_API MouseEvent : public Event
	{


	};

	class RUBY_API MouseMovedEvent : public MouseEvent
	{
		EVENT_CLASS_TYPE(MouseMove)
		EVENT_CATEGORY_TYPE(EventMouse | EventApplication)
		
	public:
		MouseMovedEvent(int& _xPos, int& _yPos) : xPos(_xPos), yPos(_yPos) {};
		MouseMovedEvent(int _xPos, int _yPos) : xPos(_xPos), yPos(_yPos) {};

		std::string ToString() const override;

	private:
		int xPos, yPos;
	};

	class RUBY_API MouseButtonEvent: public MouseEvent
	{

	};

	class RUBY_API MouseScrollEvent : public MouseEvent
	{

	};

	

}