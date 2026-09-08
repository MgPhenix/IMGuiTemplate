#include "SDL3.h"
#include <iostream>


#ifdef PLATFORM_SDL3



#include "imgui_impl_sdl3.h"
#include "imgui_impl_sdlrenderer3.h"



bool Platform::Init(const char* windowName, int windW, int windH, SDL_Window** window, SDL_Renderer** renderer, SDL_WindowFlags flags)
{
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
}

void Platform::Quit(SDL_Window* window, SDL_Renderer* renderer)
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}


void Platform::NewFrame()
{
	ImGui_ImplSDL3_NewFrame();
	ImGui_ImplSDLRenderer3_NewFrame();
}


void Platform::ImplementRenderer(SDL_Window* window, SDL_Renderer* renderer)
{
	ImGui_ImplSDL3_InitForSDLRenderer(window, renderer);
	ImGui_ImplSDLRenderer3_Init(renderer);
}

void Platform::Render(SDL_Renderer* renderer)
{
	ImGui_ImplSDLRenderer3_RenderDrawData(
		ImGui::GetDrawData(),
		renderer
	);

	SDL_RenderPresent(renderer);
}

void Platform::ProcessEvent(SDL_Event* event)
{
	ImGui_ImplSDL3_ProcessEvent(event);
}

#endif

