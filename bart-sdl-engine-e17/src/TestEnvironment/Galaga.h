#pragma once
#include "Animation.h"
#include "Component.h"
#include "GameObject.h"

#define SPRITESHEET_PATH "galaga_transpare_fixed.png"

class Galaga :
	public GameObject
{
public:
	Galaga();
	~Galaga();

	void Update();

private:
	float _timerCtr;
	int _state = 99;

	Animation* _flagship;
	Animation* _guard;

	void CreateFlagship();
	void CreateGuard();
};

