#include "PlayerAnimation.h"


PlayerAnimation::PlayerAnimation()
	: _moveSpeed(100.0f)
{
	CreatePlayerIdle();
	CreatePlayerAttack();
	CreatePlayerWalk();
	CreatePlayerWalkUp();
	CreatePlayerWalkDown();
	_currentAnimation = _playeridle;
	_currentAnimation->SetPosition(40, 240);
	_currentAnimation->Start(10, 78, 62);

	_timerCtr = 0;
	_isIdle = true;
	_flip = false;
}

PlayerAnimation::~PlayerAnimation()
{
	delete _playerattack;
	delete _playeridle;
	delete _playerwalk;
	delete _playerwalkup;
	delete _playerwalkdown;
}

//Contr�le du StateMachine pour l'anim ici
void PlayerAnimation::Update()
{
	Vector2D dir = Vector2D(
		(float)(gInput->IsKeyHeld(SDL_SCANCODE_D) ? 1 : 0) + (gInput->IsKeyHeld(SDL_SCANCODE_A) ? -1 : 0),
		(float)(gInput->IsKeyHeld(SDL_SCANCODE_W) ? -1 : 0) + (gInput->IsKeyHeld(SDL_SCANCODE_S) ? 1 : 0));

	if (gInput->IsKeyPressed(SDL_SCANCODE_D)&&(!(gInput->IsKeyHeld(SDL_SCANCODE_A)))
		|| (gInput->IsKeyHeld(SDL_SCANCODE_D)&&gInput->IsKeyReleased(SDL_SCANCODE_A)))
	{
		_flip = false;
		//WALK RIGHT
		_isIdle = false;
		_currentAnimation->Stop();
		_currentAnimation = _playerwalk;
		_currentAnimation->Start(10, 78, 62);
		this->_currentAnimation->SetSpriteState(SDL_FLIP_NONE);
	}
	else if (gInput->IsKeyPressed(SDL_SCANCODE_A) && (!(gInput->IsKeyHeld(SDL_SCANCODE_D)))
		|| (gInput->IsKeyHeld(SDL_SCANCODE_A) && gInput->IsKeyReleased(SDL_SCANCODE_D)))
	{
		_flip = true;
		//WALK LEFT
		_isIdle = false;
		_currentAnimation->Stop();
		_currentAnimation = _playerwalk;
		_currentAnimation->Start(10, 78, 62);
		this->_currentAnimation->SetSpriteState(SDL_FLIP_HORIZONTAL);
	}
	//else if (gInput->IsKeyPressed(SDL_SCANCODE_W))
	else if (gInput->IsKeyPressed(SDL_SCANCODE_W) && (!(gInput->IsKeyHeld(SDL_SCANCODE_S)))
		|| (gInput->IsKeyHeld(SDL_SCANCODE_W) && gInput->IsKeyReleased(SDL_SCANCODE_S)))
	{
		_flip = false;
		//WALK UP
		_isIdle = false;
		_currentAnimation->Stop();
		_currentAnimation = _playerwalkup;
		_currentAnimation->Start(10, 78, 62);
		this->_currentAnimation->SetSpriteState(SDL_FLIP_NONE);
	}
//	else if (gInput->IsKeyPressed(SDL_SCANCODE_S))
	else if (gInput->IsKeyPressed(SDL_SCANCODE_S) && (!(gInput->IsKeyHeld(SDL_SCANCODE_W)))
		|| (gInput->IsKeyHeld(SDL_SCANCODE_S) && gInput->IsKeyReleased(SDL_SCANCODE_W)))

	{
		_flip = false;
		//WALK DOWN
		_isIdle = false;
		_currentAnimation->Stop();
		_currentAnimation = _playerwalkdown;
		_currentAnimation->Start(10, 78, 62);
		this->_currentAnimation->SetSpriteState(SDL_FLIP_NONE);
	}
	else if (!_isIdle && dir.x == 0 && dir.y == 0)
	{
		//IDLE 
		_currentAnimation->Stop();
		_currentAnimation = _playeridle;
		_currentAnimation->Start(10, 78, 62);
		_isIdle = true;
		this->_currentAnimation->SetSpriteState(SDL_FLIP_NONE);
		if (_flip)
		{
			this->_currentAnimation->SetSpriteState(SDL_FLIP_HORIZONTAL);
		}
	}


	//MOUVEMENT
	Normalize(&dir);

	Vector2D prevPos = Vector2D(_currentAnimation->GetX(), _currentAnimation->GetY());

	_currentAnimation->SetPosition(
		_currentAnimation->GetX() + dir.x * _moveSpeed * gTimer->GetDeltaTime(),
		_currentAnimation->GetY() + dir.y * _moveSpeed * gTimer->GetDeltaTime());


	if (_currentAnimation->GetX() >= 480 || _currentAnimation->GetX() <= 5)
	{

		_currentAnimation->SetPosition(prevPos.x, _currentAnimation->GetY());
	}

	if (_currentAnimation->GetY() >= 250 || _currentAnimation->GetY() <= 160)
	{
		_currentAnimation->SetPosition(_currentAnimation->GetX(), prevPos.y);
	}
	if (gInput->IsKeyPressed(SDL_SCANCODE_SPACE))
	{
		//ATTAQUE
		_currentAnimation->Stop();
		_currentAnimation = _playerattack;
		_currentAnimation->Start(10, 78, 62);
		this->_currentAnimation->SetSpriteState(SDL_FLIP_NONE);
		if (_flip)
		{
			this->_currentAnimation->SetSpriteState(SDL_FLIP_HORIZONTAL);
		}
	}
	UpdatePositionForAnims();
}

