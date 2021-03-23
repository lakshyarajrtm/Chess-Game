#pragma once

#include <SDL/SDL.h>
#include <iostream>
#include "Component.h"


class Game
{

public:
	Game();
	~Game();
	bool isRunning();
	void update();
	void renderGame();


private:
	bool running;
	SDL_Window* window;

	// board
	Board* board;

	// character array 
	Pawn* pieces[32];
};