#pragma once

#include <SDL/SDL.h>

enum class pawnType
{
	NIL = 0, PAWN, BISHOP, KNIGHT, ROOK, KING, QUEEN,

};

enum color
{
	NIL = 0, BLACK = 1, WHITE = 2
};


extern SDL_Renderer* renderer;
extern pawnType layout[8][8];