#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <SDL_ttf.h>

#include "SDL.h"
#include "SDL_mixer.h"

#include "Component.h"
#include "Input.h"
#include "Timer.h"
#include "ResourceManager.h"

#define gEngine Engine::GetInstance()
#define gResources gEngine->GetResourceManager()
#define gInput gEngine->GetInput()
#define gTimer gEngine->GetTimer()
#define gRenderer gEngine->GetRenderer()

class Engine
{
#pragma region SINGLETON
public:
	static Engine* GetInstance() 
	{
		if (instance == nullptr)
			instance = new Engine();
		return instance;
	}

	static void Kill()
	{
		delete instance;
		instance = nullptr;
	}

private:
	Engine();
	~Engine();

	static Engine* instance;
#pragma endregion
public:
	Timer* GetTimer() { return &timer; }
	Input* GetInput() { return &input; }
	SDL_Renderer* GetRenderer() { return renderer; }
	ResourceManager* GetResourceManager() {	return &resourceManager; }

	void SetColor(Uint8 Red, Uint8 Green, Uint8 Blue)
	{
		this->red = Red;
		this->blue = Blue;
		this->green = Green;

		SDL_SetRenderDrawColor(renderer, red, green, blue, 0);
	}

	void ResetDrawColor() { SetColor(red, green, blue); }

	void SetNativeResolution(float x, float y)
	{
		int w, h;
		SDL_GetWindowSize(window, &w, &h);
		SDL_RenderSetScale(renderer, ((float)w) / x, ((float)h) / y);
	}

	bool Init(std::string title, int width, int height);
	
	void Start();
	void Update();
	void Draw();
	void Stop();

	int Run();

	void RegisterComponent(Component* const component);
	void AddComponent(Component* const c);

private:
	SDL_Event e;
	Timer timer;
	Input input;
	ResourceManager resourceManager;

	SDL_Window* window;
	SDL_Renderer* renderer;
	Uint8 red, green, blue;

	bool quit;
	bool isInitialized;
	std::vector<Component*> components;
	
};
