#include "Rectangle.h"

bool Rectangle::debugMode = true;

Rectangle::Rectangle()
	: x(0), y(0), width(0), height(0)
{
	
}

Rectangle::Rectangle(float x, float y)
	:x(x), y(y), width(0), height(0)
{

}

Rectangle::Rectangle(float x, float y, float width, float height)
	:x(x), y(y), width(abs(width)), height(abs(height))
{

}

Rectangle::Rectangle(const Vector2D* const topLeft, const Vector2D* const btmRight)
{
	if (btmRight->x < topLeft->x && btmRight->y > topLeft->y)
	{
		this->x = btmRight->x;
		this->y = btmRight->y;
		this->width = abs(btmRight->x - topLeft->x);
		this->height = abs(btmRight->y - topLeft->y);
	}
	else if (btmRight->x < topLeft->x && btmRight->y < topLeft->y)
	{
		this->x = btmRight->x;
		this->y = topLeft->y;
		this->width = abs(topLeft->x - btmRight->x);
		this->height = abs(topLeft->y - btmRight->y);
	}
	else if (btmRight->x > topLeft->x && btmRight->y > topLeft->y)
	{
		this->x = topLeft->x;
		this->y = btmRight->y;
		this->width = abs(btmRight->x - topLeft->x);
		this->height = abs(btmRight->y - topLeft->y);
	}
	else if (btmRight->x > topLeft->x && btmRight->y < topLeft->y)
	{
		this->x = topLeft->x;
		this->y = topLeft->y;
		this->width = abs(topLeft->x - btmRight->x);
		this->height = abs(topLeft->y - btmRight->y);
	}
}

void Rectangle::Update()
{

}

void Rectangle::Draw()
{
	if (debugMode)
	{
		SDL_Point points[] =
		{
			{ int(x), int(y) },
			{ int(x + width), int(y) },
			{ int(x + width), int(y + height) },
			{ int(x),  int(y + height) },
			{ int(x), int(y) }
		};

		SDL_SetRenderDrawColor(gRenderer, 0, 255, 0, SDL_ALPHA_OPAQUE);
		SDL_RenderDrawLines(gRenderer, points, 5);
		gEngine->ResetDrawColor();
	}
}

bool Rectangle::Contains(float x, float y) const
{
	return (x <= (this->x + this->width) &&
			x >= this->x &&
			y <= (this->y + this->height) && 
			y >= this->y);
}

void Rectangle::SetPosition(const Vector2D * const vect)
{
	this->x = vect->x;
	this->y = vect->y;
}

void Rectangle::SetPosition(float x, float y)
{
	this->x = x;
	this->y = y;
}

void Rectangle::MoveBy(const Vector2D * const vect)
{
	this->x += vect->x;
	this->y += vect->y;
}

void Rectangle::MoveBy(float x, float y)
{
	this->x += x;
	this->y += y;
}

bool Rectangle::CollidesWith(const Rectangle * const rect) const
{
	if (Contains(rect->x, rect->y) ||
		Contains(rect->x + rect->width, rect->y) ||
		Contains(rect->x, rect->y + rect->height) ||
		Contains(rect->x + rect->width, rect->y + rect->height) ||
		rect->Contains(x, y) ||
		rect->Contains(x + width, y) ||
		rect->Contains(x, y + height) ||
		rect->Contains(x + width, y + height))
	{
		return true;
	}

	return false;
}