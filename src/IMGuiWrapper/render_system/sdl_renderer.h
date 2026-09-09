#include "Config.h"

#ifdef PLATFORM_SDL

namespace RenderSystem
{
	void Init(SDL_Window* window, SDL_Renderer* renderer);

	void NewFrame();

	void Render(SDL_Renderer* renderer);
}


#endif // PLATFORM_SDL