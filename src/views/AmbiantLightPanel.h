#pragma once

#ifndef AmbiantLightPanel_Included
#define AmbiantLightPanel_Included

#include "ofxDatGui.h"

class MainController;

class AmbiantLightPanel
{
public:
	void setup(MainController* mainController);
	void draw();
	void onColorPickerEvent(ofxDatGuiColorPickerEvent e);

	MainController* mainControllerInstance;
	ofLight light;

	int x;
	int y;
	int z;
	int angle;
	ofxDatGui* gui;
	ofxDatGuiColorPicker* picker;
};
#endif

