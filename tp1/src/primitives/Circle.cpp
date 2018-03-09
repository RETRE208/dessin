#include "Circle.h"

Circle::Circle(int radius) {
	x = 100;
	y = 100;
	mRadius = radius;
	color = ofColor::red;
}

void Circle::draw() {
	ofSetColor(color);
	ofDrawCircle(x, y, mRadius);
}
