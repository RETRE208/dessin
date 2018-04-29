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
	ofxDatGuiButton* removeSelected;
	ofxDatGuiButton* instanciate;
	ofxDatGuiToggle* mode3DToggle;
	ofxDatGuiColorPicker* backgroundPicker;
	ofxDatGuiToggle* blurToggle;
	ofxDatGuiToggle* antiAliasingToggle;
	ofxDatGuiToggle* bloomToggle;
	ofxDatGuiToggle* contrastToggle;


	bool antiAliasingFilter = false;
	bool blurFilter = false;
	bool bloomFilter = false;
	bool contrastFilter = false;
	bool mode2D = true;
	void onButtonEvent(ofxDatGuiButtonEvent e);

	ofxDatGuiDropdown* primitives2D;
	ofxDatGuiDropdown* primitives3D;
	std::vector<std::string> options = {"Circle", "Rectangle", "Ellipse", "Line", "Square", "Cubic Bezier Curve", "Cubic Hermite Curve", "6 Points Bezier Curve", "Surface Bezier"};
	std::vector<std::string> options3D = {"Cube", "Sphere", "Cubic Bezier Curve", "Cubic Hermite Curve", "6 Points Bezier Curve", "Surface Bezier"};
	void onPrimitiveDropdownEvent(ofxDatGuiDropdownEvent e);
	void onColorPickerEvent(ofxDatGuiColorPickerEvent e);
};
#endif

