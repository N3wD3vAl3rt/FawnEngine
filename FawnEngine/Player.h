#pragma once

#include "Vector2.h"
#include "Entity.h"
#include "Sprite.h"
#include "AnimationController.h"
#include "PlayerState.h"

class Player : public Entity
{
public:
	Player();

	void Update(float deltaTime) override;
	void Render(const Vector2& camPos, Renderer& renderer) override;

	AABB GetBounds() const override;

	EntityType GetType() const override;

	float GetX() const;
	float GetY() const;

private:
	AnimationController animationController;

	PlayerState state = PlayerState::Idle;

	float acceleration = 250.0f;
	float friction = 0.92f;
};
