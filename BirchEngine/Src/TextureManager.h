#pragma once

// We want this texture manager to return SDL texture to us

#include "Game.h"


class TextureManager {

public:
	static SDL_Texture* LoadTexture(const char* filename, SDL_Renderer* ren);
};