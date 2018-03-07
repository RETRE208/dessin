#include "MainPanel.h"
#include "../controllers/MainController.h"


void MainPanel::setup(MainController* mainController) {
	mainControllerInstance = mainController;
	leftMenu.setup();
	leftMenu.setPosition(0, 0);
	leftMenu.setDefaultWidth(200);
	mode3DToggle.addListener(this, &MainPanel::toggle3DMode);
	leftMenu.add(mode3DToggle.setup("3D Mode", false));
	importBtn.addListener(this, &MainPanel::importImage);
	leftMenu.add(importBtn.setup("Import"));
	exportBtn.addListener(this, &MainPanel::exportImage);
	leftMenu.add(exportBtn.setup("Export"));

	leftMenu.add(meshLabel.setup("Mesh", "", 200, 20));
	meshFill.addListener(this, &MainPanel::toggleMeshFill);
	leftMenu.add(meshFill.setup("Fill", true));
	meshWireframe.addListener(this, &MainPanel::toggleMeshWireframe);
	leftMenu.add(meshWireframe.setup("Wireframe", false));
	meshPoints.addListener(this, &MainPanel::toggleMeshPoints);
	leftMenu.add(meshPoints.setup("Points", false));
}

void MainPanel::draw() {
	leftMenu.draw();
}

void MainPanel::toggleMeshFill(bool& pressed) {
	if (pressed == true) {
		ofLog() << "Switching to Mesh Fill";
		mainControllerInstance->switchMeshFill();
		meshWireframe = false;
		meshPoints = false;
	}
}

void MainPanel::toggleMeshWireframe(bool& pressed) {
	if (pressed == true) {
		ofLog() << "Switching to Mesh Wireframe";
		mainControllerInstance->switchMeshWireframe();
		meshFill = false;
		meshPoints = false;
	}
}

void MainPanel::toggleMeshPoints(bool& pressed) {
	if (pressed == true) {
		ofLog() << "Switching to Mesh Vertex";
		mainControllerInstance->switchMeshPoints();
		meshFill = false;
		meshWireframe = false;
	}
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

