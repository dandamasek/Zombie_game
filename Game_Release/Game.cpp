#include "Game.h"
#include "TextureManager.h"
#include "Map.h"
#include "Components.h"
#include "Vector2D.h"
#include "Collision.h"
#include "AssetManager.h"
#include <vector>
#include "AmmoComponent.h"


Map* map;
Manager manager;


SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;
bool playerWin = false;

SDL_Rect Game::camera = { 0,0,2080,2280};

AssetManager* Game::assets = new AssetManager(&manager);

bool Game::isRunning;

auto& player(manager.addEntity());
auto& text(manager.addEntity());


Game::Game()
{}

Game::~Game()
{}

void Game::EnemyRoutes()
{

}

void Game::init(const char *title, int width, int height, bool fullscreen)
{
	int flags = 0;

	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); 
		}
		isRunning = true;
		if (TTF_Init() == 0)
			std::cout << "TTF_ok";
	}


	assets->AddTexture("terrain", "assets/terrain3.png");
	assets->AddTexture("player", "assets/playerAnimation.png");
	assets->AddTexture("projectile", "assets/proj.png");
	assets->AddTexture("enemak", "assets/enemyAnimation.png");
	assets->AddTexture("hearth", "assets/hearth.png");
	assets->AddTexture("ammo", "assets/ammo.png");
	assets->AddTexture("barrel", "assets/barrel1.png");
	assets->AddTexture("boss", "assets/enemyAnimationBoss.png");
	assets->AddFont("silkscreen", "fonts/Arial.ttf", 36);
	

	map = new Map("terrain",3,32);

	map->LoadMap("assets/map2.map", 30, 30);

	player.addComponent<TransformComponent>(1061.0f, 1604.0f, 32, 32, 4,10,5);
	player.addComponent<SpriteComponent>("player",true);
	player.addComponent<KeyboardController>();
	player.addComponent<ColliderComponent>("player");
	player.addGroup(groupPlayers);



	std::vector<Vector2D> enemy1Route;                          //nacteni trasy pro obchuzky nepratel
	enemy1Route.push_back(Vector2D(923, 791));
	enemy1Route.push_back(Vector2D(923, 647));
	enemy1Route.push_back(Vector2D(2150, 647));
	enemy1Route.push_back(Vector2D(2150, 761));

	std::vector<Vector2D> enemy2Route;
	enemy2Route.push_back(Vector2D(1157, 893));
	enemy2Route.push_back(Vector2D(920, 893));
	enemy2Route.push_back(Vector2D(920, 1310));
	enemy2Route.push_back(Vector2D(1178, 1310));
	

	std::vector<Vector2D> enemy3Route;                        
	enemy3Route.push_back(Vector2D(2135, 568));
	enemy3Route.push_back(Vector2D(2135, 70));
	enemy3Route.push_back(Vector2D(2684, 58));
	enemy3Route.push_back(Vector2D(2678, 568));

	std::vector<Vector2D> enemy4Route;                       
	enemy4Route.push_back(Vector2D(2517, 169));
	enemy4Route.push_back(Vector2D(2517, 521));
	enemy4Route.push_back(Vector2D(2285, 470));
	enemy4Route.push_back(Vector2D(2258, 227));

	std::vector<Vector2D> enemy5Route;                       
	enemy5Route.push_back(Vector2D(1009, 1232));
	enemy5Route.push_back(Vector2D(1013, 968));
	enemy5Route.push_back(Vector2D(1079, 968));
	enemy5Route.push_back(Vector2D(1079, 1241));

	std::vector<Vector2D> enemyBossRoute;                      
	enemyBossRoute.push_back(Vector2D(605, 1685));
	enemyBossRoute.push_back(Vector2D(80, 1703));
	enemyBossRoute.push_back(Vector2D(260, 1805));
	enemyBossRoute.push_back(Vector2D(443, 1805));
	enemyBossRoute.push_back(Vector2D(734, 1844));
	enemyBossRoute.push_back(Vector2D(956, 1967));
	enemyBossRoute.push_back(Vector2D(962, 2288));
	enemyBossRoute.push_back(Vector2D(962, 2288));
	enemyBossRoute.push_back(Vector2D(431, 2270));
	enemyBossRoute.push_back(Vector2D(116, 2201));
	enemyBossRoute.push_back(Vector2D(410, 1829));

	std::vector<Vector2D> enemy6Route;
	enemy6Route.push_back(Vector2D(608, 1412));
	enemy6Route.push_back(Vector2D(737, 1175));
	enemy6Route.push_back(Vector2D(743, 1037));
	enemy6Route.push_back(Vector2D(608, 1412));
	enemy6Route.push_back(Vector2D(494, 1088));
	enemy6Route.push_back(Vector2D(608, 1412));
	enemy6Route.push_back(Vector2D(461, 1403));

	std::vector<Vector2D> enemy7Route;
	enemy7Route.push_back(Vector2D(1992, 1427));
	enemy7Route.push_back(Vector2D(1992, 1634));
	enemy7Route.push_back(Vector2D(1704, 1634));
	enemy7Route.push_back(Vector2D(1704, 1415));

	std::vector<Vector2D> enemy8Route;
	enemy8Route.push_back(Vector2D(2091, 952));
	enemy8Route.push_back(Vector2D(2661, 952));
	enemy8Route.push_back(Vector2D(2661, 1615));
	enemy8Route.push_back(Vector2D(2109, 1615));

	std::vector<Vector2D> enemy9Route;
	enemy9Route.push_back(Vector2D(1046, 718));
	enemy9Route.push_back(Vector2D(1961, 718));

	std::vector<Vector2D> enemy10Route;
	enemy10Route.push_back(Vector2D(2202, 1504));
	enemy10Route.push_back(Vector2D(2565, 1504));
	enemy10Route.push_back(Vector2D(2565, 1063));
	enemy10Route.push_back(Vector2D(2193, 1063));

	std::vector<Vector2D> enemy11Route;
	enemy11Route.push_back(Vector2D(2651, 2564));
	enemy11Route.push_back(Vector2D(2678, 2690));
	enemy11Route.push_back(Vector2D(1886, 2696));
	enemy11Route.push_back(Vector2D(1910, 2369));
	enemy11Route.push_back(Vector2D(1904, 2555));
	enemy11Route.push_back(Vector2D(2651, 2564));

	std::vector<Vector2D> enemy12Route;
	enemy12Route.push_back(Vector2D(2285, 2348));
	enemy12Route.push_back(Vector2D(2297, 1808));
	enemy12Route.push_back(Vector2D(2075, 1808));
	enemy12Route.push_back(Vector2D(2075, 2387));

	std::vector<Vector2D> enemy13Route;
	enemy13Route.push_back(Vector2D(2195, 2000));
	enemy13Route.push_back(Vector2D(2195, 2375));

	std::vector<Vector2D> enemy14Route;
	enemy14Route.push_back(Vector2D(220, 733));
	enemy14Route.push_back(Vector2D(754, 733));
	enemy14Route.push_back(Vector2D(754, 889));
	enemy14Route.push_back(Vector2D(49, 889));

	std::vector<Vector2D> enemy15Route;
	enemy15Route.push_back(Vector2D(1164, 1788));
	enemy15Route.push_back(Vector2D(1887, 1785));
	enemy15Route.push_back(Vector2D(1932, 2223));
	enemy15Route.push_back(Vector2D(1719, 2223));
	enemy15Route.push_back(Vector2D(1719, 2688));
	enemy15Route.push_back(Vector2D(1167, 2688));
	enemy15Route.push_back(Vector2D(1164, 1788));
	

	std::vector<Vector2D> enemy16Route;
	enemy16Route.push_back(Vector2D(1055, 2483));
	enemy16Route.push_back(Vector2D(1058, 2387));
	enemy16Route.push_back(Vector2D(920, 2444));
	enemy15Route.push_back(Vector2D(1193, 2444));

	std::vector<Vector2D> enemy17Route;
	enemy17Route.push_back(Vector2D(917, 2561));
	enemy17Route.push_back(Vector2D(968, 2708));
	enemy17Route.push_back(Vector2D(77, 2708));
	enemy17Route.push_back(Vector2D(77, 2342));
	enemy17Route.push_back(Vector2D(787, 2425));
	enemy17Route.push_back(Vector2D(787, 2561));

	std::vector<Vector2D> enemy18Route;
	enemy18Route.push_back(Vector2D(1793, 1910));
	enemy18Route.push_back(Vector2D(1355, 1919));
	enemy18Route.push_back(Vector2D(1385, 2522));
	enemy18Route.push_back(Vector2D(1793, 1910));
	enemy18Route.push_back(Vector2D(1553, 2033));



	

	assets->CreateBoss(Vector2D(410.0f, 1829.0f), 2, "boss", enemyBossRoute);

	assets->CreateEnemy(enemy1Route[0], 2, "enemak",enemy1Route);       //vytvoreni enemy
	assets->CreateEnemy(enemy2Route[0], 3, "enemak", enemy2Route);
	assets->CreateEnemy(enemy3Route[0], 2, "enemak", enemy3Route);
	assets->CreateEnemy(enemy4Route[0], 4, "enemak", enemy4Route);
	assets->CreateEnemy(enemy5Route[0], 2, "enemak", enemy5Route);
	assets->CreateEnemy(enemy6Route[0], 4, "enemak", enemy6Route);
	assets->CreateEnemy(enemy7Route[0], 2, "enemak", enemy7Route);
	assets->CreateEnemy(enemy8Route[0], 2, "enemak", enemy8Route);
	assets->CreateEnemy(enemy9Route[0], 4, "enemak", enemy9Route);
	assets->CreateEnemy(enemy10Route[0], 2, "enemak", enemy10Route);
	assets->CreateEnemy(enemy11Route[0], 2, "enemak", enemy11Route);
	assets->CreateEnemy(enemy12Route[0], 2, "enemak", enemy12Route);
	assets->CreateEnemy(enemy13Route[0], 3, "enemak", enemy13Route);
	assets->CreateEnemy(enemy14Route[0], 2, "enemak", enemy14Route);
	assets->CreateEnemy(enemy15Route[0], 3, "enemak", enemy15Route);
	assets->CreateEnemy(enemy16Route[0], 2, "enemak", enemy16Route);
	assets->CreateEnemy(enemy17Route[0], 4, "enemak", enemy17Route);
	assets->CreateEnemy(enemy18Route[0], 2, "enemak", enemy18Route);


	assets->CreateBarrel(Vector2D(830, 1406), "barrel");
	assets->CreateBarrel(Vector2D(1280, 1405), "barrel");
	assets->CreateBarrel(Vector2D(2078, 60), "barrel");
	assets->CreateBarrel(Vector2D(64, 735), "barrel");
	assets->CreateBarrel(Vector2D(375, 1600), "barrel");




	SDL_Color white = { 0,0,0,255 };
	text.addComponent<TextComponent>(335, 140, "", "silkscreen", white);
	text.addGroup(groupText);
	

	for (int i = 0; i < player.getComponent<TransformComponent>().sumHearth; i++)   //zivoty
	{
		assets->CreateHearth(i, "hearth");
	}
	for (int i = 0; i < player.getComponent<TransformComponent>().ammo; i++)   //zivoty
	{
		assets->CreateAmmo(i, "ammo");
	}

} 

