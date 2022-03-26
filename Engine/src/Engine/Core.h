#pragma once


#ifdef OX_PLATFORM_WINDOWS
	#ifdef OX_BUILD_DLL
		#define OX_API __declspec(dllexport)
	#else
		#define OX_API __declspec(dllimport)
	#endif
#else
	#error ToyEngine Only Supports Window!
#endif