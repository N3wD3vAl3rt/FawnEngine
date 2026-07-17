#include "Player.h"
#include <Windows.h>
#include "Input.h"
#include "Renderer.h"
#include <cmath>

Player::Player()
{
	position.x = 0.0f;
	position.y = 0.0f;

	velocity.x = 0.0f;
	velocity.y = 0.0f;

	Animation idleAnimation;

	Sprite idleFrame1(16, 16);
	idleFrame1.Fill(0x0000FF);

	Sprite idleFrame2(16, 16);
	idleFrame2.Fill(0x000088);

	for (int y = 4; y < 12; y++)
	{
		for (int x = 4; x < 12; x++)
		{
			idleFrame2.SetPixel(x, y, 0x00FFFF);
		}
	}

	idleAnimation.AddFrame(idleFrame1);
	idleAnimation.AddFrame(idleFrame2);

	animationController.AddAnimation(AnimationState::Idle, idleAnimation);
	animationController.Play(AnimationState::Idle);


	Animation walkAnimation;

	Sprite walkFrame1(16, 16);
	walkFrame1.Fill(0x00AA00);

	Sprite walkFrame2(16, 16);
	walkFrame2.Fill(0x00FF00);

	for (int y = 4; y < 12; y++)
	{
		for (int x = 4; x < 12; x++)
		{
			walkFrame2.SetPixel(x, y, 0xFFFFFF);
		}
	}

	walkAnimation.AddFrame(walkFrame1);
	walkAnimation.AddFrame(walkFrame2);

	animationController.AddAnimation(AnimationState::Walk, walkAnimation);
}

void Player::Update(float deltaTime)
{
	Entity::Update(deltaTime);

	float maxSpeed = 300.0f;

	if (velocity.x > maxSpeed) velocity.x = maxSpeed;
	if (velocity.x < -maxSpeed) velocity.x = -maxSpeed;

	if (velocity.y > maxSpeed) velocity.y = maxSpeed;
	if (velocity.y < -maxSpeed) velocity.y = -maxSpeed;

	Vector2 inputDir;

	if (Input::IsKeyDown('W')) inputDir.y -= 1;
	if (Input::IsKeyDown('S')) inputDir.y += 1;
	if (Input::IsKeyDown('A')) inputDir.x -= 1;
	if (Input::IsKeyDown('D')) inputDir.x += 1;

	velocity.x += inputDir.x * acceleration * deltaTime;
	velocity.y += inputDir.y * acceleration * deltaTime;

	// friction
	float frameScale = deltaTime * 60.0f;

	velocity.x *= std::pow(friction, frameScale);
	velocity.y *= std::pow(friction, frameScale);

	position = position + (velocity * deltaTime);

	const float movementThreshold = 1.0f;

	if (std::abs(velocity.x) > movementThreshold ||
		std::abs(velocity.y) > movementThreshold)
	{
		state = PlayerState::Walking;
	}
	else
	{
		state = PlayerState::Idle;
	}

	switch (state)
	{
	case PlayerState::Idle:
		animationController.Play(AnimationState::Idle);
		break;

	case PlayerState::Walking:
		animationController.Play(AnimationState::Walk);
		break;
	}

	animationController.Update(deltaTime);
}

float Player::GetX() const
{
	return position.x;
}

float Player::GetY() const
{
	return position.y;
}

void Player::Render(const Vector2& camPos, Renderer& renderer)
{
	int screenX = (int)(GetX() - camPos.x);
	int screenY = (int)(GetY() - camPos.y);

	renderer.DrawSprite(
		screenX,
		screenY,
		animationController.GetCurrentFrame()
	);
}

AABB Player::GetBounds() const
{
	return
	{
	position.x,
	position.y,
	static_cast<float>(animationController.GetCurrentFrame().GetWidth()),
	static_cast<float>(animationController.GetCurrentFrame().GetHeight())
	};
}

EntityType Player::GetType() const
{
	return EntityType::Player;
}