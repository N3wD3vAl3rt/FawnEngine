#include "Sprite.h"

Sprite::Sprite(int width, int height)
	: width(width), height(height), pixels(width* height, 0)
{
}

int Sprite::GetWidth() const
{
	return width;
}

int Sprite::GetHeight() const
{
	return height;
}

unsigned int* Sprite::GetPixels()
{
	return pixels.data();
}

const unsigned int* Sprite::GetPixels() const
{
	return pixels.data();
}

void Sprite::SetPixel(int x, int y, unsigned int color)
{
	if (x < 0 || x >= width ||
		y < 0 || y >= height)
	{
		return;
	}

	pixels[y * width + x] = color;
}

void Sprite::Fill(unsigned int color)
{
	for (unsigned int& pixel : pixels)
	{
		pixel = color;
	}
}
