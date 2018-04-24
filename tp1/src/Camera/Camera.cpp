#include "Camera.h"

Camera::Camera()
{
	x = 964 / 2;
	y = 700 / 2;
	z = 1000;
}

void Camera::draw() 
{
	cam->setPosition(x, y, z);
}

void Camera::begin()
{
	cam->begin();
}

void Camera::end()
{
	cam->end();
}
