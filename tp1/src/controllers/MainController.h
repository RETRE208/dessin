#pragma once

#ifndef MainController_Included
#define MainController_Included

#include "ofMain.h"
#include "../views/PrimitivePanel.h"
#include "../system/files.h"
#include <vector>
#include "../texture/texture.h"
#include "../views/controllerPanel.h"
#include "../views/CirclePanel.h"
#include "../views/RectanglePanel.h"
#include "../views/LinePanel.h"
#include "../views/EllipsePanel.h"
#include "../views/SpherePanel.h"
#include "../views/CubePanel.h"
#include "../views/ModelPanel.h"
#include "ofxAssimpModelLoader.h"

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
	void applyTexture(int keyPressed);

	Files files;
	std::vector<ofImage*> images;
	void switch3DMode();
	void switch2DMode();
	void instanciateNewModel(ofxAssimpModelLoader model);
	void openNewPrimitvePanel(string primitiveName);
	void openNewPrimitve3DPanel(string primitiveName);

	ofLight light;
	float center_x;
	float center_y;

	std::vector<ModelPanel*> modelsPanels;
	std::vector<CirclePanel*> circlePrimivites;
	std::vector<RectanglePanel*> rectanglePrimivites;
	std::vector<LinePanel*> linePrimivites;
	std::vector<EllipsePanel*> ellipsePrimivites;
	std::vector<SpherePanel*> spherePrimivites;
	std::vector<CubePanel*> cubePrimivites;

	controllerPanel controlPanel;
	PrimitivePanel primitivePanel;
	Texture texture;
};

#endif