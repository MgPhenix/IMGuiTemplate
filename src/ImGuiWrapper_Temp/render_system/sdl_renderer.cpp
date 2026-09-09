#include "sdl_renderer.h"

#ifdef PLATFORM_SDL


#ifdef SDL3
#include "imgui_impl_sdl3.h"
#include "imgui_impl_sdlrenderer3.h"
#endif


#ifdef SDL2
#include "imgui_impl_sdl2.h"
#include "imgui_impl_sdlrenderer2.h"
#include "sdl3_gpu.h"
#endif 


void RenderSystem::Init(SDL_Window* window, SDL_Renderer* renderer)
{
#ifdef SDL3
	ImGui_ImplSDL3_InitForSDLRenderer(window, renderer);
	ImGui_ImplSDLRenderer3_Init(renderer);
#endif // SDL3


#ifdef SDL2
	ImGui_ImplSDL2_InitForSDLRenderer(window, renderer);
	ImGui_ImplSDLRenderer2_Init(renderer);
#endif // SDL2
}

void RenderSystem::NewFrame()
{
#ifdef SDL3
	ImGui_ImplSDL3_NewFrame();
	ImGui_ImplSDLRenderer3_NewFrame();
#endif // SDL3


#ifdef SDL2
	ImGui_ImplSDL2_NewFrame();
	ImGui_ImplSDLRenderer2_NewFrame();
#endif // SDL2
}


void RenderSystem::Render(SDL_Renderer* renderer)
{
#ifdef SDL3
	ImGui_ImplSDLRenderer3_RenderDrawData(
		ImGui::GetDrawData(),
		renderer
	);
#endif // SDL3


#ifdef SDL2
	ImGui_ImplSDLRenderer2_RenderDrawData(
		ImGui::GetDrawData(),
		renderer
	);
#endif // SDL2
}


#endif