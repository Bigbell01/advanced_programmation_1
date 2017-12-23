#include <iostream>

#include "Engine.h"
#include "Game_Manager.h"

int main(int argc, char* args[])
{
	gEngine->Init("SDLEngine", 960, 540);
	
	Sprite::SetDebug(false);

	Game_Manager GM;
	
	
	

	gEngine->Run();
	
	Engine::Kill();
	
	return 0;
}