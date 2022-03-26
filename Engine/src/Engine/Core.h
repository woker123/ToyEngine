#pragma once

#ifdef TOY_PLATFORM_WINDOWS
	#ifdef TOY_BUILD_DLL
		#define TOY_API __declspec(dllexport)
	#else
		#define TOY_API __declspec(dllimport)
	#endif
#else
	#error ToyEngine Only Supports Window!
#endif
