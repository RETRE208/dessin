#include "DelaunayPanel2D.h"

void DelaunayPanel2D::setup(string name)
{
	delaunay = new DelaunayTriangle();

	gui = new ofxDatGui(ofxDatGuiAnchor::TOP_RIGHT);
	gui->setWidth(200);
	gui->addHeader(name);
	sx = gui->addSlider("POSITION X", -ofGetWidth(), ofGetWidth());
	sy = gui->addSlider("POSITION Y", -ofGetHeight(), ofGetHeight());
	picker = gui->addColorPicker("COLOR PICKER", ofColor::fromHex(0xCECECE));
	picker->onColorPickerEvent(this, &DelaunayPanel2D::onColorPickerEvent);
	addPointBtn = gui->addButton("Add point");
	fillToggle = gui->addToggle("Fill triangles");

	sx->bind(x);
	sy->bind(y);

	gui->onButtonEvent(this, &DelaunayPanel2D::onButtonEvent);
}

void DelaunayPanel2D::draw()
{
	delaunay->draw();
}

void DelaunayPanel2D::onButtonEvent(ofxDatGuiButtonEvent e) {
	if (e.target == addPointBtn) {
		delaunay->addPoint(x, y, z);
	}
	if (e.target == fillToggle) {
		if (fill == true) {
			delaunay->fillTriangles = false;
			fill = false;
		}
		else {
			delaunay->fillTriangles = true;
			fill = true;
		}
	}
}

void DelaunayPanel2D::onColorPickerEvent(ofxDatGuiColorPickerEvent e)
{
	delaunay->color = e.color;
}


