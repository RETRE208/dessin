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

	int mRadius;
	ofColor color;
};

