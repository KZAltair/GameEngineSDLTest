#pragma once

#include "EntityManager.h"
#include <glm.hpp>
#include <SDL.h>

class TransformComponent : public Component
{
public:
	glm::vec2 pos;
	glm::vec2 vel;
	int width;
	int height;
	int scale;

public:
	TransformComponent(int posX, int posY, int velX, int velY, int width, int height, int scale);
	void Initialize() override;
	void Update(float dt) override;
	void Render() override;
};