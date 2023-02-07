#pragma once

#include "ECS.h"
#include "Components.h"
#include "Vector2D.h"
#include <cmath>

class EnemyMove : public Component
{
public:
	TransformComponent* transform;
	SpriteComponent* sprite;
	int speed;
	int nowRoutePoint = 0;
	std::vector<Vector2D> routePoints;

	void init() override
	{
		transform = &entity->getComponent<TransformComponent>();
		sprite = &entity->getComponent<SpriteComponent>();
	}

	EnemyMove()
	{
	}

	EnemyMove(std::vector<Vector2D>routePoints)
	{
		this->routePoints = routePoints;
	}
	
	~EnemyMove();

	void update() override
	{
		if (!transform->isAlive)
			sprite->Play("Dead");

		moveEnemy(routePoints[nowRoutePoint], routePoints.size());
	}

	void followPlayer(std::vector<Vector2D>stopa)
	{
		routePoints = stopa;
		nowRoutePoint = 0;
	}

	void moveEnemy(Vector2D end,int RoutePoints)
	{
		if (transform->isAlive)
		{
			Vector2D akthod;
			int xMove, yMove;
			int posunx = speed;
			int posuny = speed;
			akthod = entity->getComponent<TransformComponent>().position;

			speed = entity->getComponent<TransformComponent>().speed;

			xMove = akthod.x - end.x;
			yMove = akthod.y - end.y;

			if (abs(abs(end.x) - abs(akthod.x)) < speed)
				posunx = abs(abs(end.x) - abs(akthod.x));

			if (abs(abs(end.y) - abs(akthod.y)) < speed)
				posuny = abs(abs(end.y) - abs(akthod.y));



			if (abs(end.x) - abs(akthod.x) == 0 && abs(end.y) - abs(akthod.y) == 0)
			{
				if (nowRoutePoint == RoutePoints - 1)
					nowRoutePoint = 0;
				else
					nowRoutePoint++;
			}

			if (xMove < 0)
			{
				sprite->spriteFlip = SDL_FLIP_NONE;
				akthod.x += posunx;
				sprite->Play("WalkVer");
			}
			else if (xMove > 0)
			{
				sprite->spriteFlip = SDL_FLIP_NONE;
				akthod.x += -posunx;
				sprite->Play("WalkVer");
				sprite->spriteFlip = SDL_FLIP_HORIZONTAL;
			}

			if (yMove < 0)
			{
				sprite->spriteFlip = SDL_FLIP_NONE;
				akthod.y += posuny;
				sprite->Play("WalkHor");
				sprite->spriteFlip = SDL_FLIP_VERTICAL;
			}
			else if (yMove > 0)
			{
				sprite->spriteFlip = SDL_FLIP_NONE;
				akthod.y += -posuny;
				sprite->Play("WalkHor");
			}

			transform->position = akthod;
		}
	}




private:

};


