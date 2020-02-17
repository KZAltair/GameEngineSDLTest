#pragma once
#include <SDL.h>
#include <glm.hpp>
#include "EntityManager.h"

class TileComponent : public Component
{
public:
	SDL_Texture* texture;
	SDL_Rect sourceRect;
	SDL_Rect destRect;
	glm::vec2 pos;

public:
	TileComponent(int sourceRectX, int sourceRectY, int x, int y, int tileSize, int tileScale, std::string assetTextureId);
	~TileComponent();

	void Update(float dt) override;
	void Render() override;

};