#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "../primitives/Circle.h"
#include "../primitives/Rectangle.h"
#include "../primitives/Ligne.h"
#include "../primitives/Ellipse.h"
#include "../Curves/CubicBezier.h"
#include "../Curves/CubicHermite.h"

class PrimitivePanel
{
public:
	virtual void draw();
	virtual void setup(string name);
	virtual void setColor(ofColor color);
	virtual string getPanelName();
	virtual void deletePanel();
};