void PlayerAnimation::CreatePlayerWalkDown()
{
	//WALK DOWN
	_playerwalkdown = new Animation(SPRITESHEET_PLAYER);
	SDL_Rect r5;
	r5 = { 314,202, 47, 62 };	_playerwalkdown->Add(r5);
	r5 = { 314,202, 47, 62 };	_playerwalkdown->Add(r5);
	r5 = { 360,202, 37, 63 };	_playerwalkdown->Add(r5);
	r5 = { 360,202, 37, 63 };	_playerwalkdown->Add(r5);

}

void PlayerAnimation::CreatePlayerWalkUp()
{
	//WALK UP
	_playerwalkup = new Animation(SPRITESHEET_PLAYER);
	SDL_Rect r4;
	r4 = { 160,205, 55, 59 };	_playerwalkup->Add(r4);
	r4 = { 160,205, 55, 59 };	_playerwalkup->Add(r4);
	r4 = { 216, 205, 40, 59 };	_playerwalkup->Add(r4);
	r4 = { 216, 205, 40, 59 }; _playerwalkup->Add(r4);
	r4 = { 256, 202, 36, 62 }; _playerwalkup->Add(r4);
	r4 = { 256, 202, 36, 62 }; _playerwalkup->Add(r4);
}

void PlayerAnimation::CreatePlayerAttack()
{
	//ATTACK
	_playerattack = new Animation(SPRITESHEET_PLAYER);
	SDL_Rect r3;
	r3 = { 10, 583, 52, 61 };	_playerattack->Add(r3);
	r3 = { 10, 583, 52, 61 };	_playerattack->Add(r3);
	r3 = { 63, 583, 55, 58 };	_playerattack->Add(r3);
	r3 = { 122, 587, 90, 56 };  _playerattack->Add(r3);
}

void PlayerAnimation::CreatePlayerWalk()
{
	//WALK
	_playerwalk = new Animation(SPRITESHEET_PLAYER);
	SDL_Rect r2;
	r2 = { 53, 204, 47, 61 };	_playerwalk->Add(r2);
	r2 = { 53, 204, 47, 61 };	_playerwalk->Add(r2);
	r2 = { 101, 206, 44, 59 }; _playerwalk->Add(r2);
	r2 = { 101, 206, 44, 59 }; _playerwalk->Add(r2);
}


void PlayerAnimation::CreatePlayerIdle()
{
	_playeridle = new Animation(SPRITESHEET_PLAYER);

	//IDLE
	SDL_Rect r1;
	r1 = { 9, 135, 76, 60 };	_playeridle->Add(r1);
	r1 = { 9, 135, 76, 60 };	_playeridle->Add(r1);
	r1 = { 309, 131, 73, 64 }; _playeridle->Add(r1);
	r1 = { 309, 131, 73, 64 }; _playeridle->Add(r1);
}

void PlayerAnimation::UpdatePositionForAnims()
{
	_playerwalk->SetPosition(&_currentAnimation->GetPosition());
	_playeridle->SetPosition(&_currentAnimation->GetPosition());
	_playerattack->SetPosition(&_currentAnimation->GetPosition());
	_playerwalkup->SetPosition(&_currentAnimation->GetPosition());
	_playerwalkdown->SetPosition(&_currentAnimation->GetPosition());
}


