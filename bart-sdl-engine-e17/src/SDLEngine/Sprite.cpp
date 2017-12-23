#include "Sprite.h"

Sprite::Sprite()
	: texture(nullptr)
	, isVisible(true)
	, angle(0.f)
{
	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = 0;
	srcRect.h = 0;
}

Sprite::Sprite(float x, float y)
	: Rectangle(x, y)
	, texture(nullptr)
	, isVisible(true)
{
	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = 0;
	srcRect.h = 0;
}

Sprite::Sprite(const char * path)
	: texture(nullptr)
	, isVisible(true)
{
	texture = gResources->LoadTexture(gRenderer, path);

	if (texture)
	{
		srcRect.x = 0;
		srcRect.y = 0;

		SDL_QueryTexture(texture, 0, 0, &srcRect.w, &srcRect.h);

		SetSize((float)srcRect.w, (float)srcRect.h);
	}
}

Sprite::Sprite(const char * path, float x, float y)
	: Rectangle(x, y, (float)srcRect.w, (float)srcRect.h)
	, texture(nullptr)
	, isVisible(true)
{
	texture = gResources->LoadTexture(gRenderer, path);

	if (texture)
	{
		srcRect.x = 0;
		srcRect.y = 0;

		SDL_QueryTexture(texture, 0, 0, &srcRect.w, &srcRect.h);

		SetSize((float)srcRect.w, (float)srcRect.h);
	}
}

Sprite::Sprite(const char* path, float x, float y, float w, float h)
	: Rectangle(x, y, w, h)
	, texture(nullptr)
	, isVisible(true)
{
	texture = gResources->LoadTexture(gRenderer, path);

	srcRect.x = 0;
	srcRect.y = 0;

	SDL_QueryTexture(texture, 0, 0, &srcRect.w, &srcRect.h);
}

Sprite::~Sprite()
{
}

void Sprite::SetTexture(const char * path)
{
	texture = gResources->LoadTexture(gRenderer, path);

	if (texture)
	{
		srcRect.x = 0;
		srcRect.y = 0;

		SDL_QueryTexture(texture, 0, 0, &srcRect.w, &srcRect.h);

		SetSize((float)srcRect.w, (float)srcRect.h);
	}
}

void Sprite::Draw()
{
	Rectangle::Draw();

	if (isVisible)
	{
		if (texture != nullptr)
		{
			destRect.x = int(x);
			destRect.y = int(y);
			destRect.w = int(width);
			destRect.h = int(height);

			// TODO: Rotation as parameter with Setter for sprite class
			// TODO: Setter for SDL_RenderFLip last parameter of SDL_RenderCopyEx
			SDL_RenderCopyEx(gRenderer, texture, &srcRect, &destRect, angle, nullptr, m_RenderFlipState);

			// As been replaced by SDL_RenderCopy, enabling rotation and flip.
			//SDL_BlitScaled(image, &srcRect, gEngine->GetScreen(), &destRect);
		}
	}
}
