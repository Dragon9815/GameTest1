#include "GUIText.h"
#include "ObjectManager.h"
#include "TextureManager.h"
#include "Game.h"
#include "GameLogger.h"

GUIText::GUIText()
{
	x = 0;
	y = 0;
}

GUIText::~GUIText()
{

}

void GUIText::render(float camX, float camY)
{
	GameObject::render(0, 0);
	TextureManager::Instance()->draw(this->textureID, this->x, this->y, this->width, this->height);
}

void GUIText::update(Uint32 deltaTime)
{
	GameObject::update(deltaTime);
}

void GUIText::load(std::string TextID, std::string textureID, float x, float y, float width, float height)
{
	/*int w, h;
	w = width;
	h = height;
	if (w == -1)
	{
		w = TextureManager::Instance()->getTextureWidth(textureID);
	}

	if (h == -1)
	{
		h = TextureManager::Instance()->getTextureHeight(textureID);
	}*/

	GameObject::load(TextID, textureID, x, y, width, height);
}

void GUIText::handleInput(SDL_Event e)
{
	GameObject::handleInput(e);
}