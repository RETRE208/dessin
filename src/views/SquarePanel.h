#pragma once

#include "ofxDatGui.h"
#include "../primitives/Square.h"
#include "PrimitivePanel.h"

class SquarePanel : public PrimitivePanel
{
public:
	void setup(string name);
	void draw();
	void setColor(ofColor color);
	string getPanelName();
	void deletePanel();

	string panelName;
	void onColorPickerEvent(ofxDatGuiColorPickerEvent e);
	void onButtonEvent(ofxDatGuiButtonEvent e);
	bool mDragging;
	Square* square;
	ofxDatGui* gui;
	ofxDatGuiColorPicker* primaryPicker;
	ofxDatGuiColorPicker* secondaryPicker;
	ofxDatGuiSlider* sx;
	ofxDatGuiSlider* sy;
	ofxDatGuiSlider* sheight;
	ofxDatGuiSlider* slineWidth;
	ofxDatGuiToggle* isFillToggle;
};