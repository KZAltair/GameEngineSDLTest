#pragma once
#include "Entity.h"
#include "Component.h"
#include <memory>

class EntityManager
{
private:
	std::vector<Entity*> entities;
public:
	void ClearData();
	void Update(float dt);
	void Render();
	bool HasNoEntities();
	Entity& AddEntity(std::string entityName);
	std::vector<Entity*> GetEntities() const;
	unsigned int GetEntityCound() const;
};