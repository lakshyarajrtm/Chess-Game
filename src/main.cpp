#pragma once

#include "Game.h"
#include <chrono>
#include <ctime>



int main(int argc, char* args[])
{
	
	Game* game = new Game();
	Uint32 FPS = 200;

	while (game->isRunning())
	{
		std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();

		game->update();
		game->renderGame();

		std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
		auto duration = end - start;

		Uint32 dur = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
		
		
		if (FPS > dur)
		{
			SDL_Delay(FPS - dur);
		}

	}

	delete game;
	
	return 0;
}



