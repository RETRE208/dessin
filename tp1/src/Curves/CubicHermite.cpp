#include "CubicHermite.h"

CubicHermite::CubicHermite() {
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

void CubicHermite::draw() {
	update();
	ofSetColor(color);
	ofSetLineWidth(line_width);
	line_renderer.draw();
}

void CubicHermite::update()
{
	line_renderer.clear();
	for (index = 0; index < line_resolution; ++index)
	{
		ofVec2f ctrl_point1 = { ctrl_point1x, ctrl_point1y };
		ofVec2f ctrl_point2 = { ctrl_point2x, ctrl_point2y };
		ofVec2f ctrl_point3 = { ctrl_point3x, ctrl_point3y };
		ofVec2f ctrl_point4 = { ctrl_point4x, ctrl_point4y };
		tangent1 = ctrl_point2 - ctrl_point1;
		tangent2 = ctrl_point3 - ctrl_point4;

		evaluate(
			index / (float)line_resolution,
			ctrl_point1x, ctrl_point1y,
			tangent1.x, tangent1.y,
			tangent2.x, tangent2.y,
			ctrl_point4x, ctrl_point4y,
			position.x, position.y, position.z);
		line_renderer.addVertex(position);
	}
}

inline void CubicHermite::evaluate(
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

	x = (2 * ttt - 3 * tt + 1) * p1x + (ttt - 2 * tt + t) * p2x + (ttt - tt) * p3x + (-2 * ttt + 3 * tt) * p4x;
	y = (2 * ttt - 3 * tt + 1) * p1y + (ttt - 2 * tt + t) * p2y + (ttt - tt) * p3y + (-2 * ttt + 3 * tt) * p4y;
	z = 0;
}
