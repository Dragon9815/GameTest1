#include "Tile.h"
#include "ObjectManager.h"
#include "TextureManager.h"
#include "Game.h"
#include "GameLogger.h"

Tile::Tile()
{
	x = 0;
	y = 0;
}

Tile::~Tile()
{

}

void Tile::render(float camX, float camY)
{
	GameObject::render(camX, camY);
	TextureManager::Instance()->draw(this->textureID, (int)(this->x - camX), (int)(this->y - camY), (int)this->width, (int)this->height);
}

void Tile::update(Uint32 deltaTime)
{
	GameObject::update(deltaTime);
}

void Tile::load(std::string tileID, std::string textureID, float x, float y, float width, float height)
{
	GameObject::load(tileID, textureID, x, y, width, height);
}

void Tile::handleInput(SDL_Event e)
{
	GameObject::handleInput(e);
}