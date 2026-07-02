#pragma once
#include "Vector2.h"

class Camera
{
public:
	Camera();

	void Update(Vector2 target);

	Vector2 GetPosition() const;

private:
	Vector2 position;

	float pitch = 0.0f;
	float yaw = 0.0f;

	float mouseSensitivity = 0.1f;
};
