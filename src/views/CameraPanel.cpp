#include "CameraPanel.h"


void CameraPanel::setup()
{
	ofSetFrameRate(60);
	ofEnableDepthTest();
	main_camera_position = { 0.0f, 0.0f, 0.0f };
	camera_target = { 0.0f, 0.0f, 0.0f };

	camera_near = 50.0f;
	camera_far = 1750.0f;

	camera_fov = 60.0f;
	camera_fov_delta = 16.0f;

	orthogonalMode = false;
	orientation_is_visible = false;

	is_camera_fov_narrow = false;
	is_camera_fov_wide = false;

	x = 0;
	y = 0;
	
	panelName = "3D Camera";
	gui = new ofxDatGui(ofxDatGuiAnchor::TOP_RIGHT);
	gui->setWidth(200);
	gui->addHeader(panelName);
	orthogonalToggle = gui->addToggle("Orthogonal Mode");
	orientationAxesToggle = gui->addToggle("Orientation Axes Visible");
	sx = gui->addSlider("CAMERA X", (ofGetWidth() / -2), (ofGetWidth() / 2));
	sy = gui->addSlider("CAMERA Y", (ofGetHeight() / -2), (ofGetHeight() / 2));
	sz = gui->addSlider("CAMERA Z", -1000, 3000);
	cam_choice = gui->addDropdown("Control Point Number", options);

	sx->bind(x);
	sy->bind(y);
	sz->bind(z);

	gui->onButtonEvent(this, &CameraPanel::onButtonEvent);
	gui->onDropdownEvent(this, &CameraPanel::onDropdownEvent);

	reset();

	setup_camera();
}

void CameraPanel::reset() 
{
	offset_scene =  64.0f;
	offset_camera = offset_scene * 3.5f * -1.0f;
	z = -offset_camera;
	if (active_camera == "Back Camera") {
		cam.setPosition(0, 0, offset_camera);
		cam.lookAt(camera_target);
	}
	else if (active_camera == "Left Camera") {
		cam.setPosition(-offset_camera, 0, 0);
		cam.lookAt(camera_target);
	}
	else if (active_camera == "Top Camera") {
		cam.setPosition(0, offset_camera, 0);
		cam.lookAt(camera_target, ofVec3f(1, 0, 0));
	}
	else if (active_camera == "Right Camera") {
		cam.setPosition(offset_camera,0 , 0);
		cam.lookAt(camera_target);
	}
	else if (active_camera == "Down Camera") {
		cam.setPosition(0, -offset_camera, 0);
		cam.lookAt(camera_target, ofVec3f(1, 0, 0));
	}
	else {
		cam.setPosition(0, 0, z);
		cam.lookAt(camera_target);
	}
	
	ofLog() << "<reset>";
}

void CameraPanel::setup_camera()
{
	main_camera_position = cam.getPosition();
	main_camera_orientation = cam.getOrientationQuat();
	if (is_camera_perspective)
	{
		cam.disableOrtho();
		cam.setupPerspective(false, camera_fov, camera_near, camera_far, ofVec2f(0, 0));
	}
	else
	{
		cam.enableOrtho();
	}

	cam.setPosition(main_camera_position);
	cam.setOrientation(main_camera_orientation);
}

void CameraPanel::onDropdownEvent(ofxDatGuiDropdownEvent e)
{
	cout << "the option at index # " << e.child << " was selected " << endl;
	string choice = options.at(e.child);
	active_camera = choice;
	reset();
}

void CameraPanel::onButtonEvent(ofxDatGuiButtonEvent e) {
	if (e.target == orientationAxesToggle) {
		if (orientation_is_visible == true) {
			ofLog() << "orientation_is_not visible";
			orientation_is_visible = false;
		}
		else {
			ofLog() << "orientation_is_visible";
			orientation_is_visible = true;
		}
	}
	if (e.target == orthogonalToggle) {
		if (orthogonalMode == true) {
			ofLog() << "Switching to perspective Mode";
			orthogonalMode = false;
			is_camera_perspective = true;
			if (is_camera_fov_narrow)
			{
				cam.setFov(camera_fov);
			}

			if (is_camera_fov_wide)
			{
				cam.setFov(camera_fov);
			}
		}
		else {
			ofLog() << "Switching to orthogonal Mode";
			orthogonalMode = true;
			is_camera_perspective = false;
		}
	}
	setup_camera();
}

void CameraPanel::draw()
{
	if (orientation_is_visible) {
		ofDrawRotationAxes(64);
	}	
	ofDrawGrid();
	cam.setPosition(x, y, z);	
	cam.draw();
}

void CameraPanel::begin()
{
	cam.begin();
}

void CameraPanel::end()
{
	cam.end();
}

