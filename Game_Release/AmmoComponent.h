#pragma once

#include "ECS.h"
#include "Components.h"
#include "Vector2D.h"

class AmmoComponent : public Component
{
public:
	int index = 0;
	Vector2D pos;
	TransformComponent* transform;

	AmmoComponent(int i)
	{
		index = i;
	};

	AmmoComponent()
	{
	};

	~AmmoComponent();


	void init() override
	{

	}
	void update() override
	{

	}
};
