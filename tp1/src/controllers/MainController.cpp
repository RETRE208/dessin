#include "MainController.h"

void MainController::setup()
{
	primitivePanel.setup();
	mainPanel.setup();
}

void MainController::draw()
{
	mainPanel.draw();
	primitivePanel.draw();
}
	