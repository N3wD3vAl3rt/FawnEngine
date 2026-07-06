#include "Entity.h"
#include "Renderer.h"

Entity::Entity()
{
}

void Entity::Update()
{
}

void Entity::Render(const Vector2& camPos, Renderer& renderer)
{
}

float Entity::GetX() const
{
	return position.x;
}

float Entity::GetY() const
{
	return position.y;
}

int Entity::GetHealth() const
{
	return health;
}

void Entity::SetHealth(int value)
{
	health = value;
}

void Entity::TakeDamage(int amount)
{
	health -= amount;

	if (health <= 0)
	{
		health = 0;
		Destroy();
	}
}