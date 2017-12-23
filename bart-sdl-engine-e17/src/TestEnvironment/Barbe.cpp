#include "Barbe.h"

Barbe::Barbe()
	: Sprite("full-face-beard.png", 100, 100)
	, speed(100)
{
	jukebox = new MusicSound();
	jukebox->PlayMusic(MUSICTEST);

}

Barbe::Barbe(int x, int y)
	: Sprite("full-face-beard.png", (float)x, (float)y)
{
}

Barbe::~Barbe()
{
	delete jukebox;
}

void Barbe::Update() // Part saved
{
	Vector2D dir = Vector2D(((gInput->IsKeyHeld(SDL_SCANCODE_D) ? 1.f: 0.f) + (gInput->IsKeyHeld(SDL_SCANCODE_A) ? -1.f: 0.f)), ((gInput->IsKeyHeld(SDL_SCANCODE_W) ? -1.f: 0.f) + (gInput->IsKeyHeld(SDL_SCANCODE_S) ? 1.f: 0.f)));

	//std::cout << "GetX(): " << GetX() << std::endl;

	// Attention! La direction n,est pas normalizé! Va plus vite en diagonale.
	SetPosition(
		GetX() + dir.x * speed * gTimer->GetDeltaTime(), 
		GetY() + dir.y * speed * gTimer->GetDeltaTime());

	//std::cout << gTimer->GetDeltaTime() << std::endl;;
}
