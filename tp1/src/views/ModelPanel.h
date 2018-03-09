#pragma once
#pragma once

#ifndef ModelPanel_Included
#define ModelPanel_Included

#include "ofxDatGui.h"
#include "ofxAssimpModelLoader.h"

class MainController;

enum class MeshRenderMode { fill, wireframe, points };

class ModelPanel
{
public:
	MainController* mainControllerInstance;

	void setup(MainController * mainController, string modelPath);
	void draw();

	bool mDragging;

	ofxAssimpModelLoader model;
	MeshRenderMode mesh_render_mode;

	ofxDatGui* gui;
	ofxDatGuiSlider* sx;
	ofxDatGuiSlider* sy;
	ofxDatGuiSlider* sz;
	ofxDatGuiSlider* rx;
	ofxDatGuiSlider* ry;
	ofxDatGuiSlider* rz;
	ofxDatGuiSlider* ssize;
	ofxDatGuiToggle* meshFillToggle;
	ofxDatGuiToggle* meshWireframeToggle;
	ofxDatGuiToggle* meshPointsToggle;
	ofxDatGuiButton* instanciate;

	void onButtonEvent(ofxDatGuiButtonEvent e);

	int x;
	int y;
	int z;
	int angleX;
	int angleY;
	int angleZ;
	float size;
};

#endif

