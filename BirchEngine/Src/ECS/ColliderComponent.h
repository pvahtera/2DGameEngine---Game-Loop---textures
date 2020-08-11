#pragma once

#include <string>
#include "Components.h"
#include "SDL.h"

class ColliderComponent : public Component
{
public:
	// represent area that is collidable
	SDL_Rect collider;
	// when we detect collision, grab a tag of object
	// i.e. enemy has a different effect to a wall
	std::string tag; 

	TransformComponent* transform;

	ColliderComponent(std::string t)
	{
		tag = t;
	}


	void init() override
	{
		// error checking
		if (entity->hasComponent<TransformComponent>())
		{
			entity->addComponent<TransformComponent>();
		}
		transform = &entity->getComponent<TransformComponent>();
	}

	void update() override
	{
		collider.x = static_cast<int>(transform->position.x);
		collider.y = static_cast<int>(transform->position.y);
		collider.w = transform->width * transform->scale;
		collider.h = transform->height * transform->scale;
	}

};
