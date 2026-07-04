#pragma once

#include "Vector2.h"

struct AABB
{
	float x, y;
	float w, h;
};

class Entity
{
public:
	Entity();
	virtual ~Entity() = default;

	virtual AABB GetBounds() const = 0;

	virtual void Update();
	virtual void Render(const Vector2& camPos, class Renderer& renderer);

	float GetX() const;
	float GetY() const;

	bool IsAlive() const { return alive; }
	void Destroy() { alive = false; }

protected:
	bool alive = true;

	Vector2 position;
	Vector2 velocity;
};
