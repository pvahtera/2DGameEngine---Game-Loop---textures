#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"

/*
// this part is no longer needed with GameObject class implemented
SDL_Texture* playerTex;
SDL_Rect srcR, destR; // source and destination rectangles that scale our pic

*/

GameObject* player;
GameObject* enemy;

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

	/*
	// ***in the initial implementation, but not needed anymore
	// we first need surface before we can initialize image
	SDL_Surface* tmpSurface = IMG_Load("assets/Player.png");
	playerTex = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);
	
	*/

	/*
	// this part is no longer needed with GameObject class implemented
	playerTex = TextureManager::LoadTexture("assets/Player.png", renderer);
	*/

	player = new GameObject("assets/Player2.png", renderer, 0, 0);
	enemy = new GameObject("assets/boogey_png.png", renderer, 50, 50);

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

	/*
	//this part is no longer needed with GameObject class implemented
	cnt++;
	// size of pic
	destR.h = 64; // height
	destR.w = 64; // width

	//we can use the rectangle to move our pic
	destR.x = cnt;

	std::cout << cnt << std::endl;
	*/
	player->Update();
	enemy->Update();

}

void Game::render()
{
	// clear buffer
	SDL_RenderClear(renderer);

	player->Render();
	enemy->Render();
	//SDL_RenderCopy(renderer, playerTex, NULL, &destR);
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
