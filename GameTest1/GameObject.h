#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SDL.h>
#include <string>
#include "IGameObject.h"
#include "Size.h"
#include "Camera.h"
#include "Location.h"

class Camera; // Forward Deklaration

class GameObject : public IGameObject
{
public:

	GameObject();
	~GameObject();

	void render(Camera* cam);
	void update(Uint32 deltaTime);
	void handleInput(SDL_Event e);
	void load(std::string ID, std::string textureID, float x = 0, float y = 0, float width = 0, float height = 0);
	bool intersects(IGameObject* object);

	std::string getID() { return this->ID; }

private:
};

enum { KEY_W, KEY_S, KEY_A, KEY_D, KEYS_TOTAL };

#endif