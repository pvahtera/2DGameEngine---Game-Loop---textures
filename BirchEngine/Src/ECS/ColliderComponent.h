#pragma once

#include <string>
#include "Components.h"
#include "SDL.h"

class ColliderComponent : public Component
{
	// represent area that is collidable
	SDL_Rect collider;
	// when we detect collision, grab a tag of object
	// i.e. enemy has a different effect to a wall
	std::string tag; 

	TransformComponent* transform;

	void init() override
	{
		// error checking
		if (entity->hasComponent<TransformComponent>())
		{
			entity->addComponent<TransformComponent>();
		}
		transform = &entity->getComponent<TransformComponent>();
	}

};
