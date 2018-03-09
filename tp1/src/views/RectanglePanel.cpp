#include "RectanglePanel.h"

void RectanglePanel::setup(string name)
{
	rectangle = new tp1::Rectangle();
	panelName = name;
	gui = new ofxDatGui(ofxDatGuiAnchor::TOP_RIGHT);
	gui->addHeader(name);
	sx = gui->addSlider("RECTANLGLE X", 0, ofGetWidth());
	sy = gui->addSlider("RECTANLGLE Y", 0, ofGetHeight());
	swidth = gui->addSlider("RECTANLGLE WIDTH", 0, ofGetWidth());
	sheight = gui->addSlider("RECTANLGLE HEIGHT", 0, ofGetHeight());
	picker = gui->addColorPicker("COLOR PICKER", ofColor::fromHex(0xCECECE));
	picker->onColorPickerEvent(this, &RectanglePanel::onColorPickerEvent);

	sx->bind(rectangle->x);
	sy->bind(rectangle->y);
	swidth->bind(rectangle->width);
	sheight->bind(rectangle->height);

	rectangle->x = ofGetWidth() / 2;
	rectangle->y = ofGetHeight() / 2;
}

void RectanglePanel::draw()
{
	rectangle->draw();
}

void RectanglePanel::onColorPickerEvent(ofxDatGuiColorPickerEvent e)
{
	rectangle->color = e.color;
}

void RectanglePanel::setColor(ofColor color) {
	rectangle->color = color;
}

string RectanglePanel::getPanelName() {
	return panelName;
}

void RectanglePanel::deletePanel()
{
	gui->~ofxDatGui();
}
