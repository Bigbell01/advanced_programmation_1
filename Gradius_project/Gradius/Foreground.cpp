#include "Foreground.h"




Foreground::Foreground()
{
}

Foreground::Foreground(int x, int y, int w, int h)
	:Sprite("ProgAvance_LVL1.2.png", x, y, w, h)
	, speed(100)
{
	
}


Foreground::~Foreground()
{
}

void Foreground::Parallaxe()
{

	if (this->GetX() <= -960)
	{
		SetPosition(960, 465);
	}
}
void Foreground::Update()
{
	Parallaxe();
	Vector2D dir;
	dir.x = -1;

	SetPosition(
		GetX() + dir.x * speed * gTimer->GetDeltaTime(),
		GetY() + dir.y * speed * gTimer->GetDeltaTime());


}

