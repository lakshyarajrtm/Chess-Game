#pragma once

#include "Game.h"
#include "Globals.h"
#include "Component.h"


SDL_Renderer* renderer;


int layout[8][8] = {

				   { 1,2,3,4,5,3,2,1 },
				   { 1,1,1,1,1,1,1,1 },
				   { 0,0,0,0,0,0,0,0 },
				   { 0,0,0,0,0,0,0,0 },
				   { 0,0,0,0,0,0,0,0 },
				   { 0,0,0,0,0,0,0,0 },
				   { 1,1,1,1,1,1,1,1 },
				   { 1,2,3,4,5,3,2,1 }
};


Game::Game():running(false), window(nullptr),board(nullptr)
{
	

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0)
	{
		std::cout << "Unable to initialize SDL Error:" << SDL_GetError();
		

	}
	else
	{
		Uint32 flags = false;
		window = SDL_CreateWindow("Chess 2D", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, flags);
		if (!window)
		{
			std::cout << "Error, can not create window :" << SDL_GetError();
			SDL_Quit();
		}
		else
		{
			renderer = SDL_CreateRenderer(window, -1, 0);

			if (!renderer)
			{
				std::cout << "Error, can not create renderer:" << SDL_GetError();
				SDL_DestroyWindow(window);
				SDL_Quit();
			}

			running = true;
			board = new Board("assets/images/chess-board.bmp");
		}
	}
}


void Game::renderGame()
{
	board->DrawTexture();
	
}

void Game::update()
{
	
}

bool Game::isRunning()
{
	return running;
}


Game::~Game()
{

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	delete board;
	window = nullptr;
	renderer = nullptr;
	board = nullptr;
}