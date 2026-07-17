#pragma once

#include <vector>
#include "Sprite.h"

class Animation
{
public:
	Animation();

	void AddFrame(const Sprite& sprite);
	const Sprite& GetCurrentFrame() const;

	void Update(float deltaTime);

private:
	std::vector<Sprite> frames;

	int currentFrame = 0;

	float frameTime = 0.15f;
	float timer = 0.0f;

	Sprite fallbackSprite;
};