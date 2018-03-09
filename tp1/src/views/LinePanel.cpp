#include "LinePanel.h"

void LinePanel::setup(string name)
{
	line = new Ligne();
	panelName = name;
	gui = new ofxDatGui(ofxDatGuiAnchor::TOP_RIGHT);
	gui->addHeader("Line Panel");
	sp1x = gui->addSlider("LINE POINT 1 X", 0, ofGetWidth());
	sp1y = gui->addSlider("LINE POINT 1 Y", 0, ofGetHeight());
	sp2x = gui->addSlider("LINE POINT 2 X", 0, ofGetWidth());
	sp2y = gui->addSlider("LINE POINT 2 Y", 0, ofGetHeight());
	picker = gui->addColorPicker("COLOR PICKER", ofColor::fromHex(0xCECECE));
	picker->onColorPickerEvent(this, &LinePanel::onColorPickerEvent);

	sp1x->bind(line->p1x);
	sp1y->bind(line->p1y);
	sp2x->bind(line->p2x);
	sp2y->bind(line->p2y);

	line->p1x = ofGetWidth() / 2;
	line->p1y = ofGetHeight() / 2;
	line->p2x = ofGetWidth() / 2;
	line->p2y = ofGetHeight() / 2;
}

void LinePanel::update()
{
	if (ofGetMousePressed() && gui->getMouseDown() == false) {
		ofPoint mouse = ofPoint(ofGetMouseX(), ofGetMouseY());
		if (line->inside(mouse)) {
			line->p1x = mouse.x;
			line->p1y = mouse.y;
		}
	}
}

void LinePanel::draw()
{
	line->draw();
	update();
}

void LinePanel::onColorPickerEvent(ofxDatGuiColorPickerEvent e)
{
	line->color = e.color;
}

