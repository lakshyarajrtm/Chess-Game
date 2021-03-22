#pragma once
#include "Game.h"


int main(int argc, char* args[])
{
	Game* game = new Game();

	while (game->isRunning())
	{
		game->update();
		game->renderGame();
	}

	return 0;
}

