#pragma once

#include "ofxBezierSurface.h"

class BezierSurface
{
public:
	BezierSurface();
	
	ofXml xml;

	int width;
	int height;

	ofxBezierSurface surface;

	ofColor color;

	bool drawCtrlPoints;
	bool drawSurface;

	int ctrlPointNumber = 1;
	float ctrl_point_x;
	float ctrl_point_y;
	float ctrl_point_z;

	void loadPoints();
	void draw();
	void modifyControlPointNumber(string ctrlPoint);
	void modifyControlPoint();
};

