#include "Config.h"

#ifdef PLATFORM_SDL

struct ImGui_ImplSDLGPU3_InitInfo;

namespace Platform
{
#ifdef SDL3
	static bool gpu_enabled = false;
#endif // SDL3

	bool Init(const char* windowName, int windW, int windH, SDL_Window** window, SDL_Renderer** renderer, SDL_WindowFlags flags = NULL);

	void Quit(SDL_Window* window, SDL_Renderer* renderer);

	void NewFrame();

	void ImplementRenderer(SDL_Window* window, SDL_Renderer* renderer);

#ifdef SDL3
	void ImplementRenderer(SDL_Window* window, ImGui_ImplSDLGPU3_InitInfo* gpuInfo); //Yeah i know the name is not correct but i don't care for now
#endif // SDL3

	void Render(SDL_Renderer* renderer);

#ifdef SDL3
	void Render(SDL_GPUDevice* device);
#endif // SDL3

	void ProcessEvent(SDL_Event* event);
}


#endif // PLATFORM_SDL