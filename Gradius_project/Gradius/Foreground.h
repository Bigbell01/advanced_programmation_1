#pragma once
#include"Sprite.h"
#include "Vector2D.h"

class Foreground:
	public Sprite

{
public:
	Foreground();
	Foreground(int x, int y, int w, int h);
	~Foreground();
	
	void Update();
	void Parallaxe();
	
	

private:
	float speed;
	
};

