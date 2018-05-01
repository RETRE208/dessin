﻿#include "MainController.h"
#include "RayTracingRenderWindow.cpp"
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
	ofSetVerticalSync(true);
	filterInstance.setup();
	blurFilter = filterInstance.getBlurFilter();
	AAFilter = filterInstance.getAAFilter();
	bloomFilter = filterInstance.getBloomFilter();
	contrastFilter = filterInstance.getContrastFilter();
}

void MainController::update()
{
	controlPanel.update();
}

void MainController::draw()
{

	selectorPanel.draw();
	if (mode3DState) {
		if (blurIsActive) {
			blurFilter->begin();
		}
		if (AntiAliasingIsActive) {
			AAFilter->begin();
		}
		if (bloomIsActive) {
			bloomFilter->begin();
		}
		if (contrastIsActive) {
			contrastFilter->begin();
		}
		cameraPanel.begin();
		cameraPanel.draw();
		ofEnableDepthTest();
		for (auto i : ambiantLightPanels)
			i->draw();
		for (auto i : directionalLightPanels)
			i->draw();
		for (auto i : pointLightPanels)
			i->draw();
		for (auto i : spotLightPanels)
			i->draw();
		for (int i = 0; i < modelsPanels.size(); i++) {
			modelsPanels[i]->draw();
		}
		for (int i = 0; i < spherePrimivites.size(); i++) {
			spherePrimivites[i]->draw();
		}
		for (int i = 0; i < cubePrimivites.size(); i++) {
			cubePrimivites[i]->draw();
		}
		for (int i = 0; i < surfaceBezierPrimitives.size(); i++) {
			surfaceBezierPrimitives[i]->draw();
		}
		for (int i = 0; i < cubicBezier3DPrimitives.size(); i++) {
			cubicBezier3DPrimitives[i]->draw();
		}
		for (int i = 0; i < cubicHermite3DPrimitives.size(); i++) {
			cubicHermite3DPrimitives[i]->draw();
		}
		for (int i = 0; i < parametriqueBezier3DPrimitives.size(); i++) {
			parametriqueBezier3DPrimitives[i]->draw();
		}
		cameraPanel.end();
		ofDisableDepthTest();
		if (contrastIsActive) {
			contrastFilter->end();
		}
		if (bloomIsActive) {
			bloomFilter->end();
		}
		if (AntiAliasingIsActive) {
			AAFilter->end();
		}
		if (blurIsActive) {
			blurFilter->end();
		}
	}
	else {
		if (blurIsActive) {
			blurFilter->begin();
		}
		if (AntiAliasingIsActive) {
			AAFilter->begin();
		}
		if (bloomIsActive) {
			bloomFilter->begin();
		}
		if (contrastIsActive) {
			contrastFilter->begin();
		}
		for (int i = 0; i < imagesPanels.size(); i++) {
			imagesPanels[i]->draw();
		}
		for (int i = 0; i < primitives2DPanels.size(); i++) {
			if (selectorPanel.getIfSelected(primitives2DPanels[i]->getPanelName())) {
				ofLog() << "toggle" << primitives2DPanels[i]->getPanelName();
				ofColor color;
				color.r = selectorPanel.redSlider;
				color.g = selectorPanel.greenSlider;
				color.b = selectorPanel.blueSlider;
				primitives2DPanels[i]->setColor(color);
			}
			primitives2DPanels[i] -> draw();
		}
		if (contrastIsActive) {
			contrastFilter->end();
		}
		if (bloomIsActive) {
			bloomFilter->end();
		}
		if (AntiAliasingIsActive) {
			AAFilter->end();
		}
		if (blurIsActive) {
			blurFilter->end();
		}
		ofSetColor(255,255,255);
	}
}

void MainController::removeSelectedPrimitives() {
	for (int i = 0; i < primitives2DPanels.size(); i++) {
		if (selectorPanel.getIfSelected(primitives2DPanels[i]->getPanelName())) {
			selectorPanel.removeToggle(primitives2DPanels[i]->getPanelName());
			primitives2DPanels[i]->deletePanel();
			primitives2DPanels.erase(primitives2DPanels.begin() + i);
		}
		ofSetColor(255, 255, 255);
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
			ImagePanel* imagePanel = new ImagePanel();
			imagePanel->setup(imagePath, this);
			imagesPanels.push_back(imagePanel);
			ofLog() << "<import image: " << imagePath << ">";
		}
		else if (imagePath.back() == 'j' || imagePath.back() == 'e') {
			ModelPanel* model = new ModelPanel();
			model->setup(this, imagePath);
			modelsPanels.push_back(model);
			ofLog() << "<import model: " << imagePath << ">";
		}
	}
	catch (exception& e) {
		ofLog() << e.what();
	}
}

