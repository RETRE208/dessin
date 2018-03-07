#include "MainPanel.h"
#include "../controllers/MainController.h"


void MainPanel::setup(MainController* mainController) {
	mainControllerInstance = mainController;
	gui.setup();
	gui.add(intSlider.setup("int slider", 0, 0, 300));
	gui.add(floatSlider.setup("float slider", 33.33, 0.0, 66.66));
	gui.add(toggle.setup("toggle", false));
	importBtn.addListener(this, &MainPanel::importImage);
	gui.add(importBtn.setup("Import"));
	exportBtn.addListener(this, &MainPanel::exportImage);
	gui.add(exportBtn.setup("Export"));
}

void MainPanel::draw() {
	gui.draw();
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

