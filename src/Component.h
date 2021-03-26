#pragma once

#include <SDL/SDL.h>
#include "Globals.h"
#include <iostream>



class Component
{

public:
	// constructors
	Component();
	explicit Component(const char*);
	virtual ~Component();
	

	SDL_Surface* surf = nullptr;
	SDL_Texture* tex = nullptr;

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

	// methods
	void DrawTexture();
	void update();
	//void move(SDL_Event& e);

	// stores piece type and color info
	pawnType type;
	color col;

	// store the block postion of a piece
	int xBlock, yBlock;

	// stores the src and dest for textures
	SDL_Rect src, dest;
};