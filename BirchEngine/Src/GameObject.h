#pragma once
#include "Game.h"



class GameObject {

public:
	// constructor
	GameObject(const char* texturesheet, SDL_Renderer* ren, int x, int y);
	~GameObject();

	void Update();
	void Render();

private:

	int xpos;
	int ypos;

	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect; // source and destination rectangles
	SDL_Renderer* renderer;


};