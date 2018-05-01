#include "controllerPanel.h"
#include "../controllers/MainController.h"

void controllerPanel::setup(MainController* mainController)
{	
	mainControllerInstance = mainController;
	gui->setWidth(200);
	gui->addLabel("Control Panel");
	importBtn = gui->addButton("Import");
	exportBtn = gui->addButton("Export");
	removeSelected = gui->addButton("Remove selected");
	mode3DToggle = gui->addToggle("3D Mode");
	modeRayTracing = gui->addToggle("Ray Tracing");
	gui->addLabel("Background Color : ");
	backgroundPicker = gui->addColorPicker("", ofColor::fromHex(0xCECECE));
	backgroundPicker->onColorPickerEvent(this, &controllerPanel::onColorPickerEvent);

	primitives2D = gui->addDropdown("Primitives 2D", options);
	primitives3D = gui->addDropdown("Primitives 3D", options3D);
	lights = gui->addDropdown("Lights", optionsLights);
	blurToggle = gui->addToggle("Blur");
	antiAliasingToggle = gui->addToggle("Anti-Aliasing");
	bloomToggle = gui->addToggle("Bloom");
	contrastToggle = gui->addToggle("Contrast");
	noiseToggle = gui->addToggle("Noise");

	gui->addBreak();

	gui->onButtonEvent(this, &controllerPanel::onButtonEvent);
	gui->onDropdownEvent(this, &controllerPanel::onPrimitiveDropdownEvent);
}

void controllerPanel::update()
{
	if (mode3DToggle->getChecked()) {
		modeRayTracing->setChecked(false);
		modeRayTracing->setEnabled(false);
	}
	else if (!mode3DToggle->getChecked())
		modeRayTracing->setEnabled(true);

	if (modeRayTracing->getChecked()) {
		mode3DToggle->setChecked(false);
		mode3DToggle->setEnabled(false);
	}
	else if (!modeRayTracing->getChecked())
		mode3DToggle->setEnabled(true);
}

void controllerPanel::onButtonEvent(ofxDatGuiButtonEvent e) {
	if (e.target == importBtn) {
		cout << "Importing Image..." << endl;
		mainControllerInstance->importImage();
	}
	else if (e.target == exportBtn) {
		cout << "Exporting Image..." << endl;
		mainControllerInstance->exportImage();
	}
	else if (e.target == removeSelected) {
		cout << "Removing selected..." << endl;
		mainControllerInstance->removeSelectedPrimitives();
	}
	else if (e.target == blurToggle) {
		cout << "Blur effect..." << endl;
		if (blurFilter) {
			blurFilter = false;
		}
		else {
			blurFilter = true;
		}
		mainControllerInstance->blurIsActive = blurFilter;
	}
	else if (e.target == antiAliasingToggle) {
		cout << "Antia Aliasing effect..." << endl;
		if (antiAliasingFilter) {
			antiAliasingFilter = false;
		}
		else {
			antiAliasingFilter = true;
		}
		mainControllerInstance->AntiAliasingIsActive = antiAliasingFilter;
	}
	else if (e.target == bloomToggle) {
		cout << "Bloom effect..." << endl;
		if (bloomFilter) {
			bloomFilter = false;
		}
		else {
			bloomFilter = true;
		}
		mainControllerInstance->bloomIsActive = bloomFilter;
	}
	else if (e.target == contrastToggle) {
		cout << "Contrast effect..." << endl;
		if (contrastFilter) {
			contrastFilter = false;
		}
		else {
			contrastFilter = true;
		}
		mainControllerInstance->contrastIsActive = contrastFilter;
	}
	else if (e.target == noiseToggle) {
		cout << "Noise effect..." << endl;
		if (noiseFilter) {
			noiseFilter = false;
		}
		else {
			noiseFilter = true;
		}
		mainControllerInstance->noiseIsActive = noiseFilter;
	}
	else if (e.target == mode3DToggle) {
		if (mode2D == true) {
			ofLog() << "Switching to 3D mode";
			mainControllerInstance->switch3DMode();
			mode2D = false;
		}
		else {
			ofLog() << "Switching to 2D mode";
			mainControllerInstance->switch2DMode();
			mode2D = true;
		}
	}
	else if (e.target == modeRayTracing) {
		if (mode2D == true) {
			ofLog() << "Switching to ray tracing mode";
			mainControllerInstance->switchRayTracingMode();
			mode2D = false;
		}
		else {
			ofLog() << "Switching to 2D mode";
			mainControllerInstance->switch2DMode();
			mode2D = true;
		}
	}
}

void controllerPanel::onPrimitiveDropdownEvent(ofxDatGuiDropdownEvent e) 
{
	if (e.target == primitives2D) {
		cout << "the option at index # " << e.child << " was selected " << endl;
		string primitive = options.at(e.child);
		mainControllerInstance->openNewPrimitvePanel(primitive);
	}
	else if (e.target == primitives3D) {
		cout << "the option at index # " << e.child << " was selected " << endl;
		string primitive = options3D.at(e.child);
		mainControllerInstance->openNewPrimitve3DPanel(primitive);
	}
	else if (e.target == lights) {
		cout << "the option at index # " << e.child << " was selected " << endl;
		string primitive = optionsLights.at(e.child);
		mainControllerInstance->openNewLightPanel(primitive);
	}
}

void controllerPanel::onColorPickerEvent(ofxDatGuiColorPickerEvent e)
{	
	ofBackground(e.color);
}
