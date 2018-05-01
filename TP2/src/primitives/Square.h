#pragma once

#include "ofMain.h"
class Square
{
public:
	Square();
	void draw();

	bool isFill;
	float x;
	float y;
	int height;
	float lineWidth;
	ofColor primaryColor;
	ofColor secondaryColor;
};

