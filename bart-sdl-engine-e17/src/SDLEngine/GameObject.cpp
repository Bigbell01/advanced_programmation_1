#include "GameObject.h"

GameObject::GameObject()
{
	gEngine->RegisterComponent(this);
}

GameObject::~GameObject()
{
}
