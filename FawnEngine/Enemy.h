#pragma once

#include "Entity.h"
#include "Vector2.h"
#include "Renderer.h"

class Enemy : public Entity
{
public:
	Enemy(float x, float y);

	void Update(float deltaTime) override;
	void Render(const Vector2& camPos, Renderer& renderer) override;

	AABB GetBounds() const override;

	EntityType GetType() const override;

	float GetX() const;
	float GetY() const;

private:
	float speed = 1.0f;
};
