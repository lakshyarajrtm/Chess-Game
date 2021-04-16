#pragma once

#include <SDL/SDL.h>
#include <iostream>
#include "Globals.h"



class Component
{

public:
	// constructors
	Component();
	explicit Component(const char*) noexcept;
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
	// constructors
	GameObj();
	explicit GameObj(const char*) noexcept;

	GameObj(const GameObj&) noexcept;

	GameObj(GameObj&&) noexcept;
	~GameObj();

	// methods
	void DrawTexture();
	void update();
	void onClicked();
	

	// stores piece type and color info
	pawnType type;
	color col;

	// store the block postion of a piece
	int xBlock, yBlock;

	bool clicked;
	// stores the src and dest for textures
	SDL_Rect src, dest;
};


template<> class GameObj<false> : public Component
{
public:

	// constructors
	GameObj();
	explicit GameObj(const char*) noexcept;
	~GameObj();

	// methods
	void DrawTexture();

};

using Pawn = GameObj<true>;
using Board = GameObj<false>;

