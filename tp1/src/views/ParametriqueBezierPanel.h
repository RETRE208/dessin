#pragma once

#include "ofxDatGui.h"
#include "../views/PrimitivePanel.h"
#include "../Curves/ParametriqueBezier.h"

class ParametriqueBezierPanel : public PrimitivePanel
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
	ParametriqueBezier* bezier;
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
	ofxDatGuiSlider* ctrl_point5x;
	ofxDatGuiSlider* ctrl_point5y;
	ofxDatGuiSlider* ctrl_point6x;
	ofxDatGuiSlider* ctrl_point6y;
};



