#include "SpriteComponent.h"

SpriteComponent::SpriteComponent(const char* filePath)
{
	isAnimated = false;
	isFixed = false;
	SetTexture(filePath);
}

SpriteComponent::SpriteComponent(std::string id, int numFrames, int animSpeed, bool hasDirections, bool isFixed)
	:
	numFrames(numFrames),
	animationSpeed(animSpeed),
	isFixed(isFixed)
{
	isAnimated = true;

	if (hasDirections)
	{
		Animation downAnimation = Animation(0, numFrames, animationSpeed);
		Animation rightAnimation = Animation(1, numFrames, animationSpeed);
		Animation leftAnimation = Animation(2, numFrames, animationSpeed);
		Animation upAnimation = Animation(3, numFrames, animationSpeed);

		animations.emplace("DownAnimation", downAnimation);
		animations.emplace("RightAnimation", rightAnimation);
		animations.emplace("LeftAnimation", leftAnimation);
		animations.emplace("UpAnimation", upAnimation);

		this->animIndex = 0;
		this->curAnimName = "DownAnimation";
	}
	else
	{
		Animation singleAnimation = Animation(0, numFrames, animationSpeed);
		animations.emplace("SingleAnimation", singleAnimation);
		this->animIndex = 0;
		this->curAnimName = "SingleAnimation";
	}
	Play(this->curAnimName);
	SetTexture(id);
}

void SpriteComponent::Play(std::string animationName)
{
	numFrames = animations[animationName].numFrames;
	animIndex = animations[animationName].index;
	animationSpeed = animations[animationName].animSpeed;
	curAnimName = animationName;
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
	if (isAnimated)
	{
		sourceRect.x = sourceRect.w * static_cast<int>((SDL_GetTicks() / animationSpeed) % numFrames);
	}
	sourceRect.y = animIndex * transform->height;
	destRect.x = static_cast<int>(transform->pos.x);
	destRect.y = static_cast<int>(transform->pos.y);
	destRect.w = transform->width * transform->scale;
	destRect.h = transform->height * transform->scale;
}

void SpriteComponent::Render()
{
	TextureManager::Draw(texture, sourceRect, destRect, spriteFlip);
}
