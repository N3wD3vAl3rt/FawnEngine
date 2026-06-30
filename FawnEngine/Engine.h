#pragma once

#include <windows.h>

class Engine
{
public:
	bool Initialize();
	int Run();
	void Shutdown();

	HWND GetWindowHandle() const;

private:
	void Update();
	void Render();

	void ClearScreen(unsigned int color);
	void DrawRect(int x, int y, int w, int h, unsigned int color);

	HINSTANCE hInstance = nullptr;
	HWND hwnd = nullptr;

	HDC hdc = nullptr;
	HDC memoryDC = nullptr;
	HBITMAP bitmap = nullptr;

	int width = 1280;
	int height = 720;

	unsigned int* pixels = nullptr;
};