#pragma once

#ifndef MainController_Included
#define MainController_Included

#include "ofMain.h"
#include "../views/PrimitivePanel.h"
#include "../system/files.h"
#include <vector>
#include "../views/MainPanel.h"

class MainController
{
public:

	int DRAWING_ZONE_X_LIMIT = 50;
	int DRAWING_ZONE_Y_LIMIT = 200;
	int DRAWING_ZONE_WIDTH = 964;
	int DRAWING_ZONE_HEIGHT = 539;

	void setup();
	void draw();

	void exportImage();
	void importImage();

	Files files;
	std::vector<ofImage> images;

	MainPanel mainPanel;
	PrimitivePanel primitivePanel;
};

#endif