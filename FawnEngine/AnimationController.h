#pragma once

#include <unordered_map>
#include "Animation.h"
#include "AnimationState.h"

class AnimationController
{
public:
	void AddAnimation(AnimationState state,
		const Animation& animation);

	void Play(AnimationState state);

	void Update(float deltaTime);

	const Sprite& GetCurrentFrame() const;

private:
	std::unordered_map<AnimationState, Animation> animations;

	Animation* currentAnimation = nullptr;

	AnimationState currentState = AnimationState::Idle;
};
