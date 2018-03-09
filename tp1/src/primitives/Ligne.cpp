#include "Ligne.h"

Ligne::Ligne() {
	p1x = 100.0;
	p1y = 100.0;
	p2x = 200.0;
	p2y = 100.0;
	color = ofColor::white;
}

bool Ligne::inside(ofPoint mouse)
{
	return mouse.distance(ofPoint(p1x, p1y));
}

void Ligne::draw() {
	ofSetColor(color);
	ofDrawLine(p1x, p1y, p2x, p2y);
}