## Introduction

This idea for this template is just to simplify the utilisation of ImGui because setup it it's not really """easy""" for beginners
For now it work only with SDL2 & 3 but i will add more supported backends if i'm not lazy

- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)


## Features

- Simplify ImGui utilisation (really slightly modifier version of ImGui is include)
- SDL2 & SDL3 Support
- SDL Renderer & SDL3 GPU support (GPU does not work yet)


## Installation 

Just use the github template system or fork it or just download it, do as you want
Require C++20 (but maybe i will add more version support later)

**Clone Command**
```bash
git clone https://github.com/MgPhenix/ImGuiTemplate
```
When you have the project go to bin folder and execute "make.bat" it will create the solution (i really need to change that and switch to cmake)
After that you can create your own project or use the "Test" project if you want


## Usage

```cpp
#include "SDL3/SDL.h" // The programm itself detect if you have SDL2 or 3 so the usage is the same for SDF2
#include "IMGuiManager.h"

void main()
{
	//Create window & renderer variable
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;

	ImGuiManager::InitWindow("Test", 800, 800, &window, &renderer, SDL_WINDOW_RESIZABLE); //Create your window)
	ImGuiIO& io = ImGuiManager::GetIO();


  //Loop
  bool run = true;
  while (run)
  {
  	//Event
  	SDL_Event event;
  	while (SDL_PollEvent(&event))
  	{
  		if (event.type == SDL_EVENT_QUIT)
  			run = false;
  
  		ImGuiManager::ProcessEvent(&event); //Process Event
  	}

    ImGuiManager::NewFrame(); //Create a new Frame

    //ImGUI Code 
    ImGui::Begin("Hello ImGui");
    ImGui::Text("Hello World!");
    ImGui::End();

    //Then render 
    //Render SDL
    SDL_SetRenderDrawColor(renderer, 30, 30, 30, 255);
    SDL_RenderClear(renderer);
    
    
    //Render ImGui
    ImGuiManager::Render(renderer);
  }

ImGuiManager::Quit(window, renderer); // quit ImGui, Window & Renderer are auto destroy

return 0;
}

```


## Contributing
Contributions are welcome of course if you have suggestions for improvements or wish to add new features, please follow these steps :

Fork the repository

Create a new branch:

bash```
git checkout -b feature/ImGuiTemplate```
Commit your changes with a descriptive message:

bash```
git commit -m "Add description of the new feature"```

Push to your branch:

bash```
git push origin feature/ImGuiTemplate```
Open a Pull Request with a clear explanation of your changes.


## License
This project is licensed under the MIT License

