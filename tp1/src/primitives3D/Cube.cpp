#include "Cube.h"

void Cube::setup() {
	cubeParameters.setName("Cube controls");

	cubeParameters.add(red.set("Red", 255, 0, 255));
	cubeParameters.add(green.set("Green", 255, 0, 255));
	cubeParameters.add(blue.set("Blue", 255, 0, 255));

	cubeParameters.add(posX.set("posX", 500, 0, 1000));
	cubeParameters.add(posY.set("posY", 600, 0, 800));
	cubeParameters.add(posZ.set("posZ", 0, 0, 1000));

	cubeParameters.add(height.set("Height", 10, 0, 200));
	cubeParameters.add(width.set("Width", 10, 0, 200));
	cubeParameters.add(depth.set("Depth", 10, 0, 200));

	cubeParameters.add(rotateX.set("Rotate X", 0, 0, 360));
	cubeParameters.add(rotateY.set("Rotate Y", 0, 0, 360));
	cubeParameters.add(rotateZ.set("Rotate Z", 0, 0, 360));
}

void Cube::draw() {
	ofSetColor(red, green, blue);
	ofBoxPrimitive box = ofBoxPrimitive();
	box.set(width, height, depth);
	box.setPosition(posX, posY, posZ);
	box.rotate(rotateX, 1.0f, 0.0f, 0.0f);
	box.rotate(rotateY, 0.0f, 1.0f, 0.0f);
	box.rotate(rotateZ, 0.0f, 0.0f, 1.0f);
	box.draw();
}
