#pragma once
#include "imgui.h"

struct SDL_Renderer;
struct SDL_Window;

bool InitSDL3(const char* windowName, int windW, int windH, SDL_Window** window, SDL_Renderer** renderer);

ImGuiIO& InitImGui(SDL_Window* window, SDL_Renderer* renderer);

namespace ImGui {
	
	void SDL3_NewFrame();

	void SDL3_ImGuiRender(SDL_Renderer* renderer);
}