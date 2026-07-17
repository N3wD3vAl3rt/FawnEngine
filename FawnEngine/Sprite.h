#pragma once

#include <vector>

class Sprite
{
public:
	Sprite(int width, int height);

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