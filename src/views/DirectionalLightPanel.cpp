#include "DirectionalLightPanel.h"
#include "../controllers/MainController.h"

void DirectionalLightPanel::setup(MainController* mainController)
{
	mainControllerInstance = mainController;

	gui = new ofxDatGui(ofxDatGuiAnchor::TOP_RIGHT);
	gui->setWidth(200);
	gui->addHeader("Light Panel");

	sliderX = gui->addSlider("Image X", 0, ofGetWidth(), 200);
	sliderY = gui->addSlider("Image Y", 0, ofGetHeight(), 200);
	sliderZ = gui->addSlider("Image Z", -500, 500);
	picker = gui->addColorPicker("COLOR PICKER", ofColor::fromHex(0xCECECE));

	sliderX->bind(x);
	sliderY->bind(y);
	sliderZ->bind(z);

	sliderX->onSliderEvent(this, &DirectionalLightPanel::onSliderEvent);
	sliderY->onSliderEvent(this, &DirectionalLightPanel::onSliderEvent);
	sliderZ->onSliderEvent(this, &DirectionalLightPanel::onSliderEvent);
	picker->onColorPickerEvent(this, &DirectionalLightPanel::onColorPickerEvent);
}

void DirectionalLightPanel::draw()
{
	ofEnableDepthTest();
	ofEnableLighting();
	light.setPosition(x, y, z);
	light.enable();
}

void DirectionalLightPanel::onSliderEvent(ofxDatGuiSliderEvent e) {
	light.setPosition(x, y, z);
	ofLog() << x << " : " << y << " : " << z;
}

void DirectionalLightPanel::onColorPickerEvent(ofxDatGuiColorPickerEvent e)
{
	light.setSpecularColor(ofColor(e.color.r, e.color.g, e.color.b));
	light.setDiffuseColor(ofColor(e.color.r, e.color.g, e.color.b));
	light.setAmbientColor(ofColor(e.color.r, e.color.g, e.color.b));
}