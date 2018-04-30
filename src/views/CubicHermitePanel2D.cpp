#include "CubicHermitePanel2D.h"

void CubicHermitePanel2D::setup(string name)
{
	hermite = new CubicHermite();
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

	picker->onColorPickerEvent(this, &CubicHermitePanel2D::onColorPickerEvent);
	gui->onDropdownEvent(this, &CubicHermitePanel2D::onDropdownEvent);
	gui->onButtonEvent(this, &CubicHermitePanel2D::onButtonEvent);

	ctrl_point_x->bind(hermite->ctrl_point_x);
	ctrl_point_y->bind(hermite->ctrl_point_y);
	slineWidth->bind(hermite->line_width);
}

void CubicHermitePanel2D::draw()
{
	hermite->draw();
}

void CubicHermitePanel2D::onColorPickerEvent(ofxDatGuiColorPickerEvent e)
{
	if (e.target == picker) {
		hermite->color = e.color;
	}
}

void CubicHermitePanel2D::setColor(ofColor color) {
	hermite->color = color;
}

string CubicHermitePanel2D::getPanelName() {
	return panelName;
}

void CubicHermitePanel2D::deletePanel()
{
	gui->~ofxDatGui();
}

void CubicHermitePanel2D::onDropdownEvent(ofxDatGuiDropdownEvent e)
{
	cout << "the option at index # " << e.child << " was selected " << endl;
	string choice = options.at(e.child);
	hermite->modifyControlPointNumber(choice);
}

void CubicHermitePanel2D::onButtonEvent(ofxDatGuiButtonEvent e) {
	if (e.target == drawCtrlPointsToggle) {
		if (drawCtrlPoints == true) {
			hermite->drawCtrlPoints = false;
			drawCtrlPoints = false;
		}
		else {
			hermite->drawCtrlPoints = true;
			drawCtrlPoints = true;
		}
	}
}
