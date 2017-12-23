#pragma once
#include <iostream>
#include "ResourceManager.h"
#include "Sprite.h"
#include "Vector2D.h"
#include <vector>

class Level:
	public  Sprite
{


public:
	Level();
	Level(int x, int y);
	
	~Level();
	void Paralaxe();
	void Update();
	

private:
	float speed;
	

};

