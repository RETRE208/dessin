#pragma once

#include "ofMain.h"

class Sphere
{
public:
	void setup();
	void draw();

	ofParameterGroup sphereParameters;
	ofParameter<int> red;
	ofParameter<int> green;
	ofParameter<int> blue;

	ofParameter<int> posX;
	ofParameter<int> posY;
	ofParameter<int> posZ;
	ofParameter<int> radius;
};

