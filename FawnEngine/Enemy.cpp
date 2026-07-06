#include "Enemy.h"

Enemy::Enemy()
{
	position = { 200.0f, 200.0f };
}

void Enemy::Update()
{
	 // No Movement For Now
}

void Enemy::Render(const Vector2& camPos, Renderer& renderer)
{
	int screenX = (int)(GetX() - camPos.x);
	int screenY = (int)(GetY() - camPos.y);

	renderer.DrawRect(
		screenX,
		screenY,
		16,
		16,
		0x00FF0000 // red enemy
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