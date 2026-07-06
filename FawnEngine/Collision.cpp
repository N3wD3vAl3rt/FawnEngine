#include "Collision.h"

bool Collision::CheckAABB(const Entity& a, const Entity& b)
{
	AABB boxA = a.GetBounds();
	AABB boxB = b.GetBounds();

	return
		(
			boxA.x < boxB.x + boxB.w &&
			boxA.x + boxA.w > boxB.x &&
			boxA.y < boxB.y + boxB.h &&
			boxA.y + boxA.h > boxB.y
			);
}
