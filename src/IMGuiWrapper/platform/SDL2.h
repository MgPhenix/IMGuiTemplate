#include "Config.h"

#ifdef PLATFORM_SDL2

namespace Platform
{
	bool Init(const char* windowName, int windW, int windH, SDL_Window** window, SDL_Renderer** renderer, SDL_WindowFlags flags = NULL);

	void Quit(SDL_Window* window, SDL_Renderer* renderer);

	void NewFrame();

	void ImplementRenderer(SDL_Window* window, SDL_Renderer* renderer);

	void Render(SDL_Renderer* renderer);

	void ProcessEvent(SDL_Event* event);
}








#endif // PLATFORM_SDL2
