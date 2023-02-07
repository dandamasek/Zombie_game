#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* texturesheet, int x, int y)
{
	objTexture = TextureManager::LoadTexture(texturesheet);

	xpos = x;
	ypos = y;
}

void GameObject::Update()
{
	xpos++;
	ypos++;

	srcRect.h = 1500;
	srcRect.w = 500;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w /15;
	destRect.h = srcRect.h / 15;
}

void GameObject::Render()
{
	SDL_RenderCopy(Game::renderer,objTexture, &srcRect, &destRect);
}