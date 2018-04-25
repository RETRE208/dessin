#include "CubicHermitePanel.h"

void CubicHermitePanel::setup(string name)
{
	hermite = new CubicHermite();
	panelName = name;
	gui = new ofxDatGui(ofxDatGuiAnchor::TOP_RIGHT);
	gui->setWidth(300);
	gui->addHeader(name);
	ctrl_point1x = gui->addSlider("Control Point 1 X", 0, ofGetWidth());
	ctrl_point1y = gui->addSlider("Control Point 1 Y", 0, ofGetHeight());
	ctrl_point2x = gui->addSlider("Control Point 2 X", 0, ofGetWidth());
	ctrl_point2y = gui->addSlider("Control Point 2 Y", 0, ofGetHeight());
	ctrl_point3x = gui->addSlider("Control Point 3 X", 0, ofGetWidth());
	ctrl_point3y = gui->addSlider("Control Point 3 Y", 0, ofGetHeight());
	ctrl_point4x = gui->addSlider("Control Point 4 X", 0, ofGetWidth());
	ctrl_point4y = gui->addSlider("Control Point 4 Y", 0, ofGetHeight());
	slineWidth = gui->addSlider("LINE WIDTH", 0.1, 8.0);
	picker = gui->addColorPicker("COLOR", ofColor::fromHex(0xCECECE));
	picker->onColorPickerEvent(this, &CubicHermitePanel::onColorPickerEvent);

	ctrl_point1x->bind(hermite->ctrl_point1x);
	ctrl_point1y->bind(hermite->ctrl_point1y);
	ctrl_point2x->bind(hermite->ctrl_point2x);
	ctrl_point2y->bind(hermite->ctrl_point2y);
	ctrl_point3x->bind(hermite->ctrl_point3x);
	ctrl_point3y->bind(hermite->ctrl_point3y);
	ctrl_point4x->bind(hermite->ctrl_point4x);
	ctrl_point4y->bind(hermite->ctrl_point4y);
	slineWidth->bind(hermite->line_width);
}

void CubicHermitePanel::draw()
{
	hermite->draw();
}

void CubicHermitePanel::onColorPickerEvent(ofxDatGuiColorPickerEvent e)
{
	if (e.target == picker) {
		hermite->color = e.color;
	}
}

void CubicHermitePanel::setColor(ofColor color) {
	hermite->color = color;
}

string CubicHermitePanel::getPanelName() {
	return panelName;
}

void CubicHermitePanel::deletePanel()
{
	gui->~ofxDatGui();
}
