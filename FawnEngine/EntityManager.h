#pragma once

#include <vector>
#include <memory>
#include "Entity.h"
#include "Renderer.h"
#include "Vector2.h"
#include <cstddef>
#include <type_traits>

class EntityManager
{
public:
	EntityManager();
	~EntityManager();

	void Update();
	void Render(const Vector2& camPos, Renderer& renderer);

	void AddEntity(std::unique_ptr<Entity> entity);

	Entity* GetFirstEntity() const;
	Entity* GetEntityByIndex(std::size_t index) const;
	Entity* GetFirstEntityOfType(EntityType type) const;

	template<typename T>
	T* Spawn()
	{
		static_assert(std::is_base_of<Entity, T>::value, "T must derive from Entity");

		std::unique_ptr<T> entity = std::make_unique<T>();
		T* ptr = entity.get();

		entities.push_back(std::move(entity));

		return ptr;
	}

	void Cleanup();

private:
	std::vector<std::unique_ptr<Entity>> entities;
};
