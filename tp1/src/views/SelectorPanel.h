#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class SelectorPanel {
public:
	void setup();
	void draw();

	void addToggle(string name);
	void removeToggle(string name);
	bool getIfSelected(string name);

	ofxPanel selectorPanel;
	ofxToggle* toggle;

	vector<ofxToggle*> toggleList;
};