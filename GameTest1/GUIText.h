#ifndef GUITEXT_H
#define GUITEXT_H

#include "GameObject.h"

class GUIText : public GameObject
{
public:
	GUIText();
	~GUIText();

	void render(float camX, float camY);
	void update(Uint32 deltaTime);
	void handleInput(SDL_Event e);
	void load(std::string tileID, std::string textureID, float x, float y, float width, float height);
};

#endif