#include "Tile.h"
#include "ObjectManager.h"
#include "TextureManager.h"
#include "Game.h"
#include "GameLogger.h"

Tile::Tile()
{
	GameObject::GameObject();
}

Tile::~Tile()
{

}

void Tile::render(Camera* cam)
{
	GameObject::render(cam);
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