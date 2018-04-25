#pragma once

#include "ofxDatGui.h"
#include "../views/PrimitivePanel.h"
#include "../Curves/ParametriqueBezier.h"

class ParametriqueBezierPanel2D : public PrimitivePanel
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
	ofxDatGuiColorPicker* picker;
	ofxDatGuiSlider* slineWidth;
	ofxDatGuiSlider* ctrl_point_x;
	ofxDatGuiSlider* ctrl_point_y;
	ofxDatGuiSlider* ctrl_point_z;

	ofxDatGuiDropdown* ctrl_points_choice;
	std::vector<std::string> options = { "Control Point 1", "Control Point 2" , "Control Point 3" , "Control Point 4", "Control Point 5", "Control Point 6" };
	void onDropdownEvent(ofxDatGuiDropdownEvent e);

	ofxDatGuiToggle* drawCtrlPointsToggle;
	bool drawCtrlPoints = false;
	void onButtonEvent(ofxDatGuiButtonEvent e);
};



