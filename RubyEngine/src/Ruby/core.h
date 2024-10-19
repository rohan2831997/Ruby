#pragma once

#ifdef R_WINDOWS_PLATFORM
	#ifdef R_BUILD_DLL
		#define RUBY_API __declspec(dllexport)
	#else
		#define RUBY_API __declspec(dllimport)
	#endif // R_BUILD_DLL
#else
   #error RUBY Only Supports Windows!
#endif // R_WINDOWS_PLATFORM

#define BIT(x) 1<<x

#ifdef R_ENABLE_ASSERTS
	#define R_ASSERT(x,...) {if(!(x)) {RUBY_LOG_ERROR("Condition Failed :{0} ",__VA_ARGS__); __debugbreak();}}
	#define A_ASSERT(x,...) {if(!(x)) {APP_LOG_ERROR("Condition Failed :{0} ",__VA_ARGS__); __debugbreak();}}
#else
	#define R_ASSERT(x,...) 
	#define A_ASSERT(x,...) 
#endif
	
