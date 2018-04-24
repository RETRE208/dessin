#pragma once

#include "ofxDatGui.h"
#include "ofMain.h"
#include "../Camera/Camera.h"

class CameraPanel
{
public:
	void setup();
	void draw();
	void begin();
	void end();
	void onButtonEvent(ofxDatGuiButtonEvent e);

	ofCamera cam;
	int x;
	int y;
	int z;
	bool orthogonalMode;
	ofVec3f camera_target;
	string panelName;
	ofxDatGui* gui;
	ofxDatGuiToggle* orthogonalToggle;
	ofxDatGuiSlider* sx;
	ofxDatGuiSlider* sy;
	ofxDatGuiSlider* sz;
};

