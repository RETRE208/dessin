#pragma once

#include "ofxDatGui.h"
#include "../primitives3D/Sphere.h"

class SpherePanel
{
public:
	void setup();
	void draw();

	void onColorPickerEvent(ofxDatGuiColorPickerEvent e);
	bool mDragging;
	Sphere* sphere;
	ofxDatGui* gui;
	ofxDatGuiColorPicker* picker;
	ofxDatGuiSlider* sx;
	ofxDatGuiSlider* sy;
	ofxDatGuiSlider* sz;
	ofxDatGuiSlider* sr;
};

