#pragma once

#include "ofMain.h"

class Circle
{
public:
	Circle(int radius);
	bool inside(ofPoint mouse);
	void draw();
	
	float x;
	float y;
	int mRadius;

};