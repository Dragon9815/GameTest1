#ifndef IMOUSEINTERACT_H
#define IMOUSEINTERACT_H

#include <SDL.h>

class IMouseInteract
{
protected:
	virtual void OnMouseDown(SDL_Event e) = 0;
	virtual void OnMouseUp(SDL_Event e) = 0;
	virtual void OnMouseOver(SDL_Event e) = 0;
	virtual void OnMouseOut(SDL_Event e) = 0;
	virtual void OnMouseMotion(SDL_Event e) = 0;

	virtual int getX();
	virtual int getY();

	void handleInput(SDL_Event e)
	{
		switch (e.type)
		{
		case SDL_MOUSEBUTTONDOWN:
			OnMouseDown(e);
			break;

		case SDL_MOUSEBUTTONUP:
			OnMouseUp(e);
			break;

		case SDL_MOUSEMOTION:
			OnMouseMotion(e);
			break;
		}
	}
};

#endif