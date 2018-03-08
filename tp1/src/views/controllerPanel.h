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
	void onDropdownEvent(ofxDatGuiDropdownEvent e);
	
	std::vector<std::string> options = { "Circle", "Square", "Dot", "Line", "Triangle" };
};
#endif

