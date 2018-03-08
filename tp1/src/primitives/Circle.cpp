#include "Circle.h"

Circle::Circle(int radius) {
	x = 100;
	y = 100;
	mRadius = radius;
}

bool Circle::inside(ofPoint mouse)
{
	return mouse.distance(ofPoint(x, y)) <= mRadius;
}

void Circle::draw() {
	ofSetColor(ofColor::red);
	ofDrawCircle(x, y, mRadius);
}
