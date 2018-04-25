#pragma once

#include "ofMain.h"

class CubicHermite
{
public:
	CubicHermite();

	ofPolyline line_renderer;

	ofVec3f ctrl_point1;
	ofVec3f ctrl_point2;
	ofVec3f ctrl_point3;
	ofVec3f ctrl_point4;

	int ctrlPointNumber = 1;
	float ctrl_point_x;
	float ctrl_point_y;
	float ctrl_point_z;

	float radius;

	bool drawCtrlPoints = false;

	ofVec3f tangent1;
	ofVec3f tangent2;

	ofVec3f position;

	float line_width;

	int line_resolution;

	int index;

	ofColor color;

	void evaluate(
		float t,
		float p1x, float p1y, float p1z,
		float p2x, float p2y, float p2z,
		float p3x, float p3y, float p3z,
		float p4x, float p4y, float p4z,
		float&  x, float& y, float&  z);

	void update();
	void draw();

	void modifyControlPointNumber(string ctrlPoint);
	void modifyControlPoint();
};

