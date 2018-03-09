#include "Sphere.h"

Sphere::Sphere(int radius) {
	x = 0;
	y = 0;
	z = 0;
	mRadius = radius;
	color = ofColor::red;
}

void Sphere::draw() {
	ofSetColor(color);
	ofSphere(x, y, z - 1000, mRadius);
}
