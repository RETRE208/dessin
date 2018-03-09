#pragma once

#include "ofxDatGui.h"

class ImagePanel
{
public:
	void setup(string path);
	void update();
	void draw();

	ofImage newImage;
	bool mDragging;

	int imageWidth;
	int imageHeight;
	int x;
	int y;
	ofxDatGui* gui;
	ofxDatGuiSlider* alphaSlider;
	ofxDatGuiSlider* sliderX;
	ofxDatGuiSlider* sliderY;
	ofxDatGuiSlider* sliderWidth;
	ofxDatGuiSlider* sliderHeight;
};

