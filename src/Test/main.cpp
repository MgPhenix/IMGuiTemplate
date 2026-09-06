#include <iostream>
#include "main.h"
#include "imgui.h"
#include "imgui_impl_sdl3.h"
#include "imgui_impl_sdlrenderer3.h"
#include "SDL3/SDL.h"

#include "Initialize.h"


struct Player
{
	float x = 100.0f;
	float y = 100.0f;
	float speed = 5.0f;
	int health = 100;
	bool enabled = true;
};



int main()
{
	//INIT
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;

	if (!InitSDL3("Test",800,800,&window,&renderer))
	{
		return 0;
	}

	ImGuiIO& io = InitImGui(window, renderer);


	//LOOP 

	bool enabled = false;
	int machin = 100;
	float speed = 5.0f;
	float rotation = 0.0f;
	float volume = 0.4f;

	Player player;

	bool run = true;
	while (run)
	{
		//Event
		SDL_Event event;

		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_EVENT_QUIT)
				run = false;

			ImGui_ImplSDL3_ProcessEvent(&event); //ImGUI read SDL event
		}


		//Frame
		ImGui::SDL3_NewFrame();


		// DO shitty thing
		ImGui::Begin("Hello ImGui");
		ImGui::Text("Hello World!");

		if (ImGui::Button("Click me"))
		{
			std::cout << "Button clicked!\n";
		}


		ImGui::Checkbox("Enabled", &enabled);
		ImGui::SameLine();
		ImGui::InputInt("Input", &machin);
		ImGui::SliderFloat("Speed", &speed, 0.0f, 20.0f);

		ImGui::DragFloat("Rotation", &rotation, 0.1f);

		ImGui::SliderFloat("Volume", &volume, 0.0f, 1.0f);


		ImGui::End();


		ImGui::Begin("Player");

		ImGui::Text("Position");
		ImGui::Separator();
		ImGui::DragFloat("Pos X", &player.x, 0.1f);
		ImGui::DragFloat("Pos Y", &player.y, 0.1f);

		ImGui::Text("Gameplay");
		ImGui::Separator();
		ImGui::SliderFloat("Speed", &player.speed, 0.0f, 20.0f);
		ImGui::InputInt("Input", &player.health);

		ImGui::NewLine();
		ImGui::Checkbox("Enabled", &player.enabled);



		ImGui::BeginChild("Zone", ImVec2(300, 100), ImGuiChildFlags_Borders);
		ImGui::Text("Je suis dans le Child !");
		ImGui::Button("Button");

		ImGui::EndChild();

		ImGui::Text("Apres");


		if (ImGui::BeginTable("Stats", 3, ImGuiTableFlags_Borders))
		{
			ImGui::TableNextRow();

			ImGui::TableNextColumn();
			ImGui::Text("Name");

			ImGui::TableNextColumn();
			ImGui::Text("Health");

			ImGui::TableNextColumn();
			ImGui::Text("Speed");

			ImGui::EndTable();
		}

		ImGui::End();


		//Render SDL
		SDL_SetRenderDrawColor(renderer, 30, 30, 30, 255);
		SDL_RenderClear(renderer);


		//Render ImGui
		ImGui::SDL3_ImGuiRender(renderer);
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	return 0;
}