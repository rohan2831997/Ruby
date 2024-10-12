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

	};

	class RUBY_API MouseButtonEvent: public MouseEvent
	{

	};

	class RUBY_API MouseScrollEvent : public MouseEvent
	{

	};

	

}