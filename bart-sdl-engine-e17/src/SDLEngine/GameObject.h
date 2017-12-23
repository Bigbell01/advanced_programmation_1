#pragma once
#include "Engine.h"

class GameObject :
	public Component
{
public:
	GameObject();
	~GameObject();

	virtual void Start() {}
	virtual void Update() {}
	virtual void Draw() {}
	virtual void Stop() {}
};

