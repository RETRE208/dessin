#pragma once

#ifndef controllerPanel_Included
#define controllerPanel_Included

#include "ofMain.h"
#include "ofxDatGui.h"

class MainController;

class controllerPanel
{
public:
	void setup(MainController * mainController);

	MainController* mainControllerInstance;

	ofxDatGui* gui = new ofxDatGui(ofxDatGuiAnchor::TOP_LEFT);
	
	ofxDatGuiButton* importBtn;
	ofxDatGuiButton* exportBtn;
	ofxDatGuiToggle* mode3DToggle;

	bool mode2D = true;
	void onButtonEvent(ofxDatGuiButtonEvent e);

	ofxDatGuiDropdown* primitives2D;
	ofxDatGuiDropdown* primitives3D;
	std::vector<std::string> options = { "Circle", "Rectangle", "Ellipse", "Line", "Triangle" };
	std::vector<std::string> options3D = { "Cube", "Sphere"};
	void onPrimitiveDropdownEvent(ofxDatGuiDropdownEvent e);
};
#endif

