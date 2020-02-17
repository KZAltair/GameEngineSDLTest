#include "SpriteComponent.h"

SpriteComponent::SpriteComponent(const char* filePath)
{
	SetTexture(filePath);
}

void SpriteComponent::SetTexture(std::string assetTextureId)
{
	texture = Game::assetManager->GetTexture(assetTextureId);
}

void SpriteComponent::Initialize()
{
	transform = owner->GetComponent<TransformComponent>();
	sourceRect.x = 0;
	sourceRect.y = 0;
	sourceRect.w = transform->width;
	sourceRect.h = transform->height;
}

void SpriteComponent::Update(float dt)
{
	destRect.x = (int)transform->pos.x;
	destRect.y = (int)transform->pos.y;
	destRect.w = transform->width * transform->scale;
	destRect.h = transform->height * transform->scale;
}

void SpriteComponent::Render()
{
	TextureManager::Draw(texture, sourceRect, destRect, spriteFlip);
}
