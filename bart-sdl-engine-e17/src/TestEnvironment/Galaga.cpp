#include "Galaga.h"
#include <iostream>

	

Galaga::Galaga()
{
	CreateFlagship();
	_flagship->SetPosition(50, 50);
	_flagship->Start(2, 36, 36);
	CreateGuard();
	_guard->SetPosition(50, 90);
	_guard->Start(2, 30, 20);

	_timerCtr = 0;
}


Galaga::~Galaga()
{
}

void Galaga::Update()
{
	// std::cout << "update galaga"; // uncommment to check
	_timerCtr += gTimer->GetDeltaTime();
	if (_timerCtr > 5 && _timerCtr <10 && _state !=1)
	{
		_guard->Stop();
		_state = 1;
	}

	if (_timerCtr > 11 && _timerCtr <15 && _state != 2)
	{
		_guard->Start(2, 30, 20);
		_state = 2;
	}

	if (_timerCtr > 16 && _timerCtr <20 && _state != 3)
	{
		_flagship->Stop();
		_state = 3;
	}

	if (_timerCtr > 21 && _timerCtr <25 && _state != 4)
	{
		_flagship->Start(2, 36, 36);
		_state = 4;
	}

	if (_timerCtr > 25) // fly the guard 10 frames per sec in x and 5 fps in y)
		_guard->SetPosition(50 + (_timerCtr - 25) * 10, 90 + (_timerCtr - 25) * 5);

}

void Galaga::CreateFlagship()
{
	_flagship = new Animation(SPRITESHEET_PATH);

	SDL_Rect r1;
	r1 = { 7, 110, 17, 17 };	_flagship->Add(r1);
	r1 = { 31, 110, 17, 17 };	_flagship->Add(r1);

	// gEngine->AddComponent(_flagship); // deprecated MM
}

void Galaga::CreateGuard()
{
	_guard = new Animation(SPRITESHEET_PATH);

	SDL_Rect r1;
	r1 = { 9, 161, 15, 10 };	_guard->Add(r1);
	r1 = { 33, 161, 15, 10 };	_guard->Add(r1);

	// gEngine->AddComponent(_guard); // deprecated MM
}
