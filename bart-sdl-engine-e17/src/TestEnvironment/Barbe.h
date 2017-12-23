#pragma once
#include <iostream>

#include "Sprite.h"
#include "Geometry.h"
#include "MusicSound.h"

class Barbe :
	public Sprite
{
public:
	Barbe();
	Barbe(int x, int y);
	~Barbe();

	void Update();

private:
	float speed;
	MusicSound* jukebox;
};

