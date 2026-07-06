#pragma once

#include "Vector2.h"

struct AABB
{
	float x, y;
	float w, h;
};

enum class EntityType
{
	Player,
	Enemy
};

class Entity
{
public:
	Entity();
	virtual ~Entity() = default;

	virtual AABB GetBounds() const = 0;
	
	virtual EntityType GetType() const = 0;

	virtual void Update();
	virtual void Render(const Vector2& camPos, class Renderer& renderer);

	float GetX() const;
	float GetY() const;

	bool IsAlive() const { return alive; }
	void Destroy() { alive = false; }

	int GetHealth() const;
	void SetHealth(int value);
	void TakeDamage(int amount);

protected:
	bool alive = true;
	int health = 100;

	Vector2 position;
	Vector2 velocity;
};
