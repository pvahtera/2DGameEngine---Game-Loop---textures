#include "Game.h"

// create instance of game
// make it a pointer

Game* game = nullptr;


int main(int argc, const char* argv[])
{

	// declare the game
	game = new Game();

	game->init("BirchEngine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

	while (game->running()) {
		game->handleEvents();
		game->update(); // where we handle all logic
		game->render();

	}

	game->clean();

	return 0;

}