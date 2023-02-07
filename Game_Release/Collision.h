#pragma once
#include <SDL.h>

class ColliderComponent;

class Collision
{
public:
	static bool AABB(const SDL_Rect& recA, const SDL_Rect& recB);
	static bool AABB(const ColliderComponent& colA, const ColliderComponent& colB);
	static bool odraz(SDL_Rect& playerCol, const SDL_Rect& cCol, int arr[]);
	static bool HitEnemy(SDL_Rect& playerCol, const SDL_Rect& cCol);
	static bool BodyCheck(SDL_Rect& playerCol, const SDL_Rect& cCol, int arr[], int odrazOdSteny);
	static bool odrazBullet(SDL_Rect& playerCol, const SDL_Rect& cCol);
};