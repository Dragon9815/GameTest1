#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <vector>
#include "Tile.h"
#include "Timer.h"
#include "Player.h"
#include "GUIText.h"

#define SCREEN_HEIGHT 720
#define SCREEN_WIDTH  1280

#define TERRAIN_HEIGHT 4992
#define TERRAIN_WIDTH  4992

class Game
{
public:
	Game();
	~Game();

	void init(int width, int height);

	void render();
	void update();
	void handleInput(SDL_Event(e));

private:

	void load();

	int ScreenHeight;
	int ScreenWidth;

	SDL_Window* gWindow;
	SDL_Renderer* gRenderer;
	TTF_Font* gFont;

	Timer renderTimer;
	Uint32 oldDelta;

	int m_currentFrame;

	Player mainPlayer;
	std::vector<Tile*> tiles;
	Tile Test;
	GUIText testText;

	Vector2D* Camera;

	bool KeysDown[4];
	
	
};

#endif