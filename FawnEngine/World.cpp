#include "World.h"
#include "enemy.h"

World::World()
{
	entityManager.Spawn<Player>();

	entityManager.Spawn<Enemy>(300.0f, 200.0f);
	entityManager.Spawn<Enemy>(500.0f, 300.0f);
	entityManager.Spawn<Enemy>(700.0f, 400.0f);

	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			testSprite.SetPixel(x, y, 0x00000000);
		}
	}

	for (int i = 0; i < 8; i++)
	{
		testSprite.SetPixel(i, 0, 0x00FFFFFF);
		testSprite.SetPixel(i, 7, 0x00FFFFFF);

		testSprite.SetPixel(0, i, 0x00FFFFFF);
		testSprite.SetPixel(7, i, 0x00FFFFFF);
	}

}

void World::Update(float deltaTime)
{
	entityManager.Update(deltaTime);
}

void World::Render(const Vector2& camPos, Renderer& renderer)
{
	entityManager.Render(camPos, renderer);

	renderer.DrawSprite(
		600,
		300,
		testSprite);
}

Vector2 World::GetPlayerPosition() const
{
	Entity* e = entityManager.GetFirstEntity();

	if (!e)
		return { 0.0f, 0.0f };

	return { e->GetX(), e->GetY() };
}
