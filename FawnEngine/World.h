#pragma once

#include "Player.h"
#include "Vector2.h"
#include "Renderer.h"
#include <vector>
#include "EntityManager.h"
#include "Scene.h"
#include "Sprite.h"

class World : public Scene
{
public:
	World();

	void Update(float deltaTime) override;
	void Render(const Vector2& camPos, Renderer& renderer) override;

	Vector2 GetPlayerPosition() const override;

private:
	EntityManager entityManager;

	Sprite testSprite{8, 8};
};