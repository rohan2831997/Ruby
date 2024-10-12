#pragma once

#include "core.h"
#include <functional>
#include <string>
#include <sstream>

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
		EventMouse = BIT(3)
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
		friend class Event;
		template<typename T>
		using Eventfn = std::function<bool>(T&);

	public:

		template<typename T>
		bool Dispatch(Eventfn<T>& fun)
		{
			T* Temp = dynamic_cast<T*>(&_Event);
			if (T == nullptr)
			{
				RUBY_LOG_WARN("Event is of the wrong class type, Dynamic Cast failed");
				return false;
			}

			eEvent.bHandled = fun(*T);
			return eEvent.bHandled;
		};

	protected:
		Event& _Event;
	};





	inline std::ostream& operator<<(std::stringstream& ss, const Event& E)
	{
		return ss << E.ToString();
	}
}
