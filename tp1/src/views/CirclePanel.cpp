#include "CirclePanel.h"

void CirclePanel::setup()
{
	circle = new Circle(150);

	gui = new ofxDatGui(ofxDatGuiAnchor::TOP_RIGHT);
	gui->addHeader("Circle Panel");
	sx = gui->addSlider("CIRCLE X", 0, ofGetWidth());
	sy = gui->addSlider("CIRCLE Y", 0, ofGetHeight());
	sr = gui->addSlider("CIRCLE RADUIS", 0, ofGetWidth()/2);
	picker = gui->addColorPicker("COLOR PICKER", ofColor::fromHex(0xCECECE));
	picker->onColorPickerEvent(this, &CirclePanel::onColorPickerEvent);

	sx->bind(circle->x);
	sy->bind(circle->y);
	sr->bind(circle->mRadius);

	circle->x = ofGetWidth() / 2;
	circle->y = ofGetHeight() / 2;
}

void CirclePanel::draw()
{
	circle -> draw();
}

void CirclePanel::onColorPickerEvent(ofxDatGuiColorPickerEvent e)
{
	circle->color = e.color;
}

