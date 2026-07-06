#pragma once

#include "Entity.h"

class Collision
{
public:
	static bool CheckAABB(const Entity& a, const Entity& b);
};
