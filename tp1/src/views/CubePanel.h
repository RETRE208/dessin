#pragma once

#include "ofxDatGui.h"
#include "../primitives3D/Cube.h"

class CubePanel
{
public:
	void setup();
	void draw();

	void onColorPickerEvent(ofxDatGuiColorPickerEvent e);
	void onToggleEvent(ofxDatGuiToggleEvent e);
	void onSliderEvent(ofxDatGuiSliderEvent e);
	bool mDragging;
	int shinyness;
	Cube* cube;
	ofMaterial material;
	ofxDatGui* gui;
	ofxDatGuiColorPicker* picker;
	ofxDatGuiSlider* sx;
	ofxDatGuiSlider* sy;
	ofxDatGuiSlider* sz;
	ofxDatGuiSlider* w;
	ofxDatGuiSlider* h;
	ofxDatGuiSlider* d;
	ofxDatGuiSlider* rx;
	ofxDatGuiSlider* ry;
	ofxDatGuiSlider* rz;
	ofxDatGuiToggle* materialToggle;
	ofxDatGuiSlider* shininessSlider;
};

