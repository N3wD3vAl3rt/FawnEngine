#include "World.h"

World::World()
{
	entityManager.AddEntity(std::make_unique<Player>());
}

void World::Update()
{
	entityManager.Update();
}

void World::Render(const Vector2& camPos, Renderer& renderer)
{
	entityManager.Render(camPos, renderer);
}

Vector2 World::GetPlayerPosition() const
{
	Entity* e = entityManager.GetFirstEntity();

	if (!e)
		return { 0.0f, 0.0f };

	return { e->GetX(), e->GetY() };
}