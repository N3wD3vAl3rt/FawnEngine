#include "Camera.h"
#include "Input.h"

Camera::Camera()
{
	position = { 640.0f, 360.0f };
	pitch = 0.0f;
	yaw = 0.0f;
	mouseSensitivity = 0.1f;
}

void Camera::Update(Vector2 target)
{
	float followSpeed = 0.15f;

	float targetX = target.x - 640.0f;
	float targetY = target.y - 360.0f;

	position.x += (targetX - position.x) * followSpeed;
	position.y += (targetY - position.y) * followSpeed;

	// mouse look
	float dx = (float)Input::GetMouseDeltaX();
	float dy = (float)Input::GetMouseDeltaY();

	yaw += dx * mouseSensitivity;
	pitch -= dy * mouseSensitivity;

	// clamp pitch (prevents flipping)
	if (pitch > 89.0f) pitch = 89.0f;
	if (pitch < -89.0f) pitch = -89.0f;
}

Vector2 Camera::GetPosition() const
{
	return position;
}