#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "../primitives/Circle.h";
#include "../primitives3D/Sphere.h";
#include "../primitives3D/Cube.h";

class PrimitivePanel
{
public:
	void setup();
	void draw();

	ofxPanel gui;
	ofParameterGroup parameterGroup;
	Circle circleGroup;
	Sphere sphereGroup;
	Cube cubeGroup;
};