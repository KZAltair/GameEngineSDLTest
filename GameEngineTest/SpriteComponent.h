#pragma once

#include "TextureManager.h"
#include "AssetManager.h"
#include "TransformComponent.h"

class SpriteComponent : public Component
{
private:
	TransformComponent* transform;
	SDL_Texture* texture;
	SDL_Rect sourceRect;
	SDL_Rect destRect;
public:
	SDL_RendererFlip spriteFlip = SDL_FLIP_NONE;
	SpriteComponent(const char* filePath);
	void SetTexture(std::string assetTextureId);
	void Initialize() override;
	void Update(float dt) override;
	void Render() override;

};