#include "KeyboardControlComponent.h"

KeyboardControlComponent::KeyboardControlComponent()
{
}

KeyboardControlComponent::KeyboardControlComponent(std::string upKey, std::string rightKey, std::string downKey, std::string leftKey, std::string shootKey)
	:
	upKey(GetSDLKeyStringCode(upKey)),
	rightKey(GetSDLKeyStringCode(rightKey)),
	downKey(GetSDLKeyStringCode(downKey)),
	leftKey(GetSDLKeyStringCode(leftKey)),
	shootKey(GetSDLKeyStringCode(shootKey))
{
}

std::string KeyboardControlComponent::GetSDLKeyStringCode(std::string key)
{
	if (key.compare("up") == 0) return "1073741906";
	if (key.compare("down") == 0) return "1073741905";
	if (key.compare("left") == 0) return "1073741904";
	if (key.compare("right") == 0) return "1073741903";
	if (key.compare("space") == 0) return "32";
	return std::to_string(static_cast<int>(key[0]));
}

void KeyboardControlComponent::Initialize()
{
	transform = owner->GetComponent<TransformComponent>();
	sprite = owner->GetComponent<SpriteComponent>();
}

void KeyboardControlComponent::Update(float dt)
{
	if (Game::event.type == SDL_KEYDOWN)
	{
		std::string keyCode = std::to_string(Game::event.key.keysym.sym);
		if (keyCode.compare(upKey) == 0)
		{
			transform->vel.y = -1.0f;
			transform->vel.x = 0.0f;
			sprite->Play("UpAnimation");
		}
		if (keyCode.compare(rightKey) == 0)
		{
			transform->vel.y = 0.0f;
			transform->vel.x = 1.0f;
			sprite->Play("RightAnimation");
		}
		if (keyCode.compare(downKey) == 0)
		{
			transform->vel.y = 1.0f;
			transform->vel.x = 0.0f;
			sprite->Play("DownAnimation");
		}
		if (keyCode.compare(leftKey) == 0)
		{
			transform->vel.y = 0.0f;
			transform->vel.x = -1.0f;
			sprite->Play("LeftAnimation");
		}
		if (keyCode.compare(shootKey) == 0)
		{
			//TODO:logic
		}
	}
	if (Game::event.type == SDL_KEYUP)
	{
		std::string keyCode = std::to_string(Game::event.key.keysym.sym);
		if (keyCode.compare(upKey) == 0)
		{
			transform->vel.y = 0.0f;
		}
		if (keyCode.compare(rightKey) == 0)
		{
			transform->vel.x = 0.0f;
		}
		if (keyCode.compare(downKey) == 0)
		{
			transform->vel.y = 0.0f;
		}
		if (keyCode.compare(leftKey) == 0)
		{
			transform->vel.x = 0.0f;
		}
		if (keyCode.compare(shootKey) == 0)
		{
			//TODO:logic
		}
	}
}

void KeyboardControlComponent::Render()
{
}
