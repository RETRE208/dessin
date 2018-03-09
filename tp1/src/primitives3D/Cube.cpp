#include "Cube.h"

Cube::Cube(int cubeWidth, int cubeHeight, int cubeDepth) {
	x = 0;
	y = 0;
	z = 0;
	
	height = cubeHeight;
	width = cubeWidth;
	depth = cubeDepth;

	color = ofColor::red;
}

bool Cube::inside(ofPoint mouse)
{
	return mouse.distance(ofPoint(x, y, z)) <= width;
}

void Cube::draw() {
	ofSetColor(color);
	ofBoxPrimitive box = ofBoxPrimitive();
	box.set(width, height, depth);
	box.setPosition(x, y, z);
	box.rotate(angleX, 1.0f, 0.0f, 0.0f);
	box.rotate(angleY, 0.0f, 1.0f, 0.0f);
	box.rotate(angleZ, 0.0f, 0.0f, 1.0f);
	box.draw();
}
