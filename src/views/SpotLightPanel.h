#pragma once

#ifndef SpotLightPanel_Included
#define SpotLightPanel_Included

#include "ofxDatGui.h"

class MainController;

class SpotLightPanel
{
public:
	void setup(MainController* mainController);
	void draw();
	void onColorPickerEvent(ofxDatGuiColorPickerEvent e);
	void onSliderEvent(ofxDatGuiSliderEvent e);

	MainController* mainControllerInstance;
	ofLight light;

	int imageWidth;
	int imageHeight;
	int x;
	int y;
	int z;
	int angle;
	ofxDatGui* gui;
	ofxDatGuiSlider* sliderX;
	ofxDatGuiSlider* sliderY;
	ofxDatGuiSlider* sliderZ;
	ofxDatGuiSlider* sliderAngle;
	ofxDatGuiColorPicker* picker;
};
#endif

#pragma once
