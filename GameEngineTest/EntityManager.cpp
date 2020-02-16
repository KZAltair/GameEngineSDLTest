#include "EntityManager.h"

void EntityManager::ClearData()
{
	for (auto& entity : entities)
	{
		entity->Destroy();
	}
}

void EntityManager::Update(float dt)
{
	for (auto& entity : entities)
	{
		entity->Update(dt);
	}
}

void EntityManager::Render()
{
	for (auto& entity : entities)
	{
		entity->Render();
	}
}

bool EntityManager::HasNoEntities()
{
	return entities.size() == 0;
}

std::unique_ptr<Entity> EntityManager::AddEntity(std::string entityName)
{
	auto entity = std::make_unique<Entity>(*this, entityName);
	entities.emplace_back(entity.get());
	return entity;
}

std::vector<Entity*> EntityManager::GetEntities() const
{
	return entities;
}

unsigned int EntityManager::GetEntityCound() const
{
	return entities.size();
}
