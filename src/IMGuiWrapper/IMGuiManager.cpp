#include "IMGuiManager.h"

#ifdef PLATFORM_SDL
#include "platform/SDL_Platform.h"
#endif // PLATFORM_SDL3

bool ImGuiManager::InitWindow(const char* windowName, int windW, int windH, SDL_Window** window, SDL_Renderer** renderer, SDL_WindowFlags flags)
{
	if (!Platform::Init(windowName, windW, windH, window, renderer, flags))
	{
		Platform::Quit(*window, *renderer);
		return false;
	}

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	
	Platform::ImplementRenderer(*window, *renderer);

	return true;
}

ImGuiIO& ImGuiManager::GetIO()
{
	return ImGui::GetIO();
}

void ImGuiManager::NewFrame()
{
	Platform::NewFrame();
	ImGui::NewFrame();
}

void ImGuiManager::Render(SDL_Renderer* renderer)
{
	ImGui::Render();
	Platform::Render(renderer);
}

void ImGuiManager::Quit(SDL_Window* window, SDL_Renderer* renderer)
{
	Platform::Quit(window, renderer);
}

void ImGuiManager::ProcessEvent(SDL_Event* event)
{
	Platform::ProcessEvent(event);
}
