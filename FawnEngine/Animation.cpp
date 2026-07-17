#include "Animation.h"

Animation::Animation()
	: fallbackSprite(1, 1)
{
	fallbackSprite.Fill(0xFF00FF);
}
void Animation::AddFrame(const Sprite& sprite)
{
	frames.push_back(sprite);
}
const Sprite& Animation::GetCurrentFrame() const
{
	if (frames.empty())
	{
		return fallbackSprite;
	}

	return frames[currentFrame];
}

void Animation::Update(float deltaTime)
{
	if (frames.empty())
		return;

	timer += deltaTime;

	if (timer >= frameTime)
	{
		timer -= frameTime;

		currentFrame++;

		if (currentFrame >= static_cast<int>(frames.size()))
		{
			currentFrame = 0;
		}
	}
}

