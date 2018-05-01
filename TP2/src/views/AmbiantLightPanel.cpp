#include "AmbiantLightPanel.h"
#include "../controllers/MainController.h"

void AmbiantLightPanel::setup(MainController* mainController)
{
	mainControllerInstance = mainController;

	gui = new ofxDatGui(ofxDatGuiAnchor::TOP_RIGHT);
	gui->setWidth(200);
	gui->addHeader("Ambiant light Panel");
	picker = gui->addColorPicker("COLOR PICKER", ofColor::fromHex(0xCECECE));
	picker->onColorPickerEvent(this, &AmbiantLightPanel::onColorPickerEvent);
}

void AmbiantLightPanel::draw()
{
	ofEnableDepthTest();
	ofEnableLighting();
	light.setDirectional();
	light.enable();
}

void AmbiantLightPanel::onColorPickerEvent(ofxDatGuiColorPickerEvent e)
{
	light.setSpecularColor(ofColor(e.color.r, e.color.g, e.color.b));
	light.setDiffuseColor(ofColor(e.color.r, e.color.g, e.color.b));
	light.setAmbientColor(ofColor(e.color.r, e.color.g, e.color.b));
}