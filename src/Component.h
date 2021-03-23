#pragma once

#include <SDL/SDL.h>
#include "Globals.h"
#include <iostream>


// enum for type of pieces




class Component
{

public:

	SDL_Surface* surf = nullptr;
	SDL_Texture* tex = nullptr; 

	Component();
	Component(const char*);
	virtual ~Component();
	

};




class Board : public Component
{

public:
	Board();
	Board(const char*);
	~Board();
	void DrawTexture();

	

};


class Pawn : public Component
{

public:

	Pawn();
	Pawn(const char* );
	~Pawn();
	void DrawTexture();
	void update();
	//void move(SDL_Event&);             to implement

	pawnType type;
	color col;

	SDL_Rect src, dest;
};