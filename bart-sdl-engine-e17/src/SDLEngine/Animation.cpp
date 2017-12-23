#include "Animation.h"



Animation::Animation(const char *path)
	: Sprite(path)
{
	_nbRect = 0;
	this->SetVisible(false); // dont show it up front
}


Animation::~Animation()
{
}

void Animation::Update()
{
	
	if (!_active)
		return; // not visible
	if ((_waitCtr += gTimer->GetDeltaTime()) < _waitTime)
		return; // not time to display yet
	_waitCtr = 0; // for next cycle

	SetDrawSize(_drawSizeX, _drawSizeY);
	SetSourceRect
	(
		_rects[_currentRec].x,
		_rects[_currentRec].y,
		_rects[_currentRec].w,
		_rects[_currentRec].h
	);
	SetPosition(GetX(), GetY());

	if (++_currentRec >= _nbRect)
		_currentRec = 0;

}

void Animation::
Add(SDL_Rect aRect)
{
	if (_nbRect >= MAX_RECTS) return; // avoid index out of range
	_rects[_nbRect++] = aRect;
}

void Animation::Start(float aRectPerSect, int aDrawSizeX, int aDrawSizeY)
{
	if (abs(aRectPerSect) < FLT_EPSILON) return; // avoid zerodivide
	if (_nbRect <= 0) return; // nothing to animate
	_active = true;
	_currentRec = 0;
	_waitTime = 1.0f / aRectPerSect;
	_waitCtr = _waitTime + 100.0f; // force display first rec up front
	_drawSizeX = aDrawSizeX;
	_drawSizeY = aDrawSizeY;
	this->SetVisible(true); // show it!
}

void Animation::Stop()
{
	_active = false;
	this->SetVisible(false); // hide it while stopped
}

