#pragma once

#include "ofxDatGui.h"
#include "../views/PrimitivePanel.h"
#include "../Curves/BezierSurface.h"

class BezierSurfacePanel3D : public PrimitivePanel
{
public:
	void setup(string name);
	void draw();
	void setColor(ofColor color);
	string getPanelName();
	void deletePanel();

	bool mDragging;
	string panelName;
	BezierSurface* bezier;

	ofxDatGui* gui;
	ofxDatGuiColorPicker* picker;
	ofxDatGuiSlider* ctrl_point_x;
	ofxDatGuiSlider* ctrl_point_y;
	ofxDatGuiSlider* ctrl_point_z;
	ofxDatGuiDropdown* ctrl_points_choice;
	std::vector<std::string> options = { "Control Point (1,1)", "Control Point (1,2)", "Control Point (1,3)", "Control Point (1,4)",
										 "Control Point (2,1)", "Control Point (2,2)", "Control Point (2,3)", "Control Point (2,4)",
										 "Control Point (3,1)", "Control Point (3,2)", "Control Point (3,3)", "Control Point (3,4)",
										 "Control Point (4,1)", "Control Point (4,2)", "Control Point (4,3)", "Control Point (4,4)"};
	void onDropdownEvent(ofxDatGuiDropdownEvent e);
	void onColorPickerEvent(ofxDatGuiColorPickerEvent e);
	ofxDatGuiToggle* hideSurfaceToggle;
	ofxDatGuiToggle* drawCtrlPointsTogle;
	bool hideSurface = true;
	bool drawCtrlPoints = false;
	void onButtonEvent(ofxDatGuiButtonEvent e);
};

