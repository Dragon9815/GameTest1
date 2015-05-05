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

void GUIText::render(int camX, int camY)
{
	GameObject::render(0, 0);
	TextureManager::Instance()->draw(this->textureID, this->x, this->y, this->width, this->height);
}

void GUIText::update(Uint32 deltaTime)
{
	GameObject::update(deltaTime);
}

void GUIText::load(std::string TextID, std::string textureID, int x, int y, int width, int height)
{
	int w, h;
	w = width;
	h = height;
	if (width == -1)
	{
		w = TextureManager::Instance()->getTextureWidth(textureID);
	}

	if (h == -1)
	{
		h = TextureManager::Instance()->getTextureHeight(textureID);
	}

	GameObject::load(TextID, textureID, x, y, w, h);
}

void GUIText::handleInput(SDL_Event e)
{
	GameObject::handleInput(e);
}