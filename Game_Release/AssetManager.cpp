#include "AssetManager.h"
#include "Components.h"
#include "AmmoComponent.h"

AssetManager::AssetManager(Manager* man) : manager(man)
{}

AssetManager::~AssetManager()
{}

void AssetManager::CreateProjectile(Vector2D pos,Vector2D vel, int range, int speed, std::string id)
{
	auto& projectile(manager->addEntity());
	projectile.addComponent<TransformComponent>(pos.x, pos.y, 16, 16, 1);
	projectile.addComponent<SpriteComponent>(id);
	projectile.addComponent<ProjectileComponent>(range, speed, vel);
	projectile.addComponent<ColliderComponent>("projectile");  
	projectile.addGroup(Game::groupProjectiles);
}

void AssetManager::CreateEnemy(Vector2D pos, int speed, std::string id, std::vector<Vector2D>routePoints)
{
	auto& enemy(manager->addEntity());
	enemy.addComponent<TransformComponent>(pos.x, pos.y, 32, 32,4, 5);
	enemy.addComponent<SpriteComponent>(id,true);
	enemy.addComponent<EnemyMove>(routePoints);
	enemy.addComponent<ColliderComponent>("enemak");
	enemy.addGroup(Game::groupEnemy);
	enemy.getComponent<TransformComponent>().speed = speed;
}

void AssetManager::CreateBoss(Vector2D pos, int speed, std::string id, std::vector<Vector2D>routePoints)
{
	auto& boss(manager->addEntity());
	boss.addComponent<TransformComponent>(pos.x, pos.y, 32, 32, 6, 10);
	boss.addComponent<SpriteComponent>(id, true);
	boss.addComponent<EnemyMove>(routePoints);
	boss.addComponent<ColliderComponent>("boss");
	boss.addGroup(Game::groupBoss);
	boss.getComponent<TransformComponent>().speed = speed;
}

void AssetManager::CreateHearth(int i, std::string id)
{
	auto& hearth(manager->addEntity());
	hearth.addComponent<TransformComponent>(Game::camera.x, Game::camera.y, 32, 32, 2);
	hearth.addComponent<SpriteComponent>(id);
	hearth.addComponent<HealthComponent>(i);
	hearth.addGroup(Game::groupHearths);
}

void AssetManager::CreateAmmo(int i, std::string id)
{
	auto& ammo(manager->addEntity());
	ammo.addComponent<TransformComponent>(Game::camera.x, Game::camera.y, 32, 32, 2);
	ammo.addComponent<SpriteComponent>(id);
	ammo.addComponent<AmmoComponent>(i);
	ammo.addGroup(Game::groupAmmo);
}

void AssetManager::CreateBarrel(Vector2D pos, std::string id)
{
	auto& barrel(manager->addEntity());
	barrel.addComponent<TransformComponent>(pos.x, pos.y, 32, 32, 3);
	barrel.addComponent<SpriteComponent>(id);
	barrel.addComponent<ColliderComponent>("barrel");
	barrel.addGroup(Game::groupBarrel);
}

void AssetManager::AddFont(std::string id, std::string path, int fontSize)
{
	const char* path1 = "fonts/Arial.ttf";
	
	fonts.emplace(id, TTF_OpenFont(path1, fontSize));
}

void AssetManager::AddTexture(std::string id, const char* path)
{
	textures.emplace(id, TextureManager::LoadTexture(path));
}

SDL_Texture* AssetManager::GetTexture(std::string id)
{
	return textures[id];
}

TTF_Font* AssetManager::GetFont(std::string id)
{
	return fonts[id];
}