#pragma once

#include "ofxDatGui.h"
#include "../primitives/Rectangle.h"
#include "PrimitivePanel.h"

class RectanglePanel : public PrimitivePanel
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
	tp1::Rectangle* rectangle;
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

