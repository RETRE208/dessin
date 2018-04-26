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
	ofBoxPrimitive box = ofBoxPrimitive();
	ofSpherePrimitive sphere = ofSpherePrimitive();
	sphere.set(mRadius, 50);
	sphere.setPosition(x, y, z);
	sphere.rotate(angleX, 1.0f, 0.0f, 0.0f);
	sphere.rotate(angleY, 0.0f, 1.0f, 0.0f);
	sphere.rotate(angleZ, 0.0f, 0.0f, 1.0f);
	sphere.draw();
}
