#pragma once
#include <Windows.h>

class Renderer
{
public:
	bool Initialize(HWND hwnd, int width, int height);
	void Clear(unsigned int color);
	void DrawRect(int x, int y, int w, int h, unsigned int color);
	void Present();

private:
	HDC hdc = nullptr;
	HDC memoryDC = nullptr;
	HBITMAP bitmap = nullptr;

	unsigned int* pixels = nullptr;

	int width = 0;
	int height = 0;
};