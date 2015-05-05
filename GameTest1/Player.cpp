#include "Player.h"
#include "ObjectManager.h"
#include "TextureManager.h"
#include "Game.h"
#include "GameLogger.h"

Player::Player()
{
	x = 0;
	y = 0;

	this->direction = new Vector2D(0, 0);
}

Player::~Player()
{

}

void Player::render(float camX, float camY)
{
	GameObject::render(camX, camY);
	TextureManager::Instance()->draw(this->textureID, this->x - camX, this->y - camY, this->width, this->height);
}

void Player::update(Uint32 deltaTime)
{
	GameObject::update(deltaTime);

	this->x += this->direction->getX() * deltaTime;
	this->y += this->direction->getY() * deltaTime;

	if (this->x < -(TERRAIN_WIDTH / 2 - SCREEN_WIDTH / 2))
	{
		this->x = -(TERRAIN_WIDTH / 2 - SCREEN_WIDTH / 2);
	}
	else if (this->x + this->width > (TERRAIN_WIDTH / 2 + SCREEN_WIDTH / 2))
	{
		this->x = (TERRAIN_WIDTH / 2 + SCREEN_WIDTH / 2) - this->width;
	}

	if (this->y < -(TERRAIN_HEIGHT / 2 - SCREEN_HEIGHT / 2))
	{
		this->y = -(TERRAIN_HEIGHT / 2 - SCREEN_HEIGHT / 2);
	}
	else if (this->y + this->height > (TERRAIN_HEIGHT / 2 + SCREEN_HEIGHT / 2))
	{
		this->y = (TERRAIN_HEIGHT / 2 + SCREEN_HEIGHT / 2) - this->height;
	}

	
}

void Player::load(std::string PlayerID, std::string textureID, float x, float y, float width, float height)
{
	GameObject::load(PlayerID, textureID, x, y, width, height);
}

void Player::handleInput(SDL_Event e)
{
	GameObject::handleInput(e);

	const Uint8* keysates = SDL_GetKeyboardState(0);

	if (keysates != 0)
	{
		if (keysates[SDL_SCANCODE_UP] == 1 || keysates[SDL_SCANCODE_DOWN] == 1)
		{
			if (keysates[SDL_SCANCODE_UP] == 1)
			{
				this->direction->setY(-this->maxSpeed);
					
			}

			if (keysates[SDL_SCANCODE_DOWN] == 1)
			{
				this->direction->setY(this->maxSpeed);
			}
		}
		else
		{
			this->direction->setY(0);
		}

		if (keysates[SDL_SCANCODE_LEFT] == 1 || keysates[SDL_SCANCODE_RIGHT] == 1)
		{

			if (keysates[SDL_SCANCODE_LEFT] == 1)
			{
				this->direction->setX(-this->maxSpeed);
			}

			if (keysates[SDL_SCANCODE_RIGHT] == 1)
			{
				this->direction->setX(this->maxSpeed);
			}
		}
		else
		{
			this->direction->setX(0);
		}
	}
}

void Player::setSpeed(float speed)
{
	this->maxSpeed = speed;
}