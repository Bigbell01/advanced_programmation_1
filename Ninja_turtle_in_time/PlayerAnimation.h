#pragma once
#include "GameObject.h"
#include "Animation.h"

#define SPRITESHEET_PLAYER "sprite/Player/SNES - Teenage Mutant Ninja Turtles 4 Turtles in Time - Leonardo (1).png"

class PlayerAnimation
	:public GameObject
{
public:
	PlayerAnimation();
	~PlayerAnimation();

	void Update();
	Animation* GetCurrentAnimation() { return _currentAnimation; }

private:
	float _timerCtr;
	bool _flip;

	float _moveSpeed;
	int _state = 99;

	bool _isIdle;

	Animation* _playerwalk;
	Animation* _playeridle;
	Animation* _playerattack;
	Animation* _playerwalkup;
	Animation* _playerwalkdown;
	Animation* _currentAnimation;


	void CreatePlayerWalkDown();
	void CreatePlayerWalkUp();
	void CreatePlayerAttack();
	void CreatePlayerWalk();
	void CreatePlayerIdle();
	void UpdatePositionForAnims();

};

