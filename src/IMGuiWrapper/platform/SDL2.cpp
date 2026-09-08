#include "platform/SDL2.h"

#ifdef PLATFORM_SDL2



#include "imgui_impl_sdl2.h"
#include "imgui_impl_sdlrenderer2.h"



bool Platform::Init(const char* windowName, int windW, int windH, SDL_Window** window, SDL_Renderer** renderer, SDL_WindowFlags flags = NULL)
{
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
	ImGui_ImplSDL2_NewFrame();
	ImGui_ImplSDLRenderer2_NewFrame();
}

void Platform::ImplementRenderer(SDL_Window* window, SDL_Renderer* renderer)
{
	ImGui_ImplSDL2_InitForSDLRenderer(window, renderer);
	ImGui_ImplSDLRenderer2_Init(renderer);
}

void Platform::Render(SDL_Renderer* renderer)
{
	ImGui_ImplSDLRenderer2_RenderDrawData(
		ImGui::GetDrawData(),
		renderer
	);

	SDL_RenderPresent(renderer);
}

void Platform::ProcessEvent(SDL_Event* event)
{
	ImGui_ImplSDL2_ProcessEvent(event);
}

#endif