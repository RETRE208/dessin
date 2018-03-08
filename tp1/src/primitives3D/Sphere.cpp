#include "Sphere.h"

void Sphere::setup() {
	sphereParameters.setName("Sphere controls");

	sphereParameters.add(red.set("Red", 255, 0, 255));
	sphereParameters.add(green.set("Green", 255, 0, 255));
	sphereParameters.add(blue.set("Blue", 255, 0, 255));

	sphereParameters.add(posX.set("posX", 500, 0, 1000));
	sphereParameters.add(posY.set("posY", 600, 0, 800));
	sphereParameters.add(posZ.set("posZ", 0, 0, 1000));

	sphereParameters.add(radius.set("Radius", 90, 0, 1000));
}

void Sphere::draw() {
	ofSetColor(red, green, blue);
	ofSphere(posX, posY, posZ - 1000, radius);
}
