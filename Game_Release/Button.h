#pragma once
#include "Game.h"

class Button
{
public:
	SDL_Texture* texture;
	SDL_Rect sRect, dRect;
	bool selected;

	Button() {};
	//pass in 
	Button(int x, int y);

	void setXY(int x, int y);
	void draw();
	~Button() {};



};

 