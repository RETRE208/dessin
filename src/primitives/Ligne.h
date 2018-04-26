#pragma once

#include "ofMain.h"

class Ligne
{
public:
	Ligne();
	void draw();

	int lineWidth;
	float p1x;
	float p1y;
	float p2x;
	float p2y;
	ofColor color;
};

