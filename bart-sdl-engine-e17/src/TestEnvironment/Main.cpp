#include <iostream>

#include "Engine.h"

#include "Text.h"

#include "Barbe.h"

#include "Galaga.h"

int main(int argc, char* args[])
{
	gEngine->Init("SDLEngine", 960, 540);

	// Enleve le debuMode qui dessine des lignes autour des colliders.
	Sprite::SetDebug(false);

	gEngine->SetColor(128, 128, 128);

	Text* textTest = new Text("hello world", 10, 10);
	// gEngine->AddComponent(textTest); // Deprecated MM

	Barbe b2 = Barbe(100, 100);
	// gEngine->AddComponent(&b2); // Deprecated MM
	
	Barbe b;
	// gEngine->AddComponent(&b); // deprecated MM

	Galaga g;
	// gEngine->AddComponent(&g); // deprecated MM
	
	gEngine->Run();
	return 0;
}