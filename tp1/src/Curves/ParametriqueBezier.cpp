#include "ParametriqueBezier.h"

ParametriqueBezier::ParametriqueBezier() {
	line_resolution = 50;
	line_width = 8.0f;

	ctrl_point1x = 500;
	ctrl_point1y = 500;

	ctrl_point2x = 520;
	ctrl_point2y = 550;

	ctrl_point3x = 540;
	ctrl_point3y = 600;

	ctrl_point4x = 560;
	ctrl_point4y = 600;

	ctrl_point5x = 580;
	ctrl_point5y = 550;

	ctrl_point6x = 600;
	ctrl_point6y = 500;

	color = ofColor::green;
}

void ParametriqueBezier::draw() {
	update();
	ofSetColor(color);
	ofSetLineWidth(line_width);
	line_renderer.draw();
}

void ParametriqueBezier::update()
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
			ctrl_point5x, ctrl_point5y,
			ctrl_point6x, ctrl_point6y,
			position.x, position.y, position.z);
		line_renderer.addVertex(position);
	}
}

inline void ParametriqueBezier::evaluate(
	float t,
	float p1x, float p1y,
	float p2x, float p2y,
	float p3x, float p3y,
	float p4x, float p4y,
	float p5x, float p5y,
	float p6x, float p6y,
	float&  x, float& y, float& z)
{
	float u = 1 - t;
	float uu = u * u;
	float uuu = uu * u;
	float uuuu = uuu * u;
	float uuuuu = uuuu * u;
	float tt = t * t;
	float ttt = tt * t;
	float tttt = ttt * t;
	float ttttt = tttt * t;

	x = uuuuu * p1x + 5 * uuuu * t * p2x + 10 * uuu * tt * p3x + 10 * uu * ttt * p4x + 5 * u * tttt * p5x + ttttt * p6x;
	y = uuuuu * p1y + 5 * uuuu * t * p2y + 10 * uuu * tt * p3y + 10 * uu * ttt * p4y + 5 * u * tttt * p5y + ttttt * p6y;
	z = 0;
}

