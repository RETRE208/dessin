#include "controllerPanel.h"
#include "../controllers/MainController.h"

void controllerPanel::setup(MainController* mainController)
{	
	mainControllerInstance = mainController;
	gui->addLabel("Control Panel");
	gui->addDropdown("Primitives", options);
	gui->addBreak();

	gui->onDropdownEvent(this, &controllerPanel::onDropdownEvent);
}

void controllerPanel::onDropdownEvent(ofxDatGuiDropdownEvent e) 
{
	cout << "the option at index # " << e.child << " was selected " << endl;
	string primitive = options.at(e.child);
	mainControllerInstance->openNewPrimitvePanel(primitive);
}
