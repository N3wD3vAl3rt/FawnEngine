#include "Renderer.h"

bool Renderer::Initialize(HWND hwnd, int w, int h)
{
	width = w;
	height = h;

	hdc = GetDC(hwnd);
	memoryDC = CreateCompatibleDC(hdc);

	BITMAPINFO bmi = {};
	bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	bmi.bmiHeader.biWidth = width;
	bmi.bmiHeader.biHeight = -height; // top-down buffer
	bmi.bmiHeader.biPlanes = 1;
	bmi.bmiHeader.biBitCount = 32;
	bmi.bmiHeader.biCompression = BI_RGB;

	void* ptr = nullptr;

	bitmap = CreateDIBSection(
		hdc,
		&bmi,
		DIB_RGB_COLORS,
		&ptr,
		nullptr,
		0
	);

	if (!bitmap || !ptr)
		return false;

	SelectObject(memoryDC, bitmap);

	pixels = static_cast<unsigned int*>(ptr);

	return true;
}

void Renderer::Clear(unsigned int color)
{
	for (int i = 0; i < width * height; i++)
	{
		pixels[i] = color;
	}
}

void Renderer::DrawRect(int x, int y, int w, int h, unsigned int color)
{
	for (int py = 0; py < h; py++)
	{
		for (int px = 0; px < w; px++)
		{
			int drawX = x + px;
			int drawY = y + py;

			if (drawX >= 0 && drawX < width &&
				drawY >= 0 && drawY < height)
			{
				pixels[drawY * width + drawX] = color;
			}
		}
	}
}

void Renderer::Present()
{
	BitBlt(
		hdc,
		0, 0,
		width,
		height,
		memoryDC,
		0, 0,
		SRCCOPY
	);
}

