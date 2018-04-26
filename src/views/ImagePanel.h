#pragma once

#ifndef ImagePanel_Included
#define ImagePanel_Included

#include "ofxDatGui.h"

class MainController;

class ImagePanel
{
public:
	void setup(string path, MainController* mainController);
	void draw();
	void onButtonEvent(ofxDatGuiButtonEvent e);

	MainController* mainControllerInstance;
	ofImage newImage;

	int imageWidth;
	int imageHeight;
	int x;
	int y;
	int alpha;
	ofxDatGui* gui;
	ofxDatGuiSlider* alphaSlider;
	ofxDatGuiSlider* sliderX;
	ofxDatGuiSlider* sliderY;
	ofxDatGuiSlider* sliderWidth;
	ofxDatGuiSlider* sliderHeight;
	ofxDatGuiSlider* sliderAlpha;

	ofxDatGuiButton* embossBtn;
	ofxDatGuiButton* sharpenBtn;
	ofxDatGuiButton* edgeDetectBtn;
	ofxDatGuiButton* blurBtn;
	ofxDatGuiButton* alphaBtn;
	ofxDatGuiButton* inverseBtn;
	ofxDatGuiButton* gridBtn;
};
#endif

