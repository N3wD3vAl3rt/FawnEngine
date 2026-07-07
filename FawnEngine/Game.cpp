#include "Game.h"

Game::Game()
{
}

void Game::Update(float deltaTime)
{
	world.Update(deltaTime);
}

void Game::Render(const Vector2& camPos, Renderer& renderer)
{
	world.Render(camPos, renderer);
}

Vector2 Game::GetPlayerPosition() const
{
	return world.GetPlayerPosition();
}