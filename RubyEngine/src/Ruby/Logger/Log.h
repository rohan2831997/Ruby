#pragma once
#include <RubyPCH.h>

#include "core.h"
#include "Event.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"


namespace Ruby
{
	class RUBY_API Log
	{
	public:
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return CoreLogger; };
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return ClientLogger; };

		static void Init();

	private:
		static std::shared_ptr<spdlog::logger> CoreLogger;
		static std::shared_ptr<spdlog::logger> ClientLogger;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& E)
	{
		return os << E.ToString();
	}
}

#define RUBY_LOG_TRACE(...)		Ruby::Log::GetCoreLogger()->trace(__VA_ARGS__);
#define RUBY_LOG_INFO(...)		Ruby::Log::GetCoreLogger()->info(__VA_ARGS__);
#define RUBY_LOG_WARN(...)		Ruby::Log::GetCoreLogger()->warn(__VA_ARGS__);
#define RUBY_LOG_ERROR(...)		Ruby::Log::GetCoreLogger()->error(__VA_ARGS__);
#define RUBY_LOG_FATAL(...)		Ruby::Log::GetCoreLogger()->fatal(__VA_ARGS__);

#define APP_LOG_TRACE(...)		Ruby::Log::GetClientLogger()->trace(__VA_ARGS__);
#define APP_LOG_INFO(...)		Ruby::Log::GetClientLogger()->info(__VA_ARGS__);
#define APP_LOG_WARN(...)		Ruby::Log::GetClientLogger()->warn(__VA_ARGS__);
#define APP_LOG_ERROR(...)		Ruby::Log::GetClientLogger()->error(__VA_ARGS__);
#define APP_LOG_FATAL(...)		Ruby::Log::GetClientLogger()->fatal(__VA_ARGS__);

