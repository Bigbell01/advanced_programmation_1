#include "ResourceManager.h"

ResourceManager::ResourceManager()
{
}

ResourceManager::~ResourceManager()
{
	for (auto& mapElement : resources)
	{
		SDL_DestroyTexture(mapElement.second);
	}
	resources.erase(resources.begin(), resources.end());
	resources.clear();
}

SDL_Texture* ResourceManager::LoadTexture(SDL_Renderer* renderer, const char * path)
{
	//auto res = resources.find(path);
	//
	//if (res == resources.end())
	//{
	//	printf("Texture: %s loaded\n", path);
		SDL_Surface* image = IMG_Load(path);
		SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, image);
		
		resources.insert(
			std::pair<const char*, SDL_Texture*>(path, std::move(texture)));
	
		SDL_FreeSurface(image);
	
		return texture;
	//}
	//else
	//{
	//	printf("Texture: %s already loaded\n", path);
	//	return res->second;
	//}
}
