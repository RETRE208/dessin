#pragma once

#include "ofMain.h"

class Sphere
{
public:
	Sphere(int radius);
	void draw();

	float x;
	float y;
	float z;

	float angleX;
	float angleY;
	float angleZ;

	int mRadius;
	ofColor color;
};

