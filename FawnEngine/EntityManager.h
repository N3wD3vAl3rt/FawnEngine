#pragma once

#include <vector>
#include <memory>
#include "Entity.h"
#include "Renderer.h"
#include "Vector2.h"

class EntityManager
{
public:
	EntityManager();
	~EntityManager();

	void Update();
	void Render(const Vector2& camPos, Renderer& renderer);

	void AddEntity(std::unique_ptr<Entity> entity);

	Entity* GetFirstEntity() const;

private:
	std::vector<std::unique_ptr<Entity>> entities;
};