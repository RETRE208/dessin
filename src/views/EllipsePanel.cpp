#include "EllipsePanel.h"

void EllipsePanel::setup(string name)
{
	ellipse = new tp1::Ellipse();
	panelName = name;
	gui = new ofxDatGui(ofxDatGuiAnchor::TOP_RIGHT);
	gui->setWidth(200);
	gui->addHeader(name);
	sx = gui->addSlider("Ellipse X", 0, ofGetWidth());
	sy = gui->addSlider("Ellipse Y", 0, ofGetHeight());
	swidth = gui->addSlider("Ellipse width", 0, ofGetWidth() / 2);
	sheight = gui->addSlider("Ellipse height", 0, ofGetHeight() / 2);
	slineWidth = gui->addSlider("LINE WIDTH", 0.1, 8.0);
	primaryPicker = gui->addColorPicker("PRIMARY COLOR", ofColor::fromHex(0xCECECE));
	primaryPicker->onColorPickerEvent(this, &EllipsePanel::onColorPickerEvent);
	secondaryPicker = gui->addColorPicker("SECONDARY COLOR", ofColor::fromHex(0xCECECE));
	secondaryPicker->onColorPickerEvent(this, &EllipsePanel::onColorPickerEvent);
	isFillToggle = gui->addToggle("Fill");

	gui->onButtonEvent(this, &EllipsePanel::onButtonEvent);

	sx->bind(ellipse->x);
	sy->bind(ellipse->y);
	swidth->bind(ellipse->width);
	sheight->bind(ellipse->height);
	slineWidth->bind(ellipse->lineWidth);

	ellipse->x = ofGetWidth() / 2;
	ellipse->y = ofGetHeight() / 2;
}

void EllipsePanel::draw()
{
	ellipse->draw();
}

void EllipsePanel::onColorPickerEvent(ofxDatGuiColorPickerEvent e)
{
	if (e.target == primaryPicker) {
		ellipse->primaryColor = e.color;
	}
	if (e.target == secondaryPicker) {
		ellipse->secondaryColor = e.color;
	}
}

void EllipsePanel::onButtonEvent(ofxDatGuiButtonEvent e) {
	if (ellipse->isFill == false) {
		ellipse->isFill = true;
	}
	else {
		ellipse->isFill = false;
	}
}

void EllipsePanel::setColor(ofColor color) {
	ellipse->primaryColor = color;
}

string EllipsePanel::getPanelName() {
	return panelName;
}

void EllipsePanel::deletePanel()
{
	gui->~ofxDatGui();
}

