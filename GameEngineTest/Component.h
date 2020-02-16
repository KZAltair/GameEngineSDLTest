#pragma once

class Entity;

class Component
{
public:
	virtual ~Component();
	virtual void Initialize();
	virtual void Update(float dt);
	virtual void Render();
public:
	Entity* owner;
};