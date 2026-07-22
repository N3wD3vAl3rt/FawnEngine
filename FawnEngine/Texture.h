#pragma once

#include "Image.h"

class Texture
{
public:
	Texture();
	~Texture();

	bool Load(const std::string& filepath);

	const Image& GetImage() const;

private:
	Image image;
};
