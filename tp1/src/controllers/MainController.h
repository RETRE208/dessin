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
#include "../views/ImagePanel.h"
#include "../views/ModelPanel.h"
#include "ofxAssimpModelLoader.h"
#include "../views/SelectorPanel.h"
#include "../views/SquarePanel.h"

class MainController
{
public:
	bool mode3DState = false;

	int DRAWING_ZONE_X_LIMIT = 200;
	int DRAWING_ZONE_Y_LIMIT = 0;
	int DRAWING_ZONE_WIDTH = 964;
	int DRAWING_ZONE_HEIGHT = 700;

	void setup();
	void draw();

	void exportImage();
	void importImage();
	void applyTexture(int typeTexture, ofImage* image);

	Files files;
	void switch3DMode();
	void switch2DMode();
	void instanciateNewModel(ofxAssimpModelLoader model);
	void openNewPrimitvePanel(string primitiveName);
	void openNewPrimitve3DPanel(string primitiveName);
	void changeImageOpacity(ofImage* image, int alpha);
	void removeSelectedPrimitives();
	void inversionImageColor(ofImage* image);
	void proceduralGridTexture(ofImage* image);

	ofLight light;
	float center_x;
	float center_y;

	std::vector<ModelPanel*> modelsPanels;
	std::vector<SpherePanel*> spherePrimivites;
	std::vector<CubePanel*> cubePrimivites;
	std::vector<ImagePanel*> imagesPanels;
	std::vector<PrimitivePanel*> primitives2DPanels;

	SelectorPanel selectorPanel;
	controllerPanel controlPanel;
	PrimitivePanel primitivePanel;
	Texture texture;
};

#endif