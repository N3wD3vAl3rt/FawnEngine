#pragma once

#include "Vector2.h"

class Player
{
public:
	Player();

	void Update();

	float GetX() const;
	float GetY() const;

private:
	Vector2 position;
	Vector2 velocity;

	float acceleration = 0.04f;
	float friction = 0.88f;
};
