#pragma once

#ifndef MainPanel_Included
#define MainPanel_Included

#include "ofMain.h"
#include "ofxGui.h"
#include "PrimitivePanel.h"

class MainController;

class MainPanel
{
public:
	void setup(MainController * mainController);
	void draw();
	void importImage();
	void exportImage();
	void toggle3DMode(bool& pressed);
	void toggleMeshFill(bool& pressed);
	void toggleMeshWireframe(bool& pressed);
	void toggleMeshPoints(bool& pressed);
	void instanciateNewModel();

	MainController* mainControllerInstance;

	ofxPanel leftMenu;
	ofxIntSlider intSlider;
	ofxFloatSlider floatSlider;
	ofxToggle mode3DToggle;
	ofxButton importBtn;
	ofxButton exportBtn;
	ofxButton instanciateBtn;
	ofxLabel meshLabel;
	ofxToggle meshFill;
	ofxToggle meshWireframe;
	ofxToggle meshPoints;
};

#endif