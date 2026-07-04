#pragma once

#include "Entity.h"
#include "Vector2.h"
#include "Renderer.h"

class Enemy : public Entity
{
public:
	Enemy();

	void Update() override;
	void Render(const Vector2& camPos, Renderer& renderer) override;

	AABB GetBounds() const override;

	float GetX() const;
	float GetY() const;

private:
	float speed = 1.0f;
};
