#pragma once

#include "ofMain.h"
#include "../views/MainPanel.h"
#include "../views/PrimitivePanel.h"

class MainController
{
public:

	void setup();
	void draw();

	MainPanel mainPanel;
	PrimitivePanel primitivePanel;
};