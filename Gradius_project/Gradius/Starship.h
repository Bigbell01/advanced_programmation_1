#pragma once
#include<iostream>
#include "Sprite.h"
#include "Vector2D.h"
#include "ResourceManager.h"
#include "Laser.h"



class Starship :
	public Sprite
	
{
public:
	Starship();
	Starship(int x, int y);

	~Starship();

	void Update();
	void DestroyStarship();

	std::vector<Laser*> GetLaserList() { return list; };

private:
	float speed;
	int currentLaser;
	Vector2D prevPos;
	Laser laser1[15];
	
	std::vector<Laser*> list;
};

