#include "controllerPanel.h"
#include "../controllers/MainController.h"

void controllerPanel::setup(MainController* mainController)
{	
	mainControllerInstance = mainController;
	gui->addLabel("Control Panel");
	importBtn = gui->addButton("Import");
	exportBtn = gui->addButton("Export");
	mode3DToggle = gui->addToggle("3D Mode");

	primitives2D = gui->addDropdown("Primitives 2D", options);
	primitives3D = gui->addDropdown("Primitives 3D", options3D);
	gui->addBreak();

	gui->onButtonEvent(this, &controllerPanel::onButtonEvent);
	gui->onDropdownEvent(this, &controllerPanel::onPrimitiveDropdownEvent);
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
}