void MainController::applyTexture(int typeTexture, ofImage* image) {
	switch (typeTexture)
	{
	case 1:
		texture.kernel_type = ConvolutionKernel::identity;
		texture.kernel_name = "identité";
		break;

	case 2:
		texture.kernel_type = ConvolutionKernel::emboss;
		texture.kernel_name = "bosseler";
		break;

	case 3:
		texture.kernel_type = ConvolutionKernel::sharpen;
		texture.kernel_name = "aiguiser";
		break;

	case 4:
		texture.kernel_type = ConvolutionKernel::edge_detect;
		texture.kernel_name = "détection de bordure";
		break;

	case 5:
		texture.kernel_type = ConvolutionKernel::blur;
		texture.kernel_name = "flou";
		break;

	default:
		break;
	}
	texture.filter(image);
}
	
void MainController::switch2DMode() {
	mode3DState = false;
	modeRayTracingState = false;
	ofDisableLighting();
}

void MainController::switch3DMode() {
	mode3DState = true;
	modeRayTracingState = false;
	cameraPanel.setup();
}

void MainController::switchRayTracingMode() {
	ofAppGlutWindow window;
	ofSetupOpenGL(&window, 800, 600, OF_WINDOW);
	ofRunApp(new RayTracingRenderWindow(spherePrimivites));
}

void MainController::instanciateNewModel(ofxAssimpModelLoader model) {
	ModelPanel* panel = new ModelPanel();
	panel->setup(this, "Instanciate");
	panel->model = model;
	center_x = DRAWING_ZONE_WIDTH / 2.0f + DRAWING_ZONE_X_LIMIT;
	center_y = DRAWING_ZONE_HEIGHT / 2.0f + DRAWING_ZONE_Y_LIMIT;
	panel->x = center_x + (rand() % DRAWING_ZONE_WIDTH) - (DRAWING_ZONE_WIDTH / 2.0f);
	panel->y = center_y + (rand() % DRAWING_ZONE_HEIGHT) - (DRAWING_ZONE_HEIGHT / 2.0f);
	panel->z = 0;
	float scale = ofRandom(1.0f, 150.00f);
	panel->size = scale;
	float rotationX = ofRandom(0.0f, 360.0f);
	float rotationY = ofRandom(0.0f, 360.0f);
	float rotationZ = ofRandom(0.0f, 360.0f);
	panel->angleX = rotationX;
	panel->angleY = rotationY;
	panel->angleZ = rotationZ;
	modelsPanels.push_back(panel);
}

