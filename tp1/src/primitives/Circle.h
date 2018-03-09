#pragma once

#include "ofMain.h"

class Circle
{
public:
	Circle(int radius);
	void draw();
	
	float x;
	float y;
	int mRadius;
	ofColor color;
};