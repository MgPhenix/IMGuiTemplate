#include "SDL_Platform.h"
#include <iostream>


#ifdef PLATFORM_SDL

#include "render_system/sdl_renderer.h"

#ifdef SDL3
#include "imgui_impl_sdl3.h"
#include "render_system/sdl3_gpu.h"
#endif


#ifdef SDL2
#include "imgui_impl_sdl2.h"
#endif 





bool Platform::Init(const char* windowName, int windW, int windH, SDL_Window** window, SDL_Renderer** renderer, SDL_WindowFlags flags)
{
#ifdef SDL3


	if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_AUDIO))
	{
		std::cout << "SDL_Init_Error :  " << SDL_GetError() << std::endl;
		return false;
	}

	SDL_CreateWindowAndRenderer(windowName, 800, 800, flags, window, renderer);

	if (!window)
	{
		std::cout << "SDL_CreateWindow_Error : " << SDL_GetError() << std::endl;
		SDL_Quit();
		return false;
	}

	if (!renderer)
	{
		std::cout << "Renderer_error : " << SDL_GetError() << std::endl;
		SDL_DestroyWindow(*window);
		SDL_Quit();
		return false;
	}


	return true;

#endif // SDL3


#ifdef SDL2

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0)
	{
		std::cout << "SDL_Init_Error :  " << SDL_GetError() << std::endl;
		return false;
	}

	SDL_CreateWindowAndRenderer(800, 800, flags, window, renderer);

	if (!window)
	{
		std::cout << "SDL_CreateWindow_Error : " << SDL_GetError() << std::endl;
		SDL_Quit();
		return false;
	}

	if (!renderer)
	{
		std::cout << "Renderer_error : " << SDL_GetError() << std::endl;
		SDL_DestroyWindow(*window);
		SDL_Quit();
		return false;
	}

	SDL_SetWindowTitle(*window, windowName);

	return true;

#endif // SDL2
}


void Platform::Quit(SDL_Window* window, SDL_Renderer* renderer)
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}


void Platform::NewFrame()
{
	RenderSystem::NewFrame();
}


void Platform::ImplementRenderer(SDL_Window* window, SDL_Renderer* renderer)
{
	RenderSystem::Init(window, renderer);
}


void Platform::Render(SDL_Renderer* renderer)
{
	RenderSystem::Render(renderer);
	SDL_RenderPresent(renderer);
}


void Platform::ProcessEvent(SDL_Event* event)
{
#ifdef SDL3
	ImGui_ImplSDL3_ProcessEvent(event);
#endif // SDL3


#ifdef SDL2
	ImGui_ImplSDL2_ProcessEvent(event);
#endif // SDL2
}




#endif // PLATFORM_SDL