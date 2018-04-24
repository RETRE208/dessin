#include "PointLightPanel.h"
#include "../controllers/MainController.h"

void PointLightPanel::setup(MainController* mainController)
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

	sliderX->onSliderEvent(this, &PointLightPanel::onSliderEvent);
	sliderY->onSliderEvent(this, &PointLightPanel::onSliderEvent);
	sliderZ->onSliderEvent(this, &PointLightPanel::onSliderEvent);
	picker->onColorPickerEvent(this, &PointLightPanel::onColorPickerEvent);
}

void PointLightPanel::draw()
{
	ofEnableDepthTest();
	ofEnableLighting();
	light.setPointLight();
	light.setPosition(x, y, z);
	light.enable();
}

void PointLightPanel::onSliderEvent(ofxDatGuiSliderEvent e) {
	light.setPosition(x, y, z);
	ofLog() << x << " : " << y << " : " << z;
}

void PointLightPanel::onColorPickerEvent(ofxDatGuiColorPickerEvent e)
{
	light.setSpecularColor(ofColor(e.color.r, e.color.g, e.color.b));
	light.setDiffuseColor(ofColor(e.color.r, e.color.g, e.color.b));
	light.setAmbientColor(ofColor(e.color.r, e.color.g, e.color.b));
}