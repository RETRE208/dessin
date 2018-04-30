#include "DelaunayPanel3D.h"

void DelaunayPanel3D::setup(string name)
{
	delaunay = new DelaunayTriangle();

	gui = new ofxDatGui(ofxDatGuiAnchor::TOP_RIGHT);
	gui->setWidth(200);
	gui->addHeader(name);
	sx = gui->addSlider("POSITION X", -ofGetWidth(), ofGetWidth());
	sy = gui->addSlider("POSITION Y", -ofGetHeight(), ofGetHeight());
	sz = gui->addSlider("POSITION Z", -1000, 1000);
	picker = gui->addColorPicker("COLOR PICKER", ofColor::fromHex(0xCECECE));
	picker->onColorPickerEvent(this, &DelaunayPanel3D::onColorPickerEvent);
	addPointBtn = gui->addButton("Add point");
	fillToggle = gui->addToggle("Fill triangles");

	sx->bind(x);
	sy->bind(y);
	sz->bind(z);

	gui->onButtonEvent(this, &DelaunayPanel3D::onButtonEvent);
}

void DelaunayPanel3D::draw()
{
	delaunay->draw();
}

void DelaunayPanel3D::onButtonEvent(ofxDatGuiButtonEvent e) {
	if (e.target == addPointBtn){
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

void DelaunayPanel3D::onColorPickerEvent(ofxDatGuiColorPickerEvent e)
{
	delaunay->color = e.color;
}

