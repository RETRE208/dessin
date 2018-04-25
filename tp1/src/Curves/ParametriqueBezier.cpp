#include "ParametriqueBezier.h"

ParametriqueBezier::ParametriqueBezier() {
	line_resolution = 100;
	line_width = 8.0f;
	radius = 12.0f;

	ctrl_point1 = { 500, 500, 0 };
	ctrl_point2 = { 550, 520, 0 };
	ctrl_point3 = { 600, 540, 0 };
	ctrl_point4 = { 600, 560, 0 };
	ctrl_point5 = { 550, 580, 0 };
	ctrl_point6 = { 500, 600, 0 };
	ctrl_point_z = 0;

	color = ofColor::green;
}

void ParametriqueBezier::draw() {
	update();
	ofSetColor(color);
	ofSetLineWidth(line_width);
	line_renderer.draw();
	if (drawCtrlPoints) {
		ofSphere(ctrl_point1.x, ctrl_point1.y, ctrl_point1.z, radius);
		ofSphere(ctrl_point2.x, ctrl_point2.y, ctrl_point2.z, radius);
		ofSphere(ctrl_point3.x, ctrl_point3.y, ctrl_point3.z, radius);
		ofSphere(ctrl_point4.x, ctrl_point4.y, ctrl_point4.z, radius);
		ofSphere(ctrl_point5.x, ctrl_point5.y, ctrl_point5.z, radius);
		ofSphere(ctrl_point6.x, ctrl_point6.y, ctrl_point6.z, radius);
	}
}

void ParametriqueBezier::update()
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
			ctrl_point5.x, ctrl_point5.y, ctrl_point5.z,
			ctrl_point6.x, ctrl_point6.y, ctrl_point6.z,
			position.x, position.y, position.z);
		line_renderer.addVertex(position);
	}
}

inline void ParametriqueBezier::evaluate(
	float t,
	float p1x, float p1y, float p1z,
	float p2x, float p2y, float p2z,
	float p3x, float p3y, float p3z,
	float p4x, float p4y, float p4z,
	float p5x, float p5y, float p5z,
	float p6x, float p6y, float p6z,
	float&  x, float& y, float&  z)
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
	z = uuuuu * p1z + 5 * uuuu * t * p2z + 10 * uuu * tt * p3z + 10 * uu * ttt * p4z + 5 * u * tttt * p5z + ttttt * p6z;
}

void ParametriqueBezier::modifyControlPoint() {
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
	else if (ctrlPointNumber == 5) {
		ctrl_point5 = ofVec3f(ctrl_point_x, ctrl_point_y, ctrl_point_z);
	}
	else if (ctrlPointNumber == 6) {
		ctrl_point6 = ofVec3f(ctrl_point_x, ctrl_point_y, ctrl_point_z);
	}
}

void ParametriqueBezier::modifyControlPointNumber(string choice) {
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
	else if (choice == "Control Point 5") {
		ctrlPointNumber = 5;
	}
	else if (choice == "Control Point 6") {
		ctrlPointNumber = 6;
	}
}

