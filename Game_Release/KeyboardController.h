#pragma once

#include "Game.h"
#include "ECS.h"
#include "Components.h"

class KeyboardController : public Component
{
public:
	TransformComponent* transform;
	SpriteComponent* sprite;
	bool fire = false;
	bool fireRelesed = true;    //zamezeni davce
	int moveSpeed = 0;   //scitani rychlosti proektilu pri chuzi
	bool eActivated = false;

	void init() override

	{
		transform = &entity->getComponent<TransformComponent>();
		sprite = &entity->getComponent<SpriteComponent>();
	}


	void update() override
	{
		if (Game::event.type == SDL_KEYDOWN && transform->isAlive)   //is pressed
		{
			switch (Game::event.key.keysym.sym)
			{
			case SDLK_w:
				Game::event.key.keysym.sym = SDLK_w;
				sprite->spriteFlip = SDL_FLIP_NONE;
				transform->velocity.y = -1;
				transform->smer.y = -1;
				transform->smer.x = 0;
				sprite->Play("WalkHor");
				moveSpeed = transform->speed;
				w = true;
				break;
			case SDLK_a:
				sprite->spriteFlip = SDL_FLIP_NONE;
				transform->velocity.x = -1;
				transform->smer.x = -1;
				transform->smer.y = 0;
				sprite->Play("WalkVer");
				sprite->spriteFlip = SDL_FLIP_HORIZONTAL;
				moveSpeed = transform->speed;
				a = true;
				break;
			case SDLK_d:
				sprite->spriteFlip = SDL_FLIP_NONE;
				transform->velocity.x = 1;
				transform->smer.x = 1;
				transform->smer.y = 0;
				sprite->Play("WalkVer");
				moveSpeed = transform->speed;
				d = true;
				break;
			case SDLK_s:
				sprite->spriteFlip = SDL_FLIP_NONE;
				transform->velocity.y = 1;
				transform->smer.y = 1;
				transform->smer.x = 0;
				sprite->Play("WalkHor");
				sprite->spriteFlip = SDL_FLIP_VERTICAL;
				moveSpeed = transform->speed;
				s = true;
				break;
			case SDLK_SPACE:
				if (fireRelesed)
				{
					fire = true;
				}
				fireRelesed = false;
				break;
			case SDLK_LSHIFT:   //zatim delat nebudu musel bych pak upravit collision
			//	transform->speed = 5;
				break;
			case SDLK_e:
				eActivated = true;
				if (transform->position.x >= 2176 && transform->position.x <= 2272 && transform->position.y >= 1886 && transform->position.y <= 1982)    //teleport
				{
					transform->position.x = 181;
					transform->position.y = 1136;

				}
				else if (transform->position.x >= 128 && transform->position.x <= 224 && transform->position.y >= 1088 && transform->position.y <= 1184)
				{
					transform->position.x = 2195;
					transform->position.y = 1889;
				}

				break;
			default:
				break;
			}

		}
		else if (Game::event.type == SDL_KEYUP)
		{
			switch (Game::event.key.keysym.sym)
			{
			case SDLK_w:
				if (transform->isAlive)
				{
					w = false;
					transform->velocity.y = 0;
					if (w || s || d || a)
						movement();
					else
						sprite->Play("IdleVer");
					moveSpeed = 0;
				}
				break;
			case SDLK_a:
				if (transform->isAlive)
				{
					a = false;
					transform->velocity.x = 0;
					if (w || s || d || a)
						movement();
					else
					{
						sprite->Play("IdleHor");
						sprite->spriteFlip = SDL_FLIP_HORIZONTAL;
					}
					moveSpeed = 0;
				}
				break;
			case SDLK_d:
				if (transform->isAlive)
				{
					d = false;
					transform->velocity.x = 0;
					if (w || s || d || a)
						movement();
					else
						sprite->Play("IdleHor");
					moveSpeed = 0;
				}
				break;
			case SDLK_s:
				if (transform->isAlive)
				{
					s = false;
					transform->velocity.y = 0;
					if (w || s || d || a)
						movement();
					else
					{
						sprite->Play("IdleVer");
						sprite->spriteFlip = SDL_FLIP_VERTICAL;
					}
					moveSpeed = 0;
				}
				break;
			case SDLK_ESCAPE:
				Game::isRunning = false;
				break;
			case SDLK_SPACE:
				if (transform->isAlive)
				{
					fire = false;
					fireRelesed = true;
				}
				break;
			case SDLK_e:
				if (transform->isAlive)
				{
					eActivated = false;
				}
			default:
				break;
			}
		}
		else if (!transform->isAlive)
		{
			transform->velocity.x = 0;
			transform->velocity.y = 0;
			sprite->Play("Dead");
		}
	}

	void movement()
	{
		if (w)
		{
			sprite->Play("WalkHor");
			transform->velocity.y = -1;
			transform->smer.y = -1;
			transform->smer.x = 0;
		}
		else if (s)
		{
			sprite->Play("WalkHor");
			sprite->spriteFlip = SDL_FLIP_VERTICAL;
			transform->velocity.y = 1;
			transform->smer.y = 1;
			transform->smer.x = 0;
		}
		else if (a)
		{
			sprite->Play("WalkVer");
			sprite->spriteFlip = SDL_FLIP_HORIZONTAL;
			transform->velocity.x = -1;
			transform->smer.x = -1;
			transform->smer.y = 0;
		}
		else if (d)
		{
			sprite->Play("WalkVer");
			transform->velocity.x = 1;
			transform->smer.x = 1;
			transform->smer.y = 0;
		}
	}



	private:
		Uint32 frameStart = SDL_GetTicks();
		bool w = false, s = false, d = false, a = false; //pressed wasd

};