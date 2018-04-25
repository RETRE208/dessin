#include "CubePanel.h"

void CubePanel::setup()
{
	cube = new Cube(10,10,10);

	gui = new ofxDatGui(ofxDatGuiAnchor::TOP_RIGHT);
	gui->setWidth(200);
	gui->addHeader("Cube Panel");
	sx = gui->addSlider("POSITION X", 0, ofGetWidth());
	sy = gui->addSlider("POSITION Y", 0, ofGetHeight());
	sz = gui->addSlider("POSITION Z", -500, 500);
	w = gui->addSlider("WIDTH", 0, ofGetWidth() / 2);
	h = gui->addSlider("HEIGHT", 0, ofGetWidth() / 2);
	d = gui->addSlider("DEPTH", 0, ofGetWidth() / 2);
	rx = gui->addSlider("ROTATION X", 0, 360);
	ry = gui->addSlider("ROTATION Y", 0, 360);
	rz = gui->addSlider("ROTATION Z", 0, 360);
	picker = gui->addColorPicker("COLOR PICKER", ofColor::fromHex(0xCECECE));
	picker->onColorPickerEvent(this, &CubePanel::onColorPickerEvent);
	materialToggle = gui->addToggle("ENABLE MATERIAL", false);
	shininessSlider = gui->addSlider("SNININESS", 0, 255);
	shininessSlider->setEnabled(false);
	shininessSlider->onSliderEvent(this, &CubePanel::onSliderEvent);
	materialToggle->onToggleEvent(this, &CubePanel::onToggleEvent);

	sx->bind(cube->x);
	sy->bind(cube->y);
	sz->bind(cube->z);
	w->bind(cube->width);
	h->bind(cube->height);
	d->bind(cube->depth);
	rx->bind(cube->angleX);
	ry->bind(cube->angleY);
	rz->bind(cube->angleZ);
	shininessSlider->bind(shinyness);

	cube->x = ofGetWidth() / 2;
	cube->y = ofGetHeight() / 2;
}

void CubePanel::draw()
{
	if (materialToggle->getChecked()) {
		material.setShininess(shinyness);
		material.begin();
		cube->draw();
		material.end();
	}
	else {
		cube->draw();
	}
}

void CubePanel::onToggleEvent(ofxDatGuiToggleEvent e)
{
	shininessSlider->setEnabled(materialToggle->getChecked());
}

void CubePanel::onColorPickerEvent(ofxDatGuiColorPickerEvent e)
{
	cube->color = e.color;
	material.setSpecularColor(e.color);
	material.setDiffuseColor(e.color);
	material.setAmbientColor(e.color);
}

void CubePanel::onSliderEvent(ofxDatGuiSliderEvent e)
{
	material.setShininess(e.value);
}

