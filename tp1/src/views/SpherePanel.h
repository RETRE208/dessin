#pragma once

#include "ofxDatGui.h"
#include "../primitives3D/Sphere.h"

class SpherePanel
{
public:
	void setup();
	void draw();

	void onColorPickerEvent(ofxDatGuiColorPickerEvent e);
	void onToggleEvent(ofxDatGuiToggleEvent e);
	void onSliderEvent(ofxDatGuiSliderEvent e);
	bool mDragging;
	int shinyness;
	Sphere* sphere;
	ofMaterial material;
	ofxDatGui* gui;
	ofxDatGuiColorPicker* picker;
	ofxDatGuiSlider* sx;
	ofxDatGuiSlider* sy;
	ofxDatGuiSlider* sz;
	ofxDatGuiSlider* sr;
	ofxDatGuiToggle* materialToggle;
	ofxDatGuiSlider* shininessSlider;
};

