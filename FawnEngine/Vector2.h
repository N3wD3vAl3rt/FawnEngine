#pragma once
struct Vector2
{
	float x = 0.0f;
	float y = 0.0f;

	Vector2 operator+(const Vector2& other) const
	{
		return { x + other.x, y + other.y };
	}

	Vector2 operator*(float value) const
	{
		return { x * value, y * value };
	}
};
