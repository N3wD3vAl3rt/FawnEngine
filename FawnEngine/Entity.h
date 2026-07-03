#pragma once

#include "Vector2.h"

class Entity
{
public:
	Entity();
	virtual ~Entity() = default;

	virtual void Update();
	virtual void Render(const Vector2& camPos, class Renderer& renderer);

	float GetX() const;
	float GetY() const;

protected:
	Vector2 position;
	Vector2 velocity;
};
