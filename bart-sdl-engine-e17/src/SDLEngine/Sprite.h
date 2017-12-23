#pragma once

#include "Engine.h"
#include "Rectangle.h"

class Sprite :
	public Rectangle
{
public:
	Sprite();
	Sprite(float x, float y);
	Sprite(const char* path);
	Sprite(const char* path, float x, float y);
	Sprite(const char* path, float x, float y, float w, float h);

	~Sprite();

	float GetWidth() const { return width; }
	float GetHeight() const { return height; }
	bool GetVisible() const { return isVisible; }
	float GetAngle() const { return angle; }

	void SetTexture(const char* path);
	void SetTexture(SDL_Texture* tex) 
	{
		texture = tex;
		SDL_QueryTexture(texture, nullptr, nullptr, &destRect.w, &destRect.h);

		srcRect.w = destRect.w;
		srcRect.h = destRect.h;
		SetDrawSize(destRect.w, destRect.h);
	}

	SDL_RendererFlip GetSpriteState() { return m_RenderFlipState; }
	void SetSpriteState(SDL_RendererFlip p_RenderFlipState) { m_RenderFlipState = p_RenderFlipState; }
	void SetRotation(float angle) { this->angle = angle; }
	void SetVisible(bool tf) { isVisible = tf; }
	void SetSourceRect(int x, int y, int w, int h)
	{
		srcRect.x = x;
		srcRect.y = y;
		srcRect.w = w;
		srcRect.h = h;
	}
	void SetDrawSize(int w, int h)
	{
		if (texture)
		{
			width = (float)w;
			height = (float)h;
		}
	}

	virtual void Update() {}
	void Draw();

private:
	float angle;
	bool isVisible;
	SDL_Rect srcRect;
	SDL_Rect destRect;
	SDL_Texture* texture;
	SDL_RendererFlip m_RenderFlipState;
	
	//Sprite* debug;
};

