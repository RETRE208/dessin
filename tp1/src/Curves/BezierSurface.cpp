#include "BezierSurface.h"

BezierSurface::BezierSurface()
{
	width = 1024;
	height = 768;

	ctrl_point_z = 0;

	surface.setup(width, height, 4, 20);
	color = ofColor::red;

	drawSurface = true;
	drawCtrlPoints = false;

	loadPoints();
	surface.update();
}

void BezierSurface::loadPoints()
{
	string str;
	vector<ofVec3f> vec;
	int i = 300;
	for (int i = 300; i <= 600; i+=100) {
		for (int j = 200; j <= 500; j += 100) {
			int x = i;
			int y = j;
			int z = 0;
			vec.push_back(ofVec3f(x, y, z));
		}
	}
	surface.setControlPnts(vec);
}

void BezierSurface::draw()
{
	modifyControlPoint();
	ofSetColor(color);
	if (drawSurface) {
		surface.draw();
	}
	if (drawCtrlPoints) {
		surface.drawControls();
	}
}

void BezierSurface::modifyControlPoint() {
	vector<ofVec3f> vec = surface.getControlPnts();
	ofVec3f newPosition = ofVec3f(ctrl_point_x, ctrl_point_y, ctrl_point_z);
	vec[ctrlPointNumber] = newPosition;
	surface.setControlPnts(vec);
}

void BezierSurface::modifyControlPointNumber(string choice) {
	if (choice == "Control Point (1,1)") {
		ctrlPointNumber = 3;
	}
	else if (choice == "Control Point (1,2)") {
		ctrlPointNumber = 7;
	}
	else if (choice == "Control Point (1,3)") {
		ctrlPointNumber = 11;
	}
	else if (choice == "Control Point (1,4)") {
		ctrlPointNumber = 15;
	}
	else if (choice == "Control Point (2,1)") {
		ctrlPointNumber = 2;
	}
	else if (choice == "Control Point (2,2)") {
		ctrlPointNumber = 6;
	}
	else if (choice == "Control Point (2,3)") {
		ctrlPointNumber = 10;
	}
	else if (choice == "Control Point (2,4)") {
		ctrlPointNumber = 14;
	}
	else if (choice == "Control Point (3,1)") {
		ctrlPointNumber = 1;
	}
	else if (choice == "Control Point (3,2)") {
		ctrlPointNumber = 5;
	}
	else if (choice == "Control Point (3,3)") {
		ctrlPointNumber = 9;
	}
	else if (choice == "Control Point (3,4)") {
		ctrlPointNumber = 13;
	}
	else if (choice == "Control Point (4,1)") {
		ctrlPointNumber = 0;
	}
	else if (choice == "Control Point (4,2)") {
		ctrlPointNumber = 4;
	}
	else if (choice == "Control Point (4,3)") {
		ctrlPointNumber = 8;
	}
	else if (choice == "Control Point (4,4)") {
		ctrlPointNumber = 12;
	}
}
