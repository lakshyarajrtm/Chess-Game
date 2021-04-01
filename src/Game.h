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

	static int turn;


private:
	bool running;
	SDL_Window* window;

	// board
	Board* board;

	// character array 
	Pawn* pieces[32];
	

	// to see if opponent is computer
	bool ai_enabled;
};

