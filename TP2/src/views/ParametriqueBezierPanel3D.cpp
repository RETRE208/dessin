#include "ParametriqueBezierPanel3D.h"

void ParametriqueBezierPanel3D::setup(string name)
{
	bezier = new ParametriqueBezier("3D");
	panelName = name;
	gui = new ofxDatGui(ofxDatGuiAnchor::TOP_RIGHT);
	gui->setWidth(300);
	gui->addHeader(name);
	ctrl_points_choice = gui->addDropdown("Control Point Number", options);
	ctrl_point_x = gui->addSlider("Control Point X", -ofGetWidth(), ofGetWidth());
	ctrl_point_y = gui->addSlider("Control Point Y", -ofGetHeight(), ofGetHeight());
	ctrl_point_z = gui->addSlider("Control Point Z", -1000, 1000);
	slineWidth = gui->addSlider("LINE WIDTH", 0.1, 8.0);
	picker = gui->addColorPicker("COLOR", ofColor::fromHex(0xCECECE));
	drawCtrlPointsToggle = gui->addToggle("Draw Control Points");

	picker->onColorPickerEvent(this, &ParametriqueBezierPanel3D::onColorPickerEvent);
	gui->onDropdownEvent(this, &ParametriqueBezierPanel3D::onDropdownEvent);
	gui->onButtonEvent(this, &ParametriqueBezierPanel3D::onButtonEvent);

	ctrl_point_x->bind(bezier->ctrl_point_x);
	ctrl_point_y->bind(bezier->ctrl_point_y);
	ctrl_point_z->bind(bezier->ctrl_point_z);
	slineWidth->bind(bezier->line_width);
}

void ParametriqueBezierPanel3D::draw()
{
	bezier->draw();
}

void ParametriqueBezierPanel3D::onColorPickerEvent(ofxDatGuiColorPickerEvent e)
{
	if (e.target == picker) {
		bezier->color = e.color;
	}
}

void ParametriqueBezierPanel3D::setColor(ofColor color) {
	bezier->color = color;
}

string ParametriqueBezierPanel3D::getPanelName() {
	return panelName;
}

void ParametriqueBezierPanel3D::deletePanel()
{
	gui->~ofxDatGui();
}

void ParametriqueBezierPanel3D::onDropdownEvent(ofxDatGuiDropdownEvent e)
{
	cout << "the option at index # " << e.child << " was selected " << endl;
	string choice = options.at(e.child);
	bezier->modifyControlPointNumber(choice);
}

void ParametriqueBezierPanel3D::onButtonEvent(ofxDatGuiButtonEvent e) {
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
