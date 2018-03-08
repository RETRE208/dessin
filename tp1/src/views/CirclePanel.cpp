#include "CirclePanel.h"

void CirclePanel::setup()
{
	circle = new Circle(150);

	gui = new ofxDatGui(ofxDatGuiAnchor::TOP_RIGHT);
	gui->addHeader("ofxDATGUI DATA BINDING EXAMPLE");
	sx = gui->addSlider("CIRCLE X", 0, ofGetWidth());
	sy = gui->addSlider("CIRCLE Y", 0, ofGetHeight());

	sx->bind(circle->x);
	sy->bind(circle->y);

	circle->x = ofGetWidth() / 2;
	circle->y = ofGetHeight() / 2;
}

void CirclePanel::update()
{
	// drag the circle around if the mouse is pressed while over it //
	if (ofGetMousePressed() && gui->getMouseDown() == false) {
		ofPoint mouse = ofPoint(ofGetMouseX(), ofGetMouseY());
		if (circle->inside(mouse)) {
			circle->x = mouse.x;
			circle->y = mouse.y;
		}
	}
}

void CirclePanel::draw()
{
	circle->draw();
}

