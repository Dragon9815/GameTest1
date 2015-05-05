#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SDL.h>
#include <string>
#include "IGameObject.h"

class GameObject : public IGameObject
{
public:
	void render(float camX, float camY);
	void update(Uint32 deltaTime);
	void handleInput(SDL_Event e);
	void load(std::string ID, std::string textureID, float x = 0, float y = 0, float width = 0, float height = 0);
	bool intersects(IGameObject* object);


	void setX(float x) { this->x = x; }
	void setY(float y) { this->y = y; }
	void setWidth(float width) { this->width = width; }
	void setHeight(float height) { this->height = height; }

	float getX() { return this->x; }
	float getY() { return this->y; }
	float getWidth() { return this->width; }
	float getHeight() { return this->height; }

	std::string getID() { return this->ID; }

private:
};

enum { KEY_W, KEY_S, KEY_A, KEY_D, KEYS_TOTAL };

#endif