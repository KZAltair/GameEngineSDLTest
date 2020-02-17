#include "TileComponent.h"
#include "AssetManager.h"

TileComponent::TileComponent(int sourceRectX, int sourceRectY, int x, int y, int tileSize, int tileScale, std::string assetTextureId)
{
	texture = Game::assetManager->GetTexture(assetTextureId);

	sourceRect.x = sourceRectX;
	sourceRect.y = sourceRectY;
	sourceRect.w = tileSize;
	sourceRect.h = tileSize;

	destRect.x = x;
	destRect.y = y;
	destRect.x = tileSize * tileScale;
	destRect.y = tileSize * tileScale;

	pos.x = x;
	pos.y = y;
}

TileComponent::~TileComponent()
{
	SDL_DestroyTexture(texture);
}

void TileComponent::Update(float dt)
{
	//Tile positions based on camera movement
}

void TileComponent::Render()
{
	TextureManager::Draw(texture, sourceRect, destRect, SDL_FLIP_NONE);
}
