#include "Player.h"
#include "ObjectManager.h"
#include "TextureManager.h"
#include "Game.h"
#include "GameLogger.h"
#include "defs.h"

Player::Player()
{
	GameObject::GameObject();

	this->direction = new Vector2D(0, 0);
}

Player::~Player()
{

}

void Player::render(Camera* cam)
{
	GameObject::render(cam);
	
}

void Player::update(Uint32 deltaTime)
{
	GameObject::update(deltaTime);

	Location.X += this->direction->getX() * deltaTime;
	Location.Y += this->direction->getY() * deltaTime;

	if (Location.X < -(TERRAIN_WIDTH / 2 - SCREEN_WIDTH / 2))
	{
		Location.X = -(TERRAIN_WIDTH / 2 - SCREEN_WIDTH / 2);
	}
	else if (Location.X + Size.Width > (TERRAIN_WIDTH / 2 + SCREEN_WIDTH / 2))
	{
		Location.X = (TERRAIN_WIDTH / 2 + SCREEN_WIDTH / 2) - Size.Width;
	}

	if (Location.Y < -(TERRAIN_HEIGHT / 2 - SCREEN_HEIGHT / 2))
	{
		this->Location.Y = -(TERRAIN_HEIGHT / 2 - SCREEN_HEIGHT / 2);
	}
	else if (this->Location.X + this->Size.Height > (TERRAIN_HEIGHT / 2 + SCREEN_HEIGHT / 2))
	{
		this->Location.Y = (TERRAIN_HEIGHT / 2 + SCREEN_HEIGHT / 2) - this->Size.Height;
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