#include "Square.h"

Square::Square() {
	x = 100;
	y = 100;
	height = 100;
	lineWidth = 1.0;
	primaryColor = ofColor::red;
	secondaryColor = ofColor::red;
	isFill = false;
}

void Square::draw() {
	ofRectangle myRect(x, y, height, height);

	if (isFill)
	{
		ofFill();
		ofSetColor(primaryColor);
		ofDrawRectangle(myRect);
	}

	ofNoFill();
	ofSetColor(secondaryColor);
	ofSetLineWidth(lineWidth);
	ofDrawRectangle(myRect);
}
