#include "CameraPanel.h"


void CameraPanel::setup()
{
	x = ofGetWidth() / 2;
	y = ofGetHeight() / 2;
	z = 0;
	camera_target = { 0.0f, 0.0f, 0.0f };
	orthogonalMode = false;
	panelName = "3D Camera";
	gui = new ofxDatGui(ofxDatGuiAnchor::TOP_RIGHT);
	gui->setWidth(200);
	gui->addHeader(panelName);
	orthogonalToggle = gui->addToggle("Orthogonal Mode");
	sx = gui->addSlider("CAMERA X", 0, ofGetWidth());
	sy = gui->addSlider("CAMERA Y", 0, ofGetHeight());
	sz = gui->addSlider("CAMERA Z", 0, 1000);

	sx->bind(x);
	sy->bind(y);
	sz->bind(z);
}

void CameraPanel::onButtonEvent(ofxDatGuiButtonEvent e) {
	if (e.target == orthogonalToggle) {
		if (orthogonalMode == true) {
			ofLog() << "Switching to perspective Mode";
			orthogonalMode = false;
		}
		else {
			ofLog() << "Switching to orthogonal Mode";
			orthogonalMode = true;
		}
	}
}

void CameraPanel::draw()
{
	if (orthogonalMode == false) {
		cam.lookAt(camera_target);
	}
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
