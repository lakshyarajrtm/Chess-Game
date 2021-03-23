#include "Component.h"

#include <fstream>




Component::Component(const char* image)
{
	surf = SDL_LoadBMP(image);
	tex = SDL_CreateTextureFromSurface(renderer, surf);
	SDL_FreeSurface(surf);
	surf = nullptr;
	

}

Component::~Component()
{
	delete tex;
	tex = nullptr;
}

// implementation for board


Board::Board(const char* img):Component(img)
{
}

void Board::DrawTexture() 
{
	
	SDL_SetRenderTarget(renderer, tex);
	SDL_RenderCopy(renderer, tex, NULL, NULL);
	SDL_RenderPresent(renderer);
}

Board::~Board()
{
	
}


// implementation for pawn

Pawn::Pawn(const char* image) :Component(image)
{
	src.h = 250;
	src.w = 80;
	dest.h = 60;
	dest.w = 60;

	
}

void Pawn::DrawTexture()
{
	switch (type)
	{
	case pawnType::PAWN:
	{
		src.x = 416;

		if (col == color::BLACK)
			src.y = 140;
		else
			src.y = 0;
		break;
	}
	case pawnType::ROOK:
	{
		src.x = 333;

		if (col == color::BLACK)
			src.y = 140;
		else
			src.y = 0;
		break;
	}
	case pawnType::KNIGHT:
	{
		src.x = 250;

		if (col == color::BLACK)
			src.y = 140;
		else
			src.y = 0;

		break;
	}
	case pawnType::BISHOP:
	{
		src.x = 166;

		if (col == color::BLACK)
			src.y = 140;
		else
			src.y = 0;

		break;
	}
	case pawnType::QUEEN:
	{
		src.x = 83;

		if (col == color::BLACK)
			src.y = 140;
		else
			src.y = 0;

		break;
	}
	case pawnType::KING:
	{
		src.x = 0;

		if (col == color::BLACK)
			src.y = 140;
		else
			src.y = 0;

		break;
	}
	default:
		return;

	}
	
	SDL_SetRenderTarget(renderer, tex);
	SDL_RenderCopy(renderer, tex, &src, &dest);
	SDL_RenderPresent(renderer);
}



/*  implemet the move operation

void Pawn::move(SDL_Event& e)
{

	case pawnType::BLACK_PAWN:

}


*/


Pawn::~Pawn()
{

}

