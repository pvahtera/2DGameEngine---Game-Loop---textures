#include "Game.h"

SDL_Texture* playerTex;

Game::Game()
{}
Game::~Game()
{}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "subsystems initialized" << std::endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		//window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
		//check if window has been created properly
		if (window)
		{
			std::cout << "Window created" << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "renderer created" << std::endl;
		}

		isRunning = true;

	}
	else {
		isRunning = false;
	}

	// we first need surface before we can initialize image

	SDL_Surface* tmpSurface = IMG_Load("assets/Player.png");
	//SDL_Surface *tmpSurface = IMG_Load("C:/Users/w100692/Dev/2D_Game_Engine_textures/2D_Game_Engine/assets/Player.png");

	playerTex = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);


}

void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);

	// check the type of event

	switch (event.type)
	{
		// when we click x on window will be found by handlevents
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}

}


void Game::update()
{
	cnt++;
	std::cout << cnt << std::endl;

}

void Game::render()
{
	// clear buffer
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, playerTex, NULL, NULL);
	// this is where we add stuff to render
	SDL_RenderPresent(renderer);


}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game cleaned" << std::endl;
}
