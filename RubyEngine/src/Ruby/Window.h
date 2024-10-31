#pragma once
#include "RubyPCH.h"
#include "Event.h"
#include "core.h"

namespace Ruby
{
	struct WindowProps
	{
		int Width;
		int Height;
		std::string Title;

		bool bVSync;
	};

	class RUBY_API Window
	{
	public:
		virtual void Update() = 0;
		virtual ~Window() {};

		virtual void SetVSync(bool _Enable) = 0;
		virtual bool IsVSync() = 0;
		virtual void SetEventCallBack(std::function<void(Event&)>) = 0;

		static Window* Create(WindowProps& _Props);

	protected:

		//WindowProps Props;
		static inline bool bGraphicsInitialized = false;
	};

}