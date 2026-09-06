#include "Initialize.h"
#include <iostream>
#include "SDL3/SDL.h"
#include "imgui_impl_sdl3.h"
#include "imgui_impl_sdlrenderer3.h"

bool InitSDL3(const char* windowName, int windW, int windH, SDL_Window** window, SDL_Renderer** renderer)
{
	if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_AUDIO))
	{
		std::cout << "SDL_Init_Error :  " << SDL_GetError() << std::endl;
		return false;
	}

	SDL_CreateWindowAndRenderer("Test", 800, 800, SDL_WINDOW_RESIZABLE, window, renderer);

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

ImGuiIO& InitImGui(SDL_Window* window, SDL_Renderer* renderer)
{
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	ImGui_ImplSDL3_InitForSDLRenderer(window, renderer);
	ImGui_ImplSDLRenderer3_Init(renderer);

	return io;
}

void ImGui::SDL3_NewFrame()
{
	ImGui_ImplSDL3_NewFrame();
	ImGui_ImplSDLRenderer3_NewFrame();
	ImGui::NewFrame();
}

void ImGui::SDL3_ImGuiRender(SDL_Renderer* renderer)
{
	ImGui::Render();
	ImGui_ImplSDLRenderer3_RenderDrawData(
		ImGui::GetDrawData(),
		renderer
	);

	SDL_RenderPresent(renderer);
}
