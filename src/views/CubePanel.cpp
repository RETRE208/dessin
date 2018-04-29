#include "CubePanel.h"

void CubePanel::setup()
{
	cube = new Cube(10,10,10);

	gui = new ofxDatGui(ofxDatGuiAnchor::TOP_RIGHT);
	gui->setWidth(200);
	gui->addHeader("Cube Panel");
	sx = gui->addSlider("POSITION X", -ofGetWidth(), ofGetWidth());
	sy = gui->addSlider("POSITION Y", -ofGetHeight(), ofGetHeight());
	sz = gui->addSlider("POSITION Z", -1000, 1000);
	w = gui->addSlider("WIDTH", 0, ofGetWidth() / 2);
	h = gui->addSlider("HEIGHT", 0, ofGetWidth() / 2);
	d = gui->addSlider("DEPTH", 0, ofGetWidth() / 2);
	rx = gui->addSlider("ROTATION X", 0, 360);
	ry = gui->addSlider("ROTATION Y", 0, 360);
	rz = gui->addSlider("ROTATION Z", 0, 360);
	picker = gui->addColorPicker("COLOR PICKER", ofColor::fromHex(0xCECECE));
	picker->onColorPickerEvent(this, &CubePanel::onColorPickerEvent);

	sx->bind(cube->x);
	sy->bind(cube->y);
	sz->bind(cube->z);
	w->bind(cube->width);
	h->bind(cube->height);
	d->bind(cube->depth);
	rx->bind(cube->angleX);
	ry->bind(cube->angleY);
	rz->bind(cube->angleZ);

	cube->x = 0;
	cube->y = 0;
}

void CubePanel::draw()
{
	cube->draw();
}

void CubePanel::onColorPickerEvent(ofxDatGuiColorPickerEvent e)
{
	cube->color = e.color;
}

