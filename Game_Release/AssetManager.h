#pragma once

#include <map>
#include <string>
#include "TextureManager.h"
#include "Vector2D.h"
#include "ECS.h"
#include <vector>

class AssetManager
{
public:
	AssetManager(Manager* man);
	~AssetManager();
	//game object
	void CreateProjectile(Vector2D pos, Vector2D vel, int range, int speed, std::string id);
	void CreateEnemy(Vector2D pos, int speed, std::string id, std::vector<Vector2D>routePoints);
	void CreateHearth(int i ,std::string id);
	void CreateAmmo(int i, std::string id);
	void CreateBarrel(Vector2D pos, std::string id);
	void AddTexture(std::string id, const char* path);
	void CreateBoss(Vector2D pos, int speed, std::string id, std::vector<Vector2D>routePoints);
	void AddFont(std::string id, std::string path, int fontSize);
	SDL_Texture* GetTexture(std::string id);
	TTF_Font* GetFont(std::string id);
	
private:

	Manager* manager;
	std::map<std::string, SDL_Texture*> textures;
	std::map<std::string, TTF_Font*> fonts;

};