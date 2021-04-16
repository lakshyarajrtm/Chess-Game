#pragma once

#include <iostream>
#include <SDL/SDL.h>
#include <vector>

#include "Component.h"


class Game
{

public:
	Game();
	~Game();
	bool isRunning();
	void update();
	void renderGame();

	static int turn;


private:
	bool running;
	SDL_Window* window;

	// board
	Board* board;

	// character array 
	std::vector<Pawn*> pieces;
	

	// to see if opponent is computer
	bool ai_enabled;

	
};

