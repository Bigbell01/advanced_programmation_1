#pragma once

#include "Sprite.h"
#include "SDL_ttf.h"

class Text
	: public Sprite
{
public:
	enum ColorFont { CLR_WHITE, CLR_BLACK, CLR_RED, CLR_GREEN, CLR_BLUE, CLR_YELLOW, CLR_COUNT };

	Text::Text() : Text("") {}
	Text(const char* text) : Text(text, 0, 0) {}
	Text(const char* text, float x, float y);
	~Text();

	void SetText(const char* text);
	void SetText(const char* text, const ColorFont FontCode);
	void SetText(const char* text, const SDL_Color colorCode);

private:
	TTF_Font* font;
	SDL_Color currentColor;

	const SDL_Color ColorCodes[CLR_COUNT] =
	{ { 255, 255, 255 },
	{ 0, 0, 0 },
	{ 255, 0, 0 },
	{ 0, 255, 0 },
	{ 0, 0, 255 },
	{ 255, 255, 0 }
	};

};
