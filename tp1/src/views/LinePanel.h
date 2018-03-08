#pragma once

#include "ofxDatGui.h"
#include "../primitives/Ligne.h"

class LinePanel
{
public:
	void setup();
	void update();
	void draw();

	void onColorPickerEvent(ofxDatGuiColorPickerEvent e);
	bool mDragging;
	Ligne* line;
	ofxDatGui* gui;
	ofxDatGuiColorPicker* picker;
	ofxDatGuiSlider* sp1x;
	ofxDatGuiSlider* sp1y;
	ofxDatGuiSlider* sp2x;
	ofxDatGuiSlider* sp2y;
};

