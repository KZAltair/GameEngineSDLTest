#include "TransformComponent.h"

TransformComponent::TransformComponent(int posX, int posY, int velX, int velY, int width, int height, int scale)
	:
	pos(glm::vec2(posX, posY)),
	vel(glm::vec2(velX, velY)),
	width(width),
	height(height),
	scale(scale)
{
}

void TransformComponent::Initialize()
{
}

void TransformComponent::Update(float dt)
{
}

void TransformComponent::Render()
{
	SDL_Rect transformRect = {
		(int)pos.x,
		(int)pos.y,
		width,
		height
	};
}
