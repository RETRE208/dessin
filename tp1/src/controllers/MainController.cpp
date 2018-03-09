#include "MainController.h"
#include <cstdlib>

class noModelsExeption : public exception
{
	virtual const char* what() const throw()
	{
		return "There is no models loaded yet";
	}
} NO_MODELS;

void MainController::setup()
{
	controlPanel.setup(this);
	selectorPanel.setup();
}

void MainController::draw()
{
	selectorPanel.draw();
	if (mode3DState) {
		ofEnableDepthTest();
		for (int i = 0; i < models.size(); i++) {
			switch (mesh_render_mode)
			{
			case MeshRenderMode::fill:
				models[i].draw(OF_MESH_FILL);
				break;

			case MeshRenderMode::wireframe:
				models[i].draw(OF_MESH_WIREFRAME);
				break;

			case MeshRenderMode::points:
				models[i].draw(OF_MESH_POINTS);
			}
		}
		for (int i = 0; i < spherePrimivites.size(); i++) {
			spherePrimivites[i]->draw();
		}
		for (int i = 0; i < cubePrimivites.size(); i++) {
			cubePrimivites[i]->draw();
		}
		ofDisableDepthTest();
	}
	else {
		for (int i = 0; i < images.size(); i++) {
			int imageWidth = images[i].getWidth();
			int imageHeight = images[i].getHeight();

			images[i].draw(
				DRAWING_ZONE_X_LIMIT,
				DRAWING_ZONE_Y_LIMIT,
				imageWidth,
				imageHeight);
		}
		for (int i = 0; i < circlePrimivites.size(); i++) {
			if (selectorPanel.getIfSelected(circlePrimivites[i]->panelName)) {
				circlePrimivites[i]->circle->color.r = selectorPanel.redSlider;
				circlePrimivites[i]->circle->color.g = selectorPanel.greenSlider;
				circlePrimivites[i]->circle->color.b = selectorPanel.blueSlider;
			}
			circlePrimivites[i] -> draw();
		}
		for (int i = 0; i < rectanglePrimivites.size(); i++) {
			if (selectorPanel.getIfSelected(rectanglePrimivites[i]->panelName)) {
				rectanglePrimivites[i]->rectangle->color.r = selectorPanel.redSlider;
				rectanglePrimivites[i]->rectangle->color.g = selectorPanel.greenSlider;
				rectanglePrimivites[i]->rectangle->color.b = selectorPanel.blueSlider;
			}
			rectanglePrimivites[i]->draw();
		}
		for (int i = 0; i < linePrimivites.size(); i++) {
			if (selectorPanel.getIfSelected(linePrimivites[i]->panelName)) {
				linePrimivites[i]->line->color.r = selectorPanel.redSlider;
				linePrimivites[i]->line->color.g = selectorPanel.greenSlider;
				linePrimivites[i]->line->color.b = selectorPanel.blueSlider;
			}
			linePrimivites[i]->draw();
		}
		for (int i = 0; i < ellipsePrimivites.size(); i++) {
			if (selectorPanel.getIfSelected(ellipsePrimivites[i]->panelName)) {
				ellipsePrimivites[i]->ellipse->color.r = selectorPanel.redSlider;
				ellipsePrimivites[i]->ellipse->color.g = selectorPanel.greenSlider;
				ellipsePrimivites[i]->ellipse->color.b = selectorPanel.blueSlider;
			}
			ellipsePrimivites[i]->draw();
		}
	}
}

void MainController::removeSelectedPrimitives() {
	for (int i = 0; i < circlePrimivites.size(); i++) {
		if (selectorPanel.getIfSelected(circlePrimivites[i]->panelName)) {
			selectorPanel.removeToggle(circlePrimivites[i]->panelName);
			circlePrimivites.erase(circlePrimivites.begin() + i);
		}
	}

	for (int i = 0; i < rectanglePrimivites.size(); i++) {
		if (selectorPanel.getIfSelected(rectanglePrimivites[i]->panelName)) {
			selectorPanel.removeToggle(rectanglePrimivites[i]->panelName);
			rectanglePrimivites.erase(rectanglePrimivites.begin() + i);
		}
	}

	for (int i = 0; i < linePrimivites.size(); i++) {
		if (selectorPanel.getIfSelected(linePrimivites[i]->panelName)) {
			selectorPanel.removeToggle(linePrimivites[i]->panelName);
			linePrimivites.erase(linePrimivites.begin() + i);
		}
	}

	for (int i = 0; i < ellipsePrimivites.size(); i++) {
		if (selectorPanel.getIfSelected(ellipsePrimivites[i]->panelName)) {
			selectorPanel.removeToggle(ellipsePrimivites[i]->panelName);
			ellipsePrimivites.erase(ellipsePrimivites.begin() + i);
		}
	}
}

void MainController::exportImage() {
	try {
		ofImage image;
		string fileName = files.setFile() + ".png";

		image.grabScreen(DRAWING_ZONE_X_LIMIT, DRAWING_ZONE_Y_LIMIT, DRAWING_ZONE_WIDTH, DRAWING_ZONE_HEIGHT);

		image.save(fileName);

		ofLog() << "<export image: " << fileName << ">";
	}
	catch (exception& e) {
		ofLog() << e.what();
	}
}

