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

	leatherToggle = gui->addToggle("ENABLE LEATHER MATERIAL", false);
	goldToggle = gui->addToggle("ENABLE METAL MATERIAL", false);
	concreteToggle = gui->addToggle("ENABLE VELVET MATERIAL", false);
	leatherToggle->onToggleEvent(this, &CubePanel::onToggleLeatherEvent);
	goldToggle->onToggleEvent(this, &CubePanel::onToggleGoldEvent);
	concreteToggle->onToggleEvent(this, &CubePanel::onToggleConcreteEvent);
	materialToggle = gui->addToggle("ENABLE MATERIAL", false);
	shininessSlider = gui->addSlider("SNININESS", 5, 126);
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

	cube->x = 0;
	cube->y = 0;

	ofDisableArbTex();
	ofLoadImage(leatherTexture, "leather.jpg");
	ofLoadImage(goldTexture, "metal.jpg");
	ofLoadImage(concreteTexture, "velvet.jpg");
}

void CubePanel::draw()
{
	if (materialToggle->getChecked()) {
		material.setShininess(shinyness);
		material.begin();
		cube->draw();
		material.end();
	}
	else if (leatherToggle->getChecked()) {
		material.setShininess(50);
		leatherTexture.bind();
		leatherMaterial.begin();
		cube->draw();
		leatherTexture.unbind();
		leatherMaterial.end();
	}
	else if (goldToggle->getChecked()) {
		material.setShininess(110);
		goldTexture.bind();
		goldMaterial.begin();
		cube->draw();
		goldTexture.unbind();
		goldMaterial.end();
	}
	else if (concreteToggle->getChecked()) {
		concreteMaterial.setShininess(0);
		concreteTexture.bind();
		concreteMaterial.begin();
		cube->draw();
		concreteTexture.unbind();
		concreteMaterial.end();
	}
	else {
		cube->draw();
	}
}

void CubePanel::onToggleEvent(ofxDatGuiToggleEvent e)
{
	shininessSlider->setEnabled(materialToggle->getChecked());
	leatherToggle->setChecked(false);
	goldToggle->setChecked(false);
	concreteToggle->setChecked(false);
}

void CubePanel::onColorPickerEvent(ofxDatGuiColorPickerEvent e)
{
	cube->color = e.color;
	material.setSpecularColor(e.color);
	material.setDiffuseColor(e.color);
	material.setAmbientColor(e.color);
	material.setSpecularColor(e.color);
}

void CubePanel::onSliderEvent(ofxDatGuiSliderEvent e)
{
	material.setShininess(e.value);
}

void CubePanel::onToggleLeatherEvent(ofxDatGuiToggleEvent e)
{
	if (leatherToggle->getChecked())
		cube->color = (200, 200, 200);
	else
		cube->color = picker->getColor();
	shininessSlider->setEnabled(false);
	materialToggle->setChecked(false);
	goldToggle->setChecked(false);
	concreteToggle->setChecked(false);
}

void CubePanel::onToggleGoldEvent(ofxDatGuiToggleEvent e)
{
	if (goldToggle->getChecked())
		cube->color = (255, 255, 255);
	else
		cube->color = picker->getColor();
	shininessSlider->setEnabled(false);
	materialToggle->setChecked(false);
	leatherToggle->setChecked(false);
	concreteToggle->setChecked(false);
}

void CubePanel::onToggleConcreteEvent(ofxDatGuiToggleEvent e)
{
	if (concreteToggle->getChecked())
		cube->color = (255, 255, 255);
	else
		cube->color = picker->getColor();
	shininessSlider->setEnabled(false);
	materialToggle->setChecked(false);
	goldToggle->setChecked(false);
	leatherToggle->setChecked(false);
}


