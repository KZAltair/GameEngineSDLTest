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


	//TODO: Change to unique pointer
	template <typename T, typename... TArgs>
	T& AddComponent(TArgs&&... args)
	{
		//auto newComponent = std::make_unique<T>();
		T* newComponent(new T(std::forward<TArgs>(args)...));
		newComponent->owner = this;
		components.emplace_back(newComponent);
		newComponent->Initialize();
		return *newComponent;
	}

private:
	EntityManager& manager;
	bool isActive;
	std::vector<Component*> components;
};