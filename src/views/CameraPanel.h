#pragma once

#include "ofxDatGui.h"
#include "ofMain.h"

class CameraPanel
{
public:
	void setup();
	void draw();
	void begin();
	void end();
	void onButtonEvent(ofxDatGuiButtonEvent e);
	void onDropdownEvent(ofxDatGuiDropdownEvent e);
	void reset();
	void setup_camera();

	ofCamera cam;
	string active_camera;

	ofQuaternion main_camera_orientation;

	ofVec3f main_camera_position;
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
	bool is_cam_top_active;

	std::vector<std::string> options = { 
		"Top Camera", 
		"Down Camera", 
		"Left Camera", 
		"Right Camera",
		"Front Camera", 
		"Back Camera"
	};

	int x;
	int y;
	int z;
	bool orthogonalMode;
	bool orientation_is_visible;
	string panelName;
	ofxDatGui* gui;
	ofxDatGuiToggle* orthogonalToggle;
	ofxDatGuiToggle* orientationAxesToggle;
	ofxDatGuiDropdown* cam_choice;
	ofxDatGuiSlider* sx;
	ofxDatGuiSlider* sy;
	ofxDatGuiSlider* sz;
};

