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
	primitivePanel.setup();
	mainPanel.setup(this);
}

void MainController::draw()
{
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
	}
	mainPanel.draw();
	primitivePanel.draw();
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
		newModel.setRotation(rotationX, rotationY, rotationZ, 1.0f, 0.0f);
		models.push_back(newModel);
	}
	else {
		throw NO_MODELS;
	}
}

	