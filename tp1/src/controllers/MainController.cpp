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
	mainPanel.setup(this);
	controlPanel.setup(this);
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
      int imageWidth = images[i]->getWidth();
      int imageHeight = images[i]->getHeight();

      images[i]->draw(
        DRAWING_ZONE_X_LIMIT,
        DRAWING_ZONE_Y_LIMIT,
        imageWidth,
        imageHeight);
		}
		for (int i = 0; i < circlePrimivites.size(); i++) {
			circlePrimivites[i] -> draw();
		}
		for (int i = 0; i < rectanglePrimivites.size(); i++) {
			rectanglePrimivites[i]->draw();
		}
		for (int i = 0; i < linePrimivites.size(); i++) {
			linePrimivites[i]->draw();
		}
		for (int i = 0; i < ellipsePrimivites.size(); i++) {
			ellipsePrimivites[i]->draw();
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
		ofImage *newImage = new ofImage;
		newImage->load(imagePath);
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

void MainController::applyTexture(int keyPressed) {
	switch (keyPressed)
	{
	case 49:  // key 1
		texture.kernel_type = ConvolutionKernel::identity;
		texture.kernel_name = "identit�";

		break;

	case 50:  // key 2
		texture.kernel_type = ConvolutionKernel::emboss;
		texture.kernel_name = "bosseler";

		break;

	case 51:  // key 3
		texture.kernel_type = ConvolutionKernel::sharpen;
		texture.kernel_name = "aiguiser";
		break;

	case 52:  // key 4
		texture.kernel_type = ConvolutionKernel::edge_detect;
		texture.kernel_name = "d�tection de bordure";
		break;

	case 53:  // key 5
		texture.kernel_type = ConvolutionKernel::blur;
		texture.kernel_name = "flou";
		break;

	default:
		break;
	}
	texture.filter(images[0]);
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
		circlePanel->setup();
		circlePrimivites.push_back(circlePanel);
	}
	if (primitiveName == "Rectangle") {
		RectanglePanel* rectanglePanel = new RectanglePanel();
		rectanglePanel->setup();
		rectanglePrimivites.push_back(rectanglePanel);
	}
	if (primitiveName == "Line") {
		LinePanel* linePanel = new LinePanel();
		linePanel->setup();
		linePrimivites.push_back(linePanel);
	}
	if (primitiveName == "Ellipse") {
		EllipsePanel* ellipsePanel = new EllipsePanel();
		ellipsePanel->setup();
		ellipsePrimivites.push_back(ellipsePanel);
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
