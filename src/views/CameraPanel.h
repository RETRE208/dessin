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
	void reset();
	void setup_camera();
	ofCamera* getCamera();

	ofCamera cam;

	ofQuaternion camera_orientation;

	ofVec3f camera_position;
	ofVec3f camera_target;

	float camera_near;
	float camera_far;

	float camera_fov;
	float camera_fov_delta;

	float offset_camera;
	float offset_color;
	float offset_scene;
	float offset_cube;

	bool is_camera_fov_narrow;
	bool is_camera_fov_wide;

	bool is_camera_perspective;


	int x;
	int y;
	int z;
	bool orthogonalMode;
	bool orientation_is_visible;
	string panelName;
	ofxDatGui* gui;
	ofxDatGuiToggle* orthogonalToggle;
	ofxDatGuiToggle* orientationAxesToggle;
	ofxDatGuiSlider* sx;
	ofxDatGuiSlider* sy;
	ofxDatGuiSlider* sz;
};

