#include "Entity.h"
#include "Renderer.h"

Entity::Entity()
{
}

void Entity::Update(float deltaTime)
{
	if (damageCooldown > 0)
	{
		damageCooldown--;
	}

	if (hitFlashTimer > 0)
	{
		hitFlashTimer--;
	}
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
	if (damageCooldown > 0)
		return;

	health -= amount;

	damageCooldown = 30;  // 30 frames of protection
	hitFlashTimer = 10;

	if (health <= 0)
	{
		health = 0;
		Destroy();
	}
}