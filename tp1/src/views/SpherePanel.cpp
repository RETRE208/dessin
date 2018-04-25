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
	materialToggle = gui->addToggle("ENABLE MATERIAL", false);
	shininessSlider = gui->addSlider("SNININESS", 0, 255);
	shininessSlider->setEnabled(false);
	shininessSlider->onSliderEvent(this, &SpherePanel::onSliderEvent);
	materialToggle->onToggleEvent(this, &SpherePanel::onToggleEvent);

	sx->bind(sphere->x);
	sy->bind(sphere->y);
	sz->bind(sphere->z);
	sr->bind(sphere->mRadius);
	shininessSlider->bind(shinyness);

	sphere -> x = ofGetWidth() / 2;
	sphere -> y = ofGetHeight() / 2;
}

void SpherePanel::draw()
{
	if (materialToggle->getChecked()) {
		material.setShininess(shinyness);
		material.begin();
		sphere->draw();
		material.end();
	}
	else {
		sphere->draw();
	}
}

void SpherePanel::onToggleEvent(ofxDatGuiToggleEvent e)
{
	shininessSlider->setEnabled(materialToggle->getChecked());
}

void SpherePanel::onColorPickerEvent(ofxDatGuiColorPickerEvent e)
{
	sphere->color = e.color;
	material.setSpecularColor(e.color);
	material.setDiffuseColor(e.color);
	material.setAmbientColor(e.color);
}

void SpherePanel::onSliderEvent(ofxDatGuiSliderEvent e)
{
	material.setShininess(e.value);
}

