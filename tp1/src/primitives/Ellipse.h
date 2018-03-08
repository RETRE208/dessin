#pragma once

#include "ofMain.h"
namespace tp1 {
	class Ellipse
	{
	public:
		Ellipse();
		bool inside(ofPoint mouse);
		void draw();

		float x;
		float y;
		float width;
		float height;
		ofColor color;
	};
}


