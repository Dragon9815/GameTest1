#ifndef TEXTURE_H
#define TEXTURE_H

#include <SDL.h>

class Texture
{
public:
	Texture() {};
	~Texture() {};

	void setTexture(SDL_Texture* texture, float width, float height);
	SDL_Texture* getTexture();

	void setHeight(float height) { this->height = height; }
	void setWidth(float width) { this->width = width; }

	float getHeight() { return this->height; }
	float getWidth() { return this->width; }

private:
	SDL_Texture* texture;
	float height;
	float width;
};

#endif