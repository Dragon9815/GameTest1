#include "GameObject.h"
#include "ObjectManager.h"
#include "TextureManager.h"
#include "GameLogger.h"
#include "Game.h"

void GameObject::render(float camX, float camY)
{
	
}

void GameObject::update(Uint32 deltaTime)
{
	
}

void GameObject::load(std::string ID, std::string textureID, float x, float y, float width, float height)
{
	this->ID = ID;
	this->textureID = textureID;
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
}

void GameObject::handleInput(SDL_Event e)
{

}

bool GameObject::intersects(IGameObject* object)
{
	return ((this->x < object->x + object->width && this->x > object->x) || (this->x + this->width > object->x && this->x + this->width < object->x + object->width) || (this->y < object->y + object->height && this->y > object->y) || (this->y + this->height > object->y && this->y + this->height < object->y + object->height));
}