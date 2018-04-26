#pragma once

#include "ofxDatGui.h"
#include "../primitives/Ellipse.h"
#include "PrimitivePanel.h"
using namespace tp1;

class EllipsePanel : public PrimitivePanel
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
	tp1::Ellipse* ellipse;
	ofxDatGui* gui;
	ofxDatGuiColorPicker* primaryPicker;
	ofxDatGuiColorPicker* secondaryPicker;
	ofxDatGuiSlider* sx;
	ofxDatGuiSlider* sy;
	ofxDatGuiSlider* swidth;
	ofxDatGuiSlider* sheight;
	ofxDatGuiSlider* slineWidth;
	ofxDatGuiToggle* isFillToggle;
};

