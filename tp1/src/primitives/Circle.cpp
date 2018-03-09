#include "Circle.h"

Circle::Circle(int radius) {
	x = 100;
	y = 100;
	mRadius = radius;
	primaryColor = ofColor::red;
	secondaryColor = ofColor::red;
	isFill = false;
}

void Circle::draw() {
	if (isFill)
	{
		ofFill();
		ofSetColor(primaryColor);
		ofDrawCircle(x, y, mRadius);
	}

	ofNoFill();
	ofSetColor(secondaryColor);
	ofSetLineWidth(lineWidth);
	ofDrawCircle(x, y, mRadius);
}
