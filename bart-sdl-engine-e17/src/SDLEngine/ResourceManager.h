#pragma once

#include <iostream>
#include <map>

#include "SDL.h"
#include "SDL_image.h"

class ResourceManager
{
public:
	ResourceManager();
	~ResourceManager();

	SDL_Texture* LoadTexture(SDL_Renderer* renderer, const char* path);

private:
	std::map<const char*, SDL_Texture*> resources;
};

