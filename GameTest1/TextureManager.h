#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <map>
#include <SDL.h>
#include <SDL_ttf.h>
#include "Texture.h"

class TextureManager
{
public:
	
	static TextureManager* Instance()
	{
		if (m_pInstance == 0)
		{
			m_pInstance = new TextureManager();
		}

		return m_pInstance;
	}

	void setRenderer(SDL_Renderer* renderer);
	SDL_Renderer* getRenderer();
	void setFont(TTF_Font* font);
	TTF_Font* getFont();

	float getTextureHeight(std::string textureID);
	float getTextureWidth(std::string textureID);

	bool load(std::string fileName, std::string id);
	bool loadText(std::string text, SDL_Color textColor, std::string id);
	void draw(std::string id, float x, float y, float width, float height, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void drawFrame(std::string id, float x, float y, float width, float height, int currentRow, int currentFrame, SDL_RendererFlip flip = SDL_FLIP_NONE);

	void render();

private:
	
	TextureManager() 
	{
		this->m_Renderer = NULL;
	}

	~TextureManager() {};

	std::map<std::string, Texture> m_TextureMap;

	SDL_Renderer* m_Renderer;
	TTF_Font* m_Font;

	static TextureManager* m_pInstance;
};

#endif