#include "SceneManager.h"
#include "Scene.h"

void SceneManager::SetScene(std::unique_ptr<Scene> scene)
{
	currentScene = std::move(scene);
}

void SceneManager::Update(float deltaTime)
{
	if (currentScene)
	{
		currentScene->Update(deltaTime);
	}
}

void SceneManager::Render(const Vector2& camPos, Renderer& renderer)
{
	if (currentScene)
	{
		currentScene->Render(camPos, renderer);
	}
}

Vector2 SceneManager::GetPlayerPosition() const
{
	if (currentScene)
	{
		return currentScene->GetPlayerPosition();
	}

	return { 0.0f, 0.0f };
}