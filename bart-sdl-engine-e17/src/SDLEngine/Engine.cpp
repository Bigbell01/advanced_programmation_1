#include "Engine.h"

Engine* Engine::instance = nullptr;

Engine::Engine()
	: quit(false)
	, window(nullptr)
	, renderer(nullptr)
	, isInitialized(false)
	, red(0x00)
	, green(0x00)
	, blue(0x00)
{

}

Engine::~Engine()
{
	//delete renderer;
}

bool Engine::Init(std::string title, int width, int height)
{
	bool success = true;

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		window = SDL_CreateWindow(title.c_str(),
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			width, height, SDL_WINDOW_SHOWN);

		if (window == nullptr)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//pScreen = SDL_GetWindowSurface(pWindow);
			renderer = SDL_CreateRenderer(window, -1, 0);

			if (TTF_Init())
			{
				printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
				success = false;
			}

			//Initialize SDL_mixer
			if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
			{
				printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
				success = false;
			}
		}
	}

	return success;
}

void Engine::Start()
{
	timer.Reset();
	timer.Start();

	for (auto c : components)
	{
		c->Start();
	}
}

void Engine::Update()
{
	timer.Tick();

	for (auto c : components)
	{
		c->Update();
	}
}

void Engine::Draw()
{
	SDL_RenderClear(renderer);

	// As been replace by RenderClear
	// SDL_FillRect(pScreen, nullptr,
	//	 SDL_MapRGB(pScreen->format, Red, Green, Blue));

	for (auto c : components)
	{
		c->Draw();
	}

	SDL_RenderPresent(renderer);
	//SDL_UpdateWindowSurface(pWindow);
}

void Engine::Stop()
{
	timer.Stop();

	for (auto c : components)
	{
		c->Stop();
	}
}

int Engine::Run()
{
	Start();
	
	while (!quit)
	{
		while (SDL_PollEvent(&e) != 0)
		{
			input.Poll(e);

			if (e.type == SDL_QUIT || 
				input.IsKeyPressed(SDL_SCANCODE_ESCAPE))
			{
				quit = true;
			}
		}

		Update();
		Draw();
	}

	Stop();

	return 0;
}

void Engine::RegisterComponent(Component * const component)
{
	components.push_back(component);
	component->SetDepth((int)components.size() - 1);
}

void Engine::AddComponent(Component* const c)
{
	std::cout << "AddComponent is deprecated, no need to call AddComponent, all components now add themselves to the engine." << std::endl;
}


