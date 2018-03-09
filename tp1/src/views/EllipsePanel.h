#pragma once

#include "ofxDatGui.h"
#include "../primitives/Ellipse.h"
using namespace tp1;

class EllipsePanel
{
public:
	void setup(string name);
	void update();
	void draw();
	string panelName;
	void onColorPickerEvent(ofxDatGuiColorPickerEvent e);
	bool mDragging;
	tp1::Ellipse* ellipse;
	ofxDatGui* gui;
	ofxDatGuiColorPicker* picker;
	ofxDatGuiSlider* sx;
	ofxDatGuiSlider* sy;
	ofxDatGuiSlider* swidth;
	ofxDatGuiSlider* sheight;
};

