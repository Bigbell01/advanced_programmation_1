#pragma once
#include "Sprite.h"
#include<iostream>

#include "Vector2D.h"
#include "ResourceManager.h"



class Laser
	:public Sprite
{
public:
	Laser();
	Laser(int x, int y);
	Laser(int x, int y, int width, int height);
	~Laser();
	void Update();
	void Shoot();

private:
	float speed;
	bool Laser_Is_Shot;
};

