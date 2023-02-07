#include "Button.h"
#include "SDL.h"
#include "Components.h"




Button::Button(int x, int y): sRect{x,y,128,64}, dRect{x,y,128,64}
{
	static SDL_Texture* t = IMG_LoadTexture(Game::renderer, "Button.png");
	texture = t;
	selected = false;
}

void Button::setXY(int x, int y)
{
	dRect.x = x;
	dRect.y = y;
}

void Button::draw()
{
	SDL_RenderCopy(Game::renderer, texture, &sRect, &dRect);

}
