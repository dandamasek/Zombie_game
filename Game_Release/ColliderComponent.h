#pragma once
#include <string>
#include "SDL.h"
#include "Components.h"
#include "TextureManager.h"

class ColliderComponent : public Component
{
public:
	int collisionNumber = 16; //hitbox
	SDL_Rect collider;
	std::string tag;

	SDL_Texture* tex;
	SDL_Rect srcR, destR;

	TransformComponent* tranform;

	ColliderComponent(std::string t)
	{
		tag = t;
	}

	ColliderComponent(std::string t, int xpos, int ypos, int size)
	{
		tag = t;
		collider.x = xpos;
		collider.y = ypos;
		collider.h = collider.w = size;
	}


	void init() override
	{
		if (!entity->hasComponent<TransformComponent>())
		{
			entity->addComponent<TransformComponent>();
		}
		tranform = &entity->getComponent<TransformComponent>();

		tex = TextureManager::LoadTexture("assets/coltex.png");
		srcR = { 0,0,32,32 };
		destR = {collider.x, collider.y, collider.w, collider.h}; 
		
	}

	void update() override
	{
		if (tag != "terrain")
		{
			collider.x = static_cast<int>(tranform->position.x);
			collider.y = static_cast<int>(tranform->position.y);
			collider.w = ((tranform->width) * tranform->scale);
			collider.h = ((tranform->height) * tranform->scale);
		}
	
		destR.x = collider.x - Game::camera.x;
		destR.y = collider.y - Game::camera.y;

	}

	
	void draw() override
	{
		//TextureManager::Draw(tex, srcR, destR, SDL_FLIP_NONE);       //vykresluje hitbox zluty
	}

private:

}; 