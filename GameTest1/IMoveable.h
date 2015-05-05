#ifndef IMOVEABLE_H
#define IMOVEABLE_H

#include "Vector2D.h"
#include <SDL.h>

class IMoveable
{
protected:
	IMoveable()
	{

	}

	~IMoveable() {}

	void setVelocity(Vector2D* v)
	{
		this->m_Velocity = v;
	}

	void setVelocity(float v_x, float v_y)
	{
		this->m_Velocity = new Vector2D(v_x, v_y);
	}

	Vector2D* getVelocity()
	{
		return this->m_Velocity;
	}


	Vector2D* m_Velocity;


	virtual void OnKeyDown(const Uint8* keystates) = 0;
	virtual void OnKeyUp(const Uint8* keystates) = 0;

	void handleInput(SDL_Event e)
	{
		if (e.type == SDL_KEYDOWN)
		{
			this->OnKeyDown(SDL_GetKeyboardState(0));
		}
		else if (e.type == SDL_KEYUP)
		{
			this->OnKeyUp(SDL_GetKeyboardState(0));
		}
	}
};

#endif