#include "Rectangle.h"
using namespace tp1;

Rectangle::Rectangle() {
	x = 100;
	y = 100;
	height = 100;
	width = 100;
	lineWidth = 1.0;
	primaryColor = ofColor::red;
	secondaryColor = ofColor::red;
	isFill = false;
}

void Rectangle::draw() {
	ofRectangle myRect(x, y, width, height);

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
