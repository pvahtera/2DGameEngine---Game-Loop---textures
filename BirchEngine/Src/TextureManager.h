#pragma once

// We want this texture manager to return SDL texture to us

#include "Game.h"


class TextureManager {

public:
	static SDL_Texture* LoadTexture(const char* filename);
	static void Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest);
};