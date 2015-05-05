#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"
#include "Vector2D.h"

class Player : public GameObject
{
public:
	Player();
	~Player();

	void render(float camX, float camY);
	void update(Uint32 deltaTime);
	void setSpeed(float speed);

	void handleInput(SDL_Event e);
	void load(std::string PlayerID, std::string textureID, float x = 0, float y = 0, float width = 0, float height = 0);

private:
	Vector2D* direction;

	float maxSpeed;
};

#endif