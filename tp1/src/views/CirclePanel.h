#pragma once

#include "ofxDatGui.h"
#include "../primitives/Circle.h";

class CirclePanel
{
public:
	void setup();
	void update();
	void draw();

	bool mDragging;
	Circle* circle;
	ofxDatGui* gui;
	ofxDatGuiSlider* sx;
	ofxDatGuiSlider* sy;
};

