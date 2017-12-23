#pragma once

#include<iostream>
#include"Engine.h"
#include "HUD.h"
#include "Player.h"
#include "PlayerVsEnnemy.h"
#include "Ennemy.h"
#include "Background.h"
#include "LifeBar.h"

class TMNTInTime
	:public GameObject
{
public:
	TMNTInTime();
	~TMNTInTime();

	void Update();
	
private:
	Background* background;

	Text* textTest;

	Player* player1;
	/*Player* player2*/

	Ennemy* enemy1;

	HUD* player1_hud;
	/*HUD* player2_hud*/

	LifeBar* lifeBar;

	std::vector<Ennemy*> ennemy_list;
};

