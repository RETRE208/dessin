#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "../primitives/Circle.h";

class PrimitivePanel
{
public:
	void setup();
	void draw();

	ofxPanel gui;
	ofParameterGroup parameterGroup;
	Circle circleGroup;
};