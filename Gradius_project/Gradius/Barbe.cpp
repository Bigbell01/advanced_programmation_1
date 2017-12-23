#include "Barbe.h"

Barbe::Barbe()
	: Sprite("full-face-beard.bmp", 100, 100)
{
}

Barbe::~Barbe()
{
}

void Barbe::Update()
{
	SetPosition(GetX() + 0.5f, GetY());
}
