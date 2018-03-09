#pragma once

#include "ofxDatGui.h"
#include "../primitives/Circle.h"

class CirclePanel
{
public:
	void setup(string name);
	void update();
	void setup();
	void draw();

	void onColorPickerEvent(ofxDatGuiColorPickerEvent e);
	bool mDragging;
	string panelName;
	Circle* circle;
	ofxDatGui* gui;
	ofxDatGuiColorPicker* picker;
	ofxDatGuiSlider* sx;
	ofxDatGuiSlider* sy;
	ofxDatGuiSlider* sr;
};

