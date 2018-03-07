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

	MainController* mainControllerInstance;

	ofxPanel gui;
	ofxIntSlider intSlider;
	ofxFloatSlider floatSlider;
	ofxToggle toggle;
	ofxButton importBtn;
	ofxButton exportBtn;
};

#endif