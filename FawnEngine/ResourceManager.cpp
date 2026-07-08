#include "ResourceManager.h"

ResourceManager::ResourceManager()
{
}

void ResourceManager::Initialize()
{
	resources.clear();
}

void ResourceManager::Shutdown()
{
	resources.clear();
}

void ResourceManager::RegisterResource(const std::string& name)
{
	resources[name] = true;
}

bool ResourceManager::HasResource(const std::string& name) const
{
	return resources.find(name) != resources.end();
}
