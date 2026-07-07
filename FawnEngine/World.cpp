#include "World.h"
#include "enemy.h"

World::World()
{
	entityManager.Spawn<Player>();

	entityManager.Spawn<Enemy>(300.0f, 200.0f);
	entityManager.Spawn<Enemy>(500.0f, 300.0f);
	entityManager.Spawn<Enemy>(700.0f, 400.0f);
}

void World::Update(float deltaTime)
{
	entityManager.Update(deltaTime);
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