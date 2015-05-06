#ifndef CAMERA_H
#define CAMERA_H

#include "Player.h"
#include "Vector2D.h"

class Camera
{
public:
	void recalculateFromPlayer(float playerX, float playerY, float playerWidth, float playerHeight);
	void recalculateFromPlayer(Vector2D playerPos, Vector2D playerDimensions);

	int getRelativeX(float absoluteX);
	int getRelativeY(float absoluteY);

private:
	Vector2D CameraPos;
};

#endif