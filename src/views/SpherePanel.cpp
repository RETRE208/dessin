#include "SpherePanel.h"

void SpherePanel::setup()
{
	sphere = new Sphere(10);

	gui = new ofxDatGui(ofxDatGuiAnchor::TOP_RIGHT);
	gui->setWidth(200);
	gui->addHeader("Sphere Panel");
	sx = gui->addSlider("SPHERE X", 0, ofGetWidth());
	sy = gui->addSlider("SPHERE Y", 0, ofGetHeight());
	sz = gui->addSlider("SPHERE Z", -500, 500);
	sr = gui->addSlider("SPHERE RADUIS", 0, ofGetWidth() / 2);
	picker = gui->addColorPicker("COLOR PICKER", ofColor::fromHex(0xCECECE));
	picker->onColorPickerEvent(this, &SpherePanel::onColorPickerEvent);

	sx->bind(sphere->x);
	sy->bind(sphere->y);
	sz->bind(sphere->z);
	sr->bind(sphere->mRadius);

	sphere -> x = 0;
	sphere -> y = 0;
}

void SpherePanel::draw()
{
	sphere->draw();
}

void SpherePanel::onColorPickerEvent(ofxDatGuiColorPickerEvent e)
{
	sphere->color = e.color;
}
