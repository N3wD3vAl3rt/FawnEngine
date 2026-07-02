#include "Player.h"
#include <Windows.h>
#include "Input.h"

Player::Player()
{
	position.x = 0.0f;
	position.y = 0.0f;

	velocity.x = 0.0f;
	velocity.y = 0.0f;
}

void Player::Update()
{
	float delta = 1.0f;  // placeholder for now

	position = position + velocity * delta;

	float maxSpeed = 3.0f;

	if (velocity.x > maxSpeed) velocity.x = maxSpeed;
	if (velocity.x < -maxSpeed) velocity.x = -maxSpeed;

	if (velocity.y > maxSpeed) velocity.y = maxSpeed;
	if (velocity.y < -maxSpeed) velocity.y = -maxSpeed;

	Vector2 inputDir;

	if (Input::IsKeyDown('W')) inputDir.y -= 1;
	if (Input::IsKeyDown('S')) inputDir.y += 1;
	if (Input::IsKeyDown('A')) inputDir.x -= 1;
	if (Input::IsKeyDown('D')) inputDir.x += 1;

	velocity.x += inputDir.x * acceleration;
	velocity.y += inputDir.y * acceleration;

	// friction
	velocity.x *= friction;
	velocity.y *= friction;

	position = position + velocity;
}

float Player::GetX() const
{
	return position.x;
}

float Player::GetY() const
{
	return position.y;
}
