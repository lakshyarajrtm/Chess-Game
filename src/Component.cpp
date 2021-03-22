#include "Component.h"

#include <fstream>

// layout of board



Component::Component(const char* image)
{
	surf = SDL_LoadBMP(image);
	tex = SDL_CreateTextureFromSurface(renderer, surf);
	SDL_FreeSurface(surf);
	surf = nullptr;
	

}


Component::~Component()
{
	delete(tex);
	tex = nullptr;
}


// implementation for board


Board::Board(const char* img):Component(img)
{
}

void Board::DrawTexture() 
{
	SDL_RenderClear(renderer);
	SDL_SetRenderTarget(renderer, tex);
	SDL_RenderCopy(renderer, tex, NULL, NULL);
	SDL_RenderPresent(renderer);
}

Board::~Board()
{

}


// implementation of pawn

