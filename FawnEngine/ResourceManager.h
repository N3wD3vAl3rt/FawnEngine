#pragma once

#include <string>
#include <unordered_map>

class ResourceManager
{
public:
	ResourceManager();

	void Initialize();
	void Shutdown();

	void RegisterResource(const std::string& name);

	bool HasResource(const std::string& name) const;

private:
	std::unordered_map<std::string, bool> resources;
};