void MainController::openNewPrimitvePanel(string primitiveName) {
	cout << "The primitive " << primitiveName << " was selected " << endl;

	if (primitiveName == "Circle") {
		CirclePanel* circlePanel = new CirclePanel();
		circlePanel->setup("Circle " + to_string(primitives2DPanels.size()));
		primitives2DPanels.push_back(circlePanel);
		selectorPanel.addToggle("Circle " + to_string(primitives2DPanels.size() - 1));
	}
	if (primitiveName == "Rectangle") {
		RectanglePanel* rectanglePanel = new RectanglePanel();
		rectanglePanel->setup("Rectangle " + to_string(primitives2DPanels.size()));
		primitives2DPanels.push_back(rectanglePanel);
		selectorPanel.addToggle("Rectangle " + to_string(primitives2DPanels.size() - 1));
	}
	if (primitiveName == "Line") {
		LinePanel* linePanel = new LinePanel();
		linePanel->setup("Line " + to_string(primitives2DPanels.size()));
		primitives2DPanels.push_back(linePanel);
		selectorPanel.addToggle("Line " + to_string(primitives2DPanels.size() - 1));
	}
	if (primitiveName == "Ellipse") {
		EllipsePanel* ellipsePanel = new EllipsePanel();
		ellipsePanel->setup("Ellipse " + to_string(primitives2DPanels.size()));
		primitives2DPanels.push_back(ellipsePanel);
		selectorPanel.addToggle("Ellipse " + to_string(primitives2DPanels.size() - 1));
	}
	if (primitiveName == "Square") {
		SquarePanel* squarePanel = new SquarePanel();
		squarePanel->setup("Square " + to_string(primitives2DPanels.size()));
		primitives2DPanels.push_back(squarePanel);
		selectorPanel.addToggle("Square " + to_string(primitives2DPanels.size() - 1));
	}
	if (primitiveName == "Cubic Bezier Curve") {
		CubicBezierPanel2D* cubicBezierPanel = new CubicBezierPanel2D();
		cubicBezierPanel->setup("Cubic Bezier Curve " + to_string(primitives2DPanels.size()));
		primitives2DPanels.push_back(cubicBezierPanel);
		selectorPanel.addToggle("Cubic Bezier Curve " + to_string(primitives2DPanels.size() - 1));
	}
	if (primitiveName == "Cubic Hermite Curve") {
		CubicHermitePanel2D* cubicHermitePanel = new CubicHermitePanel2D();
		cubicHermitePanel->setup("Cubic Hermite Curve " + to_string(primitives2DPanels.size()));
		primitives2DPanels.push_back(cubicHermitePanel);
		selectorPanel.addToggle("Cubic Hermite Curve " + to_string(primitives2DPanels.size() - 1));
	}
	if (primitiveName == "6 Points Bezier Curve") {
		ParametriqueBezierPanel2D* parametriqueBezierPanel = new ParametriqueBezierPanel2D();
		parametriqueBezierPanel->setup("6 Points Bezier Curve " + to_string(primitives2DPanels.size()));
		primitives2DPanels.push_back(parametriqueBezierPanel);
		selectorPanel.addToggle("6 Points Bezier Curve " + to_string(primitives2DPanels.size() - 1));
	}
	if (primitiveName == "Surface Bezier") {
		BezierSurfacePanel2D* bezierSurfacePanel = new BezierSurfacePanel2D();
		bezierSurfacePanel->setup("Surface Bezier " + to_string(primitives2DPanels.size()));
		primitives2DPanels.push_back(bezierSurfacePanel);
		selectorPanel.addToggle("Surface Bezier " + to_string(primitives2DPanels.size() - 1));
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
	if (primitiveName == "Surface Bezier") {
		BezierSurfacePanel3D* bezierSurfacePanel = new BezierSurfacePanel3D();
		bezierSurfacePanel->setup("Surface Bezier " + to_string(surfaceBezierPrimitives.size()));
		surfaceBezierPrimitives.push_back(bezierSurfacePanel);
	}
	if (primitiveName == "Cubic Bezier Curve") {
		CubicBezierPanel3D* cubicBezierPanel = new CubicBezierPanel3D();
		cubicBezierPanel->setup("Cubic Bezier Curve " + to_string(cubicBezier3DPrimitives.size()));
		cubicBezier3DPrimitives.push_back(cubicBezierPanel);
	}
	if (primitiveName == "Cubic Hermite Curve") {
		CubicHermitePanel3D* cubicHermitePanel = new CubicHermitePanel3D();
		cubicHermitePanel->setup("Cubic Hermite Curve " + to_string(cubicHermite3DPrimitives.size()));
		cubicHermite3DPrimitives.push_back(cubicHermitePanel);
	}
	if (primitiveName == "6 Points Bezier Curve") {
		ParametriqueBezierPanel3D* parametriqueBezierPanel = new ParametriqueBezierPanel3D();
		parametriqueBezierPanel->setup("6 Points Bezier Curve " + to_string(parametriqueBezier3DPrimitives.size()));
		parametriqueBezier3DPrimitives.push_back(parametriqueBezierPanel);
	}
}

void MainController::openNewLightPanel(string primitiveName) {
	cout << "The light " << primitiveName << " was selected " << endl;

	if (primitiveName == "Ambiant") {
		AmbiantLightPanel* ambiantLightPanel = new AmbiantLightPanel();
		ambiantLightPanel->setup(this);
		ambiantLightPanels.push_back(ambiantLightPanel);
	}
	if (primitiveName == "Directional") {
		DirectionalLightPanel* directionalLightPanel = new DirectionalLightPanel();
		directionalLightPanel->setup(this);
		directionalLightPanels.push_back(directionalLightPanel);
	}
	if (primitiveName == "Point") {
		PointLightPanel* pointLightPanel = new PointLightPanel();
		pointLightPanel->setup(this);
		pointLightPanels.push_back(pointLightPanel);
	}
	if (primitiveName == "Spot") {
		SpotLightPanel* spotLightPanel = new SpotLightPanel();
		spotLightPanel->setup(this);
		spotLightPanels.push_back(spotLightPanel);
	}
}

void MainController::changeImageOpacity(ofImage* image, int alpha) {
	texture.changeOpacity(image, alpha);
}

void MainController::inversionImageColor(ofImage* image) {
	texture.inversionFilter(image);
}

void MainController::proceduralGridTexture(ofImage* image) {
	texture.proceduralTexture(image);
}
