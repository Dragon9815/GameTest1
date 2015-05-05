#include "TextureManager.h"
#include "GameLogger.h"
#include <sstream>
#include <SDL_image.h>
#include "Game.h"

TextureManager* TextureManager::m_pInstance = 0;

void TextureManager::setRenderer(SDL_Renderer* renderer)
{
	this->m_Renderer = renderer;
}

SDL_Renderer* TextureManager::getRenderer()
{
	return this->m_Renderer;
}

void TextureManager::setFont(TTF_Font* font)
{
	this->m_Font = font;
}

TTF_Font* TextureManager::getFont()
{
	return this->m_Font;
}

float TextureManager::getTextureHeight(std::string textureID)
{
	Texture tex = this->m_TextureMap[textureID];

	return tex.getHeight();
}

float TextureManager::getTextureWidth(std::string textureID)
{
	Texture tex = this->m_TextureMap[textureID];

	return tex.getWidth();
}

bool TextureManager::load(std::string fileName, std::string id)
{
	SDL_Surface* pTempSurface = IMG_Load(fileName.c_str());

	if (pTempSurface == 0)
	{
		FATAL(IMG_GetError());
		return false;
	}

	SDL_Texture* pTexture = SDL_CreateTextureFromSurface(this->m_Renderer, pTempSurface);

	if (pTexture != 0)
	{
		Texture tex;
		tex.setTexture(pTexture, (float)pTempSurface->w, (float)pTempSurface->h);
		m_TextureMap[id] = tex;
		SDL_FreeSurface(pTempSurface);
		return true;
	}

	FATAL(SDL_GetError());
	SDL_FreeSurface(pTempSurface);
	return false;
}

bool TextureManager::loadText(std::string text, SDL_Color textColor, std::string id)
{
	SDL_Surface* textSurface = TTF_RenderText_Solid(this->m_Font, text.c_str(), textColor);

	if (textSurface == NULL)
	{
		FATAL(TTF_GetError());
		return false;
	}

	SDL_Texture* pTexture = SDL_CreateTextureFromSurface(this->m_Renderer, textSurface);

	if (pTexture != 0)
	{
		Texture tex;
		tex.setTexture(pTexture, (float)textSurface->w, (float)textSurface->h);
		m_TextureMap[id] = tex;
		SDL_FreeSurface(textSurface);
		return true;
	}

	FATAL(SDL_GetError());
	SDL_FreeSurface(textSurface);
	return false;
}

void TextureManager::draw(std::string id, float x, float y, float width, float height, SDL_RendererFlip flip)
{
	SDL_Rect srcRect;
	SDL_Rect destRect;

	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = destRect.w = (int)width;
	srcRect.h = destRect.h = (int)height;
	destRect.x = (int)x;
	destRect.y = (int)y;

	SDL_RenderCopyEx(this->m_Renderer, m_TextureMap[id].getTexture(), &srcRect, &destRect, 0, 0, flip);
}

void TextureManager::drawFrame(std::string id, float x, float y, float width, float height, int currentRow, int currentFrame, SDL_RendererFlip flip)
{
	SDL_Rect srcRect;
	SDL_Rect destRect;

	srcRect.x = (int)(width * currentFrame);
	srcRect.y = (int)(height * (currentRow - 1));
	srcRect.w = destRect.w = (int)width;
	srcRect.h = destRect.h = (int)height;
	destRect.x = (int)x;
	destRect.y = (int)y;

	SDL_RenderCopyEx(this->m_Renderer, m_TextureMap[id].getTexture(), &srcRect, &destRect, 0, 0, flip);
}