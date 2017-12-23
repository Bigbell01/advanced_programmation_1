#pragma once

#include <iostream>

#include "Engine.h"

#include "Level.h" 

#include "Starship.h"

#include "Foreground.h"

#include "Laser.h"

#include "Text.h"

#include "Ennemies.h"

class Game_Manager
	: public GameObject
{
public:
	Game_Manager();
	~Game_Manager();

	void Update();

	//const std::vector<Rectangle*> GetList() const { return list; }
	//void AddToList(Rectangle* rectum);

private:
	Level* l1; 
	Level* l2;

	Foreground* f1;
	Foreground* f2;

	Starship* xWing;

	Ennemies* e1;
	Ennemies* e2;
	Ennemies* e3;


	std::vector<Rectangle*>lub;
	
	std::vector<Laser*> lasers;

	Text* text;



}; 

