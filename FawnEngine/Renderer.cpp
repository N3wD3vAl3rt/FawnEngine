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

void Renderer::DrawPixel(int x, int y, unsigned int color)
{
	if (x < 0 || x >= width ||
		y < 0 || y >= height)
	{
		return;
	}

	pixels[y * width + x] = color;
}

void Renderer::DrawRect(int x, int y, int w, int h, unsigned int color)
{
	for (int py = 0; py < h; py++)
	{
		for (int px = 0; px < w; px++)
		{
			DrawPixel(x + px, y + py, color);
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

void Renderer::DrawSprite(
	int x,
	int y,
	const Sprite& sprite)
{
	const unsigned int* spritePixels = sprite.GetPixels();

	int spriteWidth = sprite.GetWidth();
	int spriteHeight = sprite.GetHeight();

	for (int py = 0; py < spriteHeight; py++)
	{
		for (int px = 0; px < spriteWidth; px++)
		{
			DrawPixel(
				x + px,
				y + py,
				spritePixels[py * spriteWidth + px]);
		}
	}
}

void Renderer::DrawTexture(const Texture& texture, int x, int y)
{
	const Image& image = texture.GetImage();

	const unsigned char* pixels = image.GetPixels();

	if (!pixels)
		return;

	int width = image.GetWidth();
	int height = image.GetHeight();

	for (int iy = 0; iy < height; iy++)
	{
		for (int ix = 0; ix < width; ix++)
		{
			DrawPixel(
				x + ix,
				y + iy,
				image.GetPixel(ix, iy));
		}
	}
}