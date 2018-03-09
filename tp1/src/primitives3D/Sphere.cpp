#include "Sphere.h"

Sphere::Sphere(int radius) {
	x = 0;
	y = 0;
	z = 0;
	mRadius = radius;
	color = ofColor::red;
}

bool Sphere::inside(ofPoint mouse)
{
	return mouse.distance(ofPoint(x, y, z)) <= mRadius;
}

void Sphere::draw() {
	ofSetColor(color);
	ofSphere(x, y, z - 1000, mRadius);
}
