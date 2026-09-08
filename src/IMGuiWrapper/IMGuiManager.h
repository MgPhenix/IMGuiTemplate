#include "Config.h"
#include "imgui.h"

struct SDL_Renderer;
struct SDL_Window;

namespace ImGuiManager
{
	bool InitWindow(const char* windowName, int windW, int windH, SDL_Window** window, SDL_Renderer** renderer, SDL_WindowFlags flags = NULL);

	//void InitImGuiOnly();

	ImGuiIO& GetIO();

	void NewFrame();

	void Render(SDL_Renderer* renderer);

	void Quit(SDL_Window* window, SDL_Renderer* renderer);

	void ProcessEvent(SDL_Event* event);
};