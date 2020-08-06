#include "Game.h"

// create instance of game
// make it a pointer

Game* game = nullptr;


int main(int argc, const char* argv[])
{
	const int FPS = 60; // capping the framerate
	const int frameDelay = 1000 / FPS; // max time we have between frames

	Uint32 frameStart;
	int frameTime;

	// declare the game
	game = new Game();

	game->init("BirchEngine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

	while (game->running()) {

		frameStart = SDL_GetTicks();

		game->handleEvents();
		game->update(); // where we handle all logic
		game->render();

		frameTime = SDL_GetTicks() - frameStart;

		// check if we need to delay
		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}

	}

	game->clean();

	return 0;

}