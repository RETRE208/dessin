#include "Ligne.h"

Ligne::Ligne() {
	p1x = 100.0;
	p1y = 100.0;
	p2x = 200.0;
	p2y = 100.0;
	lineWidth = 1;
	color = ofColor::white;
}

void Ligne::draw() {
	ofSetLineWidth(lineWidth);
	ofSetColor(color);
	ofDrawLine(p1x, p1y, p2x, p2y);
}