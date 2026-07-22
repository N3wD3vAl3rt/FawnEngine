#include "Image.h"
#include "stb_image.h"
#include <iostream>

Image::Image()
	: width(0),
	height(0),
	channels(0),
	pixels(nullptr)
{
}

Image::~Image()
{
	if (pixels != nullptr)
	{
		stbi_image_free(pixels);
	}
}

bool Image::Load(const std::string& filepath)
{
	pixels = stbi_load(
		filepath.c_str(),
		&width,
		&height,
		&channels,
		0);

	if (pixels == nullptr)
	{
		std::cout << stbi_failure_reason() << std::endl;
	}

	return pixels != nullptr;
}

int Image::GetWidth() const
{
	return width;
}

int Image::GetHeight() const
{
	return height;
}

int Image::GetChannels() const
{
	return channels;
}

unsigned char* Image::GetPixels() const
{
	return pixels;
}

unsigned int Image::GetPixel(int x, int y) const
{
	if (pixels == nullptr)
		return 0;

	if (x < 0 || x >= width ||
		y < 0 || y >= height)
	{
		return 0;
	}

	int index = (y * width + x) * channels;

	unsigned char r = pixels[index + 0];
	unsigned char g = pixels[index + 1];
	unsigned char b = pixels[index + 2];

	return (r << 16) | (g << 8) | b;
}