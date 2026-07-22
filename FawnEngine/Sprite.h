#pragma once

#include <vector>
#include "Image.h"

class Sprite
{
public:
	Sprite(int width, int height);
	Sprite(const Image& image);

	int GetWidth() const;
	int GetHeight() const;

	unsigned int* GetPixels();
	const unsigned int* GetPixels() const;

	void SetPixel(int x, int y, unsigned int color);

	void Fill(unsigned int color);

private:
	int width;
	int height;

	std::vector<unsigned int> pixels;
};