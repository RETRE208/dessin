#pragma once

#ifndef PointLightPanel_Included
#define PointLightPanel_Included

#include "ofxDatGui.h"

class MainController;

class PointLightPanel
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

#pragma once
