#include "Texture.h"

void Texture::setTexture(SDL_Texture* texture, float height, float width)
{
	this->texture = texture;
	this->height = height;
	this->width = width;
}

SDL_Texture* Texture::getTexture()
{
	return this->texture;
}