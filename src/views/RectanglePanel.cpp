#include "RectanglePanel.h"

void RectanglePanel::setup(string name)
{
	rectangle = new tp1::Rectangle();
	panelName = name;
	gui = new ofxDatGui(ofxDatGuiAnchor::TOP_RIGHT);
	gui->setWidth(200);
	gui->addHeader(name);
	sx = gui->addSlider("RECTANLGLE X", 0, ofGetWidth());
	sy = gui->addSlider("RECTANLGLE Y", 0, ofGetHeight());
	swidth = gui->addSlider("RECTANLGLE WIDTH", 0, ofGetWidth());
	sheight = gui->addSlider("RECTANLGLE HEIGHT", 0, ofGetHeight());
	slineWidth = gui->addSlider("LINE WIDTH", 0.1, 8.0);
	primaryPicker = gui->addColorPicker("PRIMARY COLOR", ofColor::fromHex(0xCECECE));
	primaryPicker->onColorPickerEvent(this, &RectanglePanel::onColorPickerEvent);
	secondaryPicker = gui->addColorPicker("SECONDARY COLOR", ofColor::fromHex(0xCECECE));
	secondaryPicker->onColorPickerEvent(this, &RectanglePanel::onColorPickerEvent);
	isFillToggle = gui->addToggle("Fill");

	gui->onButtonEvent(this, &RectanglePanel::onButtonEvent);

	sx->bind(rectangle->x);
	sy->bind(rectangle->y);
	swidth->bind(rectangle->width);
	sheight->bind(rectangle->height);
	slineWidth->bind(rectangle->lineWidth);

	rectangle->x = ofGetWidth() / 2;
	rectangle->y = ofGetHeight() / 2;
}

void RectanglePanel::draw()
{
	rectangle->draw();
}

void RectanglePanel::onColorPickerEvent(ofxDatGuiColorPickerEvent e)
{
	if (e.target == primaryPicker) {
		rectangle->primaryColor = e.color;
	}
	if (e.target == secondaryPicker) {
		rectangle->secondaryColor = e.color;
	}
}

void RectanglePanel::onButtonEvent(ofxDatGuiButtonEvent e) {
	if (rectangle->isFill == false) {
		rectangle->isFill = true;
	}
	else {
		rectangle->isFill = false;
	}
}


void RectanglePanel::setColor(ofColor color) {
	rectangle->primaryColor = color;
}

string RectanglePanel::getPanelName() {
	return panelName;
}

void RectanglePanel::deletePanel()
{
	gui->~ofxDatGui();
}
