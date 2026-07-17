#include "AnimationController.h"

void AnimationController::AddAnimation(AnimationState state,
	const Animation& animation)
{
	animations[state] = animation;

	if (currentAnimation == nullptr)
	{
		currentAnimation = &animations[state];
	}
}

void AnimationController::Play(AnimationState state)
{
	if (currentState == state)
	{
		return;
	}

	auto it = animations.find(state);

	if (it != animations.end())
	{
		currentState = state;
		currentAnimation = &it->second;
	}
}

void AnimationController::Update(float deltaTime)
{
	if (currentAnimation != nullptr)
	{
		currentAnimation->Update(deltaTime);
	}
}

const Sprite& AnimationController::GetCurrentFrame() const
{
	if (currentAnimation != nullptr)
	{
		return currentAnimation->GetCurrentFrame();
	}

	static Sprite fallback(1, 1);
	return fallback;
}