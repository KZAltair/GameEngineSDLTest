#pragma once

#include <string>

class Map
{
private:
	std::string textureid;
	int scale;
	int tileSize;
public:
	Map(std::string textureId, int scale, int tileSize);
	~Map();
	void LoadMap(std::string filePath, int mapSizeX, int mapSizeY);
	void AddTile(int sourceX, int souceY, int x, int y);
};