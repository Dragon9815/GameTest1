#include "Camera.h"
#include "defs.h"

Camera::Camera()
{
	m_CameraPos = MyLocation(0, 0);
	m_scale		= 1.0f;
	p_Target	= NULL;
}

void Camera::setNullPoint(float X, float Y)
{
	m_CameraPos = MyLocation(X, Y);
}

MyLocation Camera::getNullPoint()
{
	return this->m_CameraPos;
}

void Camera::targetObject(GameObject* target)
{
	if (target != NULL)
		p_Target = target;
}

void Camera::update()
{
	if (p_Target != NULL)
	{
		m_CameraPos.X = (p_Target->Location.X /* / scale*/) - ((SCREEN_WIDTH - p_Target->Size.Width /* / scale*/)) / 2;
		m_CameraPos.Y = (p_Target->Location.Y /* / scale*/) - ((SCREEN_HEIGHT - p_Target->Size.Height/* / scale*/)) / 2;
	}
}


int Camera::getRelativeX(float absoluteX)
{
	return (((int)(absoluteX - m_CameraPos.X)) + ((int)(absoluteX) % 2));
}

int Camera::getRelativeY(float absoluteY)
{
	return (int)(absoluteY - m_CameraPos.Y);
}

void Camera::setScale(float scale)
{
	m_scale = scale;
}