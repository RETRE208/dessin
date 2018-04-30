#pragma once

#include "ofxDelaunay.h"

class DelaunayTriangle
{
public:
	DelaunayTriangle();
	void draw();
	void addPoint(float x, float y, float z);

	ofxDelaunay triangulation;
	ofColor color;

	bool fillTriangles = false;
};

