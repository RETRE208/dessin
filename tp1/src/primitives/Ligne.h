#pragma once

#include "ofMain.h"

class Ligne
{
public:
	Ligne();
	bool inside(ofPoint mouse);
	void draw();

	float p1x;
	float p1y;
	float p2x;
	float p2y;
	ofColor color;
};

