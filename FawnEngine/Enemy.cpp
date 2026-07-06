#include "Enemy.h"

Enemy::Enemy(float x, float y)
{
	position = { x, y };
}

void Enemy::Update()
{
	Entity::Update();

	position.x += speed;
}

void Enemy::Render(const Vector2& camPos, Renderer& renderer)
{
	int screenX = (int)(GetX() - camPos.x);
	int screenY = (int)(GetY() - camPos.y);

	unsigned int color = 0x00FF0000;

	if (IsHit())
	{
		color = 0x00FFFFFF;
	}

	renderer.DrawRect(
		screenX,
		screenY,
		16,
		16,
		color
	);
}

float Enemy::GetX() const 
{ 
	return position.x; 
}
float Enemy::GetY() const
{
	return position.y;
}

AABB Enemy::GetBounds() const
{
	return { position.x, position.y, 16.0f, 16.0f };
}

EntityType Enemy::GetType() const
{
	return EntityType::Enemy;
}