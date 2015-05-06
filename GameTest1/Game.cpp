#include "Game.h"
#include "GameLogger.h"
#include "TextureManager.h"
#include "ObjectManager.h"
#include "Tile.h"
#include "GUIText.h"
#include "defs.h"
#include <sstream>

Game::Game()
{
	this->gWindow = NULL;

	for (int i = 0; i < KEYS_TOTAL; i++)
	{
		this->KeysDown[i] = false;
	}

	this->renderTimer.start();

	this->Camera = new Vector2D(0, 0);
}

Game::~Game()
{

}

void Game::init(int width, int height)
{
	this->ScreenHeight = height;
	this->ScreenWidth  = width;
	
	LOG("Game Init...  ");

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
	{
		CRASH(SDL_GetError());
	}

	//Create window
	this->gWindow = SDL_CreateWindow("GameTest1", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, this->ScreenWidth, this->ScreenHeight, SDL_WINDOW_SHOWN);
	if (gWindow == NULL)
	{
		CRASH(SDL_GetError());
	}

	this->gRenderer = SDL_CreateRenderer(this->gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (gRenderer == NULL)
	{
		CRASH(SDL_GetError());
	}

	if (TTF_Init() == -1)
	{
		CRASH(SDL_GetError());
	}

	gFont = TTF_OpenFont("C:\\Windows\\Fonts\\Arial.ttf", 14);
	if (this->gFont == NULL)
	{
		CRASH(SDL_GetError());
	}

	TextureManager::Instance()->setRenderer(this->gRenderer);
	TextureManager::Instance()->setFont(this->gFont);

	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	
	this->load();

	LOG("Done!");
}

void Game::render()
{
	SDL_RenderClear(this->gRenderer);
	ObjectManager::Instance()->render(this->Camera->getX(), this->Camera->getY());
	SDL_RenderPresent(this->gRenderer);
}

void Game::update()
{
	ObjectManager::Instance()->update(&this->renderTimer);
	this->renderTimer.restart();

	this->Camera->setX(-SCREEN_WIDTH / 2 - this->mainPlayer.getX() / 2 /*+ this->mainPlayer.getWidth() / 2*/);
	this->Camera->setY(-SCREEN_HEIGHT / 2 - this->mainPlayer.getY() / 2 /*+ this->mainPlayer.getHeight() / 2*/);
	
}

void Game::handleInput(SDL_Event e)
{
	ObjectManager::Instance()->handleInput(e);
}

void Game::load()
{
	TextureManager::Instance()->load("Test.png", "test");
	TextureManager::Instance()->load("grass.png", "grass");

	SDL_Color textColor = { 0, 0, 0, 255 };
	TextureManager::Instance()->loadText("Hallo", textColor, "Text1");

	int pos;
	std::stringstream ss;
	for (int y = 0; y < TERRAIN_HEIGHT; y += 64)
	{
		for (int x = 0; x < TERRAIN_WIDTH; x += 64)
		{
			this->tiles.push_back(new Tile());
			pos = ((y / 64) * (TERRAIN_WIDTH / 64)) + x / 64;
			this->tiles[pos]->load("GrassTile", "grass", x - (TERRAIN_WIDTH / 2 - SCREEN_WIDTH / 2), y - (TERRAIN_HEIGHT / 2 - SCREEN_HEIGHT / 2), 64, 64);
			REGISTER(this->tiles[pos], 0);
		}
	}

	mainPlayer.load("Player", "test", 0, 0, 64, 64);
	REGISTER(&this->mainPlayer, 1);
	mainPlayer.setSpeed(2.0f);
	
	testText.load("TestText1", "Text1", 0, 0, 100, 100);
	REGISTER(&this->testText, 0)
}