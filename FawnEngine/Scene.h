#pragma once

#include "Vector2.h"

class Renderer;

class Scene
{
public:
	virtual ~Scene() = default;

	virtual void Update(float deltaTime) = 0;
	virtual void Render(const Vector2& camPos, Renderer& renderer) = 0;
	virtual Vector2 GetPlayerPosition() const = 0;
};
