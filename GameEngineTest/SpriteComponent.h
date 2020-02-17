#pragma once

#include "TextureManager.h"
#include "AssetManager.h"
#include "TransformComponent.h"
#include "Animation.h"

class SpriteComponent : public Component
{
private:
	TransformComponent* transform;
	SDL_Texture* texture;
	SDL_Rect sourceRect;
	SDL_Rect destRect;
	bool isAnimated;
	int numFrames;
	int animationSpeed;
	bool isFixed;
	std::map<std::string, Animation> animations;
	std::string curAnimName;
	unsigned int animIndex = 0;
public:
	SDL_RendererFlip spriteFlip = SDL_FLIP_NONE;
	SpriteComponent(const char* filePath);
	SpriteComponent(std::string id, int numFrames, int animSpeed, bool hasDirections, bool isFixed);
	void Play(std::string animationName);
	void SetTexture(std::string assetTextureId);
	void Initialize() override;
	void Update(float dt) override;
	void Render() override;

};