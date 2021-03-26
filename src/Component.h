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
	explicit Component(const char*);
	virtual ~Component();
	

};




class Board : public Component
{

public:

	// constructors
	Board();
	explicit Board(const char*);
	Board(const Board&);
	Board(Board&&);
	Board& operator=(const Board&);
	~Board();

	// methods
	void DrawTexture();

	

};


class Pawn : public Component
{

public:

	Pawn();
	explicit Pawn(const char* );
	Pawn(const Pawn&);
	Pawn(Pawn&&);
	Pawn& operator=(Pawn&);
	~Pawn();
	void DrawTexture();
	void update();
	//void move(SDL_Event& e);

	pawnType type;
	color col;

	int xBlock, yBlock;
	SDL_Rect src, dest;
};