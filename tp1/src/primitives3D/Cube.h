#pragma once

#include "ofMain.h"

class Cube
{
public:
	void setup();
	void draw();

	ofParameterGroup cubeParameters;
	ofParameter<int> red;
	ofParameter<int> green;
	ofParameter<int> blue;

	ofParameter<int> posX;
	ofParameter<int> posY;
	ofParameter<int> posZ;
	ofParameter<int> height;
	ofParameter<int> width;
	ofParameter<int> depth;
	ofParameter<int> rotateX;
	ofParameter<int> rotateY;
	ofParameter<int> rotateZ;
};

