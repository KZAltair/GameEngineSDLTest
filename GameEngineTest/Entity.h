#pragma once

#include <vector>
#include <string>
#include "EntityManager.h"
#include "Component.h"

class Component;
class EntityManager;

class Entity
{
public:
	std::string name;
	Entity(EntityManager& manager);
	Entity(EntityManager& manager, std::string name);
	void Update(float dt);
	void Render();
	void Destroy();
	bool IsActive() const;
private:
	EntityManager& manager;
	bool isActive;
	std::vector<Component*> components;
};