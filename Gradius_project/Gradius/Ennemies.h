#pragma once
#include "Sprite.h"

class Ennemies
	:public Sprite

{
public:
	Ennemies();
	Ennemies(int x, int y, int w, int h);

	~Ennemies();
	
	void Update();
	/*void Parallaxe();*/
	void DestroyEnnemy();

private:

	float speed;

};

