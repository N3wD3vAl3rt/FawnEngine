#pragma once

#include <chrono>

class Time
{
public:
	static void Initialize();
	static void Update();

	static float GetDeltaTime();
	static float GetTotalTime();

private:
	static float deltaTime;
	static float totalTime;

	static std::chrono::steady_clock::time_point previousTime;
};
