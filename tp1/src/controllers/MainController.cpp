#include "MainController.h"

void MainController::setup()
{
	primitivePanel.setup();
	mainPanel.setup(this);
}

void MainController::draw()
{
	mainPanel.draw();
	primitivePanel.draw();

	if (mode3DState) {
		for (int i = 0; i < models.size(); i++) {
			center_x = DRAWING_ZONE_WIDTH / 2.0f + DRAWING_ZONE_X_LIMIT;
			center_y = DRAWING_ZONE_HEIGHT / 2.0f + DRAWING_ZONE_Y_LIMIT;
			models[i].setPosition(
				center_x,
				center_y,
				-150);
			switch (mesh_render_mode)
			{
			case MeshRenderMode::fill:
				models[i].draw(OF_MESH_FILL);
				break;

			case MeshRenderMode::wireframe:
				models[i].draw(OF_MESH_WIREFRAME);
				break;

			case MeshRenderMode::vertex:
				models[i].draw(OF_MESH_POINTS);
			}
		}
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
		else if (imagePath.back() == 'j') {
			ofxAssimpModelLoader newModel;
			newModel.loadModel(imagePath);
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
	ofDisableDepthTest();
}

void MainController::switch3DMode() {
	mode3DState = true;
	ofEnableLighting();
	ofEnableDepthTest();

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

void MainController::switchMeshVertex() {
	mesh_render_mode = MeshRenderMode::vertex;
}

	