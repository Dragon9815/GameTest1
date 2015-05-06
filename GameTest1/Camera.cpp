#include "Camera.h"
#include "defs.h"

void Camera::recalculateFromPlayer(float playerX, float playerY)
{
	this->CameraPos.setX(playerX - );
}

void Camera::recalculateFromPlayer(Vector2D playerPos)
{

}

int Camera::getRelativeX(float absoluteX)
{
	return (int)(absoluteX - this->CameraPos.getX());
}

int Camera::getRelativeY(float absoluteY)
{
	return (int)(absoluteY - this->CameraPos.getX());
}