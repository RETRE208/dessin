#pragma once

#include "ofxDatGui.h"
#include "../primitives/Circle.h"
#include "PrimitivePanel.h"

class CirclePanel : public PrimitivePanel
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

