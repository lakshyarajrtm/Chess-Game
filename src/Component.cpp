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
	SDL_FreeSurface(surf);
	tex = nullptr;
	
}

// implementation for board

Board::GameObj(const char* img) : Component(img)
{

}

void Board::DrawTexture() 
{
	
	SDL_SetRenderTarget(renderer, tex);
	SDL_RenderCopy(renderer, tex, NULL, NULL);
	
}

Board::~GameObj()
{
	
}


// implementation for pawn

Pawn::GameObj(const char* image) : Component(image), xBlock(0), yBlock(0),
								type(pawnType::NIL), col(NIL), clicked(false)
{
	src.h = 120;
	src.w = 80;
	dest.h = 60;
	dest.w = 60;
}

void Pawn::DrawTexture()
{
	int xoffset = 10;
	int yoffset = 30;

	switch (type)
	{

		case pawnType::PAWN:
		{
			src.x = 416 + xoffset;

			if (col == BLACK)
				src.y = 140;
			else
				src.y = yoffset;
			break;
		}
		case pawnType::ROOK:
		{
			src.x = 333 + xoffset;

			if (col == BLACK)
				src.y = 140;
			else
				src.y = yoffset;
			break;
		}
		case pawnType::KNIGHT:
		{
			src.x = 250 + xoffset;

			if (col == BLACK)
				src.y = 140;
			else
				src.y = yoffset;

			break;
		}
		case pawnType::BISHOP:
		{
			src.x = 166 + xoffset;

			if (col == BLACK)
				src.y = 140;
			else
				src.y = yoffset;

			break;
		}
		case pawnType::QUEEN:
		{
			src.x = 83 + xoffset;

			if (col == BLACK)
				src.y = 140;
			else
				src.y = yoffset;

			break;
		}
		case pawnType::KING:
		{
			src.x = 0 + xoffset;

			if (col == BLACK)
				src.y = 140;
			else
				src.y = yoffset;

			break;
		}

		default:
			return;
	}
	
	SDL_SetRenderTarget(renderer, tex);
	SDL_RenderCopy(renderer, tex, &src, &dest);
	
}


void Pawn::onClicked()				// to implement, this method will make the pawn move
{
	
}


Pawn::~GameObj()
{
	
}

