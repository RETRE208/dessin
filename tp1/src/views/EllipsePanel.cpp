#include "EllipsePanel.h"

void EllipsePanel::setup()
{
	ellipse = new tp1::Ellipse();

	gui = new ofxDatGui(ofxDatGuiAnchor::TOP_RIGHT);
	gui->addHeader("Ellipse Panel");
	sx = gui->addSlider("Ellipse X", 0, ofGetWidth());
	sy = gui->addSlider("Ellipse Y", 0, ofGetHeight());
	swidth = gui->addSlider("Ellipse width", 0, ofGetWidth() / 2);
	sheight = gui->addSlider("Ellipse height", 0, ofGetHeight() / 2);
	picker = gui->addColorPicker("COLOR PICKER", ofColor::fromHex(0xCECECE));
	picker->onColorPickerEvent(this, &EllipsePanel::onColorPickerEvent);

	sx->bind(ellipse->x);
	sy->bind(ellipse->y);
	swidth->bind(ellipse->width);
	sheight->bind(ellipse->height);

	ellipse->x = ofGetWidth() / 2;
	ellipse->y = ofGetHeight() / 2;
}

void EllipsePanel::update()
{
	// drag the circle around if the mouse is pressed while over it //
	if (ofGetMousePressed() && gui->getMouseDown() == false) {
		ofPoint mouse = ofPoint(ofGetMouseX(), ofGetMouseY());
		if (ellipse->inside(mouse)) {
			ellipse->x = mouse.x;
			ellipse->y = mouse.y;
		}
	}
}

void EllipsePanel::draw()
{
	ellipse->draw();
	update();
}

void EllipsePanel::onColorPickerEvent(ofxDatGuiColorPickerEvent e)
{
	ellipse->color = e.color;
}