auto& tiles(manager.getGroup(Game::groupMap));
auto& players(manager.getGroup(Game::groupPlayers));
auto& enemy(manager.getGroup(Game::groupEnemy));
auto& colliders(manager.getGroup(Game::groupColliders));
auto& projectiles(manager.getGroup(Game::groupProjectiles));
auto& hearth(manager.getGroup(Game::groupHearths));
auto& ammo(manager.getGroup(Game::groupAmmo));
auto& barrel(manager.getGroup(Game::groupBarrel));
auto& boss(manager.getGroup(Game::groupBoss));
auto& texts(manager.getGroup(Game::groupText));

void Game::handleEvents()
{
	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;

	default:
		break;
	}
} 

void Game::update()
{
	SDL_Rect playerCol = player.getComponent<ColliderComponent>().collider;  //pozice hrace pred refesh
	Vector2D playerPos = player.getComponent<TransformComponent>().position;



	manager.refresh();
	manager.update();



	for (auto& c : colliders)           //hitboxi se stenou
	{		
			int arr[2] = { 0 };
			if (Collision::odraz(playerCol, c->getComponent<ColliderComponent>().collider, arr) && player.getComponent<TransformComponent>().isAlive)
			{
				player.getComponent<TransformComponent>().position.x = playerPos.x + arr[0];
				player.getComponent<TransformComponent>().position.y = playerPos.y + arr[1];
			}
	}

	for (auto& p : projectiles)   //zasah 
	{
		for (auto& e : enemy)
		{
			if (Collision::AABB(e->getComponent<ColliderComponent>().collider, p->getComponent<ColliderComponent>().collider) && e->getComponent<TransformComponent>().isAlive) //ENEMY
			{
				e->getComponent<TransformComponent>().sumHearth -= 1;
				player.getComponent<TransformComponent>().isFollowed = true;   
				e->getComponent<TransformComponent>().speed = 2;
				e->getComponent<TransformComponent>().followPlayer = true;
				player.getComponent<TransformComponent>().stopa.push_back(player.getComponent<TransformComponent>().position);

				if (e->getComponent<TransformComponent>().sumHearth == 0)
				{
					e->getComponent<TransformComponent>().isAlive = false;
					player.getComponent<TransformComponent>().isFollowed = false;											
					e->getComponent<TransformComponent>().followPlayer = false;
				}
				p->destroy();
			}

		}
		//pro bose
		if (Collision::AABB(boss[0]->getComponent<ColliderComponent>().collider, p->getComponent<ColliderComponent>().collider) && boss[0]->getComponent<TransformComponent>().isAlive) //BOSS
		{
			boss[0]->getComponent<TransformComponent>().sumHearth -= 1;
			player.getComponent<TransformComponent>().isFollowed = true;
			boss[0]->getComponent<TransformComponent>().followPlayer = true;
			player.getComponent<TransformComponent>().stopa.push_back(player.getComponent<TransformComponent>().position);

			if (boss[0]->getComponent<TransformComponent>().sumHearth == 0)
			{
				boss[0]->getComponent<TransformComponent>().isAlive = false;
				player.getComponent<TransformComponent>().isFollowed = false;
				boss[0]->getComponent<TransformComponent>().followPlayer = false;
				SDL_Color white = { 0,0,0,255 };
				text.addComponent<TextComponent>(335, 140, "You win!", "silkscreen", white);
				playerWin = true;

			}
			p->destroy();
		}
	}

	for (auto& p : projectiles)          //zed zastavi projektil
	{
		for (auto& c : colliders)
		{
			if (Collision::odrazBullet(p->getComponent<ColliderComponent>().collider, c->getComponent<ColliderComponent>().collider))
				p->destroy();
		}
	}

	if (boss[0]->getComponent<TransformComponent>().followPlayer)
	{
		boss[0]->getComponent<EnemyMove>().followPlayer(player.getComponent<TransformComponent>().stopa);
		player.getComponent<TransformComponent>().isFollowed = true;
	}

	for (auto& e : enemy)   //bodycheck   enemy
	{
		if (e->getComponent<TransformComponent>().followPlayer)
		{	
			e->getComponent<EnemyMove>().followPlayer(player.getComponent<TransformComponent>().stopa);
			player.getComponent<TransformComponent>().isFollowed = true;
		}

		int arr[2] = { 0 };
		int odrazOdSteny = 25;
		if ((Collision::BodyCheck(player.getComponent<ColliderComponent>().collider, e->getComponent<ColliderComponent>().collider, arr,odrazOdSteny)|| player.getComponent<TransformComponent>().position.x == e->getComponent<TransformComponent>().position.x && player.getComponent<TransformComponent>().position.y == e->getComponent<TransformComponent>().position.y)&& player.getComponent<TransformComponent>().isAlive && e->getComponent<TransformComponent>().isAlive)  //predtim playerCol
		{
			player.getComponent<TransformComponent>().position.x = playerPos.x + arr[0];
			player.getComponent<TransformComponent>().position.y = playerPos.y + arr[1];
			player.getComponent<TransformComponent>().sumHearth -= 1;
			hearth.erase(hearth.end() - 1);


			if (player.getComponent<TransformComponent>().sumHearth <= 0)
			{
				player.getComponent<TransformComponent>().isAlive = false;

				SDL_Color white = { 0,0,0,255 };
				text.addComponent<TextComponent>(335, 140, "You died!", "silkscreen", white);
			}
		}
	}

	int arr[2] = { 0 };
	int odrazOdSteny = 35;
	//boss
	if (Collision::BodyCheck(player.getComponent<ColliderComponent>().collider, boss[0]->getComponent<ColliderComponent>().collider, arr, odrazOdSteny) && player.getComponent<TransformComponent>().isAlive && boss[0]->getComponent<TransformComponent>().isAlive)  
	{
		player.getComponent<TransformComponent>().position.x = playerPos.x + arr[0];
		player.getComponent<TransformComponent>().position.y = playerPos.y + arr[1];

		if (player.getComponent<TransformComponent>().sumHearth >= 2)
		{
			player.getComponent<TransformComponent>().sumHearth -= 2;
			hearth.erase(hearth.end() - 1);
			hearth.erase(hearth.end() - 1);
		}
		else
		{
			player.getComponent<TransformComponent>().sumHearth -= 1;
			hearth.erase(hearth.end() - 1);
		}


		if (player.getComponent<TransformComponent>().sumHearth <= 0)
		{
			player.getComponent<TransformComponent>().isAlive = false;
			SDL_Color white = { 0,0,0,255 };
			text.addComponent<TextComponent>(335, 140, "You died!", "silkscreen", white);
		}
	}


	for (auto& b : barrel)
	{
		int arr[2] = { 0 };
		if (Collision::odraz(playerCol, b->getComponent<ColliderComponent>().collider, arr))
		{
			player.getComponent<TransformComponent>().position.x = playerPos.x + arr[0];
			player.getComponent<TransformComponent>().position.y = playerPos.y + arr[1];
		}
		if (Collision::AABB(playerCol, b->getComponent<ColliderComponent>().collider) && player.getComponent<KeyboardController>().eActivated)
		{
			for (int i = 0; i < 5; i++)
			{
				player.getComponent<TransformComponent>().ammo += 1;
				assets->CreateAmmo(player.getComponent<TransformComponent>().ammo - 1, "ammo");
			}
			b->destroy();
		}
	}


	for (auto& h : hearth)
	{
		h->getComponent<TransformComponent>().position.x = camera.x+20+(33*h->getComponent<HealthComponent>().index);
		h->getComponent<TransformComponent>().position.y = camera.y+520;
	}

	if (player.getComponent<KeyboardController>().fire && player.getComponent<TransformComponent>().ammo > 0)				//strelba
	{
		player.getComponent<TransformComponent>().ammo -= 1;
		assets->CreateProjectile(Vector2D(player.getComponent<TransformComponent>().position.x+64, player.getComponent<TransformComponent>().position.y+64), Vector2D(player.getComponent<TransformComponent>().smer.x, player.getComponent<TransformComponent>().smer.y), 500, 8+player.getComponent<KeyboardController>().moveSpeed, "projectile");
		player.getComponent<KeyboardController>().fire = false;  //mensi davka
		ammo.erase(ammo.end() - 1);
	}

	for (auto& a : ammo)
	{
		a->getComponent<TransformComponent>().position.x = camera.x + 450 + (8 * a->getComponent<AmmoComponent>().index);
		a->getComponent<TransformComponent>().position.y = camera.y + 520;
	}
	

	camera.x = player.getComponent<TransformComponent>().position.x -340;    //pozice kamery
	camera.y = player.getComponent<TransformComponent>().position.y - 240;


	if (camera.x < 0)            //kamera nevyjede z mapy
		camera.x = 0;
	if (camera.y < 0)
		camera.y = 0;
	if (camera.x > camera.w)
		camera.x = camera.w;
	if (camera.y > camera.h)
		camera.y = camera.h;




}

void Game::render()   //vykreslovani
{
	SDL_RenderClear(renderer);
	for (auto& t : tiles)
		t->draw();

	for (auto& c : colliders)
		c->draw();

	for (auto& a : ammo)
		a->draw();

	for (auto& b : barrel)
		b->draw();

	for (auto& p : projectiles)
		p->draw();

	if (player.getComponent<TransformComponent>().isAlive)        //ciste kvuli prekrivani mrtvol mezi enemy a player
	{
		for (auto& e : enemy)
			e->draw();

		for (auto& b : boss)
			b->draw();

		for (auto& p : players)
			p->draw();
	}
	else
	{
		for (auto& p : players)		
			p->draw();

		for (auto& b : boss)
			b->draw();

		for (auto& e : enemy)
			e->draw();
	}
	
	for (auto& h : hearth)
		h->draw();

	for (auto& t : texts)
		t->draw();




	SDL_RenderPresent(renderer); 


}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}
