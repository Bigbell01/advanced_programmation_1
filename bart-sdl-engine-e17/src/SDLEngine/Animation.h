#pragma once

#include <iostream>
#include <list>

#include "Sprite.h"

#define MAX_RECTS 40

class Animation :
	public Sprite
{

public:
	Animation(const char *path);
	~Animation();

	void Update();
	void Add(SDL_Rect aRect);
	void Start(float aRectPerSect, int aDrawSizeX, int aDrawSizeY);
	void Stop();

private:
	//std::list<SDL_Rect> _rects;
	SDL_Rect _rects[MAX_RECTS];
	int _currentRec;
	int _nbRect;

	bool _active;
	float _waitTime;
	float _waitCtr;
	int _drawSizeX, _drawSizeY;

};

