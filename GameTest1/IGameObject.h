#ifndef IGAMEOBJECT_H
#define IGAMEOBJECT_H

#include <SDL.h>
#include <string>

class IGameObject
{
public:
	virtual void render(float, float) = 0;
	virtual void update(Uint32) = 0;
	virtual void handleInput(SDL_Event) = 0;
	virtual void load(std::string, std::string, float x = 0, float y = 0, float width = 0, float height = 0) = 0;
	virtual bool intersects(IGameObject*) = 0;

	virtual std::string getID() = 0;

	float x = 0;
	float y = 0;
	float width = 0;
	float height = 0;

	std::string ID;
	std::string textureID;

private:
};


#endif