#include "Game_Manager.h"

Game_Manager::Game_Manager()
{
	l1 = new Level(0, 0);
	l2 = new Level(960, 0);
	
	f1 = new Foreground(0, 465, 960, 75);
	f2 = new Foreground(960, 465, 960, 75);
	
	xWing = new Starship(50, 50);
	
	e1 = new Ennemies(960, 50,40, 36);
	e2 = new Ennemies(960, 100, 40, 36);
	e3 = new Ennemies(960, 150, 40, 36);

	lub.push_back(f1);
	lub.push_back(f2);
	lub.push_back(e1);
	lub.push_back(e2);
	lub.push_back(e3);
	
	lasers = xWing->GetLaserList();

	text = new Text("Game in progres", 0, 0);
}

Game_Manager::~Game_Manager()
{
	delete l1;
	delete l2;
	delete xWing;
	delete text;
	
	if (lub.size() > 0)
	{
		for(Rectangle* r: lub)
		{
			delete r;
		}
	}
}

void Game_Manager::Update()
{
	for(Rectangle* r: lub)
	{
		if (xWing->CollidesWith(r))
		{
			xWing->DestroyStarship();
			text->SetText("You Lose MOFO!!!!");
		}
	}

	for each (Rectangle* r in lasers)
	{
		if (e1->CollidesWith(r))
		{
			e1->DestroyEnnemy();
		}

		if (e2->CollidesWith(r))
		{
			e2->DestroyEnnemy();
		}

		if (e3->CollidesWith(r))
		{
			e3->DestroyEnnemy();
			
		}
	}

	/*if (e3->GetVisible() == false || e2->GetVisible() == false || e1->GetVisible() == false)
	{
		text->SetText("You Won Dude!!!!");
	}*/
}

