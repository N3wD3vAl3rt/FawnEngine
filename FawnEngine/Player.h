#pragma once

#include "Vector2.h"
#include "Entity.h"

class Player : public Entity
{
public:
	Player();

	void Update() override;
	void Render(const Vector2& camPos, Renderer& renderer) override;

	AABB GetBounds() const override;

	EntityType GetType() const override;

	float GetX() const;
	float GetY() const;

private:
	float acceleration = 0.04f;
	float friction = 0.88f;
};
