#pragma once
#include "SDL.h"

class Collision
{
public:
	// collision method for AABB
	static bool AABB(const SDL_Rect& recA, const SDL_Rect& recB);
};
