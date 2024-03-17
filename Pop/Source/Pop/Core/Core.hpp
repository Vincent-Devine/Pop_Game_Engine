#pragma once

#ifdef POP_PLATFORM_WINDOWS
	#ifdef POP_BUILD_DLL
		#define POP_API __declspec(dllexport)
	#else
		#define POP_API __declspec(dllimport)
	#endif
#else
	#error Pop Game Engine only supports Windows!
#endif

#define BIT(x) (1 << x)