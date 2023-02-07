#pragma once

#include "ECS.h"
#include "AssetManager.h"
#include "Game.h";
#include <SDL.h>
#include <SDL_ttf.h>
#include <string>


class TextComponent : public Component {
private:

	SDL_Color textColour;
	std::string message;
	std::string mFont;


public:
	SDL_Texture* texText;
	SDL_Rect destRect;

	TextComponent(int xpos, int ypos, std::string text, std::string font, SDL_Color& colour) : message(text), mFont(font), textColour(colour)
	{
		destRect.x = xpos;
		destRect.y = ypos;

		setText(message, font);
	}

	void setText(std::string text, std::string font)
	{
		SDL_DestroyTexture(texText);
		SDL_Surface* surface = TTF_RenderText_Blended(Game::assets->GetFont(font), text.c_str(), textColour);
		texText = SDL_CreateTextureFromSurface(Game::renderer, surface);
		SDL_FreeSurface(surface);

		SDL_QueryTexture(texText, nullptr, nullptr, &destRect.w, &destRect.h);
	}

	void draw() override
	{
		SDL_RenderCopy(Game::renderer, texText, nullptr, &destRect);
	}
};
