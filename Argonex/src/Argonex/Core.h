#pragma once

#ifdef ARGONEX_PLATFORM_WINDOWS
	#ifdef ARGONEX_BUILD_DLL
		#define ARGONEX_API __declspec(dllexport)
	#else
		#define ARGONEX_API __declspec(dllimport)
	#endif
#else
	#error ArgonexEngine only supports Windows!
#endif