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



template <bool T> class GameObj
{

};

template<> class GameObj<true> : public Component
{
public:

	GameObj();
	explicit GameObj(const char*);
	GameObj(const GameObj&);
	GameObj(GameObj&&);
	GameObj& operator=(GameObj&);
	~GameObj();

	// methods
	void DrawTexture();
	void update();
	bool hasClicked();
	

	// stores piece type and color info
	pawnType type;
	color col;

	// store the block postion of a piece
	int xBlock, yBlock;

	// stores the src and dest for textures
	SDL_Rect src, dest;
};


template<> class GameObj<false> : public Component
{
public:

	// constructors
	GameObj();
	explicit GameObj(const char*);
	GameObj(const GameObj&);
	GameObj(GameObj&&);
	GameObj& operator=(const GameObj&);
	~GameObj();

	// methods
	void DrawTexture();

};



using Pawn = GameObj<true>;
using Board = GameObj<false>;