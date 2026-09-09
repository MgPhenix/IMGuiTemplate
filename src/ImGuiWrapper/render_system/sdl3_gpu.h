#include "Config.h"

#ifdef SDL3

struct ImGui_ImplSDLGPU3_InitInfo;
struct SDL_Window;

namespace RenderSystem
{
	void Init(SDL_Window* window, ImGui_ImplSDLGPU3_InitInfo* gpuInfo);

	void NewGPUFrame();

	void Render(SDL_GPUDevice* device);
}

#endif // SDL3