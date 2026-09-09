#include "sdl3_gpu.h"

#ifdef SDL3


#include "imgui_impl_sdl3.h"
#include "imgui_impl_sdlgpu3.h"


void RenderSystem::Init(SDL_Window* window, ImGui_ImplSDLGPU3_InitInfo* gpuInfo)
{
	ImGui_ImplSDLGPU3_Init(gpuInfo);
	ImGui_ImplSDL3_InitForSDLGPU(window);
}

void RenderSystem::NewGPUFrame()
{
	ImGui_ImplSDLGPU3_NewFrame();
	ImGui_ImplSDL3_NewFrame();
}

void RenderSystem::Render(SDL_GPUDevice* device)
{
	//IDK How sdl gpu work so i will do that later
}


#endif // SDL3