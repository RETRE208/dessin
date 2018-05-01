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
	void update();

	MainController* mainControllerInstance;

	ofxDatGui* gui = new ofxDatGui(ofxDatGuiAnchor::TOP_LEFT);
	
	ofxDatGuiButton* importBtn;
	ofxDatGuiButton* exportBtn;
	ofxDatGuiButton* removeSelected;
	ofxDatGuiButton* instanciate;
	ofxDatGuiToggle* mode3DToggle;
	ofxDatGuiToggle* modeRayTracing;
	ofxDatGuiColorPicker* backgroundPicker;

	ofxDatGuiToggle* blurToggle;
	ofxDatGuiToggle* antiAliasingToggle;
	ofxDatGuiToggle* bloomToggle;
	ofxDatGuiToggle* contrastToggle;
	ofxDatGuiToggle* noiseToggle;


	bool antiAliasingFilter = false;
	bool blurFilter = false;
	bool bloomFilter = false;
	bool contrastFilter = false;
	bool noiseFilter = false;

	bool mode2D = true;
	void onButtonEvent(ofxDatGuiButtonEvent e);

	ofxDatGuiDropdown* primitives2D;
	ofxDatGuiDropdown* primitives3D;

	ofxDatGuiDropdown* lights;
	
	std::vector<std::string> options = {"Circle", "Rectangle", "Ellipse", "Line", "Square", "Cubic Bezier Curve", "Cubic Hermite Curve", "6 Points Bezier Curve", "Surface Bezier", "Custom Delaunay Polygon"};
	std::vector<std::string> options3D = {"Cube", "Sphere", "Cubic Bezier Curve", "Cubic Hermite Curve", "6 Points Bezier Curve", "Surface Bezier", "Custom Delaunay Polygon"};
	std::vector<std::string> optionsLights = { "Ambiant", "Directional", "Point", "Spot" };	
	void onPrimitiveDropdownEvent(ofxDatGuiDropdownEvent e);
	void onColorPickerEvent(ofxDatGuiColorPickerEvent e);
};
#endif

