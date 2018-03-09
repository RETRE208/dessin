#include "CirclePanel.h"

void CirclePanel::setup(string name)
{
	circle = new Circle(150);
	panelName = name;
	gui = new ofxDatGui(ofxDatGuiAnchor::TOP_RIGHT);
	gui->addHeader(name);
	sx = gui->addSlider("CIRCLE X", 0, ofGetWidth());
	sy = gui->addSlider("CIRCLE Y", 0, ofGetHeight());
	sr = gui->addSlider("CIRCLE RADUIS", 0, ofGetWidth()/2);
	slineWidth = gui->addSlider("LINE WIDTH", 0.1, 8.0);
	primaryPicker = gui->addColorPicker("PRIMARY COLOR", ofColor::fromHex(0xCECECE));
	primaryPicker->onColorPickerEvent(this, &CirclePanel::onColorPickerEvent);
	secondaryPicker = gui->addColorPicker("SECONDARY COLOR", ofColor::fromHex(0xCECECE));
	secondaryPicker->onColorPickerEvent(this, &CirclePanel::onColorPickerEvent);
	isFillToggle = gui->addToggle("Fill");

	gui->onButtonEvent(this, &CirclePanel::onButtonEvent);

	sx->bind(circle->x);
	sy->bind(circle->y);
	sr->bind(circle->mRadius);
	slineWidth->bind(circle->lineWidth);

	circle->x = ofGetWidth() / 2;
	circle->y = ofGetHeight() / 2;
}

void CirclePanel::draw()
{
	circle-> draw();
}

void CirclePanel::onColorPickerEvent(ofxDatGuiColorPickerEvent e)
{
	if (e.target == primaryPicker) {
		circle->primaryColor = e.color;
	}
	if (e.target == secondaryPicker) {
		circle->secondaryColor = e.color;
	}
}

void CirclePanel::onButtonEvent(ofxDatGuiButtonEvent e) {
	if (circle->isFill == false) {
		circle->isFill = true;
	}
	else {
		circle->isFill = false;
	}
}

void CirclePanel::setColor(ofColor color) {
	circle->primaryColor = color;
}

string CirclePanel::getPanelName() {
	return panelName;
}

void CirclePanel::deletePanel()
{
	gui->~ofxDatGui();
}

