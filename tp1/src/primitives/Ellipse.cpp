#include "Ellipse.h"

using namespace tp1;
Ellipse::Ellipse() {
	x = 100;
	y = 100;
	width = 100;
	height = 100;
	color = ofColor::green;
}

void Ellipse::draw() {
	ofSetColor(color);
	ofDrawEllipse(x, y, width, height);
}
