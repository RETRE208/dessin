#include "SpotLightPanel.h"
#include "../controllers/MainController.h"

void SpotLightPanel::setup(MainController* mainController)
{
	mainControllerInstance = mainController;

	gui = new ofxDatGui(ofxDatGuiAnchor::TOP_RIGHT);
	gui->setWidth(200);
	gui->addHeader("Light Panel");

	sliderX = gui->addSlider("Image X", -ofGetHeight(), ofGetWidth());
	sliderY = gui->addSlider("Image Y", -ofGetHeight(), ofGetHeight());
	sliderZ = gui->addSlider("Image Z", -500, 500);
	sliderAngle = gui->addSlider("Angle", 1, 360, 180);
	picker = gui->addColorPicker("COLOR PICKER", ofColor::fromHex(0xCECECE));

	sliderX->bind(x);
	sliderY->bind(y);
	sliderZ->bind(z);
	sliderAngle->bind(angle);

	sliderX->onSliderEvent(this, &SpotLightPanel::onSliderEvent);
	sliderY->onSliderEvent(this, &SpotLightPanel::onSliderEvent);
	sliderZ->onSliderEvent(this, &SpotLightPanel::onSliderEvent);
	sliderAngle->onSliderEvent(this, &SpotLightPanel::onSliderEvent);
	picker->onColorPickerEvent(this, &SpotLightPanel::onColorPickerEvent);
	light.setSpotlight();
}

void SpotLightPanel::draw()
{
	ofEnableDepthTest();
	ofEnableLighting();
	light.enable();	
}

void SpotLightPanel::onSliderEvent(ofxDatGuiSliderEvent e) {
	light.setSpotlightCutOff(angle);
	light.setPosition(x, y, z);
	ofLog() << x << " : " << y << " : " << z;
	ofLog() << angle;
}

void SpotLightPanel::onColorPickerEvent(ofxDatGuiColorPickerEvent e)
{
	ofLog() << x << " : " << y << " : " << z;
	light.setSpecularColor(ofColor(e.color.r, e.color.g, e.color.b));
	light.setDiffuseColor(ofColor(e.color.r, e.color.g, e.color.b));
	light.setAmbientColor(ofColor(e.color.r, e.color.g, e.color.b));
}