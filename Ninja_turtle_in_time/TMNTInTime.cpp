#include "TMNTInTime.h"

TMNTInTime::TMNTInTime()
{
	background = new Background();
	player1 = new Player();

	enemy1 = new Ennemy();


	
	//	gEngine->AddComponent(textTest); // no neeed, deprecated MM

	/*player1_hud=new HUD("Leo",x,y,w,h);*/

	lifeBar = new LifeBar(player1->GetPlayerMaxHp());
}

TMNTInTime::~TMNTInTime()
{
	delete player1;
	player1 = nullptr;
	
	delete player1_hud;
	player1_hud = nullptr;

	delete lifeBar;
	lifeBar = nullptr;
}

void TMNTInTime::Update()
{	
	//if (player1->GetX() >= 530)
	{
		background->MoveBackground(player1, enemy1);
		//background->SetCount();

		//Move player at his initial position
	}

	if (player1->GetPlayerHp() > 0.f)
	{
		lifeBar->UpdatePlayerLife(player1->GetPlayerHp());
		
	}

	//player1_hud.
}
