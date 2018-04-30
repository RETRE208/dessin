#include "DelaunayTriangle.h"

DelaunayTriangle::DelaunayTriangle()
{
	ofEnableSmoothing();
}

void DelaunayTriangle::addPoint(float x, float y, float z) {
	ofLog() << "Add point to Delaunay (" << x << ", " << y << ", "<< z;
	triangulation.addPoint(ofPoint(x, y, z));
	triangulation.triangulate();
}

void DelaunayTriangle::draw()
{
	if (fillTriangles) {
		ofFill();
	}
	else {
		ofNoFill();
	}
	ofSetColor(color);
	triangulation.draw();
}
