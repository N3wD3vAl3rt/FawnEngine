#pragma once

#include "World.h"
#include "Renderer.h"
#include "Vector2.h"
#include "SceneManager.h"
#include "EngineContext.h"

class Game
{
public:
	Game();

	void Update(float deltaTime);
	void Render(const Vector2& camPos, Renderer& renderer);

	Vector2 GetPlayerPosition() const;

private:
	SceneManager sceneManager;
};