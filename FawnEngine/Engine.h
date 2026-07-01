#pragma once

#include <windows.h>
#include "Renderer.h"

class Engine
{
public:
	bool Initialize();
	int Run();
	void Shutdown();

	HWND GetWindowHandle() const;

private:
	void Tick();
	void Update();
	void Render();

	HINSTANCE hInstance = nullptr;
	HWND hwnd = nullptr;

	int width = 1280;
	int height = 720;

	Renderer renderer;
};