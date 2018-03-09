#pragma once

#include "ofMain.h"

class Cube
{
public:
	Cube(int cubeWidth, int cubeHeight, int cubeDepth);
	bool inside(ofPoint mouse);
	void draw();

	float x;
	float y;
	float z;

	int width;
	int height;
	int depth;

	float angleX;
	float angleY;
	float angleZ;

	int size;
	ofColor color;
};

