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

