#include "CubicBezier.h"

CubicBezier::CubicBezier() {
	line_resolution = 50;
	line_width = 8.0f;
	radius = 12.0f;

	ctrl_point1 = { 500, 600, 0 };
	ctrl_point2 = { 500, 500, 0 };
	ctrl_point3 = { 600, 500, 0 };
	ctrl_point4 = { 600, 600, 0 };
	ctrl_point_z = 0;

	color = ofColor::green;
}

void CubicBezier::draw() {
	update();
	ofSetColor(color);
	ofSetLineWidth(line_width);
	line_renderer.draw();
	if (drawCtrlPoints) {
		ofSphere(ctrl_point1.x, ctrl_point1.y, ctrl_point1.z, radius);
		ofSphere(ctrl_point2.x, ctrl_point2.y, ctrl_point2.z, radius);
		ofSphere(ctrl_point3.x, ctrl_point3.y, ctrl_point3.z, radius);
		ofSphere(ctrl_point4.x, ctrl_point4.y, ctrl_point4.z, radius);
	}
}

void CubicBezier::update()
{
	modifyControlPoint();
	line_renderer.clear();
	for (index = 0; index < line_resolution; ++index)
	{
		evaluate(
			index / (float)line_resolution,
			ctrl_point1.x, ctrl_point1.y, ctrl_point1.z,
			ctrl_point2.x, ctrl_point2.y, ctrl_point2.z,
			ctrl_point3.x, ctrl_point3.y, ctrl_point3.z,
			ctrl_point4.x, ctrl_point4.y, ctrl_point4.z,
			position.x, position.y, position.z);
		line_renderer.addVertex(position);
	}
}

inline void CubicBezier::evaluate(
	float t,
	float p1x, float p1y, float p1z,
	float p2x, float p2y, float p2z,
	float p3x, float p3y, float p3z,
	float p4x, float p4y, float p4z,
	float&  x, float& y, float&  z)
{
	float u = 1 - t;
	float uu = u * u;
	float uuu = uu * u;
	float tt = t * t;
	float ttt = tt * t;

	x = uuu * p1x + 3 * uu * t * p2x + 3 * u * tt * p3x + ttt * p4x;
	y = uuu * p1y + 3 * uu * t * p2y + 3 * u * tt * p3y + ttt * p4y;
	z = uuu * p1z + 3 * uu * t * p2z + 3 * u * tt * p3z + ttt * p4z;
}

void CubicBezier::modifyControlPoint() {
	if (ctrlPointNumber == 1) {
		ctrl_point1 = ofVec3f(ctrl_point_x, ctrl_point_y, ctrl_point_z);
	}
	else if (ctrlPointNumber == 2) {
		ctrl_point2 = ofVec3f(ctrl_point_x, ctrl_point_y, ctrl_point_z);
	}
	else if (ctrlPointNumber == 3) {
		ctrl_point3 = ofVec3f(ctrl_point_x, ctrl_point_y, ctrl_point_z);
	}
	else if (ctrlPointNumber == 4) {
		ctrl_point4 = ofVec3f(ctrl_point_x, ctrl_point_y, ctrl_point_z);
	}
}

void CubicBezier::modifyControlPointNumber(string choice) {
	if (choice == "Control Point 1") {
		ctrlPointNumber = 1;
	}
	else if (choice == "Control Point 2") {
		ctrlPointNumber = 2;
	}
	else if (choice == "Control Point 3") {
		ctrlPointNumber = 3;
	}
	else if (choice == "Control Point 4") {
		ctrlPointNumber = 4;
	}
}
