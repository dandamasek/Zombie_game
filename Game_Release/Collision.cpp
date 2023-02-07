#include "Collision.h"
#include "ColliderComponent.h"

bool Collision::AABB(const SDL_Rect& recA, const SDL_Rect& recB)
{
	if (
		recA.x + recA.w >= recB.x &&
		recB.x + recB.w >= recA.x &&
		recA.y + recA.h >= recB.y &&
		recB.y + recB.h >= recA.y
		)
	{
		return true;
	}

	return false;
}

bool Collision::odraz(SDL_Rect& playerCol, const SDL_Rect& cCol, int arr[2])
{
	int xbod = playerCol.x + (playerCol.w / 2.3);
	int ybod = playerCol.y + (playerCol.h / 2.3);

	// leps hitboxy
	int odrazOdSteny = 7;
	int colliBorder = 30;

	if (ybod >= cCol.y && ybod <= cCol.y + cCol.h && xbod >= cCol.x - colliBorder && xbod <= cCol.x + colliBorder)
	{
		arr[0] = -odrazOdSteny;
		return true;
	}
	else if (ybod >= cCol.y && ybod <= cCol.y + cCol.h && xbod >= (cCol.x + cCol.w) - colliBorder && xbod <= (cCol.x + cCol.w) + colliBorder)
	{
		arr[0] = odrazOdSteny;
		return true;
	}

	else if (xbod > cCol.x && xbod <= cCol.x + cCol.w && ybod >= (cCol.y + cCol.h) - colliBorder && ybod <= (cCol.y + cCol.h) + colliBorder)
	{
		arr[1] = odrazOdSteny;
		return true;
	}

	else if (xbod > cCol.x && xbod <= cCol.x + cCol.w && ybod >= (cCol.y) - colliBorder && ybod <= (cCol.y) + colliBorder)
	{
		arr[1] = -odrazOdSteny;
		return true;
	}
	else
		return false;
}

bool Collision::odrazBullet(SDL_Rect& playerCol, const SDL_Rect& cCol)
{
	int xbod = playerCol.x + (playerCol.w / 2);
	int ybod = playerCol.y + (playerCol.h / 2);

	if (ybod >= cCol.y && ybod <= cCol.y + cCol.h && xbod >= cCol.x - 5 && xbod <= cCol.x + 5)
		return true;
	else if (ybod >= cCol.y && ybod <= cCol.y + cCol.h && xbod >= (cCol.x + cCol.w) - 5 && xbod <= (cCol.x + cCol.w) + 5)
		return true;

	else if (xbod > cCol.x && xbod <= cCol.x + cCol.w && ybod >= (cCol.y + cCol.h) - 5 && ybod <= (cCol.y + cCol.h) + 5)
		return true;

	else if (xbod > cCol.x && xbod <= cCol.x + cCol.w && ybod >= (cCol.y) - 5 && ybod <= (cCol.y) + 5)
		return true;
	else
		return false;
}

bool Collision::BodyCheck(SDL_Rect& playerCol, const SDL_Rect& cCol, int arr[2], int odrazOdSteny)
{
	int xbod = playerCol.x + (playerCol.w / 2.3);
	int ybod = playerCol.y + (playerCol.h / 2.3);
	int collBorder = 3;

	if (ybod >= cCol.y && ybod <= cCol.y + cCol.h && xbod >= cCol.x - collBorder && xbod <= cCol.x + collBorder)
	{
		arr[0] = -odrazOdSteny;
		return true;
	}
	else if (ybod >= cCol.y && ybod <= cCol.y + cCol.h && xbod >= (cCol.x + cCol.w) - collBorder && xbod <= (cCol.x + cCol.w) + collBorder)
	{
		arr[0] = odrazOdSteny;
		return true;
	}

	else if (xbod > cCol.x && xbod <= cCol.x + cCol.w && ybod >= (cCol.y + cCol.h) - collBorder && ybod <= (cCol.y + cCol.h) + collBorder)
	{
		arr[1] = odrazOdSteny;
		return true;
	}

	else if (xbod > cCol.x && xbod <= cCol.x + cCol.w && ybod >= (cCol.y) - collBorder && ybod <= (cCol.y) + collBorder)
	{
		arr[1] = -odrazOdSteny;
		return true;
	}
	else
		return false;
}

bool Collision::HitEnemy(SDL_Rect& playerCol, const SDL_Rect& cCol)   
{
	int xbod = playerCol.x + (playerCol.w / 2);
	int ybod = playerCol.y + (playerCol.h / 2);


	if (ybod >= cCol.y && ybod <= cCol.y + cCol.h && xbod >= cCol.x - 2 && xbod <= cCol.x + 2)
		return true;

	else if (ybod >= cCol.y && ybod <= cCol.y + cCol.h && xbod >= (cCol.x + cCol.w) - 2 && xbod <= (cCol.x + cCol.w) + 2)
		return true;

	else if (xbod > cCol.x && xbod <= cCol.x + cCol.w && ybod >= (cCol.y + cCol.h) - 2 && ybod <= (cCol.y + cCol.h) + 2)
		return true;

	else if (xbod > cCol.x && xbod <= cCol.x + cCol.w && ybod >= (cCol.y) - 2 && ybod <= (cCol.y) + 2)
		return true;
	else
		return false;
}

bool Collision::AABB(const ColliderComponent& colA, const ColliderComponent& colB)
{
	if (AABB(colA.collider, colB.collider))
	{
		std::cout << colA.tag << " hit: " << colB.tag << std::endl;
		return true;
	}
	else
	{
		return false;
	}
}
