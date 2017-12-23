#include "Starship.h"

#include "Laser.h"

#include "Foreground.h"




Starship::Starship()
	: Sprite ("ship_straight.png",100,100)
	, speed(500)
	, currentLaser(0)
	
{
}

Starship::Starship(int x, int y)
	: Sprite("ship_straight.png",x,y)
	, speed(500)
	, currentLaser(0)
	
{
	for (int i = 0; i < 15; i++)
	{
		laser1[i].SetVisible(false);
		

		list.push_back(&laser1[i]);
	}

	SetDrawSize(GetWidth()*2, GetHeight()*2);
}


Starship::~Starship()
{
	
}

void Starship::Update()
{
	
	Vector2D dir = Vector2D (
		(gInput->IsKeyHeld(SDL_SCANCODE_D)? 1: 0) + (gInput->IsKeyHeld(SDL_SCANCODE_A)? -1: 0),
		(gInput->IsKeyHeld(SDL_SCANCODE_W)? -1: 0) + (gInput->IsKeyHeld(SDL_SCANCODE_S)? 1: 0));

	Normalize(&dir);

	prevPos = Vector2D(GetX(), GetY());

	SetPosition(
		GetX() + dir.x * speed * gTimer->GetDeltaTime(),
		GetY() + dir.y * speed * gTimer->GetDeltaTime());

	if (GetX() >= 400 || GetX() <= 10)
	{
		SetPosition(prevPos.x, GetY());
	}

	if (GetY() >= 500 || GetY() <= 10)
	{
		SetPosition(GetX(), prevPos.y);
	}

	if (gInput->IsKeyPressed(SDL_SCANCODE_SPACE))
	{
		laser1[currentLaser].SetPosition(GetPosition().x + GetWidth(), GetPosition().y + GetHeight()/2);
		laser1[currentLaser].Shoot();
		currentLaser++;

		if (currentLaser >= 15 - 1)
		{
			currentLaser = 0;
		}
	}

	// Attention! La direction n,est pas normalizé! Va plus vite en diagonale.
	
	//std::cout << gTimer->GetDeltaTime() << std::endl;;
}

void Starship::DestroyStarship()
{
	SetVisible(false);


}
