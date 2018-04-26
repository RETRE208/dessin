#pragma once

#include "ofxDatGui.h"
#include "../primitives/Circle.h"
#include "PrimitivePanel.h"

class CirclePanel : public PrimitivePanel
{
public:
	void setup(string name);
	void draw();
	void setColor(ofColor color);
	string getPanelName();
	void deletePanel();

	void onColorPickerEvent(ofxDatGuiColorPickerEvent e);
	void onButtonEvent(ofxDatGuiButtonEvent e);
	bool mDragging;
	string panelName;
	Circle* circle;
	ofxDatGui* gui;
	ofxDatGuiColorPicker* primaryPicker;
	ofxDatGuiColorPicker* secondaryPicker;
	ofxDatGuiSlider* sx;
	ofxDatGuiSlider* sy;
	ofxDatGuiSlider* sr;
	ofxDatGuiSlider* slineWidth;
	ofxDatGuiToggle* isFillToggle;
};

