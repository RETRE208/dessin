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
	rx = gui->addSlider("ROTATION X", 0, 360);
	ry = gui->addSlider("ROTATION Y", 0, 360);
	rz = gui->addSlider("ROTATION Z", 0, 360);
	picker = gui->addColorPicker("COLOR PICKER", ofColor::fromHex(0xCECECE));
	picker->onColorPickerEvent(this, &SpherePanel::onColorPickerEvent);

	leatherToggle = gui->addToggle("ENABLE LEATHER MATERIAL", false);
	goldToggle = gui->addToggle("ENABLE METAL MATERIAL", false);
	concreteToggle = gui->addToggle("ENABLE VELVET MATERIAL", false);
	leatherToggle->onToggleEvent(this, &SpherePanel::onToggleLeatherEvent);
	goldToggle->onToggleEvent(this, &SpherePanel::onToggleGoldEvent);
	concreteToggle->onToggleEvent(this, &SpherePanel::onToggleConcreteEvent);

	materialToggle = gui->addToggle("ENABLE DEFAULT MATERIAL", false);
	shininessSlider = gui->addSlider("SNININESS", 5, 126);
	shininessSlider->setEnabled(false);
	shininessSlider->onSliderEvent(this, &SpherePanel::onSliderEvent);
	materialToggle->onToggleEvent(this, &SpherePanel::onToggleEvent);

	sx->bind(sphere->x);
	sy->bind(sphere->y);
	sz->bind(sphere->z);
	sr->bind(sphere->mRadius);
	rx->bind(sphere->angleX);
	ry->bind(sphere->angleY);
	rz->bind(sphere->angleZ);
	shininessSlider->bind(shininess);

	sphere -> x = ofGetWidth() / 2;
	sphere -> y = ofGetHeight() / 2;

	ofDisableArbTex();
	ofLoadImage(leatherTexture, "leather.jpg");
	ofLoadImage(goldTexture, "metal.jpg");
	ofLoadImage(concreteTexture, "velvet.jpg");
}

void SpherePanel::draw()
{
	if (materialToggle->getChecked()) {
		material.setShininess(shininess);
		material.begin();
		sphere->draw();
		material.end();
	}
	else if (leatherToggle->getChecked()) {
		material.setShininess(50);
		leatherTexture.bind();
		leatherMaterial.begin();
		sphere->draw();
		leatherTexture.unbind();
		leatherMaterial.end();
	}
	else if (goldToggle->getChecked()) {
		material.setShininess(110);
		goldTexture.bind();
		goldMaterial.begin();
		sphere->draw();
		goldTexture.unbind();
		goldMaterial.end();
	}
	else if (concreteToggle->getChecked()) {
		concreteMaterial.setShininess(0);
		concreteTexture.bind();
		concreteMaterial.begin();
		sphere->draw();
		concreteTexture.unbind();
		concreteMaterial.end();
	}
	else {
		sphere->draw();
	}
}

void SpherePanel::onToggleEvent(ofxDatGuiToggleEvent e)
{
	shininessSlider->setEnabled(materialToggle->getChecked());
	leatherToggle->setChecked(false);
	goldToggle->setChecked(false);
	concreteToggle->setChecked(false);
}

void SpherePanel::onColorPickerEvent(ofxDatGuiColorPickerEvent e)
{
	sphere->color = e.color;
	material.setAmbientColor(e.color);
	material.setDiffuseColor(e.color);
	material.setEmissiveColor(e.color);
	material.setSpecularColor(e.color);
}

void SpherePanel::onSliderEvent(ofxDatGuiSliderEvent e)
{
	material.setShininess(e.value);
}

void SpherePanel::onToggleLeatherEvent(ofxDatGuiToggleEvent e)
{
	if (leatherToggle->getChecked())
		sphere->color = (200, 200, 200);
	else
		sphere->color = picker->getColor();
	shininessSlider->setEnabled(false);
	materialToggle->setChecked(false);
	goldToggle->setChecked(false);
	concreteToggle->setChecked(false);
}

void SpherePanel::onToggleGoldEvent(ofxDatGuiToggleEvent e)
{
	if (goldToggle->getChecked())
		sphere->color = (255, 255, 255);
	else
		sphere->color = picker->getColor();
	shininessSlider->setEnabled(false);
	materialToggle->setChecked(false);
	leatherToggle->setChecked(false);
	concreteToggle->setChecked(false);
}

void SpherePanel::onToggleConcreteEvent(ofxDatGuiToggleEvent e)
{
	if (concreteToggle->getChecked())
		sphere->color = (255, 255, 255);
	else
		sphere->color = picker->getColor();
	shininessSlider->setEnabled(false);
	materialToggle->setChecked(false);
	goldToggle->setChecked(false);
	leatherToggle->setChecked(false);
}


