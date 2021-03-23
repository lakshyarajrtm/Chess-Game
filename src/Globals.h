#pragma once

#include <SDL/SDL.h>

enum class pawnType
{
	NIL = 0, PAWN, BISHOP, KNIGHT, ROOK, KING, QUEEN,

};

enum class color
{
	BLACK = 0, WHITE = 1
};



extern SDL_Renderer* renderer;

extern pawnType layout[8][8];