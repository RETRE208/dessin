#pragma once

#include "ofxDatGui.h"
#include "../views/PrimitivePanel.h"
#include "../Curves/CubicHermite.h"

class CubicHermitePanel3D : public PrimitivePanel
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
	ofxDatGuiSlider* ctrl_point_x;
	ofxDatGuiSlider* ctrl_point_y;
	ofxDatGuiSlider* ctrl_point_z;

	ofxDatGuiDropdown* ctrl_points_choice;
	std::vector<std::string> options = { "Control Point 1", "Control Point 2" , "Control Point 3" , "Control Point 4" };
	void onDropdownEvent(ofxDatGuiDropdownEvent e);

	ofxDatGuiToggle* drawCtrlPointsToggle;
	bool drawCtrlPoints = false;
	void onButtonEvent(ofxDatGuiButtonEvent e);
};

