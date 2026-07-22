#pragma once

#include <string>

class Image
{
public:
	Image();
	~Image();

	bool Load(const std::string& filepath);

	int GetWidth() const;
	int GetHeight() const;
	int GetChannels() const;

	unsigned char* GetPixels() const;
	unsigned int GetPixel(int x, int y) const;

private:
	int width;
	int height;
	int channels;

	unsigned char* pixels;
};
