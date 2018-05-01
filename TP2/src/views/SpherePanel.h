#pragma once

#include "ofxDatGui.h"
#include "../primitives3D/Sphere.h"

class SpherePanel
{
public:
	void setup();
	void draw();

	void onColorPickerEvent(ofxDatGuiColorPickerEvent e);
	void onToggleEvent(ofxDatGuiToggleEvent e);
	void onSliderEvent(ofxDatGuiSliderEvent e);
	bool mDragging;
	int shininess;
	Sphere* sphere;

	ofMaterial material;

	ofxDatGuiToggle* leatherToggle;
	ofTexture leatherTexture;
	ofMaterial leatherMaterial;
	void onToggleLeatherEvent(ofxDatGuiToggleEvent e);

	ofxDatGuiToggle* goldToggle;
	ofTexture goldTexture;
	ofMaterial goldMaterial;
	void onToggleGoldEvent(ofxDatGuiToggleEvent e);

	ofxDatGuiToggle* concreteToggle;
	ofTexture concreteTexture;
	ofMaterial concreteMaterial;
	void onToggleConcreteEvent(ofxDatGuiToggleEvent e);

	ofxDatGui* gui;
	ofxDatGuiColorPicker* picker;
	ofxDatGuiSlider* sx;
	ofxDatGuiSlider* sy;
	ofxDatGuiSlider* sz;
	ofxDatGuiSlider* sr;
	ofxDatGuiSlider* rx;
	ofxDatGuiSlider* ry;
	ofxDatGuiSlider* rz;
	ofxDatGuiToggle* materialToggle;
	ofxDatGuiSlider* shininessSlider;
};

