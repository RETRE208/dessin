#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class SelectorPanel {
public:
	void setup();
	void draw();
	void update();

	ofxPanel selectorPanel;
};