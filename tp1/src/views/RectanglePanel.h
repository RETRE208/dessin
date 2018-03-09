#pragma once

#include "ofxDatGui.h"
#include "../primitives/Rectangle.h"

class RectanglePanel
{
public:
	void setup(string name);
	void update();
	void draw();
	string panelName;
	void onColorPickerEvent(ofxDatGuiColorPickerEvent e);
	bool mDragging;
	tp1::Rectangle* rectangle;
	ofxDatGui* gui;
	ofxDatGuiColorPicker* picker;
	ofxDatGuiSlider* sx;
	ofxDatGuiSlider* sy;
	ofxDatGuiSlider* swidth;
	ofxDatGuiSlider* sheight;
};

