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

	MainController* mainControllerInstance;

	ofxPanel leftMenu;
	ofxIntSlider intSlider;
	ofxFloatSlider floatSlider;
	ofxToggle mode3DToggle;
	ofxButton importBtn;
	ofxButton exportBtn;
};

#endif