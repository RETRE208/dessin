#pragma once

#include "ofxDatGui.h"
#include "../primitives3D/DelaunayTriangle.h"

class DelaunayPanel2D
{
public:
	void setup(string name);
	void draw();

	void onColorPickerEvent(ofxDatGuiColorPickerEvent e);
	void onToggleEvent(ofxDatGuiToggleEvent e);
	void onSliderEvent(ofxDatGuiSliderEvent e);
	void onButtonEvent(ofxDatGuiButtonEvent e);

	DelaunayTriangle* delaunay;

	ofxDatGui* gui;
	ofxDatGuiColorPicker* picker;
	ofxDatGuiSlider* sx;
	ofxDatGuiSlider* sy;
	ofxDatGuiSlider* sz;

	float x;
	float y;
	float z = 0;
	ofxDatGuiButton* addPointBtn;
	ofxDatGuiToggle* fillToggle;
	bool fill = false;
};

