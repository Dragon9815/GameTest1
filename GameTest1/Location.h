#ifndef LOCATION_H
#define LOCATION_H

#include "Vector2D.h"

class MyLocation
{
public:
	float	X;
	float	Y;

	MyLocation() : X(0), Y(0), m_oldX(0), m_oldY(0) {}
	MyLocation(float x, float y) : X(x), Y(y), m_oldX(x), m_oldY(y) {}

	bool changed() 
	{
		if (X != m_oldX || Y != m_oldY)
		{
			m_oldX = X;
			m_oldY = Y;
			return true;
		}

		return false;
	}
	
private:
	float	m_oldX;
	float	m_oldY;
};

#endif