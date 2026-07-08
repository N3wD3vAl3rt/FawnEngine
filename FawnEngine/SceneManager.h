#pragma once

#include <memory>

class Scene;
class Renderer;
struct Vector2;

class SceneManager
{
public:
	void SetScene(std::unique_ptr<Scene> scene);

	void Update(float deltaTime);
	void Render(const Vector2& camPos, Renderer& renderer);

	Vector2 GetPlayerPosition() const;

private:
	std::unique_ptr<Scene> currentScene;
};
