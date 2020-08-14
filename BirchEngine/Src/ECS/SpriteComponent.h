#pragma once

#include "Components.h"
#include "SDL.h"
#include "../TextureManager.h"

class SpriteComponent : public Component
{
private:
	TransformComponent *transform;
	SDL_Texture *texture;
	SDL_Rect srcRect, destRect;

	// to animate our object

	bool animated = false;
	int frames = 0;
	int speed = 100; // delay between frames in milliseconds

public:
	SpriteComponent() = default;
	SpriteComponent(const char* path)
	{
		setTex(path); // load texture here
	}

	SpriteComponent(const char* path, int nFrames, int mSpeed)
	{
		animated = true;
		frames = nFrames;
		speed = mSpeed;
		setTex(path); // load texture here
	}



	~SpriteComponent()
	{
		SDL_DestroyTexture(texture);
	}

	void setTex(const char* path)
	{
		texture = TextureManager::LoadTexture(path);
	}


	void init() override
	{
		transform = &entity->getComponent<TransformComponent>();

		//initialize our rectangles
		srcRect.x = srcRect.y = 0;
		srcRect.w = transform->width;
		srcRect.h = transform->height;
	}
	void update() override
	{
		if (animated)
		{
			srcRect.x = srcRect.w * static_cast<int>((SDL_GetTicks() / speed) % frames);
		}

		// this function is for moving around
		// rectangle expects int so that's why we cast them
		destRect.x = (int)transform->position.x;
		destRect.y = (int)transform->position.y;
		destRect.w = transform->width * transform->scale;
		destRect.h = transform->height * transform->scale;

	}
	void draw() override
	{
		TextureManager::Draw(texture, srcRect, destRect);
	}
};
