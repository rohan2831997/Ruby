#pragma once
#include <RubyPCH.h>
#include "core.h"

// Currently all the events are blocking
// So a better startergy to keep them in a bus
// And then send them

namespace Ruby
{
	enum class EventType
	{
		None = 0,
		Tick, Render,
		WindowResize, WindowOpen, WindowClose,
		KeyboardButtonPress, KeyboardButtonRelease,
		MouseButtonPressed, MouseButtonReleased, MouseMove, MouseScroll
	};

	enum EventCategory
	{
		None = 0,
		EventApplication = BIT(0),
		EventInput = BIT(1),
		EventKeyboard = BIT(2),
		EventMouse = BIT(3),
	};

#define EVENT_CLASS_TYPE(Type)	static EventType GetStaticType() { return EventType::##Type; }\
	virtual EventType GetEventType() const override { return GetStaticType(); } \
		virtual const char* GetEventName() const override{ return #Type; } 

#define EVENT_CATEGORY_TYPE(Type) virtual int GetCategoryFlags() const override { return Type; }

	class RUBY_API Event
	{

	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetEventName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual bool ImplementsCategory(EventCategory Category)
		{
			return GetCategoryFlags() & Category;
		}
		virtual std::string ToString() const { return GetEventName(); };

	protected:
		bool bHandled;
	};

	class EventDispatcher
	{
		void Dispatch(Event& E)
		{
			
		}
	};


}
