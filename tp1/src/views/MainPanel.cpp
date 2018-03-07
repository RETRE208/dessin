#include "MainPanel.h"
#include "../controllers/MainController.h"


void MainPanel::setup(MainController* mainController) {
	mainControllerInstance = mainController;
	leftMenu.setup();
	leftMenu.setPosition(0, 0);
	leftMenu.setDefaultWidth(200);
	mode3DToggle.addListener(this, &MainPanel::toggle3DMode);
	leftMenu.add(mode3DToggle.setup("3D Mode", false));
	//leftMenu.add(floatSlider.setup("float slider", 33.33, 0.0, 66.66));
	//leftMenu.add(toggle.setup("toggle", false));
	importBtn.addListener(this, &MainPanel::importImage);
	leftMenu.add(importBtn.setup("Import"));
	exportBtn.addListener(this, &MainPanel::exportImage);
	leftMenu.add(exportBtn.setup("Export"));
}

void MainPanel::draw() {
	leftMenu.draw();
}

void MainPanel::toggle3DMode(bool& pressed) {
	if (pressed == true) {
		ofLog() << "Switching to 3D mode";
		mainControllerInstance -> switch3DMode();
	}
	else {
		ofLog() << "Switching to 2D mode";
		mainControllerInstance -> switch2DMode();
	}
}

void MainPanel::importImage() {
	cout << "Importing Image..." << endl;
	mainControllerInstance -> importImage();
	draw();
}

void MainPanel::exportImage() {
	cout << "Exporting Image..." << endl;
	mainControllerInstance -> exportImage();
	draw();
}

