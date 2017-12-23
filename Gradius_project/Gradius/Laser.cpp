#include "Laser.h"

Laser::Laser()
	:Sprite("Lazer_Gradius.png", 100, 100)
	, speed(500)
	,Laser_Is_Shot (false)
{
	;
}

Laser::Laser(int x, int y)
	: Sprite("Lazer_Gradius.png", x, y)
	, speed(500)
	, Laser_Is_Shot(false)
{
}

Laser::Laser(int x, int y, int width, int height)
	: Sprite("Lazer_Gradius.png", x, y,width,height)
	, speed(500)
	, Laser_Is_Shot(false)
{
}

Laser::~Laser()
{
}

void Laser::Shoot()
{
	Laser_Is_Shot = true;
	SetVisible(true);
}

void Laser::Update()
{
	/*std::cout << "I live" << std::endl;

	Vector2D dir = Vector2D(GetX() + gTimer->GetDeltaTime(), GetY());

	SetPosition(dir);*/
	
	if (Laser_Is_Shot)
	{
		SetPosition(GetX() + 500.0 * gTimer->GetDeltaTime(), GetY());	
		
	}
	
	if (this->GetX() <= -960)
	{
		SetPosition(960, 0);
		Laser_Is_Shot = false;
	}	
}
