#pragma once

#include "Game.h"
#include "EntityManager.h"
#include "TransformComponent.h"
#include "SpriteComponent.h"

class KeyboardControlComponent : public Component
{
public:
	std::string upKey;
	std::string downKey;
	std::string leftKey;
	std::string rightKey;
	std::string shootKey;
	TransformComponent* transform;
	SpriteComponent* sprite;

public:
	KeyboardControlComponent();
	KeyboardControlComponent(std::string upKey, std::string rightKey, std::string downKey, std::string leftKey, std::string shootKey);
	std::string GetSDLKeyStringCode(std::string key);
	void Initialize() override;
	void Update(float dt) override;
	void Render() override;
};

