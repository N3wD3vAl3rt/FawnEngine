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
