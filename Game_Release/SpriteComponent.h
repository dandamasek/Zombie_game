#pragma once

#include "Components.h"
#include "SDL.h"
#include "TextureManager.h"
#include "Animation.h"
#include <map>
#include "AssetManager.h"

class SpriteComponent : public Component
{
private:
	TransformComponent* transform;
	SDL_Texture* texture;
	SDL_Rect srcRect, desRect;

	bool animated = false;
	int frames = 0;
	int speed = 100;
	

public:

	int animIndex = 0;

	std::map<const char*, Animation> animations;

	SDL_RendererFlip spriteFlip = SDL_FLIP_NONE;


	SpriteComponent() = default;

	SpriteComponent(std::string id)
	{

		setTex(id);
	}

	SpriteComponent(std::string id, bool isAnimated)
	{
		animated = isAnimated;

		Animation idleHor = Animation(4, 4, 400);
		Animation idleVer = Animation(5, 4, 400);
		Animation walkHor = Animation(2, 8, 100);
		Animation walkVer = Animation(0, 8, 100);
		Animation dead = Animation(6, 1, 500);

		animations.emplace("IdleHor", idleHor);
		animations.emplace("IdleVer", idleVer);
		animations.emplace("WalkHor", walkHor);
		animations.emplace("WalkVer", walkVer);
		animations.emplace("Dead", dead);

		Play("IdleVer");

		setTex(id);
	}

	~SpriteComponent()
	{}

	void setTex(std::string id)
	{
		texture = Game::assets->GetTexture(id);
	}

	void init() override
	{
		transform = &entity->getComponent<TransformComponent>();

		srcRect.x = srcRect.y = 0;
		srcRect.w = transform->width;
		srcRect.h = transform->height;
	}

	void update() override
	{
		if (animated)
		{
			srcRect.x = srcRect.w * static_cast<int>((SDL_GetTicks() / speed) % frames);
		}  

		srcRect.y = animIndex * transform->height;
		 
		desRect.x = static_cast<int>(transform->position.x) - Game::camera.x;
		desRect.y = static_cast<int>(transform->position.y) - Game::camera.y;
		desRect.w = transform->width * transform->scale;
		desRect.h = transform->height * transform->scale;

	}

	void draw() override
	{
		TextureManager::Draw(texture, srcRect, desRect, spriteFlip);
	} 

	void Play(const char* aniName)
	{
		frames = animations[aniName].frames;
		animIndex = animations[aniName].index;
		speed = animations[aniName].speed;	
	}
};