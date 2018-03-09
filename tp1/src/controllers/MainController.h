#pragma once

#ifndef MainController_Included
#define MainController_Included

#include "ofMain.h"
#include "../views/PrimitivePanel.h"
#include "../system/files.h"
#include <vector>
#include "../views/MainPanel.h"
#include "../texture/texture.h"
#include "../views/controllerPanel.h"
#include "../views/CirclePanel.h"
#include "../views/RectanglePanel.h"
#include "../views/LinePanel.h"
#include "../views/EllipsePanel.h"
#include "../views/SpherePanel.h"
#include "../views/CubePanel.h"
#include "../views/ImagePanel.h"
#include "ofxAssimpModelLoader.h"

enum class MeshRenderMode { fill, wireframe, points};

class MainController
{
public:
	bool mode3DState = false;

	int DRAWING_ZONE_X_LIMIT = 200;
	int DRAWING_ZONE_Y_LIMIT = 200;
	int DRAWING_ZONE_WIDTH = 964;
	int DRAWING_ZONE_HEIGHT = 539;

	void setup();
	void draw();

	void exportImage();
	void importImage();
	void applyTexture(int typeTexture, ofImage* image);

	Files files;
	void switch3DMode();
	void switch2DMode();
	void instanciateNewModel();
	void openNewPrimitvePanel(string primitiveName);
	void openNewPrimitve3DPanel(string primitiveName);

	ofLight light;
	float center_x;
	float center_y;
	void switchMeshFill();
	void switchMeshWireframe();
	void switchMeshPoints();
	MeshRenderMode mesh_render_mode;

	std::vector<ofxAssimpModelLoader> models;
	std::vector<CirclePanel*> circlePrimivites;
	std::vector<RectanglePanel*> rectanglePrimivites;
	std::vector<LinePanel*> linePrimivites;
	std::vector<EllipsePanel*> ellipsePrimivites;
	std::vector<SpherePanel*> spherePrimivites;
	std::vector<CubePanel*> cubePrimivites;
	std::vector<ImagePanel*> imagesPanels;

	MainPanel mainPanel;
	controllerPanel controlPanel;
	PrimitivePanel primitivePanel;
	Texture texture;
};

#endif