void MainController::importImage() {
	try {
		string imagePath = files.getFile();
		if (imagePath.back() == 'g') {
			ofImage newImage;
			newImage.load(imagePath);
			images.push_back(newImage);
			ofLog() << "<import image: " << imagePath << ">";
		}
		else if (imagePath.back() == 'j' || imagePath.back() == 'e') {
			ofxAssimpModelLoader newModel;
			newModel.loadModel(imagePath);
			center_x = DRAWING_ZONE_WIDTH / 2.0f + DRAWING_ZONE_X_LIMIT;
			center_y = DRAWING_ZONE_HEIGHT / 2.0f + DRAWING_ZONE_Y_LIMIT;
			newModel.setPosition(
				center_x,
				center_y,
				0);
			models.push_back(newModel);
			ofLog() << "<import model: " << imagePath << ">";
		}
	}
	catch (exception& e) {
		ofLog() << e.what();
	}
}

void MainController::switch2DMode() {
	mode3DState = false;
	ofDisableLighting();
}

void MainController::switch3DMode() {
	mode3DState = true;
	ofEnableLighting();

	light.setAmbientColor(ofColor(255, 255, 255));
	light.setDiffuseColor(ofColor(255, 255, 255));
	light.setPosition(0.0f, 0.0f, 1000.0f);
	light.enable();
}

void MainController::switchMeshFill() {
	mesh_render_mode = MeshRenderMode::fill;
}

void MainController::switchMeshWireframe() {
	mesh_render_mode = MeshRenderMode::wireframe;
}

void MainController::switchMeshPoints() {
	mesh_render_mode = MeshRenderMode::points;
}

void MainController::instanciateNewModel() {
	if (models.size() > 0) {
		ofxAssimpModelLoader newModel = models[0];
		center_x = DRAWING_ZONE_WIDTH / 2.0f + DRAWING_ZONE_X_LIMIT;
		center_y = DRAWING_ZONE_HEIGHT / 2.0f + DRAWING_ZONE_Y_LIMIT;
		newModel.setPosition(
			center_x + (rand() % DRAWING_ZONE_WIDTH) - (DRAWING_ZONE_WIDTH / 2.0f),
			center_y + (rand() % DRAWING_ZONE_HEIGHT) - (DRAWING_ZONE_HEIGHT / 2.0f),
			0);
		float scale = ofRandom(0.01f, 1.50f);
		newModel.setScale(scale, scale, scale);
		float rotationX = ofRandom(0.0f, 360.0f);
		float rotationY = ofRandom(0.0f, 360.0f);
		float rotationZ = ofRandom(0.0f, 360.0f);
		newModel.setRotation(0.0f, rotationX, 1.0f, 0.0f, 0.0f);
		newModel.setRotation(0.0f, rotationY, 0.0f, 1.0f, 0.0f);
		newModel.setRotation(0.0f, rotationZ, 0.0f, 0.0f, 1.0f);
		models.push_back(newModel);
	}
	else {
		throw NO_MODELS;
	}
}

void MainController::openNewPrimitvePanel(string primitiveName) {
	cout << "The primitive " << primitiveName << " was selected " << endl;

	if (primitiveName == "Circle") {
		CirclePanel* circlePanel = new CirclePanel();
		circlePanel->setup("Circle " + to_string(circlePrimivites.size()));
		circlePrimivites.push_back(circlePanel);
		selectorPanel.addToggle("Circle " + to_string(circlePrimivites.size() - 1));

	}
	if (primitiveName == "Rectangle") {
		RectanglePanel* rectanglePanel = new RectanglePanel();
		rectanglePanel->setup("Rectangle " + to_string(rectanglePrimivites.size()));
		rectanglePrimivites.push_back(rectanglePanel);
		selectorPanel.addToggle("Rectangle " + to_string(rectanglePrimivites.size() - 1));
	}
	if (primitiveName == "Line") {
		LinePanel* linePanel = new LinePanel();
		linePanel->setup("Line " + to_string(linePrimivites.size()));
		linePrimivites.push_back(linePanel);
		selectorPanel.addToggle("Line " + to_string(linePrimivites.size() - 1));
	}
	if (primitiveName == "Ellipse") {
		EllipsePanel* ellipsePanel = new EllipsePanel();
		ellipsePanel->setup("Ellipse " + to_string(ellipsePrimivites.size()));
		ellipsePrimivites.push_back(ellipsePanel);
		selectorPanel.addToggle("Ellipse " + to_string(ellipsePrimivites.size() - 1));
	}
	if (primitiveName == "Sqaure") {
	}
}

void MainController::openNewPrimitve3DPanel(string primitiveName) {
	cout << "The primitive 3D " << primitiveName << " was selected " << endl;

	if (primitiveName == "Cube") {
		CubePanel* cubePanel = new CubePanel();
		cubePanel->setup();
		cubePrimivites.push_back(cubePanel);
	}
	if (primitiveName == "Sphere") {
		SpherePanel* spherePanel = new SpherePanel();
		spherePanel->setup();
		spherePrimivites.push_back(spherePanel);
	}
}