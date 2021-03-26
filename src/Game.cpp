#pragma once

#include "Game.h"
#include "Globals.h"
#include "Component.h"
#define PIECE_COUNT (int)32

SDL_Renderer* renderer;


pawnType layout[8][8] = {

				   { pawnType::ROOK, pawnType::KNIGHT, pawnType::BISHOP, pawnType::KING, pawnType::QUEEN, pawnType::BISHOP, pawnType::KNIGHT, pawnType::ROOK },
				   { pawnType::PAWN, pawnType::PAWN, pawnType::PAWN, pawnType::PAWN, pawnType::PAWN, pawnType::PAWN, pawnType::PAWN, pawnType::PAWN },
				   { pawnType::NIL, pawnType::NIL, pawnType::NIL, pawnType::NIL, pawnType::NIL, pawnType::NIL, pawnType::NIL, pawnType::NIL, },
				   { pawnType::NIL, pawnType::NIL, pawnType::NIL, pawnType::NIL, pawnType::NIL, pawnType::NIL, pawnType::NIL, pawnType::NIL, },
				   { pawnType::NIL, pawnType::NIL, pawnType::NIL, pawnType::NIL, pawnType::NIL, pawnType::NIL, pawnType::NIL, pawnType::NIL, },
				   { pawnType::NIL, pawnType::NIL, pawnType::NIL, pawnType::NIL, pawnType::NIL, pawnType::NIL, pawnType::NIL, pawnType::NIL, },
				   { pawnType::PAWN, pawnType::PAWN, pawnType::PAWN, pawnType::PAWN, pawnType::PAWN, pawnType::PAWN, pawnType::PAWN, pawnType::PAWN },
				   { pawnType::ROOK, pawnType::KNIGHT, pawnType::BISHOP, pawnType::KING, pawnType::QUEEN, pawnType::BISHOP, pawnType::KNIGHT, pawnType::ROOK }
};


Game::Game():running(false), window(nullptr), board(nullptr), turn(BLACK), ai_enabled(false)
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

			// game objects creation

			board = new Board("assets/images/chess-board.bmp");
			for (int i = 0; i < PIECE_COUNT; i++)
			{
				pieces[i] = new Pawn("assets/images/chess-pieces.bmp");
			}

			int pieceIdx = 0;
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					pawnType num = layout[i][j];

					if (num != pawnType::NIL)
					{
						(pieces[pieceIdx])->dest.x = (j * 100) + 20;
						(pieces[pieceIdx])->dest.y = (i * 80) + 10;
						(pieces[pieceIdx])->xBlock = j;
						(pieces[pieceIdx])->yBlock = i;
						
						(pieces[pieceIdx])->type = num;
						(pieces[pieceIdx])->col = BLACK;
						
						if (pieceIdx > 15)
						{
							(pieces[pieceIdx])->col = WHITE;
						}
						
						pieceIdx++;
					}

				}
			}
		}
	}
}


void Game::renderGame()
{
	SDL_RenderClear(renderer);
	

	board->DrawTexture();
	
	for (int i = 0; i < PIECE_COUNT; i++)
	{
		(pieces[i])->DrawTexture();
	}
	
	SDL_RenderPresent(renderer);


}

void Game::update()
{
	SDL_Event event;
	int xMousePos{0}, yMousePos{0};

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
			{
				running = false;
				break;
			}

			case SDL_MOUSEBUTTONDOWN:
			{
				SDL_GetMouseState(&xMousePos, &yMousePos);
				break;
			}

		}
	}

	

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

