#include "ModelPanel.h"
#include "../controllers/MainController.h"

void ModelPanel::setup(MainController* mainController, string modelPath)
{
	mainControllerInstance = mainController;
	model.loadModel(modelPath);

	gui = new ofxDatGui(ofxDatGuiAnchor::TOP_RIGHT);
	gui->setWidth(200);
	gui->addHeader("Model Panel");
	sx = gui->addSlider("POSITION X", -ofGetWidth(), ofGetWidth());
	sy = gui->addSlider("POSITION Y", -ofGetHeight(), ofGetHeight());
	sz = gui->addSlider("POSITION Z", -1000, 1000);
	rx = gui->addSlider("ROTATION X", 0, 360);
	ry = gui->addSlider("ROTATION Y", 0, 360);
	rz = gui->addSlider("ROTATION Z", 0, 360);
	ssize = gui->addSlider("Size", 1, 150);
	meshFillToggle = gui->addToggle("Fill");
	meshWireframeToggle = gui->addToggle("Wireframe");
	meshPointsToggle = gui->addToggle("Points");
	instanciate = gui->addButton("Instanciate New Model");

	gui->onButtonEvent(this, &ModelPanel::onButtonEvent);

	sx->bind(x);
	sy->bind(y);
	sz->bind(z);
	rx->bind(angleX);
	ry->bind(angleY);
	rz->bind(angleZ);
	ssize->bind(size);

	size = 100.0f;
	x = 0;
	y = 0;
	z = 0;
}

void ModelPanel::draw()
{
	model.setPosition(x, y, z);
	model.setScale(size/100, size/100, size/100);
	model.setRotation(0, angleX, 1.0f, 0.0f, 0.0f);
	model.setRotation(1, angleY, 0.0f, 1.0f, 0.0f);
	model.setRotation(2, angleZ, 0.0f, 0.0f, 1.0f);

	switch (mesh_render_mode)
	{
	case MeshRenderMode::fill:
		model.draw(OF_MESH_FILL);
		break;

	case MeshRenderMode::wireframe:
		model.draw(OF_MESH_WIREFRAME);
		break;

	case MeshRenderMode::points:
		model.draw(OF_MESH_POINTS);
	}
}

void ModelPanel::onButtonEvent(ofxDatGuiButtonEvent e) {
	if (e.target == meshFillToggle) {
		ofLog() << "Switching to Mesh Fill";
		mesh_render_mode = MeshRenderMode::fill;
		meshWireframeToggle->setChecked(false);
		meshPointsToggle->setChecked(false);
	}
	else if (e.target == meshWireframeToggle) {
		ofLog() << "Switching to Mesh Wireframe";
		mesh_render_mode = MeshRenderMode::wireframe;
		meshFillToggle->setChecked(false);
		meshPointsToggle->setChecked(false);
	}
	else if (e.target == meshPointsToggle) {
		ofLog() << "Switching to Mesh Vertex";
		mesh_render_mode = MeshRenderMode::points;
		meshFillToggle->setChecked(false);
		meshWireframeToggle->setChecked(false);
	}
	else if (e.target == instanciate) {
		try {
			mainControllerInstance->instanciateNewModel(model);
		}
		catch (exception& e) {
			ofLog() << e.what();
		}
	}
}