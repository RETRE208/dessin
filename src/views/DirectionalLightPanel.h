#pragma once
#pragma once

#ifndef DirectionalLightPanel_Included
#define DirectionalLightPanel_Included

#include "ofxDatGui.h"

class MainController;

class DirectionalLightPanel
{
public:
	void setup(MainController* mainController);
	void draw();
	void onColorPickerEvent(ofxDatGuiColorPickerEvent e);
	void onSliderEvent(ofxDatGuiSliderEvent e);

	MainController* mainControllerInstance;
	ofLight light;

	int x;
	int y;
	int z;
	ofxDatGui* gui;
	ofxDatGuiSlider* sliderX;
	ofxDatGuiSlider* sliderY;
	ofxDatGuiSlider* sliderZ;
	ofxDatGuiColorPicker* picker;
};
#endif

