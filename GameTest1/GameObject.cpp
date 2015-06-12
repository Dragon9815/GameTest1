#include "GameObject.h"
#include "ObjectManager.h"
#include "TextureManager.h"
#include "GameLogger.h"
#include "Game.h"

GameObject::GameObject () {
	Location = MyLocation(0, 0);
	Size = MySize(0, 0);
}

GameObject::~GameObject() {

}

void GameObject::render(Camera* cam)
{
	TextureManager::Instance()->draw(this->textureID, cam->getRelativeX(Location.X), cam->getRelativeY(Location.Y), Size.Width, Size.Height);
}

void GameObject::update(Uint32 deltaTime)
{
	
}

void GameObject::load(std::string ID, std::string textureID, float x, float y, float width, float height)
{
	this->ID = ID;
	this->textureID = textureID;
	Location = MyLocation(x, y);
	Size = MySize(width, height);
}

void GameObject::handleInput(SDL_Event e)
{

}

bool GameObject::intersects(IGameObject* object)
{
	return ((Location.X < object->Location.X + object->Size.Width && this->Location.X > object->Location.X) || (this->Location.X + this->Size.Width > object->Location.X && this->Location.X + this->Size.Width < object->Location.X + object->Size.Width) || (this->Location.Y < object->Location.Y + object->Size.Height && this->Location.Y > object->Location.Y) || (this->Location.Y + this->Size.Height > object->Location.Y && this->Location.Y + this->Size.Height < object->Location.Y + object->Size.Height));
}