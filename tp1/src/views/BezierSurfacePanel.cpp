#include "BezierSurfacePanel.h"

void BezierSurfacePanel::setup(string name)
{
	bezier = new BezierSurface();
	panelName = name;
	gui = new ofxDatGui(ofxDatGuiAnchor::TOP_RIGHT);
	gui->setWidth(200);
	gui->addHeader(name);
	
	ctrl_points_choice = gui->addDropdown("Control Point Number", options);
	ctrl_point_x = gui->addSlider("Control Point X", 0, ofGetWidth());
	ctrl_point_y = gui->addSlider("Control Point Y", 0, ofGetHeight());
	ctrl_point_z = gui->addSlider("Control Point Z", 0, 1000);
	picker = gui->addColorPicker("COLOR", ofColor::fromHex(0xCECECE));

	ctrl_point_x->bind(bezier->ctrl_point_x);
	ctrl_point_y->bind(bezier->ctrl_point_y);
	ctrl_point_z->bind(bezier->ctrl_point_z);

	hideSurfaceToggle = gui->addToggle("Hide Surface");
	drawCtrlPointsTogle = gui->addToggle("Draw Control Points");
	
	picker->onColorPickerEvent(this, &BezierSurfacePanel::onColorPickerEvent);
	gui->onDropdownEvent(this, &BezierSurfacePanel::onDropdownEvent);
	gui->onButtonEvent(this, &BezierSurfacePanel::onButtonEvent);
}

void BezierSurfacePanel::onDropdownEvent(ofxDatGuiDropdownEvent e)
{
	cout << "the option at index # " << e.child << " was selected " << endl;
	string choice = options.at(e.child);
	bezier->modifyControlPointNumber(choice);
}

void BezierSurfacePanel::draw()
{
	bezier->draw();
}

void BezierSurfacePanel::onColorPickerEvent(ofxDatGuiColorPickerEvent e)
{
	if (e.target == picker) {
		bezier->color = e.color;
	}
}

void BezierSurfacePanel::setColor(ofColor color) {
	bezier->color = color;
}

string BezierSurfacePanel::getPanelName() {
	return panelName;
}

void BezierSurfacePanel::deletePanel()
{
	gui->~ofxDatGui();
}

void BezierSurfacePanel::onButtonEvent(ofxDatGuiButtonEvent e) {
	if (e.target == hideSurfaceToggle) {
		if (hideSurface == true) {
			bezier->drawSurface = false;
			hideSurface = false;
		}
		else {
			bezier->drawSurface = true;
			hideSurface = true;
		}
	}
	if (e.target == drawCtrlPointsTogle) {
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
