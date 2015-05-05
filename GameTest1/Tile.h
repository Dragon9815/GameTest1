#ifndef TILE_H
#define TILE_H

#include "GameObject.h"
#include "Vector2D.h"

class Tile : public GameObject
{
public:
	Tile();
	~Tile();

	void render(float camX, float camY);
	void update(Uint32 deltaTime);
	void handleInput(SDL_Event e);
	void load(std::string tileID, std::string textureID, float x, float y, float width = 0, float height = 0);

private:
};

#endif