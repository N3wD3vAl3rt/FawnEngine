#include "EntityManager.h"
#include <utility>
#include <cstddef>

bool IsOnScreen(float x, float y, const Vector2& camPos, int screenWidth, int screenHeight)
{
	float screenX = x - camPos.x;
	float screenY = y - camPos.y;

	return (
		screenX >= -16 &&
		screenX <= screenWidth + 16 &&
		screenY >= -16 &&
		screenY <= screenHeight + 16
		);
}

bool CheckCollision(const AABB& a, const AABB& b)
{
	return (
		a.x < b.x + b.w &&
		a.x + a.w > b.x &&
		a.y < b.y + b.h &&
		a.y + a.h > b.y
		);
}

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
	// 1. Update all entities first
	for (auto& entity : entities)
	{
		entity->Update();
	}

	// 2. THEN remove dead ones
	Cleanup();
}

void EntityManager::Render(const Vector2& camPos, Renderer& renderer)
{
	for (auto& entity : entities)
	{
		float x = entity->GetX();
		float y = entity->GetY();

		if (IsOnScreen(x, y, camPos, 1280, 720))
		{
			entity->Render(camPos, renderer);
		}
	}
}

Entity* EntityManager::GetEntityByIndex(std::size_t index) const
{
	if (index >= entities.size())
		return nullptr;

	return entities[index].get();
}

Entity* EntityManager::GetFirstEntity() const
{
	if (entities.empty())
		return nullptr;

	return entities.front().get();
}

void EntityManager::Cleanup()
{
	entities.erase(
		std::remove_if(
			entities.begin(),
			entities.end(),
			[](const std::unique_ptr<Entity>& e)
			{
				return !e->IsAlive();
			}
		),
		entities.end()
	);
}