#include "Game.h"
#include <memory>

Game::Game()
{
	sceneManager.SetScene(std::make_unique<World>());
}

void Game::Update(float deltaTime)
{
	sceneManager.Update(deltaTime);
}

void Game::Render(const Vector2& camPos, Renderer& renderer)
{
	sceneManager.Render(camPos, renderer);
}

Vector2 Game::GetPlayerPosition() const
{
	return sceneManager.GetPlayerPosition();
}