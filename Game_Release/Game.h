#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include <vector>
#include "Button.h"
#include <SDL_ttf.h>

class AssetManager;
class ColliderComponent;

class Game {
public:

	Game();
	~Game();

	void init(const char* title, int width, int height, bool fullscreen);
	
	void handleEvents();
	void update();
	void render();
	void clean();
	bool runnning() { return isRunning; }

	static SDL_Renderer *renderer;
	static SDL_Event event;
	static bool isRunning;
	static SDL_Rect camera;
	static AssetManager* assets;


	enum groupLabels : std::size_t
	{
		groupMap,
		groupPlayers,
		groupColliders,
		groupProjectiles,
		groupEnemy,
		groupHearths,
		groupAmmo,
		groupBarrel,
		groupBoss,
		groupText
	};

	void EnemyRoutes();

private:
	int cnt=0;
	SDL_Window *window;
};




