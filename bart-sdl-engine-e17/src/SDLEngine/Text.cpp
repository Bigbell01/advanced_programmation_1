#include "Text.h"

Text::Text(const char* text, float x, float y)
	: Sprite(x, y)
	, font(nullptr)
{
	font = TTF_OpenFont("PressStart2P.ttf", 12);
	currentColor = { 255, 255, 255 };

	//CreateCollider(ColliderType::SQUARE_COLLIDER, dstRect->w, dstRect->h, 0.0f);

	SetText(text);
}

Text::~Text()
{
}

void Text::SetText(const char* text)
{
	SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, text, currentColor);



	SetTexture(SDL_CreateTextureFromSurface(gRenderer, surfaceMessage));
}

void Text::SetText(const char * text, const ColorFont FontCode)
{
	SetText(text, ColorCodes[FontCode]);
}

// Méthode qui change le texte et la couleur de la police de caractères selon le code passé en paramètre.
void Text::SetText(const char* text, const SDL_Color textColor)
{
	currentColor = textColor;
	SetText(text);
}