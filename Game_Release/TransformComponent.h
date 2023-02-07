#pragma once
#include "Components.h"
#include "Vector2D.h"


class TransformComponent : public Component
{
public:

	Vector2D position;
	Vector2D velocity;
	Vector2D smer;
	bool isAlive = true;
	int height = 32;  //colision size
	int width = 32;
	int scale = 1;
	int speed = 3;
	int sumHearth=0;
	int ammo = 0;

	bool followPlayer = false;
	bool isFollowed = false;
	std::vector<Vector2D> stopa;

	TransformComponent()
	{
		position.Zero();
	}

	TransformComponent(int sc)
	{
		position.x = 340;
		position.y = 265;
		scale = sc;
	}

	TransformComponent(float x, float y)
	{
		position.Zero();
	}

	TransformComponent(int h, int w, int sc)
	{
		height = h;
		width = w;
		scale = sc;
	}


	TransformComponent(float x, float y, int h, int w, int sc)
	{
		position.x = x;
		position.y = y;
		height = h;
		width = w;
		scale = sc;
	}

	TransformComponent(float x, float y, int h, int w,int sc, int sh)  //pro enemy
	{ 
		position.x = x;
		position.y = y;
		height = h;
		width = w;
		scale = sc;
		sumHearth = sh;
	}

	TransformComponent(float x, float y, int h, int w, int sc, int sh, int amm)  //pro hrace
	{
		position.x = x;
		position.y = y;
		height = h;
		width = w;
		scale = sc;
		sumHearth = sh;
		ammo = amm;
	}

	void init() override
	{
		velocity.Zero();
		stopa.push_back(position);
	}
	void update() override
	{	
		position.x += velocity.x * speed;
		position.y += velocity.y * speed;

		if (isFollowed)
		{
			stopa.push_back(position);

			if (stopa.size() > 15)
				stopa.erase(stopa.begin(),stopa.end() -1);

		}


	}

};