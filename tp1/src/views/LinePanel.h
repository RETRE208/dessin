#pragma once

#include "ofxDatGui.h"
#include "../primitives/Ligne.h"
#include "PrimitivePanel.h"

class LinePanel : public PrimitivePanel
{
public:
	void setup(string name);
	void draw();
	void setColor(ofColor color);
	string getPanelName();
	void deletePanel();

	string panelName;
	void onColorPickerEvent(ofxDatGuiColorPickerEvent e);
	bool mDragging;
	Ligne* line;
	ofxDatGui* gui;
	ofxDatGuiColorPicker* picker;
	ofxDatGuiSlider* sp1x;
	ofxDatGuiSlider* sp1y;
	ofxDatGuiSlider* sp2x;
	ofxDatGuiSlider* sp2y;
	ofxDatGuiSlider* lineWidth;
};

