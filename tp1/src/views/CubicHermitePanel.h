#pragma once

#include "ofxDatGui.h"
#include "../views/PrimitivePanel.h"
#include "../Curves/CubicHermite.h"

class CubicHermitePanel : public PrimitivePanel
{
public:
	void setup(string name);
	void draw();
	void setColor(ofColor color);
	string getPanelName();
	void deletePanel();

	void onColorPickerEvent(ofxDatGuiColorPickerEvent e);
	bool mDragging;
	string panelName;
	CubicHermite* hermite;
	ofxDatGui* gui;
	ofxDatGuiSlider* slineWidth;
	ofxDatGuiColorPicker* picker;
	ofxDatGuiSlider* ctrl_point1x;
	ofxDatGuiSlider* ctrl_point1y;
	ofxDatGuiSlider* ctrl_point2x;
	ofxDatGuiSlider* ctrl_point2y;
	ofxDatGuiSlider* ctrl_point3x;
	ofxDatGuiSlider* ctrl_point3y;
	ofxDatGuiSlider* ctrl_point4x;
	ofxDatGuiSlider* ctrl_point4y;
};

