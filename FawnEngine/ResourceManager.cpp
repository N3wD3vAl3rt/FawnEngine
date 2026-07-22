#include "ResourceManager.h"

ResourceManager::ResourceManager()
{
}

void ResourceManager::Initialize()
{
    textures.clear();
}

void ResourceManager::Shutdown()
{
    textures.clear();
}

bool ResourceManager::LoadTexture(
    const std::string& name,
    const std::string& filename)
{
    auto texture = std::make_shared<Texture>();

    if (!texture->Load(filename))
    {
        return false;
    }

    textures[name] = texture;

    return true;
}

std::shared_ptr<Texture> ResourceManager::GetTexture(
    const std::string& name) const
{
    auto it = textures.find(name);

    if (it == textures.end())
    {
        return nullptr;
    }

    return it->second;
}