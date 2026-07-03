#include "EntityManager.h"
#include <utility>

EntityManager::EntityManager()
{
}

EntityManager::~EntityManager()
{
	entities.clear();
}

void EntityManager::AddEntity(std::unique_ptr<Entity> entity)
{
	entities.push_back(std::move(entity));
}

void EntityManager::Update()
{
	for (auto& entity : entities)
	{
		entity->Update();
	}
}

void EntityManager::Render(const Vector2& camPos, Renderer& renderer)
{
	for (auto& entity : entities)
	{
		entity->Render(camPos, renderer);
	}
}

Entity* EntityManager::GetFirstEntity() const
{
	if (entities.empty())
		return nullptr;

	return entities.front().get();
}