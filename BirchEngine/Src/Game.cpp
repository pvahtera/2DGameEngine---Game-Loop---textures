#include "Game.h"
#include "TextureManager.h"
#include "Map.h"
#include "ECS/Components.h"
#include "Vector2D.h"
#include "Collision.h"

Map* map;
// create a new manager
Manager manager;

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;
auto& player(manager.addEntity());
auto& wall(manager.addEntity());

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

	map = new Map();

	player.addComponent<TransformComponent>(2);
	player.addComponent<SpriteComponent>("assets/Player2.png");
	player.addComponent<KeyboardController>(); // control player
	player.addComponent<ColliderComponent>("player");

	wall.addComponent<TransformComponent>(300.0f, 300.0f, 300, 20, 1);
	wall.addComponent<SpriteComponent>("assets/dirt.png");
	wall.addComponent<ColliderComponent>("wall");


}

void Game::handleEvents()
{
	
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

	if (Collision::AABB(player.getComponent<ColliderComponent>().collider,
		wall.getComponent<ColliderComponent>().collider))
	{
		player.getComponent<TransformComponent>().scale = 1;
		std::cout << "Wall hit!" << std::endl;
	}

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
