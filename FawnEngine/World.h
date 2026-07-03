#pragma once

#include "Player.h"
#include "Vector2.h"
#include "Renderer.h"
#include <vector>
#include "EntityManager.h"

class World
{
public:
	World();

	void Update();
	void Render(const Vector2& camPos, Renderer& renderer);

	Vector2 GetPlayerPosition() const;

private:
	EntityManager entityManager;
};