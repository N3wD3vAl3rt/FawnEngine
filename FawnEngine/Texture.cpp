#include "Texture.h"

Texture::Texture()
{
}

Texture::~Texture()
{
}

bool Texture::Load(const std::string& filepath)
{
	return image.Load(filepath);
}

const Image& Texture::GetImage() const
{
	return image;
}
