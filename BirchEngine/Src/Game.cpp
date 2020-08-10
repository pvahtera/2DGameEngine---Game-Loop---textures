#include "Game.h"
#include "TextureManager.h"
#include "Map.h"
#include "ECS/Components.h"

Map* map;
// create a new manager
Manager manager;

SDL_Renderer* Game::renderer = nullptr;

auto& player(manager.addEntity());

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

	/*
	player = new GameObject("assets/Player2.png", 0, 0);
	enemy = new GameObject("assets/boogey_png.png", 50, 50);
	*/

	map = new Map();

	player.addComponent<PositionComponent>();
	player.addComponent<SpriteComponent>("assets/Player2.png");

	/*
	newPlayer.addComponent<PositionComponent>();
	newPlayer.getComponent<PositionComponent>().setPos(500, 500);
	*/


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
	manager.refresh();
	manager.update(); // update components

	/*
		player->Update();
	enemy->Update();
	
	std::cout << newPlayer.getComponent<PositionComponent>().x() << "," <<
		newPlayer.getComponent<PositionComponent>().y() << "," << std::endl;
	
	*/


}

void Game::render()
{

	SDL_RenderClear(renderer);
	map->DrawMap();

	manager.draw();
	SDL_RenderPresent(renderer);


}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game cleaned" << std::endl;
}
