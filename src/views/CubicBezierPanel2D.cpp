#include "CubicBezierPanel2D.h"

void CubicBezierPanel2D::setup(string name)
{
	bezier = new CubicBezier();
	panelName = name;
	gui = new ofxDatGui(ofxDatGuiAnchor::TOP_RIGHT);
	gui->setWidth(300);
	gui->addHeader(name);
	ctrl_points_choice = gui->addDropdown("Control Point Number", options);
	ctrl_point_x = gui->addSlider("Control Point X", 0, ofGetWidth());
	ctrl_point_y = gui->addSlider("Control Point Y", 0, ofGetHeight());
	slineWidth = gui->addSlider("LINE WIDTH", 0.1, 8.0);
	picker = gui->addColorPicker("COLOR", ofColor::fromHex(0xCECECE));
	drawCtrlPointsToggle = gui->addToggle("Draw Control Points");

	picker->onColorPickerEvent(this, &CubicBezierPanel2D::onColorPickerEvent);
	gui->onDropdownEvent(this, &CubicBezierPanel2D::onDropdownEvent);
	gui->onButtonEvent(this, &CubicBezierPanel2D::onButtonEvent);

	ctrl_point_x->bind(bezier->ctrl_point_x);
	ctrl_point_y->bind(bezier->ctrl_point_y);
	slineWidth->bind(bezier->line_width);
}

void CubicBezierPanel2D::draw()
{
	bezier->draw();
}

void CubicBezierPanel2D::onColorPickerEvent(ofxDatGuiColorPickerEvent e)
{
	if (e.target == picker) {
		bezier->color = e.color;
	}
}

void CubicBezierPanel2D::setColor(ofColor color) {
	bezier->color = color;
}

string CubicBezierPanel2D::getPanelName() {
	return panelName;
}

void CubicBezierPanel2D::deletePanel()
{
	gui->~ofxDatGui();
}

void CubicBezierPanel2D::onDropdownEvent(ofxDatGuiDropdownEvent e)
{
	cout << "the option at index # " << e.child << " was selected " << endl;
	string choice = options.at(e.child);
	bezier->modifyControlPointNumber(choice);
}

void CubicBezierPanel2D::onButtonEvent(ofxDatGuiButtonEvent e) {
	if (e.target == drawCtrlPointsToggle) {
		if (drawCtrlPoints == true) {
			bezier->drawCtrlPoints = false;
			drawCtrlPoints = false;
		}
		else {
			bezier->drawCtrlPoints = true;
			drawCtrlPoints = true;
		}
	}
}