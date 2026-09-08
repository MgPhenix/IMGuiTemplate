#pragma once

#if __has_include(<SDL3/SDL.h>)
	#include "SDL3/SDL.h"
	#define PLATFORM_SDL3
#elif __has_include(<SDL.h>)
	#include "SDL2/SDL.h"
	#define PLATFORM_SDL3
#else
	#error "SDL2 or SDL3 not found"
#endif