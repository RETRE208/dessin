#pragma once

#include "ofMain.h"

class Circle
{
public:
	void setup();
	void draw();

	ofParameterGroup circleParameters;
	ofParameter<int> red;
	ofParameter<int> green;
	ofParameter<int> blue;

	ofParameter<int> posX;
	ofParameter<int> posY;
	ofParameter<int> radius;
};