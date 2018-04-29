#pragma once

#include "ofxDatGui.h"
#include "../primitives3D/Cube.h"

class CubePanel
{
public:
	void setup();
	void draw();

	void onColorPickerEvent(ofxDatGuiColorPickerEvent e);
	bool mDragging;
	Cube* cube;
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
};

