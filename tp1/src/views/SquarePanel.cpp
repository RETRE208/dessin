#include "SquarePanel.h"

void SquarePanel::setup(string name)
{
	square = new Square();
	panelName = name;
	gui = new ofxDatGui(ofxDatGuiAnchor::TOP_RIGHT);
	gui->addHeader(name);
	sx = gui->addSlider("SQUARE X", 0, ofGetWidth());
	sy = gui->addSlider("SQUARE Y", 0, ofGetHeight());
	sheight = gui->addSlider("SQUARE HEIGHT", 0, ofGetHeight());
	slineWidth = gui->addSlider("LINE WIDTH", 0.1, 8.0);
	primaryPicker = gui->addColorPicker("PRIMARY COLOR", ofColor::fromHex(0xCECECE));
	primaryPicker->onColorPickerEvent(this, &SquarePanel::onColorPickerEvent);
	secondaryPicker = gui->addColorPicker("SECONDARY COLOR", ofColor::fromHex(0xCECECE));
	secondaryPicker->onColorPickerEvent(this, &SquarePanel::onColorPickerEvent);
	isFillToggle = gui->addToggle("Fill");

	gui->onButtonEvent(this, &SquarePanel::onButtonEvent);

	sx->bind(square->x);
	sy->bind(square->y);
	sheight->bind(square->height);
	slineWidth->bind(square->lineWidth);

	square->x = ofGetWidth() / 2;
	square->y = ofGetHeight() / 2;
}

void SquarePanel::draw()
{
	square->draw();
}

void SquarePanel::onColorPickerEvent(ofxDatGuiColorPickerEvent e)
{
	if (e.target == primaryPicker) {
		square->primaryColor = e.color;
	}
	if (e.target == secondaryPicker) {
		square->secondaryColor = e.color;
	}
}

void SquarePanel::onButtonEvent(ofxDatGuiButtonEvent e) {
	if (square->isFill == false) {
		square->isFill = true;
	}
	else {
		square->isFill = false;
	}
}


void SquarePanel::setColor(ofColor color) {
	square->primaryColor = color;
}

string SquarePanel::getPanelName() {
	return panelName;
}

void SquarePanel::deletePanel()
{
	gui->~ofxDatGui();
}