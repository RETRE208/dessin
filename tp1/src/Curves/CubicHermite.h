#pragma once

#include "ofMain.h"

class CubicHermite
{
public:
	CubicHermite();

	ofPolyline line_renderer;

	float ctrl_point1x;
	float ctrl_point2x;
	float ctrl_point3x;
	float ctrl_point4x;

	float ctrl_point1y;
	float ctrl_point2y;
	float ctrl_point3y;
	float ctrl_point4y;

	ofVec2f tangent1;
	ofVec2f tangent2;

	ofVec3f position;

	float line_width;

	int line_resolution;

	int index;

	ofColor color;

	void evaluate(float t,
		float p1x, float p1y,
		float p2x, float p2y,
		float p3x, float p3y,
		float p4x, float p4y,
		float&  x, float& y, float& z);

	void update();
	void draw();
};

