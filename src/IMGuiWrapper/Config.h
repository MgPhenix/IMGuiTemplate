#pragma once

#if __has_include(<SDL3/SDL.h>)
	#include "SDL3/SDL.h"
	#define SDL3
	#define PLATFORM_SDL
#elif __has_include(<SDL.h>)
	#include "SDL.h"
	#define PLATFORM_SDL
	#define SDL2
#else
	#error "SDL2 or SDL3 not found"
#endif