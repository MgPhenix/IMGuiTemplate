#include "Config.h"
#include "imgui.h"

//struct SDL_Renderer;
//struct SDL_Window;
struct ImGui_ImplSDLGPU3_InitInfo;

namespace ImGuiManager
{
	bool InitWindow(const char* windowName, int windW, int windH, SDL_Window** window, SDL_Renderer** renderer, SDL_WindowFlags flags = NULL);
	bool InitWindow(const char* windowName, int windW, int windH, SDL_Window** window, ImGui_ImplSDLGPU3_InitInfo* gpuInfo, SDL_WindowFlags flags = NULL);

	//void InitImGuiOnly();

	ImGuiIO& GetIO();

	void NewFrame();

	void Render(SDL_Renderer* renderer);

	void Quit(SDL_Window* window, SDL_Renderer* renderer);

	void ProcessEvent(SDL_Event* event);
};