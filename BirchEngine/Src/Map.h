#pragma once
#include "Game.h"


class Map
{
public:
	// create a map

	Map();
	~Map();

	void LoadMap(int arr[20][25]);
	void DrawMap();


private:
	SDL_Rect src, dest;
	SDL_Texture* dirt;
	SDL_Texture* water;
	SDL_Texture* grass;

	int map[20][25];

};