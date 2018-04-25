#include "CubicBezier.h"
#include <iostream>

CubicBezier::CubicBezier() {
	line_resolution = 50;
	line_width = 8.0f;

	ctrl_point1x = 500;
	ctrl_point1y = 500;

	ctrl_point2x = 500;
	ctrl_point2y = 600;

	ctrl_point3x = 600;
	ctrl_point3y = 600;

	ctrl_point4x = 600;
	ctrl_point4y = 500;

	color = ofColor::green;
}

void CubicBezier::draw() {
	update();
	ofSetColor(color);
	ofSetLineWidth(line_width);
	line_renderer.draw();
}

void CubicBezier::update()
{
	line_renderer.clear();
	for (index = 0; index < line_resolution; ++index)
	{
		evaluate(
			index / (float)line_resolution,
			ctrl_point1x, ctrl_point1y,
			ctrl_point2x, ctrl_point2y,
			ctrl_point3x, ctrl_point3y,
			ctrl_point4x, ctrl_point4y,
			position.x, position.y, position.z);
		line_renderer.addVertex(position);
	}
}

inline void CubicBezier::evaluate(
	float t,
	float p1x, float p1y,
	float p2x, float p2y,
	float p3x, float p3y,
	float p4x, float p4y,
	float&  x, float& y, float& z)
{
	float u = 1 - t;
	float uu = u * u;
	float uuu = uu * u;
	float tt = t * t;
	float ttt = tt * t;

	x = uuu * p1x + 3 * uu * t * p2x + 3 * u * tt * p3x + ttt * p4x;
	y = uuu * p1y + 3 * uu * t * p2y + 3 * u * tt * p3y + ttt * p4y;
	z = 0;
}
