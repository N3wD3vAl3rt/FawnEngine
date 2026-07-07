#include "Time.h"
#include <chrono>

float Time::deltaTime = 0.0f;
float Time::totalTime = 0.0f;

std::chrono::steady_clock::time_point Time::previousTime;

void Time::Initialize()
{
	deltaTime = 0.0f;
	totalTime = 0.0f;

	previousTime = std::chrono::steady_clock::now();
}

void Time::Update()
{
	auto currentTime = std::chrono::steady_clock::now();

	std::chrono::duration<float> elapsed =
		currentTime - previousTime;

	deltaTime = elapsed.count();

	previousTime = currentTime;

	totalTime += deltaTime;
}

float Time::GetDeltaTime()
{
	return deltaTime;
}

float Time::GetTotalTime()
{
	return totalTime;
}