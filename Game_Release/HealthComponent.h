#pragma once

#include "ECS.h"
#include "Components.h"
#include "Vector2D.h"

class HealthComponent : public Component
{
public:
	int index = 0;
	Vector2D pos;
	TransformComponent* transform;

	HealthComponent(int i)
	{
		index = i;
	};

	~HealthComponent(); 


	void init() override
	{

	}
	void update() override
	{
	}
};

