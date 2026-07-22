#pragma once

#include <string>
#include <unordered_map>
#include <memory>
#include "Texture.h"

class ResourceManager
{
public:
	ResourceManager();

	void Initialize();
	void Shutdown();

	bool LoadTexture(
		const std::string& name,
		const std::string& filename);

	std::shared_ptr<Texture> GetTexture(
		const std::string& name) const;

private:
	std::unordered_map<std::string, std::shared_ptr<Texture>> textures;
};