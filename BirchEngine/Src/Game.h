
#ifndef Game_hpp
#define Game_hpp
#define SDL_MAIN_HANDLED

#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include <vector>

class ColliderComponent;


class Game {

public:
	Game(); // constructor
	~Game(); // deconstructor (when we close the game)

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void handleEvents();
	void update();
	void render();
	void clean();

	static void AddTile(int srcX, int srcY, int xpos, int ypos);

	bool running() { return isRunning; }
	static SDL_Renderer* renderer;
	static SDL_Event event;
	static std::vector<ColliderComponent*> colliders;
	static bool isRunning;

private:
	int cnt = 0;
	SDL_Window* window;



};


#endif /* Game_hpp */
