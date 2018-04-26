#pragma once

#include "ofMain.h"

class Circle
{
public:
	Circle(int radius);
	void draw();
	
	bool isFill;
	float x;
	float y;
	int mRadius;
	float lineWidth;
	ofColor primaryColor;
	ofColor secondaryColor;
};