#include "Ennemies.h"



Ennemies::Ennemies()
{
}

Ennemies::Ennemies(int x, int y, int w, int h)
	:Sprite("ProgAvance_ennemy_explosion1.1.png", x, y, w, h)
	, speed(300)
{

}



Ennemies::~Ennemies()
{

}

void Ennemies::Update()
{
	
	
	
	Vector2D dir;
	dir.x = -1;

	SetPosition(
		GetX() + dir.x * speed * gTimer->GetDeltaTime(),
		GetY() + dir.y * speed * gTimer->GetDeltaTime());
}

//void Ennemies::Parallaxe()
//{
//	if (this->GetX() <= -960)
//	{
//		SetPosition(960, 465);
//	}
//
//}

void Ennemies::DestroyEnnemy()
{
	SetVisible(false);
}
