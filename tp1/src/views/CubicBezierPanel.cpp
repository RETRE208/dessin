#include "CubicBezierPanel.h"

void CubicBezierPanel::setup(string name)
{
	bezier = new CubicBezier();
	panelName = name;
	gui = new ofxDatGui(ofxDatGuiAnchor::TOP_RIGHT);
	gui->setWidth(300);
	gui->addHeader(name);
	ctrl_point1x = gui->addSlider("Control Point 1 X", 0, ofGetWidth());
	ctrl_point1y = gui->addSlider("Control Point 1 Y", 0, ofGetWidth());
	ctrl_point2x = gui->addSlider("Control Point 2 X", 0, ofGetWidth());
	ctrl_point2y = gui->addSlider("Control Point 2 Y", 0, ofGetWidth());
	ctrl_point3x = gui->addSlider("Control Point 3 X", 0, ofGetWidth());
	ctrl_point3y = gui->addSlider("Control Point 3 Y", 0, ofGetWidth());
	ctrl_point4x = gui->addSlider("Control Point 4 X", 0, ofGetWidth());
	ctrl_point4y = gui->addSlider("Control Point 4 Y", 0, ofGetWidth());
	slineWidth = gui->addSlider("LINE WIDTH", 0.1, 8.0);
	picker = gui->addColorPicker("COLOR", ofColor::fromHex(0xCECECE));
	picker->onColorPickerEvent(this, &CubicBezierPanel::onColorPickerEvent);

	ctrl_point1x->bind(bezier->ctrl_point1x);
	ctrl_point1y->bind(bezier->ctrl_point1y);
	ctrl_point2x->bind(bezier->ctrl_point2x);
	ctrl_point2y->bind(bezier->ctrl_point2y);
	ctrl_point3x->bind(bezier->ctrl_point3x);
	ctrl_point3y->bind(bezier->ctrl_point3y);
	ctrl_point4x->bind(bezier->ctrl_point4x);
	ctrl_point4y->bind(bezier->ctrl_point4y);
	slineWidth->bind(bezier->line_width);
}

void CubicBezierPanel::draw()
{
	bezier->draw();
}

void CubicBezierPanel::onColorPickerEvent(ofxDatGuiColorPickerEvent e)
{
	if (e.target == picker) {
		bezier->color = e.color;
	}
}

void CubicBezierPanel::setColor(ofColor color) {
	bezier->color = color;
}

string CubicBezierPanel::getPanelName() {
	return panelName;
}

void CubicBezierPanel::deletePanel()
{
	gui->~ofxDatGui();
}