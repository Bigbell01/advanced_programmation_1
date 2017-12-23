#include "Level.h"

Level::Level()
	: Sprite("Gradius_Back.png", 0, 0)
	,speed(100)
{
}

Level::Level(int x, int y)
	:Sprite("Gradius_Back.bmp",x,y)
	, speed(100)
{
}

Level::~Level()
{
}

void Level::Paralaxe()
{
	if (this->GetX() <= -960)
	{
		SetPosition(960, 0);
	}
}

void Level::Update()
{
	Paralaxe();
	Vector2D dir;
	dir.x = -1;

	SetPosition(
		GetX() + dir.x * speed * gTimer->GetDeltaTime(),
		GetY() + dir.y * speed * gTimer->GetDeltaTime());
}
