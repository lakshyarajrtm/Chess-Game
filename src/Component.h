#pragma once

#include <SDL/SDL.h>
#include "Globals.h"
#include <iostream>


class Component
{

public:

	SDL_Surface* surf = nullptr;
	SDL_Texture* tex = nullptr; 

	Component();
	Component(const char* image);
	~Component();
	

};




class Board : public Component
{

public:
	Board();
	Board(const char* img);
	~Board();
	void DrawTexture();

	

};


class Pawn : public Component
{

public:
	Pawn();
	~Pawn();
	void DrawTexture();
	void update();

	SDL_Rect* src, * dest;
};