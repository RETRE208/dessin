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

	void onColorPickerEvent(ofxDatGuiColorPickerEvent e);
	bool mDragging;
	Circle* circle;
	ofxDatGui* gui;
	ofxDatGuiColorPicker* picker;
	ofxDatGuiSlider* sx;
	ofxDatGuiSlider* sy;
	ofxDatGuiSlider* sr;
};

