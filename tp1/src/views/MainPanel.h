#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "PrimitivePanel.h"

class MainPanel
{
public:
	void setup();
	void draw();
	void togglePrimitivePanel();

	ofxPanel gui;
	ofxIntSlider intSlider;
	ofxFloatSlider floatSlider;
	ofxToggle toggle;
	ofxButton button;
};