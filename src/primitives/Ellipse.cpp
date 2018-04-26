#include "Ellipse.h"

using namespace tp1;
Ellipse::Ellipse() {
	x = 100;
	y = 100;
	width = 100;
	height = 100;
	primaryColor = ofColor::green;
	secondaryColor = ofColor::green;
	isFill = false;
}

void Ellipse::draw() {
	if (isFill)
	{
		ofFill();
		ofSetColor(primaryColor);
		ofDrawEllipse(x, y, width, height);
	}

	ofNoFill();
	ofSetColor(secondaryColor);
	ofSetLineWidth(lineWidth);
	ofDrawEllipse(x, y, width, height);
}
