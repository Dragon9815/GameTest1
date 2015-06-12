#ifndef CAMERA_H
#define CAMERA_H

#include "Vector2D.h"
#include "Size.h"
#include "Location.h"
#include "GameObject.h"

class GameObject; // Forward Deklaration

class Camera
{
public:
	Camera();

	void setNullPoint(float x, float y);
	MyLocation getNullPoint();

	void targetObject(GameObject* target);
	void update();

	int getRelativeX(float absoluteX);
	int getRelativeY(float absoluteY);

	void setScale(float scale);

private:
	MyLocation	m_CameraPos;
	float		m_scale;
	GameObject* p_Target;
};

#endif